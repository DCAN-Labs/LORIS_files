<?php

class NDB_BVL_Instrument_masc2_self extends NDB_BVL_Instrument
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
        $this->testName = 'masc2_self' ;           // test_names.Test_name
        $this->table = 'masc2_self';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array(
              "Date_taken" 
        );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // Get the subject age in months for scoring

        $db =& Database::singleton();
        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner', 'Date_taken'
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
        // display test name
        $this->addHeader("MASC 2 Self-Report");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addHeader("Total Scores");
        $this->form->addElement('static','masc2_total',"MASC 2 Total Score");
        $this->form->addElement('static','masc2_total_t',"MASC 2 Total Score T-Score");
        $this->form->addElement('select', 'masc2_anx_prob_score', "Anxiety Probability Score<h5>The Anxiety Probability Score is determined by the number of elevated T-scores (60 or higher) on the Anxiety Scales.</h5>", array(''=>'', '0'=>"0 - Low Probability", '1'=>"1 - Borderline Probability", '2'=>"2- High Probability", '3'=>"3 - Very High Probability"), array('disabled'=>'disabled') );
        $this->form->addElement('static','masc2_inconsistency_index',"Inconsistency Index<h5 style='color:red'>If the Inconsistency Index is greater than 8 there may be some inconsistency, and the results should be interpreted with caution.</h5>");
        $this->addHeader("Seperation Anxiety/Phobias");
        $this->form->addElement('static','masc2_sp',"Seperation Anxiety/Phobias");
        $this->form->addElement('static','masc2_sp_t',"Seperation Anxiety/Phobias T-Score");
        $this->addHeader("GAD Index");
        $this->form->addElement('static','masc2_gad',"GAD Index");
        $this->form->addElement('static','masc2_gad_t',"GAD Index T-Score");
        $this->addHeader("Social Anxiety");
        $this->form->addElement('static','masc2_sa',"Social Anxiety Total");
        $this->form->addElement('static','masc2_sa_t',"Social Anxiety Total T-Score");
        $this->form->addElement('static','masc2_hr',"Humiliation/Rejection");
        $this->form->addElement('static','masc2_hr_t',"Humiliation/Rejection T-Score");
        $this->form->addElement('static','masc2_pf',"Performance Fears");
        $this->form->addElement('static','masc2_pf_t',"Performance Fears T-Score");
        $this->addHeader("Obsessions & Compulsions");
        $this->form->addElement('static','masc2_oc',"Obsessions & Compulsions");
        $this->form->addElement('static','masc2_oc_t',"Obsessions & Compulsions T-Score");
        $this->addHeader("Physical Symptoms");
        $this->form->addElement('static','masc2_ps',"Physical Symptoms Total");
        $this->form->addElement('static','masc2_ps_t',"Physical Symptoms Total T-Score");
        $this->form->addElement('static','masc2_p',"Panic");
        $this->form->addElement('static','masc2_p_t',"Panic T-Score");
        $this->form->addElement('static','masc2_tr',"Tense/Restless");
        $this->form->addElement('static','masc2_tr_t',"Tense/Restless T-Score");
        $this->addHeader("Harm Avoidance");
        $this->form->addElement('static','masc2_ha',"Harm Avoidance");
        $this->form->addElement('static','masc2_ha_t',"Harm Avoidance T-Score");
    }


    function _page1()
    {
        $this->addHeader("MASC 2 Self-Report Questions");
        $this->form->addElement('select', 'masc2_q01', "1. I feel tense or uptight.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q02', "2. I usually ask permission to do things.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q03', "3. I worry about other people laughing at me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q04', "4. I get scared when my parents go away.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q05', "5. I keep my eyes open for danger.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q06', "6. I have trouble getting my breath.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q07', "7. The idea of going away to camp scares me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q08', "8. I get shaky or jittery.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q09', "9. I try to stay near my mom or dad.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q10', "10. I'm afraid that other kids will make fun of me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q11', "11. I try hard to obey my parents and teachers.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q12', "12. I get dizzy or faint feelings.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q13', "13. I check things out first.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q14', "14. I worry about getting called on in class.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q15', "15. I'm jumpy.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q16', "16. I'm afraid other people will think I'm stupid.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q17', "17. I keep the light on at night.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q18', "18. I have pains in my chest.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q19', "19. I avoid going to places without my family.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q20', "20. I feel strange, weird, or unreal.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q21', "21. I try to do things other people will like.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q22', "22. I worry about what other people think of me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q23', "23. I avoid watching scary movies and TV shows.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q24', "24. My heart races or skips beats.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q25', "25. I stay away from things that upset me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q26', "26. I sleep next to someone from my family.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q27', "27. I feel restless and on edge.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q28', "28. I try to do everything exactly right.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q29', "29. I worry about doing something stupid or embarrassing.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q30', "30. I get scared riding in the car or on the bus.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q31', "31. I feel sick to my stomach.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q32', "32. I get nervous if I have to perfom in public.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q33', "33. Bad weather, the dark, heights, animals, or bugs scare me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q34', "34. My hands shake.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q35', "35. I check to make sure things are safe.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q36', "36. I have trouble asking other kids to play with me.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q37', "37. My hands feel sweaty or cold.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q38', "38. I feel shy.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q39', "39. I have trouble making up my mind about simple things.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q40', "40. I get upset over the thought that I might get sick.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q41', "41. I have bad or silly thoughts that I can't stop.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q42', "42. I have to do things over and over again for no reason.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q43', "43. I get really upset about dirt, germs, chemicals, radiation, or sticky things.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q44', "44. I feel that I have to wash or clean more than I really need to.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q45', "45. I fear I'll be responsible for something bad happening.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q46', "46. I have to check that nothing terrible has happened.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q47', "47. I have to check things several times or more.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q48', "48. I count things for no reason.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q49', "49. I get too concerned with sin or wrongdoing.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'masc2_q50', "50. I have to repeat things until it feels just right.", array(''=>'', '0'=>"0", '1'=>"1", '2'=>"2", '3'=>"3", 'not_answered'=>'Not Answered'));
    }

    var $scoreLabels = array("masc2_total", "masc2_total_t", "masc2_anx_prob_score", "masc2_inconsistency_index",
                "masc2_sp", "masc2_sp_t", "masc2_gad", "masc2_gad_t", "masc2_sa", "masc2_sa_t", "masc2_hr", "masc2_hr_t",
                "masc2_pf", "masc2_pf_t", "masc2_oc", "masc2_oc_t", "masc2_ps", "masc2_ps_t", "masc2_p", "masc2_p_t",
                "masc2_tr", "masc2_tr_t", "masc2_ha", "masc2_ha_t");

    function score(): void
    {
        // if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
        //     return;
        // }
        
        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db =& Database::singleton();

        $query = "SELECT * FROM $this->table WHERE CommentID = :CommentID";
	    $WhereCriteria = array('CommentID'=>$this->commentID);
        $record = $db->pselectRow($query, $WhereCriteria);

        //questions for subscores
        $sp = array('masc2_q4', 'masc2_q7', 'masc2_q9', 'masc2_q17', 'masc2_q19', 'masc2_q23','masc2_q26', 'masc2_q30', 'masc2_q33');
        $gad = array('masc2_q27', 'masc2_q29', 'masc2_q31', 'masc2_q1', 'masc2_q6', 'masc2_q39', 'masc2_q40', 'masc2_q13', 'masc2_q17', 'masc2_q22');
        $hr = array('masc2_q29', 'masc2_q3', 'masc2_q10', 'masc2_q16', 'masc2_q22');
        $pf = array('masc2_q32', 'masc2_q36', 'masc2_q38', 'masc2_q14');
        $oc = array('masc2_q41', 'masc2_q42', 'masc2_q43', 'masc2_q44', 'masc2_q45', 'masc2_q46', 'masc2_q47', 'masc2_q48', 'masc2_q49', 'masc2_q50');
        $p = array('masc2_q31', 'masc2_q37', 'masc2_q6', 'masc2_q12', 'masc2_q18', 'masc2_q20', 'masc2_q24');
        $tr = array('masc2_q27', 'masc2_q1', 'masc2_q34', 'masc2_q8', 'masc2_q15');
        $ha = array('masc2_q28', 'masc2_q2', 'masc2_q35', 'masc2_q5', 'masc2_q11', 'masc2_q13', 'masc2_q21', 'masc2_q25');

        $scores        = array_fill_keys($this->scoreLabels,"0");


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
                    $scores['masc2_sp'] += $value;
                    $scores['masc2_total'] += $value;
                }
                if (in_array($qstn[0], $gad)) {
                    $scores['masc2_gad'] += $value;
                }
                if (in_array($qstn[0], $hr)) {
                    $scores['masc2_hr'] += $value;
                    $scores['masc2_total'] += $value;
                    $scores['masc2_sa'] += $value;
                }
                if (in_array($qstn[0], $pf)) {
                    $scores['masc2_pf'] += $value;
                    $scores['masc2_total'] += $value;
                    $scores['masc2_sa'] += $value;
                }
                if (in_array($qstn[0], $oc)) {
                    $scores['masc2_oc'] += $value;
                    $scores['masc2_total'] += $value;
                }
                if (in_array($qstn[0], $p)) {
                    $scores['masc2_p'] += $value;
                    $scores['masc2_total'] += $value;
                    $scores['masc2_ps'] += $value;
                }
                if (in_array($qstn[0], $tr)) {
                    $scores['masc2_tr'] += $value;
                    $scores['masc2_total'] += $value;
                    $scores['masc2_ps'] += $value;
                }
                if (in_array($qstn[0], $ha)) {
                    $scores['masc2_ha'] += $value;
                    $scores['masc2_total'] += $value;
                }
            }
        }

        $scores['masc2_total'] += $record['masc2_q39'];
        $scores['masc2_total'] += $record['masc2_q40'];

        // Calculate the inconsistency index
        $inconsistency = array();
        array_push($inconsistency, abs($record['masc2_q03'] - $record['masc2_q10']));
        array_push($inconsistency, abs($record['masc2_q04'] - $record['masc2_q09']));
        array_push($inconsistency, abs($record['masc2_q08'] - $record['masc2_q15']));
        array_push($inconsistency, abs($record['masc2_q13'] - $record['masc2_q35']));
        array_push($inconsistency, abs($record['masc2_q20'] - $record['masc2_q27']));
        array_push($inconsistency, abs($record['masc2_q22'] - $record['masc2_q29']));
        array_push($inconsistency, abs($record['masc2_q43'] - $record['masc2_q44']));
        array_push($inconsistency, abs($record['masc2_q47'] - $record['masc2_q50']));
        $scores["masc2_inconsistency_index"] = array_sum($inconsistency);

        // Get gender   
        $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, masc2_self as t WHERE t.CommentID = :CommentID AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $where = array('CommentID'=>$this->commentID);
        $record_gender = $db->pselectRow($query_gender,$where);
        $gender = strtolower($record_gender['Sex']);
        $sex = substr($gender, 0, 1);

        // Get the subject age in months for scoring
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();
        $age = Utility::calculateAge($dob, $record["Date_taken"]);

        // Get the t scores from the lookup table
        $lookup_fields = array('total', 'sp', 'gad', 'sa', 'hr', 'pf', 'oc', 'ps', 'p', 'tr', 'ha');
        foreach($lookup_fields as &$value){
            $score_name = "masc2_" . $value;
            $score = $scores[$score_name];
            $query = "SELECT t_score from masc2_self_lookup WHERE sex = :sex AND age = :age AND attribute = :attribute AND score = :score";
            $where = array('sex' => $sex, 'age' => $age['year'], 'attribute' => $value, 'score' => $score);
            $tscore = $db->pselectRow($query, $where);
            $tscore_name = "masc2_{$value}_t";
            $scores[$tscore_name] = $tscore['t_score'];
        }

        // Calculate the anxiety probabliity score
        $anxiety_probability = 0;

        if ($scores['masc2_sp_t'] >= 60) {
            $anxiety_probability += 1;
        }
        if ($scores['masc2_gad_t'] >= 60) {
            $anxiety_probability += 1;
        }        
        if ($scores['masc2_sa_t'] >= 60) {
            $anxiety_probability += 1;
        }

        $scores["masc2_anx_prob_score"] = $anxiety_probability;

        // error_log(print_r($scores, TRUE));
        //save scores
        $db->update($this->table, $scores, $WhereCriteria);
        
        }
    }


?>