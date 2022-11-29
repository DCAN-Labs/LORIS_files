from redcap_to_loris_class import RedcapToLoris

loris = RedcapToLoris()

# tests = ['srs2_schoolage', 'srs2_preschool', 'srs2_relative_other', 'aq_ages_1215', 'aq_ages_16', 'aq_ages_411', 'cbcl_ages_15_to_5', 'cbcl_ages_6', 'conners_3']
# for i in range(7):
#     for j in range(2):
#         for test in tests:
#             line = { "Test_name": test, 'AgeMinDays': 0, 'AgeMaxDays': 99999, "Active": 'Y', "Stage": 'Visit', "SubprojectID": j + 1, "Visit_label": f"Sibling{i + 1}"}
#             loris.insert('test_battery', line)
# loris.commit()

loris.get_records()

visits = [
    {"label": 'Sibling1', "scan": False},
    {"label": 'Sibling2', "scan": False},
    {"label": 'Sibling3', "scan": False},
    {"label": 'Sibling4', "scan": False},
    {"label": 'Sibling5', "scan": False},
    {"label": 'Sibling6', "scan": False},
    {"label": 'Sibling7', "scan": False}
]

override_visits = [
    { "label": 'Sibling1', "date_field": 'sib_date', "identifier": 'sib_1_dob'},
    { "label": 'Sibling2', "date_field": 'sib_date', "identifier": 'sib_1_dob_2'},
    { "label": 'Sibling3', "date_field": 'sib_date', "identifier": 'sib_1_dob_3'},
    { "label": 'Sibling4', "date_field": 'sib_date', "identifier": 'sib_1_dob_4'},
    { "label": 'Sibling5', "date_field": 'sib_date', "identifier": 'sib_1_dob_5'},
    { "label": 'Sibling6', "date_field": 'sib_date', "identifier": 'sib_1_dob_6'},
    { "label": 'Sibling7', "date_field": 'sib_date', "identifier": 'sib_1_dob_7'},
]

def get_subproject_function(subject):
    if "SUB-1" in subject:
        return 1
    elif "SUB-2" in subject:
        return 2
    else:
        print("Invalid Subject ID for get_subproject_function")
        return -1

loris.populate_session_table_override(visits=visits, override_visits=override_visits, get_subproject_function=get_subproject_function)

loris.commit()

del loris