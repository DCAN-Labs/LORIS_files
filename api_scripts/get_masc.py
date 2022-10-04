import requests
import json

data = {
    'token': '43E50FE84102CCBB71217A60BE4F9E6D',
    'content': 'record',
    'action': 'export',
    'format': 'json',
    'type': 'flat',
    'csvDelimiter': '',
    'fields[0]': 'record_id',
    'forms[0]': 'masc_2_child',
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
records = [record for record in records if record['masc_2_child_complete']]
with open('response.json', 'w+') as file:
    json.dump(records, file)