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
    def __init__(self):
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

    def query(self, table, fields, condition):
        query = (f"SELECT {fields} FROM {table} " f"WHERE {condition}")
        self.cursor.execute(query)
        return [row for row in self.cursor]
    
    def log_error(self, **kwargs):
        method = kwargs.get("method")
        details = kwargs.get("details")

        print(f"Error executing {method}: {details}")
        with open(self.error_log, "a") as file:
            file.write(f"--------------------------\n{datetime.datetime.now()} | Error in {method}: {details}\n{traceback.format_exc()}\n")

    ## api calls

    def get_data(self, data):
        name = data['content']
        r = requests.post(self.api_route,data=data)
        result = r.json()
        print(f'Get {name} HTTP Status: ' + str(r.status_code))

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
        candidates = self.query('candidate', 'PSCID, CandID', 'ID')
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

        existing_visits = self.query('visit', "VisitName, VisitLabel", "VisitID")
        num_old = len(existing_visits)
        num_new = 0
        num_error = 0

        for visit in visits:
            values = {
                "VisitName": visit["label"],
                "VisitLabel": visit["label"]
            }
            duplicate = False
            for existing_visit in existing_visits:
                if existing_visit == values:
                    duplicate = True
                    break
            if not duplicate:
                try:
                    self.insert('visit', values)
                    num_new += 1
                except Exception:
                    self.log_error(method="populate_visit_table", details=visit["label"])
                    num_error += 1
        f"{num_old + num_new} visits in visit. {num_old} unchanged, {num_new} added. {num_error} errors."

    def populate_test_battery_table(self, **kwargs):
        visits = kwargs.get("visits")
        exclude = kwargs.get("exclude")
        expected_repeat_instruments = kwargs.get("expected_repeat_instruments")

        tests = self.query("test_battery", "Test_name, AgeMinDays, AgeMaxDays, Stage, SubprojectID, Visit_label", "ID")
        old_num = len(tests)
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
                    
                    duplicate = False
                    for test in tests:
                        if test == values:
                            duplicate = True
                            break
                    if not duplicate:
                        try:
                            if visit_label == 'NULL':
                                raise Exception(f"Visit_label NULL for {form['form']}")
                            self.insert("test_battery", values)
                            new_num += 1
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
            result = self.query("candidate", "CandID", f"PSCID = '{subject}'")
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

        sessions = self.query('session', 'CandID, Visit_label', 'ID')
        num_old = len(sessions)
        num_new = 0
        num_error = 0
        for subject in subject_visits:
            for visit in subject_visits[subject]["visits"]:
                values = {
                    'CandID': subject_visits[subject]["CandID"],
                    'Visit_label': visit,
                }
                duplicate = False
                for session in sessions:
                    if values == session:
                        duplicate = True
                        break
                if not duplicate:
                    scan_done = 'Y' if subject_visits[subject]["visits"][visit]['scan'] else 'N'
                    result = self.query('candidate', 'RegistrationCenterID, RegistrationProjectID', f"PSCID = '{subject}'")[0]
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
                                    timestamps.append(row[f"{row['redcap_repeat_instrument']}_timestamp"])
                    try:
                        visit_date = functools.reduce(lambda a, b: a if a < b else b, timestamps)
                    except Exception:
                        self.log_error(method="visit_date = functools.reduce() in populate_session_table", details=f"{subject}, {visit}")
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
                    except Exception:
                        self.log_error(method="populate_session_table", details=f"{subject}, {visit}")
                        num_error += 1
        print(f"{num_old + num_new} sessions in session. {num_old} unchanged, {num_new} added. {num_error} errors.")
