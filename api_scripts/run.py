from redcap_to_loris_class import RedcapToLoris

exclude = ['unsecured_email_authorization_form_umn_only', 'wu_phone_screen_consent', 'wu_phone_screen_consent_04_04_2022', 'wu_online_survey_consent', 'wu_online_survey_consent_04_04_2022', 'unsecured_email_authorization_form_wu_only', 'umn_phone_screen_consent', 'umn_phone_screen_consent_04_04_2022', 'umn_phone_screen_consent_08_09_2022', 'data_collection_info', 'phonescreen', 'teacher_intake_info', 'teacher_survey_cover_page', 'coordinator_customization_for_teacher', 'umn_online_survey_consent', 'umn_online_survey_consent_04_04_2022', 'umn_online_survey_consent_08_09_2022', 'consent_tracker', 'mock_mri_survey', 'vineland_tracker']

exclude_error = ['family_medical_history_questionnaire', 'scapi']
exclude_all = exclude + exclude_error

candidate_params = {
    'dob_field': 'child_dob',
    'sex_field': 'child_sex',
    'registration_center_field': 'research_site',
    'registration_date_field': 'date_phone_screen',
    'registration_project_id': 1,
    'registration_center_lookup': {"1":2, "2":3}
}

visits = [
    { "label": "Visit1", "match": "visit_1", "scan": False },
    { "label": "Visit2", "match": "visit_2", "scan": False },
    { "label": "MRIVisit1", "match": "mri_visit", "scan": True },
    { "label": "MRIVisit2", "scan": True },
    { "label": "MRIVisit3", "scan": True },
    { "label": "MRIVisit4", "scan": True }
]

report_id = 47678

def get_subproject_function(subject):
    if "SUB-1" in subject:
        return 1
    elif "SUB-2" in subject:
        return 2
    else:
        print("Invalid Subject ID for get_subproject_function")
        return -1

expected_repeat_instruments = { 'mri_data_entry_summary': { 2: "MRIVisit2", 3: "MRIVisit3", 4: "MRIVisit4" } }

DataTransfer = RedcapToLoris()

DataTransfer.get_records()
DataTransfer.get_form_event_mapping()
DataTransfer.get_metadata()
DataTransfer.get_report(report_id)

DataTransfer.populate_candidate_table(**candidate_params)
DataTransfer.populate_visit_table(visits=visits)
DataTransfer.populate_test_battery_table(exclude=exclude_all, visits=visits, expected_repeat_instruments=expected_repeat_instruments)
DataTransfer.populate_session_table(visits=visits, get_subproject_function=get_subproject_function, report_id=report_id, expected_repeat_instruments=expected_repeat_instruments)

DataTransfer.commit()


del DataTransfer