from loris_class import Loris

exclude = ['teacher_intake_info', 'teacher_survey_cover_page', 'coordinator_customization_for_teacher', 'umn_online_survey_consent', 'umn_online_survey_consent_04_04_2022', 'umn_online_survey_consent_08_09_2022', 'consent_tracker', 'mock_mri_survey']
exclude_error = ['family_medical_history_questionnaire', 'scapi']

loris = Loris()

# loris.create_all_instrument_files(exclude=exclude, sql=True)
# loris.commit()
## mysql connector may go out of sync after create_all_instruments. Run it seperately.

# loris.get_all_form_metadata(exclude=exclude)
# loris.commit()
# loris.populate_visits()
# loris.commit()
# loris.add_all_sessions()
# loris.commit()
## before proceeding run the loris script assign_missing_instruments.php

exclude.extend(exclude_error)
loris.populate_all_instruments(exclude=exclude)
loris.commit()

del loris