from loris_class import Loris
from redcap_to_loris_class import RedcapToLoris

exclude = ['unsecured_email_authorization_form_umn_only', 'unsecured_email_authorization_form_wu_only', 'umn_phone_screen_consent', 'umn_phone_screen_consent_04_04_2022', 'umn_phone_screen_consent_08_09_2022', 'data_collection_info', 'phonescreen', 'teacher_intake_info', 'teacher_survey_cover_page', 'coordinator_customization_for_teacher', 'umn_online_survey_consent', 'umn_online_survey_consent_04_04_2022', 'umn_online_survey_consent_08_09_2022', 'consent_tracker', 'mock_mri_survey', 'vineland_tracker']
exclude_error = ['family_medical_history_questionnaire', 'scapi']

loris = RedcapToLoris(verbose=True)

condition = {
    "CandID":  958271,
    "CenterID": 2,
    "Visit_label": "Visit1"
}
fields = ["ID", "CandID", "Visit_label"]

values = {
    'CandID': 958271,
    'Visit_label': "MRIVisit4",
    'CenterID': 1,
    'ProjectID': 1,
    'SubprojectID': 1,
    'Current_stage': "Visit",
    'Visit': "In Progress",
    'Date_visit': "2000-01-01",
    'RegisteredBy': "redcapTransfer",
    'UserID': "redcapTransfer",
    'Scan_done': "N",
    'languageID': 1
}

# print(loris.query(table="session", fields=["*"], where=condition, where_like={"ID": "8%"}))
loris.update(table="session", fields=values, where=condition)


del loris
