#conda env redcap
import requests
from random import randint
import json
import mysql.connector
from config import config
import datetime 

cnx = mysql.connector.connect(**config)
cursor = cnx.cursor()

candID_query = ("SELECT CandID FROM candidate")
existing_cand_ids = []
cursor.execute(candID_query)
for candID in cursor:
    existing_cand_ids.append(candID[0])

add_candidate = ("INSERT INTO candidate "
    "(CandID, PSCID, DoB, Sex, RegistrationCenterID, RegistrationProjectID, Active, Date_active, RegisteredBy, UserID, Date_registered, flagged_caveatemptor, Testdate, Entity_type) "
    "VALUES (%(CandID)s, %(PSCID)s, %(DoB)s, %(Sex)s, %(RegistrationCenterID)s, %(RegistrationProjectID)s, %(Active)s, %(Date_active)s, %(RegisteredBy)s, %(UserID)s, %(Date_registered)s, %(flagged_caveatemptor)s, %(Testdate)s, %(Entity_type)s)")

sex_lookup = {
    '1': 'Male',
    '2': 'Female',
    '': 'Other'
}

def generate_offset():
    offset = 0
    while offset <= 10 and offset >= -10:
        offset = randint(-30,30)
    return offset

def jitter_dob(dob):
    offset = datetime.timedelta(days = generate_offset())
    date = datetime.datetime.strptime(dob, '%Y-%m-%d')
    jittered_dob = date + offset
    return jittered_dob.strftime('%Y-%m-%d')

def generate_cand_id():
    while True:
        cand_id = randint(100000, 999999)
        if cand_id not in existing_cand_ids:
            break
    return cand_id

def get_cand_info(record):
    candidate_info = {
        "CandID": generate_cand_id(),
        "PSCID": record['record_id'],
        "DoB": jitter_dob(record['child_dob']),
        "Sex": sex_lookup[record['child_sex']],
        "RegistrationCenterID": int(record['research_site']) + 19,
        "RegistrationProjectID": 3,
        "Active": 'Y',
        "Date_active": record['date_phone_screen'],
        "RegisteredBy": 'redcapTransfer',
        "UserID": 'redcapTransfer',
        "Date_registered": record['date_phone_screen'],
        "flagged_caveatemptor": 'false',
        "Testdate": record['date_phone_screen'],
        "Entity_type": 'Human'
    }
    return candidate_info

data = {
    'token': '43E50FE84102CCBB71217A60BE4F9E6D',
    'content': 'record',
    'action': 'export',
    'format': 'json',
    'type': 'flat',
    'csvDelimiter': '',
    'fields[0]': 'record_id',
    'fields[1]': 'child_dob',
    'fields[2]': 'child_sex',
    'fields[3]': 'research_site',
    'fields[4]': 'date_phone_screen',
    'rawOrLabel': 'raw',
    'rawOrLabelHeaders': 'raw',
    'exportCheckboxLabel': 'false',
    'exportSurveyFields': 'false',
    'exportDataAccessGroups': 'false',
    'returnFormat': 'json'
}

r = requests.post('https://redcap.ahc.umn.edu/api/',data=data)
print('HTTP Status: ' + str(r.status_code))
records = r.json()
with open('response.json', 'w+') as file:
    json.dump(records, file)

for record in records:
    if(record['date_phone_screen']):
        cursor.execute(add_candidate, get_cand_info(record))


# cnx.commit()
cursor.close()
cnx.close()
