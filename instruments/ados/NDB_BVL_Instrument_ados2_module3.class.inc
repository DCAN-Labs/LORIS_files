<?php


class NDB_BVL_Instrument_ados2_module3 extends NDB_BVL_Instrument_IBIS
{
    use \LorisFormDictionaryImpl;
    use LegacyInstrumentTrait;
/*
    INSERT INTO test_names (Test_name, Full_name, LimitAge, Sub_group) VALUES ('ados2_module3', 'ADOS2 Module 3', '0', '1');

    INSERT INTO instrument_subtests VALUES('', 'ados2_module3', 'ados2_module3_page1', 'Sections A-B', 1);
    INSERT INTO instrument_subtests VALUES('', 'ados2_module3', 'ados2_module3_page2', 'Sections C-E', 2);

    INSERT INTO test_battery VALUES ('', "ados_module3", "1053", "1179","Y","Visit","1", NULL);
    INSERT INTO test_battery VALUES ('', "ados_module3", "1053", "1179","Y","Visit","2", NULL);
    INSERT INTO test_battery VALUES ('', "ados_module3", "1053", "1179","Y","Visit","3", NULL);

*/
    var $option01237 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, 7=>7, "not_answered"=>"Not Answered");
    var $option0127 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 7=>7, "not_answered"=>"Not Answered");
    var $option01278 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 7=>7, 8=>8, "not_answered"=>"Not Answered");
    var $option0123 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, "not_answered"=>"Not Answered");
    var $option01238 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, 8=>8, "not_answered"=>"Not Answered");
    var $option02 = array(""=>NULL, 0=>0, 2=>2, "not_answered"=>"Not Answered");
    var $option012 = array(""=>NULL, 0=>0, 1=>1, 2=>2, "not_answered"=>"Not Answered");
    var $option0128 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 8=>8, "not_answered"=>"Not Answered");

    var $scoreCols = array("social_affect_total", "restricted_repetitive_behavior_total", "social_affect_restricted_repetitive_behavior_total", "ADOS_classification");
    /**
    * sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "ados2_module3";           // test_names.Test_name
        $this->table = 'ados2_module3';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");

       //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner', "a1", "c1");

		
		/**
		 * Array of column names to be ignored by the double data entry conflict detector.
		 */
        $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 
                'Candidate_Age',
                // Text entry columns
                'd1_specify',
                'd2_specify',
                'd4_specify',
		        'other_comments',
                // Scored columns
                "ADOS_classification",
                "social_affect_total",
                "restricted_repetitive_behavior_total",
                "social_affect_restricted_repetitive_behavior_total",
                'a2_weighted',
                'a3_weighted',
                'a8_weighted',
                'b1_weighted',
                'b3_weighted',
                'b4_weighted',
                'b5_weighted',
                'b9_weighted',
                'b10_weighted',
                'b11_weighted',
                'b12_weighted',
                'd1_weighted',
                'd2_weighted',
                'd4_weighted',
                'severity_score_lookup',
                'Data_entry_completion_status');

        // setup the form
        $this->_setupForm();
    }


    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.
    /**
    * method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm(){

       if(preg_match("/ados2_module3(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

    }

    /**
    * generates the main page of the form.
    *
    * @return void
    * @access private
    *
    */


    function _main(){
        // display test name
        $this->form->addElement('header', 'instrument_title', "ADOS2 Module 3");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();


    	$this->form->addElement("header",null,"SUMMARY SCORES:");
    
    	$this->form->addElement('static', "social_affect_total", "Social Affect Total:");
    
    	$this->form->addElement('static', "restricted_repetitive_behavior_total", "Restricted and Repetitive Behavior Total:");
    
    	$this->form->addElement('static', "social_affect_restricted_repetitive_behavior_total", "Social Affect and Restricted and Repetitive Behavior Total:");
    
    	$this->form->addElement('static', "ADOS_classification", "ADOS Classification:");
        $this->form->addElement('static', "ADOS_SA_CSS","ADOS_SA_CSS:");
        $this->form->addElement('static', "ADOS_RRB_CSS","ADOS_RRB_CSS:");
        $this->form->addElement('header', null, 'Severity Scores:');
        $this->form->addElement('static', 'severity_score_lookup', 'Severity Score:');
        $this->form->addElement("textarea", "other_comments", "Comments about Validity:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));


    }
    
/*	
	//They decided not to use this section - it was only partially implemented.
	//Section A: Observation
	//Question #1 - Free Play
        $this->form->addElement('header', null, "OBSERVATION:");
        

        $group[] =&$this->form->createElement('textarea', 'obs_q_1', null, "Communication Sample");
        $group[] =&$this->form->createElement('advcheckbox', 'obs_q_1_check', null, "Not Answered");
        $this->form->addGroup($group, 'obs_q_1_group', '1. Free Play', false);
        unset($group);

        

        $group[] =&$this->form->createElement('textarea', 'obs_q_1_notes', null, "Notes");
        $group[] =&$this->form->createElement('advcheckbox', 'obs_q_1_notes_check', null, "Not Answered");
        $this->form->addGroup($group, 'obs_q_1_notes_group', null, false);
        unset($group);

	//Rules for Question #1:
        $reqIfSettings = array('controller'=>"obs_q_1_check", 'operator'=>'!=', 'value'=>'1');
        $this->form->addRule("obs_q_1_group", 'Communication Sample is Required', 'requiredIfGroup', array_merge($reqIfSettings, array('element'=>"obs_q_1")));

        $reqIfSettings = array('controller'=>"obs_q_1_notes_check", 'operator'=>'!=', 'value'=>'1');
        $this->form->addRule("obs_q_1_notes_group", 'Notes are Required', 'requiredIfGroup', array_merge($reqIfSettings, array('element'=>"obs_q_1_notes")));



	//Question #2 - Response to Name
        

        $group[] =&$this->form->createElement('textarea', 'obs_q_2_notes', null, "Notes");
        $group[] =&$this->form->createElement('advcheckbox', 'obs_q_2_notes_check', null, "Not Answered");
        $this->form->addGroup($group, 'obs_q_2_notes_group', '2. Response to Name', false);
        unset($group);

	//Rules for Question #2:
        $reqIfSettings = array('controller'=>"obs_q_2_notes_check", 'operator'=>'!=', 'value'=>'1');
        $this->form->addRule("obs_q_2_notes_group", 'Notes are Required', 'requiredIfGroup', array_merge($reqIfSettings, array('element'=>"obs_q_2_notes")));



	//Question #3 - Response to Joint Attention
        

        $group[] =&$this->form->createElement('textarea', 'obs_q_3_notes', null, "Notes");
        $group[] =&$this->form->createElement('advcheckbox', 'obs_q_3_notes_check', null, "Not Answered");
        $this->form->addGroup($group, 'obs_q_3_notes_group', '3. Response to Joint Attention', false);
        unset($group);

	//Rules for Question #3:
        $reqIfSettings = array('controller'=>"obs_q_3_notes_check", 'operator'=>'!=', 'value'=>'1');
        $this->form->addRule("obs_q_3_notes_group", 'Notes are Required', 'requiredIfGroup', array_merge($reqIfSettings, array('element'=>"obs_q_3_notes")));



	//Question #4 - Bubble Play
        

        $group[] =&$this->form->createElement('textarea', 'obs_q_4_notes', null, "Notes");
        $group[] =&$this->form->createElement('advcheckbox', 'obs_q_4_notes_check', null, "Not Answered");
        $this->form->addGroup($group, 'obs_q_3_notes_group', '4. Bubble Play', false);
        unset($group);

	//Rules for Question #4:
        $reqIfSettings = array('controller'=>"obs_q_4_notes_check", 'operator'=>'!=', 'value'=>'1');
        $this->form->addRule("obs_q_4_notes_group", 'Notes are Required', 'requiredIfGroup', array_merge($reqIfSettings, array('element'=>"obs_q_4_notes")));



	//Question #5 - Anticipation of a Routine with Objects
        

        $group[] =&$this->form->createElement('textarea', 'obs_q_5_notes', null, "Notes");
        $group[] =&$this->form->createElement('advcheckbox', 'obs_q_5_notes_check', null, "Not Answered");
        $this->form->addGroup($group, 'obs_q_3_notes_group', '5. Anticipation of a Routine with Objects', false);
        unset($group);

	//Rules for Question #4:
        $reqIfSettings = array('controller'=>"obs_q_5_notes_check", 'operator'=>'!=', 'value'=>'1');
        $this->form->addRule("obs_q_5_notes_group", 'Notes are Required', 'requiredIfGroup', array_merge($reqIfSettings, array('element'=>"obs_q_5_notes")));

*/


    function _page1(){
    	//CODING
    	//Section A: Language and Communication
        $this->form->addElement('header', null, "ADOS Module 3");
        

        $this->form->addElement('header', null, "Section A: Language and Communication");
        
        
        $this->form->addElement('select', 'a1', '1. Overall Level of Non-Echoed Language', $this->option0123);
        
        $this->form->addElement('select', 'a2', '2. Speech Abnormalities Associated with Autism (Intonation/Volume/Rhythm/Rate)', $this->option0127);
        
        $this->form->addElement('select', 'a3', '3. Immediate Echolalia',  $this->option0123);
        
        $this->form->addElement('select', 'a4', '4. Stereotyped/Idiosyncratic Use of Words or Phrases', $this->option0123);
        
        $this->form->addElement('select', 'a5', '5. Offers Information', $this->option012);
        
        $this->form->addElement('select', 'a6', '6. Asks for Information', $this->option0123);
        
        $this->form->addElement('select', 'a7', '7. Reporting of Events', $this->option0123);
        
        $this->form->addElement('select', 'a8', '8. Conversation', $this->option0123);
        
        $this->form->addElement('select', 'a9', '9. Descriptive, Conventional, Instrumental, or Informational Gestures', $this->option01238);

        
        


	   //Section B: Reciprocal Social Interaction
        $this->form->addElement('header', null, "Section B: Reciprocal Social Interaction");
        
        

        $this->form->addElement('select', 'b1', '1. Unusual Eye Contact', $this->option02);
        
        $this->form->addElement('select', 'b2', '2. Facial Expressions Directed to the Examiner', $this->option012);
        
        $this->form->addElement('select', 'b3', '3. Language Production and Linked Nonverbal Communication', $this->option01278);
        
        $this->form->addElement('select', 'b4', '4. Shared Enjoyment in Interaction', $this->option0123);
        
        $this->form->addElement('select', 'b5', "5. Empathy/Comments on Others' Emotions", $this->option012);
        
        $this->form->addElement('select', 'b6', '6. Insight', $this->option0123);
        
        $this->form->addElement('select', 'b7', '7. Quality of Social Overtures', $this->option0123);
        
        $this->form->addElement('select', 'b8', '8. Amount of Social Overtures/Maintenance of Attention', $this->option01237);
        
        $this->form->addElement('select', 'b9', '9. Quality of Social Response', $this->option0123);
        
        $this->form->addElement('select', 'b10', '10. Amount of Reciprocal Social Communication', $this->option0123);
        
        $this->form->addElement('select', 'b11', '11. Overall Quality of Rapport', $this->option0123);
        
 
        
        
    }

    function _page2(){
    	//Section C: Play
        $this->form->addElement('header', null, "Section C: Imagination");
        
        
        $this->form->addElement('select', 'c1', '1. Imagination/Creativity', $this->option0123);
        

        
        

    	//Section D: Stereotyped Behaviors and Restricted Interests
        $this->form->addElement('header', null, "Section D: Stereotyped Behaviors and Restricted Interests");
        
        
        $this->form->addElement('select', 'd1', '1. Unusual Sensory Interest in Play Material/Person', $this->option0123);
        
     	$this->addTextAreaElement('d1_specify', $this->indent . "Please specify:");
        
        $this->form->addElement('select', 'd2', '2. Hand and Finger and Other Complex Mannerisms', $this->option0123);
        
    	$this->addTextAreaElement('d2_specify', $this->indent . "Please specify:");
        
        $this->form->addElement('select', 'd3', '3. Self-Injurious Behavior', $this->option012);
        
        $this->form->addElement('select', 'd4', '4. Excessive Interest in or References to Unusual or Highly Specific Topics or Objects or Repetitive Behaviors', $this->option0123);
        
    	$this->form->addElement('select', 'd5', "5. Compulsions or Rituals", $this->option012);
        
    	$this->addTextAreaElement('d5_specify', $this->indent . "Please specify:");

        
        

    	//Section E: Other Abnormal Behaviors
        $this->form->addElement('header', null, "Section E: Other Abnormal Behaviors");
        
        
        $this->form->addElement('select', 'e1', '1. Overactivity/Agitation', $this->option01237);
        
        $this->form->addElement('select', 'e2', '2. Tantrums, Aggression, Negative or Disruptive Behavior', $this->option0123);
        
        $this->form->addElement('select', 'e3', '3. Anxiety', $this->option012);

        
        

    } // End Form

    function score(): void{
    	if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
    		return;
    	}
	
        // null scores
        $this->_nullScores($this->scoreCols);

        //get the saved scores
    	$db =& Database::singleton();
  	
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));

        // Get the subject age in months for scoring
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();
        
		$age = Utility::calculateAge($dob, $record["Date_taken"]);
       		$age_years = $age['year'] + ($age['mon']/12);

        // For severity score from ados_lookup table
        $age_months = 0;
        if($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $dob = $timepoint->getEffectiveDateOfBirth();
        }

        $Answers = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));
        if(!empty($dob) && !empty($Answers['Date_taken'])) {
            $age = Utility::calculateAge($dob, $Answers["Date_taken"]);
            if(is_array($age)) {
                $age_months = $age['year'] * 12 + $age['mon'];
            }
        }


	
        //Convert the entered scores to countable scores:
        //"Convert scores of 3 on the protocol to 2, and treat all other scores other than 0-3 as 0."
        $scores = array(); //holds converted scores
        foreach($record as $field=>$value) {
            if($value == 0) {
                $scores[$field] = 0;
            } elseif ($value == 1) {
                $scores[$field] = 1;
            } elseif ($value == 2) {
                $scores[$field] = 2;
            } elseif ($value == 3) {
                $scores[$field] = 2;
            } elseif ($value >= 4) {
                $scores[$field] = 0;
            } elseif ($value == "not_answered") {
                $scores[$field] = 0;
            }
        }
        
        $scoreCols["social_affect_total"] = $scores["a7"] + $scores["a8"] + $scores["a9"] + $scores["b1"] + $scores["b2"] + $scores["b4"] + $scores["b7"]  + $scores["b9"]+ $scores["b10"]+ $scores["b11"]; 
    	$scoreCols["restricted_repetitive_behavior_total"] = $scores["a4"] + $scores["d1"] + $scores["d2"] + $scores["d4"];
    	$scoreCols["social_affect_restricted_repetitive_behavior_total"] = $scoreCols["social_affect_total"] + $scoreCols["restricted_repetitive_behavior_total"];
    
    	if($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 7 && $scoreCols["social_affect_restricted_repetitive_behavior_total"] < 9){
    		$scoreCols["ADOS_classification"] = "autism spectrum";
    	} elseif ($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 9) {
    		$scoreCols["ADOS_classification"] = "autism";
    	} else {
        	$scoreCols["ADOS_classification"] = "none";
    	}

        // Severity score
        if ($age_months != 0) {
            $query_severity_lookup = "SELECT sevscore FROM ados_lookup WHERE module = :modname AND minagemos <= :agemonths AND maxagemos >= :agemonths AND minraw <= :rawscore AND maxraw >= :rawscore";
            $record_lookup = array();
            $sevscore = $db->pselectOne($query_severity_lookup, array(
                    'modname' => 3,
                    'agemonths' => $age_months,
                    'rawscore' => $scoreCols['social_affect_restricted_repetitive_behavior_total']
            ));
            if(empty($sevscore)) {
                $scoreCols['severity_score_lookup']= "N/A";
            } else {
                $scoreCols['severity_score_lookup']=$sevscore;
            }

        }
        // Weightings from Risi, Pickles and Lord 2008 Table 2
        // Put in the same order as the paper, which happens to be different than
        // how Loris orders it, which is why this looks a little weird
        // Social Affect
        $scoreCols['b1_weighted'] = $scores['b1'] * 0.56; // Unusual Eye Contact
        $scoreCols['b9_weighted'] = $scores['b9'] * 0.78; // Amount of social communication
        $scoreCols['b2_weighted'] = $scores['b2'] * 0.64; // Facial Expressions
        $scoreCols['b10_weighted'] = $scores['b10'] * 0.77; // Quality of rapport
        $scoreCols['b4_weighted'] = $scores['b4'] * 0.84; // Shared Enjoyment
        $scoreCols['b7_weighted'] = $scores['b7'] * 0.72; // Quality of Social Overtures
        $scoreCols['a8_weighted'] = $scores['a8'] * 0.63; // Conversation
        $scoreCols['a9_weighted'] = $scores['a9'] * 0.66; // Gestures
        $scoreCols['b8_weighted'] = $scores['b8'] * 0.72; // Quality of social response
        $scoreCols['a7_weighted'] = $scores['a7'] * 0.37; // Reporting of events

        // Restricted Repetitive Behaviours 
        $scoreCols['a4_weighted'] = $scores['a4'] * 0.66; // Stereotyped language 
        $scoreCols['d1_weighted'] = $scores['d1'] * 0.43; // Unusual Sensory Interest 
        $scoreCols['d4_weighted'] = $scores['d4'] * 0.54; // Highly specific topics
        $scoreCols['d2_weighted'] = $scores['d2'] * 0.57; // Hand Mannerisms

        // CSS Calculations
        // TODO: Check to make sure this is correct for MODULE 1,2,3. Copied from ADOS Tod Mod
        // If the candidate is 23 months old, round to 24 months
        if ($age_months >= 23 && $age_months < 24) {
            $age_months = 24;
        }

        $ados_age = -1;

        
        for ($i = 2; $i <= 14; $i++) {
            $low  = $i * 12;
            $high = ($i + 1) * 12;
            if ($age_months >= $low && $age_months < $high) {
                $ados_age = $i;
            }
        }
        
        // console.log("Calculated ados_age for scoring: $ados_age");
        
        $scoreCols["ADOS_SA_CSS"]  = $this->ADOS_SA_CSS( $this->table, $record['a1'], $scoreCols['social_affect_total'], $ados_age);
        $scoreCols["ADOS_RRB_CSS"] = $this->ADOS_RRB_CSS($this->table, $record['a1'], $scoreCols['restricted_repetitive_behavior_total'], $ados_age);

        // save scores to database
    	$result = $db->update($this->table, $scoreCols, array("CommentID"=>$this->getCommentID()));
    }    // end score function
}
?>