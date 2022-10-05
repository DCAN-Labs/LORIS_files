from loris_class import Loris

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

forms1 = ["developmental_history_questionnaire",
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
    "scapi"]

forms2 = ["srs2_schoolage","conners_3","aq_ages_411","cbcl_ages_6","cbcl_ages_15_to_5","tmcq","swan",
    "aq_ages_1215",
    "aq_ages_16",
    "srs2_preschool",
    "srs2_relative_other","puberty_scale",]

subjects1 = ['SUB-10001-01', 'SUB-10002-01', 'SUB-10003-01', 'SUB-10004-01', 'SUB-10005-01', 'SUB-10006-01', 'SUB-10006-02', 'SUB-10007-01', 'SUB-10008-01', 'SUB-10009-01', 'SUB-10010-01', 'SUB-10011-01', 'SUB-10012-01', 'SUB-10013-01', 'SUB-10014-01', 'SUB-10015-01', 'SUB-10015-02', 'SUB-10016-01', 'SUB-10017-01', 'SUB-10018-01', 'SUB-10019-01', 'SUB-10019-02', 'SUB-10020-01', 'SUB-10021-01', 'SUB-10022-01', 'SUB-10023-01', 'SUB-10024-01', 'SUB-10025-01', 'SUB-10026-01', 'SUB-10027-01', 'SUB-10028-01', 'SUB-10029-01', 'SUB-10030-01', 'SUB-10031-01', 'SUB-10032-01', 'SUB-10033-01', 'SUB-10034-01', 'SUB-10035-01', 'SUB-10036-01', 'SUB-10037-01', 'SUB-10038-01', 'SUB-10039-01', 'SUB-10040-01', 'SUB-10041-01', 'SUB-10042-01', 'SUB-10043-01', 'SUB-10044-01', 'SUB-10045-01', 'SUB-10046-01', 'SUB-10047-01', 'SUB-10048-01', 'SUB-10049-01', 'SUB-10050-01', 'SUB-10051-01', 'SUB-10052-01', 'SUB-10053-01', 'SUB-10054-01', 'SUB-10054-02', 'SUB-10055-01', 'SUB-10056-01', 'SUB-10056-02', 'SUB-10057-01', 'SUB-10058-01', 'SUB-10059-01', 'SUB-10060-01', 'SUB-10061-01', 'SUB-10062-01', 'SUB-10063-01', 'SUB-10063-02', 'SUB-10064-01', 'SUB-10065-01', 'SUB-10066-01', 'SUB-10067-01', 'SUB-10068-01', 'SUB-10068-02', 'SUB-10069-01', 'SUB-10070-01', 'SUB-10071-01', 'SUB-10072-01', 'SUB-10073-01', 'SUB-10073-02', 'SUB-10074-01', 'SUB-10075-01', 'SUB-10076-01', 'SUB-10077-01', 'SUB-10078-01', 'SUB-10079-01', 'SUB-10080-01']
subjects2 = ['SUB-20001-01', 'SUB-20001-02', 'SUB-20002-01', 'SUB-20003-01', 'SUB-20004-01', 'SUB-20005-01', 'SUB-20006-01', 'SUB-20007-01', 'SUB-20008-01', 'SUB-20009-01', 'SUB-20010-01', 'SUB-20011-01', 'SUB-20012-01', 'SUB-20013-01', 'SUB-20014-01', 'SUB-20015-01', 'SUB-20016-01', 'SUB-20017-01', 'SUB-20018-01', 'SUB-20019-01', 'SUB-20020-01', 'SUB-20021-01', 'SUB-20022-01', 'SUB-20023-01', 'SUB-20024-01', 'SUB-20025-01', 'SUB-20026-01', 'SUB-20027-01', 'SUB-20028-01', 'SUB-20029-01', 'SUB-20030-01', 'SUB-20031-01', 'SUB-20032-01', 'SUB-20033-01', 'SUB-20034-01', 'SUB-20034-02', 'SUB-20035-01', 'SUB-20036-01', 'SUB-20037-01', 'SUB-20038-01', 'SUB-20039-01', 'SUB-20040-01', 'SUB-20041-01', 'SUB-20042-01', 'SUB-20043-01', 'SUB-20044-01', 'SUB-20045-01', 'SUB-20046-01', 'SUB-20047-01', 'SUB-20048-01', 'SUB-20048-02', 'SUB-20048-03', 'SUB-20049-01', 'SUB-20050-01', 'SUB-20051-01', 'SUB-20052-01', 'SUB-20053-01', 'SUB-20054-01', 'SUB-20054-02', 'SUB-20055-01', 'SUB-20056-01', 'SUB-20057-01', 'SUB-20058-01', 'SUB-20059-01', 'SUB-20060-01', 'SUB-20061-01', 'SUB-20062-01', 'SUB-20063-01', 'SUB-20064-01', 'SUB-20065-01', 'SUB-20066-01', 'SUB-20067-01', 'SUB-20068-01', 'SUB-20068-02']

loris = Loris()
# loris.get_form_metadata(forms=forms)
# loris.create_all_instrument_files()
loris.get_forms()
del loris