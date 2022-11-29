import mysql.connector
import datetime
import requests
import json
import traceback
import functools
from jinja2 import Template
from config import config, token, api_route
from random import randint

class RedcapToLoris:

    ## setup database connection, basic operations
    def __init__(self, **kwargs):
        self.verbose = kwargs.get("verbose")

        self.cnx = mysql.connector.connect(**config)
        self.cursor = self.cnx.cursor(dictionary=True)
        self.error_log = "outputs/redcap_to_loris_errors.txt"
        self.token = token
        self.api_route = api_route
        self.reports = {}


    def __del__(self):
        self.cnx.close()
        self.cursor.close()

    def commit(self):
        self.cnx.commit()

    def insert(self, table, dict):
        placeholder = ", ".join(["%s"] * len(dict))
        stmt = "INSERT INTO `{table}` ({columns}) VALUES ({values});".format(table=table, columns=",".join(dict.keys()), values=placeholder)
        self.cursor.execute(stmt, list(dict.values()))

    def query(self, **kwargs):
        table = kwargs.get("table")
        fields = kwargs.get("fields")
        where = kwargs.get("where")
        where_like = kwargs.get("where_like")

        columns = ', '.join(fields)

        query = f"SELECT {columns} FROM {table}"

        if where:
            wheres = ' AND '.join(f'{key} = "{value}"' for key, value in where.items())
   
        if where_like:
            where_likes = ' AND '.join(f'{key} LIKE "{value}"' for key, value in where_like.items())

        if where and where_like:
            query += " WHERE " + wheres + " AND " + where_likes
        elif where:
            query += " WHERE " + wheres
        elif where_like:
            query += " WHERE " + where_likes

        self.cursor.execute(query)
        return [row for row in self.cursor]

    def update(self, **kwargs):
        table = kwargs.get("table")
        fields = kwargs.get("fields")
        where = kwargs.get("where")

        sql = 'UPDATE {table} SET {values} WHERE {where}'.format(table=table, values=', '.join('{}=%s'.format(key) for key in fields), where=' AND '.join(f'{key} = "{value}"' for key, value in where.items()))
        self.cursor.execute(sql, list(fields.values()))


    def log_error(self, **kwargs):
        method = kwargs.get("method")
        details = kwargs.get("details")

        if self.verbose:
            print(f"Error executing {method}: {details}")
        with open(self.error_log, "a") as file:
            file.write(f"--------------------------\n{datetime.datetime.now()} | Error in {method}: {details}\n{traceback.format_exc()}\n")

    ## api calls

    def get_data(self, data):
        name = data['content']
        r = requests.post(self.api_route,data=data)
        result = r.json()
        print(f'Get {name} HTTP Status: ' + str(r.status_code))

        if self.verbose:
            with open(f'outputs/json/{name}.json', 'w+') as file:
                json.dump(result, file, indent=4)

        return result

    def get_records(self):
        data = {
            'token': self.token,
            'content': 'record',
            'action': 'export',
            'format': 'json',
            'type': 'flat',
            'csvDelimiter': '',
            'rawOrLabel': 'raw',
            'rawOrLabelHeaders': 'raw',
            'exportCheckboxLabel': 'false',
            'exportSurveyFields': 'false',
            'exportDataAccessGroups': 'false',
            'returnFormat': 'json'
        }
        self.records = self.get_data(data)

    
    def get_metadata(self):
        data = {
            'token': f'{self.token}',
            'content': 'metadata',
            'format': 'json',
            'returnFormat': 'json',
        }
        self.metadata = self.get_data(data)

    def get_form_event_mapping(self):
        data = {
            'token': self.token,
            'content': 'formEventMapping',
            'format': 'json',
            'returnFormat': 'json'
        }
        self.form_event_mapping = self.get_data(data)

    def get_report(self, report_id):
        data = {
            'token': self.token,
            'content': 'report',
            'format': 'json',
            'report_id': report_id,
            'csvDelimiter': '',
            'rawOrLabel': 'raw',
            'rawOrLabelHeaders': 'raw',
            'exportCheckboxLabel': 'false',
            'returnFormat': 'json'
        }
        self.reports[report_id] = self.get_data(data)

    ## Creating Candidates

    def get_existing_candidates(self):
        candidates = self.query(table='candidate', fields=['PSCID', 'CandID'])
        self.cand_ids = [candidate["CandID"] for candidate in candidates]
        self.pscids = [candidate["PSCID"] for candidate in candidates]

    def generate_offset(self):
        offset = 0
        while offset <= 10 and offset >= -10:
            offset = randint(-30,30)
        return offset

    def jitter_dob(self, dob):
        offset = datetime.timedelta(days = self.generate_offset())
        date = datetime.datetime.strptime(dob, '%Y-%m-%d')
        jittered_dob = date + offset
        return jittered_dob.strftime('%Y-%m-%d')

    def generate_cand_id(self):
        while True:
            cand_id = randint(100000, 999999)
            if cand_id not in self.cand_ids:
                break
            self.cand_ids.append(cand_id)
        return cand_id

    def get_cand_info(self, **kwargs):
        record = kwargs.get("record")
        dob_field = kwargs.get("dob_field")
        sex_field = kwargs.get("sex_field")
        registration_center_field = kwargs.get("registration_center_field")
        registration_date_field = kwargs.get("registration_date_field")
        registration_project_id = kwargs.get("registration_project_id")
        registration_center_lookup = kwargs.get("registration_center_lookup")
        sex_lookup = {
            '1': 'Male',
            '2': 'Female',
            '': 'Other'
        }
        candidate_info = {
            "CandID": self.generate_cand_id(),
            "PSCID": record['record_id'],
            "DoB": self.jitter_dob(record[dob_field]),
            "Sex": sex_lookup[record[sex_field]],
            "RegistrationCenterID": registration_center_lookup[record[registration_center_field]],
            "RegistrationProjectID": registration_project_id,
            "Active": 'Y',
            "Date_active": record[registration_date_field],
            "RegisteredBy": 'redcapTransfer',
            "UserID": 'redcapTransfer',
            "Date_registered": record[registration_date_field],
            "flagged_caveatemptor": 'false',
            "Testdate": record[registration_date_field],
            "Entity_type": 'Human'
        }
        return candidate_info

    def populate_candidate_table(self, **kwargs):
        dob_field = kwargs.get("dob_field")
        sex_field = kwargs.get("sex_field")
        registration_center_field = kwargs.get("registration_center_field")
        registration_date_field = kwargs.get("registration_date_field")
        registration_project_id = kwargs.get("registration_project_id", 1)
        registration_center_lookup = kwargs.get("registration_center_lookup")

        self.get_existing_candidates()
        num_old = len(self.cand_ids)
        num_added = 0
        num_error = 0
        for record in self.records:
            if record["record_id"] not in self.pscids and record[registration_date_field]:
                try:
                    candidate_info = self.get_cand_info(
                        record = record,
                        dob_field = dob_field,
                        sex_field = sex_field,
                        registration_center_field = registration_center_field,
                        registration_date_field = registration_date_field,
                        registration_project_id = registration_project_id,
                        registration_center_lookup = registration_center_lookup
                    )
                    self.insert('candidate', candidate_info)
                    if self.verbose:
                        print(f"Added candidate: {record['record_id']}")
                    num_added += 1
                except Exception:
                    self.log_error(method='populate_candidate_table', details=record["record_id"])
                    num_error += 1
        print(f"{num_added + num_old} candidates in LORIS. {num_old} unchanged, {num_added} added. {num_error} errors.")

    ## make instruments


    ## set up project in database

    def populate_visit_table(self, **kwargs):
        visits = kwargs.get("visits")

        num_old = self.query(table="visit", fields=["count(*)"])[0]["count(*)"]
        num_new = 0
        num_error = 0

        for visit in visits:
            values = {
                "VisitName": visit["label"],
                "VisitLabel": visit["label"]
            }
            if not len(self.query(table="visit", fields=list(values.keys()), where=values)):
                try:
                    self.insert('visit', values)
                    num_new += 1
                    if self.verbose:
                        print(f"Added visit {visit['label']}")
                except Exception:
                    self.log_error(method="populate_visit_table", details=visit["label"])
                    num_error += 1
        f"{num_old + num_new} visits in visit. {num_old} unchanged, {num_new} added. {num_error} errors."

    def populate_test_battery_table(self, **kwargs):
        visits = kwargs.get("visits")
        exclude = kwargs.get("exclude")
        expected_repeat_instruments = kwargs.get("expected_repeat_instruments")

        old_num = self.query(table="test_battery", fields=["count(*)"])[0]["count(*)"]
        new_num = 0
        num_error = 0

        for form in self.form_event_mapping:
            if form["form"] not in exclude:
                visit_labels = []
                if form["form"] in expected_repeat_instruments:
                    visit_labels = list(expected_repeat_instruments[form["form"]].values())
                else:
                    visit_label = 'NULL'
                    for visit in visits:
                        if "match" in visit:
                            if visit["match"] in form["unique_event_name"]:
                                visit_label = visit["label"]
                                break
                    visit_labels = [visit_label]
                for visit_label in visit_labels:
                    values = {
                        "Test_name": form["form"],
                        "AgeMinDays": 0,
                        "AgeMaxDays": 99999,
                        "Stage": 'Visit',
                        "SubprojectID": form["arm_num"],
                        "Visit_label": visit_label
                    }
                    if not len(self.query(table="test_battery", fields=list(values.keys()), where=values)):
                        try:
                            if visit_label == 'NULL':
                                raise Exception(f"Visit_label NULL for {form['form']}")
                            self.insert("test_battery", values)
                            new_num += 1
                            if self.verbose:
                                print(f"Added test {form['form']}, {visit_label}")
                        except Exception:
                            self.log_error(method="populate_test_battery_table", details=form["form"])
                            num_error += 1
        print(f"{old_num + new_num} tests in test_battery. {old_num} unchanged, {new_num} added. {num_error} errors.")

    def populate_session_table(self, **kwargs):
        visits = kwargs.get("visits")
        get_subproject_function = kwargs.get("get_subproject_function")
        report_id = kwargs.get("report_id") ## this function expects a report that generates a row for each form containing its <form>_complete and <form>_timestamp field
        expected_repeat_instruments = kwargs.get("expected_repeat_instruments")

        subject_visits = {}
        for record in self.records:
            subject = record['record_id']
            result = self.query(table="candidate", fields=["CandID"], where={"PSCID": subject})
            if result:
                cand_id = result[0]["CandID"]
                if subject not in subject_visits:
                    subject_visits[subject] = { "CandID": cand_id, "visits": {} }
                repeat_instrument = False
                if record["redcap_repeat_instrument"] in expected_repeat_instruments:
                    if record["redcap_repeat_instance"] in expected_repeat_instruments[record["redcap_repeat_instrument"]]:
                        repeat_instrument = True
                        visit_label = expected_repeat_instruments[record["redcap_repeat_instrument"]][record["redcap_repeat_instance"]]
                        for visit in visits:
                            if visit_label == visit["label"]:
                                subject_visits[subject]["visits"][visit_label] = visit
                                break
                if not repeat_instrument:
                    for visit in visits:
                        if "match" in visit:
                            if visit["match"] in record["redcap_event_name"]:
                                subject_visits[subject]["visits"][visit['label']] = visit
                                break

        num_old = self.query(table="session", fields=["count(*)"])[0]["count(*)"]
        num_new = 0
        num_error = 0
        for subject in subject_visits:
            for visit in subject_visits[subject]["visits"]:
                values = {
                    'CandID': subject_visits[subject]["CandID"],
                    'Visit_label': visit,
                }
                if not len(self.query(table="session", fields=list(values.keys()), where=values)):
                    scan_done = 'Y' if subject_visits[subject]["visits"][visit]['scan'] else 'N'
                    result = self.query(table='candidate', fields=['RegistrationCenterID', 'RegistrationProjectID'], where={"PSCID": subject})[0]
                    center_id = result['RegistrationCenterID']
                    project_id = result["RegistrationProjectID"]
                    subproject_id = get_subproject_function(subject)

                    timestamps = []
                    for row in self.reports[report_id]:
                        if subject in row["record_id"]:
                            if "match" in subject_visits[subject]["visits"][visit]:
                                if subject_visits[subject]["visits"][visit]['match'] in row["redcap_event_name"]:
                                    for field in row:
                                        if "_timestamp" in field and row[field]:
                                            timestamps.append(row[field])
                            if row["redcap_repeat_instrument"] in expected_repeat_instruments:
                                if row["redcap_repeat_instance"] in expected_repeat_instruments[row["redcap_repeat_instrument"]]:
                                    if row[f"{row['redcap_repeat_instrument']}_timestamp"]:
                                        timestamps.append(row[f"{row['redcap_repeat_instrument']}_timestamp"])
                    try:
                        visit_date = functools.reduce(lambda a, b: a if a < b else b, timestamps)
                    except Exception:
                        self.log_error(method="functools.reduce() in populate_session_table", details=f"{subject}, {visit}")
                        num_error += 1
                        continue

                    values.update({ 
                        'CenterID': center_id,
                        'ProjectID': project_id,
                        'SubprojectID': subproject_id,
                        'Current_stage': "Visit",
                        'Visit': "In Progress",
                        'Date_visit': visit_date,
                        'RegisteredBy': "redcapTransfer",
                        'UserID': "redcapTransfer",
                        'Scan_done': scan_done,
                        'languageID': 1
                    })
                    try:
                        self.insert('session', values)
                        num_new += 1
                        if self.verbose:
                            print(f"Added session {subject}, {visit_label}")
                    except Exception:
                        self.log_error(method="populate_session_table", details=f"{subject}, {visit}")
                        num_error += 1
        print(f"{num_old + num_new} sessions in session. {num_old} unchanged, {num_new} added. {num_error} errors.")

    def populate_session_table_override(self, **kwargs):
        visits = kwargs.get("visits")
        override_visits = kwargs.get("override_visits")
        get_subproject_function = kwargs.get("get_subproject_function")
        expected_repeat_instruments = kwargs.get("expected_repeat_instruments")

        num_old = self.query(table="session", fields=["count(*)"])[0]["count(*)"]
        num_new = 0
        num_error = 0

        for override_visit in override_visits:
            visit_label = override_visit["label"]
            date_field = override_visit["date_field"]
            identifier = override_visit["identifier"]
            
            for record in self.records:
                if record[identifier]:
                    if record["redcap_repeat_instrument"]:
                        repeat_instrument = record["redcap_repeat_instrument"]
                        repeat_instance = record["redcap_repeat_instance"]
                        skip = True
                        if repeat_instrument in expected_repeat_instruments:
                            if repeat_instance in expected_repeat_instruments[repeat_instrument]:
                                if visit_label == expected_repeat_instruments[repeat_instrument][repeat_instance]:
                                    skip = False
                        if skip:
                            continue
                                
                    subject = record['record_id']
                    result = self.query(table="candidate", fields=["CandID", "RegistrationCenterID", "RegistrationProjectID"], where={"PSCID":subject})
                    try:
                        cand_id = result[0]["CandID"]
                    except:
                        self.log_error(method="populate_session_table_override", details=f"{subject}, {visit_label}")
                        num_error += 1
                        continue
                    values = {
                        'CandID': cand_id,
                        'Visit_label': visit_label,
                    }
                    if not len(self.query(table="session", fields=list(values.keys()), where=values)):
                        scan_done = 'N'
                        for visit in visits:
                            if visit["label"] == visit_label:
                                scan_done = 'Y' if visit['scan'] else 'N'
                        center_id = result[0]['RegistrationCenterID']
                        project_id = result[0]["RegistrationProjectID"]
                        subproject_id = get_subproject_function(subject)
                        visit_date = record[date_field]

                        values.update({ 
                            'CenterID': center_id,
                            'ProjectID': project_id,
                            'SubprojectID': subproject_id,
                            'Current_stage': "Visit",
                            'Visit': "In Progress",
                            'Date_visit': visit_date,
                            'RegisteredBy': "redcapTransfer",
                            'UserID': "redcapTransfer",
                            'Scan_done': scan_done,
                            'languageID': 1
                        })
                        try:
                            self.insert('session', values)
                            num_new += 1
                            if self.verbose:
                                print(f"Added session {subject}, {visit_label}")
                        except Exception:
                            self.log_error(method="populate_session_table_override", details=f"{subject}, {visit}")
                            num_error += 1
        print(f"{num_old + num_new} sessions in session. {num_old} unchanged, {num_new} added. {num_error} errors.")

    def transfer_data(self, **kwargs):
        visits = kwargs.get("visits")
        expected_repeat_instruments = kwargs.get("expected_repeat_instruments")
        handle_subject_ids = kwargs.get("handle_subject_ids", lambda x: x)

        num_flag = self.query(table="flag", fields=["count(*)"])[0]["count(*)"]
        updated_flag = 0
        updated_inst = 0
        num_error = 0

        keys = list(self.records[0].keys())
        multi_selects = []
        for key in keys:
            if "___" in key:
                split_key = key.split("___")[0]
                if split_key not in multi_selects:
                    multi_selects.append(split_key)

        for record in self.records:

            for visit in visits:
                if "match" in visit:
                    if visit["match"] in record["redcap_event_name"]:
                        visit_label = visit["label"]
                        break

            if record["redcap_repeat_instrument"]:
                if record["redcap_repeat_instrument"] in expected_repeat_instruments:
                    visit_label = expected_repeat_instruments[record["redcap_repeat_instrument"]][record["redcap_repeat_instance"]]

            subject = handle_subject_ids(record["record_id"])
            result = self.query(table="candidate", fields=["CandID", "RegistrationCenterID", "RegistrationProjectID"], where={"PSCID": subject})
            try:
                cand_id = result[0]["CandID"]
            except:
                self.log_error(method="transfer_data", details=f"CandID lookup for {subject}")
                num_error += 1
                continue
            result = self.query(table="session", fields=["ID", "SubprojectID"], where={"CandID": cand_id, "Visit_label": visit_label })
            try:
                session_id = result[0]['ID']
                subproject_id = result[0]['SubprojectID']
            except:
                self.log_error(method="transfer_data", details=f"session lookup for {subject}")
                num_error += 1
                continue
            partial_comment_id = f"{cand_id}{subject}{session_id}{subproject_id}"

            tests = self.query(table="flag", fields=["Test_name"], where_like={ "CommentID": f"{partial_comment_id}%" })
            for test in tests:
                test_name = test["Test_name"]
                current_data = self.query(table=test_name, fields=["*"], where_like={ "CommentID": f"{partial_comment_id}%" })
                values = current_data[0]
                empty = True
                for value in values:
                    if value in record:
                        if record[value]:
                            values[value] = record[value]
                            empty = False
                        else:
                            values[value] = None
                    elif value in multi_selects:
                        choice_string = list(filter(lambda field: field["field_name"] == value, self.metadata))[0]["select_choices_or_calculations"]
                        choices = { choice.split(", ")[0]: choice.split(", ")[1] for choice in choice_string.split(" | ") }
                        multi_select_values = [choices[choice] for choice in choices if record[f"{value}___{choice}"] == "1"]
                        if multi_select_values:
                            values[value] = ",".join(multi_select_values)
                            empty = False
                        else:
                            values[value] = None
                if not empty:
                    try:
                        self.update(table=test_name, fields=values, where={ "CommentID": values["CommentID"]})
                        updated_inst += 1
                        if self.verbose:
                            print(f"Updated {test_name}, {subject}")
                    except Exception:
                        self.log_error(method="transfer_data", details=f"update {test_name}, {subject}")
                        num_error += 1
                if record[f"{test_name}_complete"] == "2":
                    flag_values = {
                        "Data_entry": "Complete",
                        "Administration": "All"
                    }
                    try:
                        self.update(table="flag", fields=flag_values, where={ "CommentID": values["CommentID"]})
                        updated_flag += 1
                        if self.verbose:
                            print(f"Updated flag: {test_name}, {subject}")
                    except Exception:
                        self.log_error(method="transfer_data", details=f"update flag: {test_name}, {subject}")
                        num_error += 1

        print(f"{num_flag} tests in flag. {updated_inst} instrument entries updated. {updated_flag} flag entries updated. {num_error} errors.")

    def populate_candidate_parameters(self, **kwargs):
        # add to parameter_type_category and parameter_type_category_rel
        candidate_parameters = kwargs.get("candidate_parameters")

        num_parameters = self.query(table="parameter_candidate", fields=["count(*)"])[0]["count(*)"]
        num_new = 0
        num_error = 0

        keys = list(self.records[0].keys())
        multi_selects = []
        for key in keys:
            if "___" in key:
                split_key = key.split("___")[0]
                if split_key not in multi_selects:
                    multi_selects.append(split_key)

        for parameter in candidate_parameters:
            metadata = list(filter(lambda field: field["field_name"] == parameter, self.metadata))[0]
            result = self.query(table="parameter_type", fields=["ParameterTypeID"], where={ "Name": parameter })
            if result:
                parameter_id = result[0]["ParameterTypeID"]
            else:
                values = {
                    "Name": parameter,
                    "Type": "varchar(255)",
                    "Description": metadata["field_label"],
                    "SourceFrom": "parameter_file",
                    "Queryable": 1
                }
                self.insert("parameter_type", values)
                parameter_id = self.query(table="parameter_type", fields=["ParameterTypeID"], where={ "Name": parameter })[0]["ParameterTypeID"]

            for record in self.records:
                empty = True
                if parameter in multi_selects:
                    fields = list(filter(lambda field: parameter in field, list(record.keys())))
                    if record[fields[0]]:
                        empty = False

                    if not empty:
                        choice_string = list(filter(lambda field: field["field_name"] == parameter, self.metadata))[0]["select_choices_or_calculations"]
                        choices = { choice.split(", ")[0]: choice.split(", ")[1] for choice in choice_string.split(" | ") }
                        multi_select_values = [choices[choice] for choice in choices if record[f"{parameter}___{choice}"] == "1"]
                        value  = ", ".join(multi_select_values)

                else:
                    if record[parameter]:
                        empty = False
                        choice_string = list(filter(lambda field: field["field_name"] == parameter, self.metadata))[0]["select_choices_or_calculations"]
                        choices = { choice.split(", ")[0]: choice.split(", ")[1] for choice in choice_string.split(" | ") }
                        value = choices[record[parameter]]
                
                if not empty:
                    subject = record["record_id"]
                    result = self.query(table="candidate", fields=["CandID"], where={"PSCID": subject})
                    try:
                        cand_id = result[0]["CandID"]
                    except:
                        self.log_error(method="populate_candidate_parameters", details=f"CandID lookup for {subject}")
                        num_error += 1
                        continue

                    to_insert = { 
                        "CandID": cand_id,
                        "ParameterTypeID": parameter_id,
                        "Value": value
                    }
                    if not len(self.query(table="parameter_candidate", fields=list(to_insert.keys()), where=to_insert)):
                        try:
                            self.insert("parameter_candidate", to_insert)
                            num_new += 1
                            if self.verbose:
                                print(f"Inserted Candidate Parameter: {parameter}, {subject}")
                        except Exception:
                            self.log_error(method="populate_candidate_parameters", details=f"insert parameter_candidate: {parameter}, {subject}")
                            num_error += 1

        print(f"{num_parameters} candidate parameters in parameter_candidate. {num_new} added. {num_error} errors.")

