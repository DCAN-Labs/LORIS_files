import mysql.connector
from config import config
import datetime
import requests
import json
from jinja2 import Template

class Loris:

    def __init__(self):
        self.cnx = mysql.connector.connect(**config)
        self.cursor = self.cnx.cursor(dictionary=True)
        self.field_type_lookup = {
            'radio': 'enum',
            'text': 'text',
            'descriptive':'text',
            'dropdown':'enum',
            'notes':'text',
            'calc':'int',
            'yesno':'enum',
            'checkbox':'text'
            }

    def __del__(self):
        self.cnx.close()
        self.cursor.close()

    def commit(self):
        self.cnx.commit()

    def insert(self, table, columns, values):
        statement = (f"INSERT INTO {table} " f"({columns}) " f"VALUES ({values})")
        self.cursor.execute(statement)

    def query(self, table, fields, condition):
        query = (f"SELECT {fields} FROM {table} " f"WHERE {condition}")
        self.cursor.execute(query)
        self.result = [row for row in self.cursor]

    def add_project(self, **kwargs):
        name = kwargs.get('name')
        alias = kwargs.get('alias')
        target = kwargs.get('target', 0)

        self.insert('Project', 'Name, Alias, recruitmentTarget', f'{name}, {alias}, {target}')
        self.project_id = self.cursor.lastrowid

    def add_psc(self, **kwargs):
        name = kwargs.get('name')
        alias = kwargs.get('alias')

        self.insert('psc', 'Name, Alias, Study_site', f'{name}, {alias}, Y')
        self.center_id = self.cursor.lastrowid

    def add_subproject(self, **kwargs):
        name = kwargs.get('name')
        use_edc = kwargs.get('use_edc', 0)
        window_difference = kwargs.get('window_difference', 'optimal')
        target = kwargs.get('target')

        self.insert('subproject', 'title, useEDC, WindowDifference, RecruitmentTarget', f'{name}, {use_edc}, {window_difference}, {target}')
        self.subproject_id = self.cursor.lastrowid

    def add_visit(self, **kwargs):
        name = kwargs.get('name')
        label = kwargs.get('label', name)

        self.insert('visit', 'VisitName, VisitLabel', f'{name}, {label}')
        self.visit_id = self.cursor.lastrowid

    def link_subproj(self, **kwargs):
        proj = kwargs.get('project')
        sub = kwargs.get('subproject')
        values = ''
        if proj and sub:
            self.query('Project', 'ProjectID', f"Name = '{proj}'")
            proj_id = self.result[0]['ProjectID']
            self.query('subproject', 'SubprojectID', f"title = '{sub}'")
            sub_id = self.result[0]['SubprojectID']

            values = f'{proj_id}, {sub_id}'
        else:
            values = f'{self.project_id}, {self.subproject_id}'
        self.insert('project_subproject_rel', 'ProjectID, SubprojectID', values)

    def add_to_test_battery(self, **kwargs):
        test = kwargs.get('instrument')
        visit = kwargs.get('visit')
        subproject = kwargs.get('subproject')
        age_min_days = kwargs.get('age_min_days', 0)
        age_max_days = kwargs.get('age_max_days', 99999)
        active = kwargs.get('active', 'Y')
        stage = kwargs.get('stage', 'Visit')
        center_id = kwargs.get('center_id')
        first_visit = kwargs.get('first_visit')
        instrument_order = kwargs.get('instrument_order')

        columns = 'Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID, firstVisit, instr_order'
        values = f'{test}, {age_min_days}, {age_max_days}, {active}, {stage}, {subproject}, {visit}, {center_id}, {first_visit}, {instrument_order}'
        self.insert('test_battery', columns, values)

    def get_candidate_info(self, **kwargs):
        subjects = kwargs.get('subjects')

        columns = 'PSCID, CandID, RegistrationCenterID, RegistrationProjectID'
        in_statement = '\', \''.join(str(sub) for sub in subjects)
        condition = f"PSCID IN ('{in_statement}')"
        print(condition)
        self.query('candidate', columns, condition)
        self.candidates = self.result
        
    def add_session(self, **kwargs):
        subjects = kwargs.get('subjects') # should be a list
        subproject_id = kwargs.get('subproject_id')
        visit = kwargs.get('visit')
        today = datetime.date.today().strftime("%Y-%m-%d")
        scan_done = kwargs.get('scan_done', 'N')
        self.get_candidate_info(subjects=subjects)
        for cand in self.candidates:
            cand_id = cand['CandID']
            center_id = cand['RegistrationCenterID']
            project_id = cand['RegistrationProjectID']

            columns = 'CandID, CenterID, ProjectID, Visit_label, SubprojectID, Current_stage, Date_stage_change, Visit, Date_visit, Date_active, RegisteredBy, UserID, Date_registered, Testdate, Scan_done, languageID'
            values = f"{cand_id}, {center_id}, {project_id}, '{visit}', {subproject_id}, 'Visit', '{today}', 'In Progress', '{today}', '{today}', 'redcapTransfer', 'redcapTransfer', '{today}', '{today}', '{scan_done}', 1"
            print(values)
            self.insert('session', columns, values)


    def start_visit(self):
        print("Please run assign_missing_instruments.php to start visits")

    def populate_instrument(self, **kwargs):
        form = kwargs.get('form')
        # subjects = kwargs.get('subjects')
        data = {
            'token': '43E50FE84102CCBB71217A60BE4F9E6D',
            'content': 'record',
            'action': 'export',
            'format': 'json',
            'type': 'flat',
            'csvDelimiter': '',
            'fields[0]': 'record_id',
            'forms[0]': f'{form}',
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
        records = [record for record in records if int(record[f'{form}_complete'] or 0)]
        with open('outputs/response.json', 'w+') as file:
            json.dump(records, file)

        #map form to instrument and insert
        columns = ''
        values = ''
        #self.insert(instrument, columns, values)
    
    def get_form_metadata(self, **kwargs):
        forms = kwargs.get('forms')
        data = {
            'token': '43E50FE84102CCBB71217A60BE4F9E6D',
            'content': 'metadata',
            'format': 'json',
            'returnFormat': 'json',
        }
        data.update({f'forms[{index}]': form for index, form in enumerate(forms)})
        r = requests.post('https://redcap.ahc.umn.edu/api/',data=data)
        print('HTTP Status: ' + str(r.status_code))
        records = r.json()
        self.metadata = { record['form_name']: { field['field_name']: { 'field_type': field['field_type'], 'field_label': field['field_label'], 'select_choices_or_calculations': field['select_choices_or_calculations']} for field in records if field['form_name'] == record['form_name']} for record in records if record['form_name'] in forms}
        with open('outputs/form.json', 'w+') as file:
            json.dump(self.metadata, file)

    def get_all_subject_ids(self):
        pass


    def make_enum_array(self, options, field_type):

        if self.field_type_lookup[field_type] == 'enum':
            options_loris = []
            options_sql = []
            if field_type == 'yesno':
                options_loris = ['No', 'Yes']
                options_sql = [ '0', '1' ]
            else:
                options_sql = [option.split(',')[0] for option in options.split('|')]
                options_loris = [option.split(',')[1] for option in options.split('|')]

            opt_str = "''=>''"
            for optionNum, _ in enumerate(options_sql):
                opt_sql = options_sql[optionNum].strip().strip("'").strip('"')
                opt_loris = options_loris[optionNum].strip().strip("'").strip('"')
                opt_str += ", '" + opt_sql + "'=>" + '"' + opt_loris + '"'
            opt_str += ", " + "'not_answered'=>'Not Answered'"
            return opt_str
        else:
            return ''

    def create_instrument_php(self, **kwargs):
        form = kwargs.get('form')
        field_type = {'text': ['varchar', 'int', 'char', 'tinyint', 'smallint', 'mediumint', 'bigint', 'decimal', 'dec',
                       'float', 'double', 'tinytext'],
              'textarea': ['text', 'mediumtext', 'longtext'],
              'select': 'enum', 'date': 'date'}

        values = self.metadata[form]
        instrument_params = {
            "instrument_table_name": form,
            "validity_required": False,
            "validity_enabled": False,
            "include_meta_fields": True,
            "date_fields":[],
            "loris_num_pages": 1,
            "instrument_name_text": form
        }
        var_data_object = [
            {
                "page": 1,
                "var_type": self.field_type_lookup[values[value]['field_type']],
                "status":'',
                "front_end": True,
                "name": value,
                "text": values[value]['field_label'],
                "enum_array": self.make_enum_array(values[value]['select_choices_or_calculations'], values[value]['field_type'])
            }
            for i, value in enumerate(values)]

        jinja_dict = {'param': instrument_params, 'var_data': var_data_object, 'field_type': field_type}
        # print(json.dumps(jinja_dict, indent=4))

        with open('LORIS_php_instrument_template.html.jinja2') as filein:  # noqa
            loris_template = Template(filein.read(), trim_blocks=True, lstrip_blocks=True)
        
        with open('outputs/php/NDB_BVL_Instrument_' + instrument_params['instrument_table_name'] + '.class.inc', 'w') as fileout:
            fileout.write(loris_template.render(jinja_dict))

    def create_table_lines(self, question, values):
        # `q108` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
        field_type = values['field_type']
        sql_type = self.field_type_lookup[field_type]
        if sql_type == 'enum':
            enums = 'enum('
            if field_type == 'yesno':
                enums += "'0', '1', 'not_answered')"
            else:
                choices = values['select_choices_or_calculations']
                choices = [choice.split(',')[0] for choice in choices.split('|')]
                for choice in choices:
                    choice_string = choice.strip().strip("'").strip('"')
                    enums += f"'{choice_string}', "
                enums += "'not_answered')"
            sql_type = enums
        sql_line = f"  `{question}` {sql_type} DEFAULT NULL,\n"
        return sql_line

    def create_instrument_sql(self, **kwargs):
        form = kwargs.get('form')
        file_output = kwargs.get('file_output')
        create_table = kwargs.get('create_table')
        
        if(file_output):
            table_line_start = f"CREATE TABLE `{form}` (\n"
            meta_fields = "  `CommentID` varchar(255) NOT NULL DEFAULT '',\n  `UserID` varchar(255) DEFAULT NULL,\n  `Examiner` varchar(255) DEFAULT NULL,  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',`Date_taken` date DEFAULT NULL,  `Candidate_Age` varchar(255) DEFAULT NULL,  `Window_Difference` int(11) DEFAULT NULL,"
            table_line_end = """  PRIMARY KEY (`CommentID`)\n) ENGINE=InnoDB DEFAULT CHARSET=utf8;\n"""
            test_name_insert = f"INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('{form}','{form}',1);"
            
            sqlfile = open(f'outputs/sql/{form}.sql', 'w')

            sqlfile.write(table_line_start)
            sqlfile.write(meta_fields)
            for question in self.metadata[form]:
                sql_line = self.create_table_lines(question, self.metadata[form][question])
                if sql_line:
                    sqlfile.write(sql_line)
            sqlfile.write(table_line_end)
            sqlfile.write(test_name_insert)

            sqlfile.close()
        if(create_table):
            pass

    def create_all_instrument_files(self):
        for inst in self.metadata:
            self.create_instrument_php(form=inst)
            self.create_instrument_sql(form=inst, file_output=True)

    def parse_metadata(self):
        # utility function to see what data types are in use
        field_types = []
        for inst in self.metadata:
            for question in self.metadata[inst]:
                if self.metadata[inst][question]['field_type'] not in field_types:
                    field_types.append(self.metadata[inst][question]['field_type'])
        print(field_types)
