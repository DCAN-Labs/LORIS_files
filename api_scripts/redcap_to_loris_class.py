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

        tests = self.query("test_battery", "Test_name, AgeMinDays, AgeMaxDays, Stage, SubprojectID, Visit_label", "ID")
        old_num = len(tests)
        new_num = 0
        num_error = 0

        for form in self.form_event_mapping:
            if form["form"] not in exclude:
                visit_label = 'NULL'
                for visit in visits:
                    if "match" in visit:
                        if visit["match"] in form["unique_event_name"]:
                            visit_label = visit["label"]
                            break
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
                        self.log_error(method="populate_test_battery", details=form["form"])
                        num_error += 1
        print(f"{old_num + new_num} tests in test_battery. {old_num} unchanged, {new_num} added. {num_error} errors.")

    def populate_session_table(self, **kwargs):
        visits = kwargs.get("visits")

        subject_visits = {}
        for record in self.records:
            subject = record['record_id']
            result = self.query("candidate", "CandID", f"PSCID = '{subject}'")
            if result:
                cand_id = result[0]["CandID"]
                if subject not in subject_visits:
                    subject_visits[subject] = {}
                for visit in visits:
                    if "match" in visit:
                        if visit["match"] in record["redcap_event_name"]:
                            subject_visits[subject][visit['label']] = True
                            break
        
        sessions = self.query('session', 'CandID, Visit_label', 'ID')
        num_old = len(sessions)
        num_new = 0
        num_error = 0
        for subject in subject_visits:
            for visit in subject_visits[subject]:
                values = {
                    'CandID': cand_id,
                    'Visit_label': visit,
                }
                duplicate = False
                for session in sessions:
                    if values == session:
                        duplicate = True
                        break
                if not duplicate:
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
                        self.log_error(method="populate_session", details=f"{subject}, {visit}")
                        num_error += 1
        print(f"{num_old + num_new} sessions in session. {num_old} unchanged, {num_new} added. {num_error} errors.")
                