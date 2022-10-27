from loris_class import Loris

exclude = ['unsecured_email_authorization_form_umn_only', 'unsecured_email_authorization_form_wu_only', 'umn_phone_screen_consent', 'umn_phone_screen_consent_04_04_2022', 'umn_phone_screen_consent_08_09_2022', 'data_collection_info', 'phonescreen', 'teacher_intake_info', 'teacher_survey_cover_page', 'coordinator_customization_for_teacher', 'umn_online_survey_consent', 'umn_online_survey_consent_04_04_2022', 'umn_online_survey_consent_08_09_2022', 'consent_tracker', 'mock_mri_survey', 'vineland_tracker']
exclude_error = ['family_medical_history_questionnaire', 'scapi']

loris = Loris()

loris.get_survey_dates()
loris.update_session_dates(exclude=['mri_visit_2', 'mri_visit_3', 'mri_visit_4'])

loris.commit()

del loris