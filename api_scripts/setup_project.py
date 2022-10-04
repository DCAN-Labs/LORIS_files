from loris_class import Loris

subjects = ['SUB-10009-01', 'SUB-20048-01', 'SUB-10001-01']
forms = ["developmental_history_questionnaire",
    "medical_history_questionnaire",
    "family_medical_history_questionnaire",
    "scq_lifetime",
    "srs2_schoolage",
    "adhd_rs_home",
    "conners_3",
    "aq_ages_411",
    "cbcl_ages_6",
    "ccc_2",
    "sibling_information",
    "cars_2",
    "wisc",
    "masc_2_child",
    "cdi_2_child",
    "handedness_child",
    "conners_3_teacher",
    "adhd_rs_school",
    "bpm_ages_618",
    "srs2_for_teacher",
    "ssis",
    "cbcl_ages_15_to_5",
    "sleep_habits",
    "puberty_scale_child",
    "tmcq",
    "swan",
    "aq_ages_1215",
    "aq_ages_16",
    "srs2_preschool",
    "srs2_relative_other",
    "srs2_adult_selfreport",
    "icu",
    "neo",
    "bapq",
    "puberty_scale",
    "scapi",
    "asr",
    "brief_2",
    "caars",
    "psi",
    "rsbr",
    "neo_other_bio_parent",
    "caars_other_bio_parent"]

loris = Loris()
loris.get_form_metadata(forms=forms)

loris.create_all_instrument_files()
# loris.commit()
del loris