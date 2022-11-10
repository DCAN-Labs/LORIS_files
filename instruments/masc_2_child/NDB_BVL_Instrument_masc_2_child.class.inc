<?php

class NDB_BVL_Instrument_masc_2_child extends NDB_BVL_Instrument
{
    use \LorisFormDictionaryImpl;
    use LegacyInstrumentTrait;
    var $ValidityEnabled = False;
    var $ValidityRequired = False;

    /**
     * sets up basic data, such as the HTML_Quickform object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, $page = null): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');

        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'masc_2_child' ;           // test_names.Test_name
        $this->table = 'masc_2_child';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array(

        );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // Get the subject age in months for scoring

        $db =& Database::singleton();
        // required fields for data entry completion status
        $this->_requiredElements = array(
            
        );

        //MODIFY THIS WHEN THE SCORING IS IMPLEMENTED
        // $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age', 'Data_entry_completion_status'
        // );

        // setup the form
        $this->_setupForm();

    }

    /**
     * method to build the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {

        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = :CommentID";
	    $WhereCriteria = array('CommentID'=>$this->commentID);
        $record = $db->pselectRow($query, $WhereCriteria);

        // display test name
        $this->addHeader("<h1>Masc 2 Self-Report</h1>");

        $this->addHeader("Calculated Fields");
        $this->addHeader("<h3>Summary</h3>");
        $this->form->addElement('static','masc_total',"MASC 2 Total Score");
        $this->form->addElement('static','masc_total_t',"MASC 2 Total Score T-Score");
        $this->form->addElement('select', 'masc_anx_prob_score', "Anxiety Probability Score<h5>The Anxiety Probability Score is determined by the number of elevated T-scores (60 or higher) on the Anxiety Scales.</h5>", array(''=>'', '0'=>"0 - Low Probability", '1'=>"1 - Borderline Probability", '2'=>"2- High Probability", '3'=>"3 - Very High Probability"), array('disabled'=>'disabled') );

        $this->form->addElement('static','masc_inconsistency_index',"Inconsistency Index");
        if ($record['masc_inconsistency_index'] > 8) {
            $this->form->addElement('static','',"<h5 style='color:red'>The Inconsistency Index is greater than 8. There may be some inconsistency, and the results should be interpreted with caution.</h5>");
        } elseif ($record['masc_inconsistency_index'] != null) {
            $this->form->addElement('static','',"<h5>The Inconsistency Index is 8 or less. It is unlikely the results are inconsistent.</h5>");
        }
        
        $this->addHeader("<h3>Seperation Anxiety/Phobias</h3>");
        $this->form->addElement('static','masc_sp',"Seperation Anxiety/Phobias");
        $this->form->addElement('static','masc_sp_t',"Seperation Anxiety/Phobias T-Score");
        $this->addHeader("<h3>GAD Index</h3>");
        $this->form->addElement('static','masc_gad',"GAD Index");
        $this->form->addElement('static','masc_gad_t',"GAD Index T-Score");
        $this->addHeader("<h3>Social Anxiety</h3>");
        $this->form->addElement('static','masc_sa',"Social Anxiety Total");
        $this->form->addElement('static','masc_sa_t',"Social Anxiety Total T-Score");
        $this->form->addElement('static','masc_hr',"Humiliation/Rejection");
        $this->form->addElement('static','masc_hr_t',"Humiliation/Rejection T-Score");
        $this->form->addElement('static','masc_pf',"Performance Fears");
        $this->form->addElement('static','masc_pf_t',"Performance Fears T-Score");
        $this->addHeader("<h3>Obsessions & Compulsions</h3>");
        $this->form->addElement('static','masc_oc',"Obsessions & Compulsions");
        $this->form->addElement('static','masc_oc_t',"Obsessions & Compulsions T-Score");
        $this->addHeader("<h3>Physical Symptoms</h3>");
        $this->form->addElement('static','masc_ps',"Physical Symptoms Total");
        $this->form->addElement('static','masc_ps_t',"Physical Symptoms Total T-Score");
        $this->form->addElement('static','masc_p',"Panic");
        $this->form->addElement('static','masc_p_t',"Panic T-Score");
        $this->form->addElement('static','masc_tr',"Tense/Restless");
        $this->form->addElement('static','masc_tr_t',"Tense/Restless T-Score");
        $this->addHeader("<h3>Harm Avoidance</h3>");
        $this->form->addElement('static','masc_ha',"Harm Avoidance");
        $this->form->addElement('static','masc_ha_t',"Harm Avoidance T-Score");


        $this->addHeader("Questions");
        $this->form->addElement('static','',"<div class='rich-text-field-label'><p>INSTRUCTIONS: <span style='font-weight: normal;'>These sentences ask how you might have been thinking, feeling, or acting in the last while. For each item, please select the option that describes</span> how often the sentence is true about you.</p> <p><span style='font-weight: normal;'>Choose Never (0) if a sentence is Never true about you.<br />Choose Rarely (1) if a sentence is Rarely true about you.<br />Choose Sometimes (2) if a sentence is Sometimes true about you.<br />Choose Often (3) if a sentence is Often true about you.</span></p> <p><span style='font-weight: normal;'>Remember, there are no right or wrong answers, just answer how you might have been feeling in the last while.</span></p></div>");
        $this->form->addElement('select', 'masc_1', "1. I feel tense or uptight.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_2', "2. I usually ask permission to do things.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_3', "3. I worry about other people laughing at me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_4', "4. I get scared when my parents go away.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_5', "5. I keep my eyes open for danger.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_6', "6. I have trouble getting my breath.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_7', "7. The idea of going away to camp scares me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_8', "8. I get shaky or jittery.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_9', "9. I try to stay near my mom or dad.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_10', "10. I'm afraid that other kids will make fun of me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_11', "11. I try hard to obey my parents and teachers.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_12', "12. I get dizzy or faint feelings.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_13', "13. I check things out first.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_14', "14. I worry about getting called on in class.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_15', "15. I'm jumpy.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_16', "16. I'm afraid other people will think I'm stupid.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_17', "17. I keep the light on at night.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_18', "18. I have pains in my chest.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_19', "19. I avoid going to places without my family.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_20', "20. I feel strange, weird, or unreal.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_21', "21. I try to do things other people will like.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_22', "22. I worry about what other people think of me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_23', "23. I avoid watching scary movies and TV shows.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_24', "24. My heart races or skips beats.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_25', "25. I stay away from things that upset me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_26', "26. I sleep next to someone from my family.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_27', "27. I feel restless and on edge.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_28', "28. I try to do everything exactly right.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_29', "29. I worry about doing something stupid or embarrassing.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_30', "30. I get scared riding in the car or on the bus.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_31', "31. I feel sick to my stomach.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_32', "32. I get nervous if I have to perform in public.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_33', "33. Bad weather, the dark, heights, animals, or bugs scare me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_34', "34. My hands shake.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_35', "35. I check to make sure things are safe.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_36', "36. I have trouble asking other kids to play with me.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_37', "37. My hands feel sweaty or cold.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_38', "38. I feel shy.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_39', "39. I have trouble making up my mind about simple things.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_40', "40. I get upset over the thought that I might get sick.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_41', "41. I have bad or silly thoughts that I can't stop.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_42', "42. I have to do things over and over again for no reason.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_43', "43. I get really upset about dirt, germs, chemicals, radiation, or sticky things.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_44', "44. I feel that I have to wash or clean more than I really need to.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_45', "45. I fear I'll be responsible for something bad happening.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_46', "46. I have to check that nothing terrible has happened.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_47', "47. I have to check things several times or more.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_48', "48. I count things for no reason.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_49', "49. I get too concerned with sin or wrongdoing.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc_50', "50. I have to repeat things until it feels just right.", array(''=>'', '0'=>"Never", '1'=>"Rarely", '2'=>"Sometimes", '3'=>"Often", 'not_answered'=>'Not Answered'));
    }


    var $scoreLabels = array("masc_total", "masc_total_t", "masc_anx_prob_score", "masc_inconsistency_index",
    "masc_sp", "masc_sp_t", "masc_gad", "masc_gad_t", "masc_sa", "masc_sa_t", "masc_hr", "masc_hr_t",
    "masc_pf", "masc_pf_t", "masc_oc", "masc_oc_t", "masc_ps", "masc_ps_t", "masc_p", "masc_p_t",
    "masc_tr", "masc_tr_t", "masc_ha", "masc_ha_t");

    function score(): void
    {
        if ($this->_determineRequiredElementsCompletedFlag() == "Incomplete") {
            return;
        }
        
        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db =& Database::singleton();

        $query = "SELECT * FROM $this->table WHERE CommentID = :CommentID";
	    $WhereCriteria = array('CommentID'=>$this->commentID);
        $record = $db->pselectRow($query, $WhereCriteria);

        //questions for subscores
        $sp = array('masc_4', 'masc_7', 'masc_9', 'masc_17', 'masc_19', 'masc_23','masc_26', 'masc_30', 'masc_33');
        $gad = array('masc_27', 'masc_29', 'masc_31', 'masc_1', 'masc_6', 'masc_39', 'masc_40', 'masc_13', 'masc_17', 'masc_22');
        $hr = array('masc_29', 'masc_3', 'masc_10', 'masc_16', 'masc_22');
        $pf = array('masc_32', 'masc_36', 'masc_38', 'masc_14');
        $oc = array('masc_41', 'masc_42', 'masc_43', 'masc_44', 'masc_45', 'masc_46', 'masc_47', 'masc_48', 'masc_49', 'masc_50');
        $p = array('masc_31', 'masc_37', 'masc_6', 'masc_12', 'masc_18', 'masc_20', 'masc_24');
        $tr = array('masc_27', 'masc_1', 'masc_34', 'masc_8', 'masc_15');
        $ha = array('masc_28', 'masc_2', 'masc_35', 'masc_5', 'masc_11', 'masc_13', 'masc_21', 'masc_25');

        $scores = array_fill_keys($this->scoreLabels,"0");


        // Add scores for each category
        foreach ($record as $field=>$val) {
            $qstn  = explode(" ", $field);
            $num   = explode(" ", $val);

            // error_log(print_r($record, TRUE));
            // error_log(print_r($qstn, TRUE));
            // error_log(print_r($num, TRUE));

            $value = $num[0];
            if (is_numeric($value)) {
                if (in_array($qstn[0], $sp)) {
                    $scores['masc_sp'] += $value;
                    $scores['masc_total'] += $value;
                }
                if (in_array($qstn[0], $gad)) {
                    $scores['masc_gad'] += $value;
                }
                if (in_array($qstn[0], $hr)) {
                    $scores['masc_hr'] += $value;
                    $scores['masc_total'] += $value;
                    $scores['masc_sa'] += $value;
                }
                if (in_array($qstn[0], $pf)) {
                    $scores['masc_pf'] += $value;
                    $scores['masc_total'] += $value;
                    $scores['masc_sa'] += $value;
                }
                if (in_array($qstn[0], $oc)) {
                    $scores['masc_oc'] += $value;
                    $scores['masc_total'] += $value;
                }
                if (in_array($qstn[0], $p)) {
                    $scores['masc_p'] += $value;
                    $scores['masc_total'] += $value;
                    $scores['masc_ps'] += $value;
                }
                if (in_array($qstn[0], $tr)) {
                    $scores['masc_tr'] += $value;
                    $scores['masc_total'] += $value;
                    $scores['masc_ps'] += $value;
                }
                if (in_array($qstn[0], $ha)) {
                    $scores['masc_ha'] += $value;
                    $scores['masc_total'] += $value;
                }
            }
        }

        $scores['masc_total'] += $record['masc_39'];
        $scores['masc_total'] += $record['masc_40'];

        // Calculate the inconsistency index
        $inconsistency = array();
        array_push($inconsistency, abs($record['masc_3'] - $record['masc_10']));
        array_push($inconsistency, abs($record['masc_4'] - $record['masc_9']));
        array_push($inconsistency, abs($record['masc_8'] - $record['masc_15']));
        array_push($inconsistency, abs($record['masc_13'] - $record['masc_35']));
        array_push($inconsistency, abs($record['masc_20'] - $record['masc_27']));
        array_push($inconsistency, abs($record['masc_22'] - $record['masc_29']));
        array_push($inconsistency, abs($record['masc_43'] - $record['masc_44']));
        array_push($inconsistency, abs($record['masc_47'] - $record['masc_50']));
        $scores["masc_inconsistency_index"] = array_sum($inconsistency);


        if($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $candidate   = \NDB_Factory::singleton()->candidate(
                $timepoint->getCandID()
            );
            $sex = $candidate->getCandidateSex();
            $dob = $timepoint->getEffectiveDateOfBirth();
            $age = Utility::calculateAge($dob, $timepoint->getDateOfVisit());
        }

        // Get the t scores from the lookup table
        $lookup_fields = array('total', 'sp', 'gad', 'sa', 'hr', 'pf', 'oc', 'ps', 'p', 'tr', 'ha');
        foreach($lookup_fields as &$value){
            $score_name = "masc_" . $value;
            $score = $scores[$score_name];
            $query = "SELECT t_score from masc_2_child_lookup WHERE sex = :sex AND age = :age AND attribute = :attribute AND score = :score";
            $where = array('sex' => $sex, 'age' => $age['year'], 'attribute' => $value, 'score' => $score);
            $tscore = $db->pselectRow($query, $where);
            $tscore_name = "masc_{$value}_t";
            $scores[$tscore_name] = $tscore['t_score'];
        }

        // Calculate the anxiety probabliity score
        $anxiety_probability = 0;

        if ($scores['masc_sp_t'] >= 60) {
            $anxiety_probability += 1;
        }
        if ($scores['masc_gad_t'] >= 60) {
            $anxiety_probability += 1;
        }        
        if ($scores['masc_sa_t'] >= 60) {
            $anxiety_probability += 1;
        }

        $scores["masc_anx_prob_score"] = $anxiety_probability;

        //save scores
        $db->update($this->table, $scores, $WhereCriteria);

    }

}

?>