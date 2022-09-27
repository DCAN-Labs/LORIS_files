<?php

class NDB_BVL_Instrument_conners3_teacher extends NDB_BVL_Instrument
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
        $this->testName = 'conners3_teacher' ;           // test_names.Test_name
        $this->table = 'conners3_teacher';              // name of database table corresponding to instrument
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
        $this->addHeader("Connners 3 Teacher");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->addHeader("Conners 3 ADHD Index");
            $this->form->addElement('static','adhd_index_transposed',"Total Transposed Score");
            $this->form->addElement('static','adhd_index_probability',"Probability (%)");
        $this->addHeader("Raw Scores");
            $this->form->addElement('static','raw_in',"IN");
            $this->form->addElement('static','raw_hy',"HY");
            $this->form->addElement('static','raw_le',"LE");
            $this->form->addElement('static','raw_lp',"LP");
            $this->form->addElement('static','raw_ef',"EF");
            $this->form->addElement('static','raw_ag',"AG");
            $this->form->addElement('static','raw_pr',"PR");
            $this->form->addElement('static','raw_gi',"GI");
            $this->form->addElement('static','raw_an',"AN");
            $this->form->addElement('static','raw_ah',"AH");
            $this->form->addElement('static','raw_cd',"CD");
            $this->form->addElement('static','raw_od',"OD");
            $this->form->addElement('static','raw_pi',"PI");
            $this->form->addElement('static','raw_ni',"NI");
            $this->addHeader("Response Style Analysis");
            $this->form->addElement('static','inconsistency',"Inconsistency Index");
        $this->form->addElement('static','pi',"Positive Impression");
        $this->form->addElement('static','ni',"Negative Impression");
        $this->addHeader("DSM-5 Symptom Counts");
        $this->addHeader("<h3>ADHD Inattentive</h3>");
            $this->form->addElement('static','adhd_inattentive_a1a',"A1a");
            $this->form->addElement('static','adhd_inattentive_a1b',"A1b");
            $this->form->addElement('static','adhd_inattentive_a1c',"A1c");
            $this->form->addElement('static','adhd_inattentive_a1d',"A1d");
            $this->form->addElement('static','adhd_inattentive_a1e',"A1e");
            $this->form->addElement('static','adhd_inattentive_a1f',"A1f");
            $this->form->addElement('static','adhd_inattentive_a1g',"A1g");
            $this->form->addElement('static','adhd_inattentive_a1h',"A1h");
            $this->form->addElement('static','adhd_inattentive_a1i',"A1i");
        $this->form->addElement('static','adhd_inattentive',"Total Symptom Count");
        $this->addHeader("<h3>ADHD Hyperactive/Impulsive</h3>");
            $this->form->addElement('static','adhd_hyp_imp_a2a',"A2a");
            $this->form->addElement('static','adhd_hyp_imp_a2b',"A2b");
            $this->form->addElement('static','adhd_hyp_imp_a2c',"A2c");
            $this->form->addElement('static','adhd_hyp_imp_a2d',"A2d");
            $this->form->addElement('static','adhd_hyp_imp_a2e',"A2e");
            $this->form->addElement('static','adhd_hyp_imp_a2f',"A2f");
            $this->form->addElement('static','adhd_hyp_imp_a2g',"A2g");
            $this->form->addElement('static','adhd_hyp_imp_a2h',"A2h");
            $this->form->addElement('static','adhd_hyp_imp_a2i',"A2i");
        $this->form->addElement('static','adhd_hyp_imp',"Total Symptom Count");
        $this->addHeader("<h3>Conduct Disorder</h3>");
            $this->form->addElement('static','cond_dis_a1',"A1");
            $this->form->addElement('static','cond_dis_a2',"A2");
            $this->form->addElement('static','cond_dis_a3',"A3");
            $this->form->addElement('static','cond_dis_a4',"A4");
            $this->form->addElement('static','cond_dis_a5',"A5");
            $this->form->addElement('static','cond_dis_a6',"A6");
            $this->form->addElement('static','cond_dis_a7',"A7");
            $this->form->addElement('static','cond_dis_a8',"A8");
            $this->form->addElement('static','cond_dis_a9',"A9");
            $this->form->addElement('static','cond_dis_a10',"A10");
            $this->form->addElement('static','cond_dis_a11',"A11");
            $this->form->addElement('static','cond_dis_a12',"A12");
            $this->form->addElement('static','cond_dis_a13',"A13");
            $this->form->addElement('static','cond_dis_a14',"A14");
            $this->form->addElement('static','cond_dis_a15',"A15");
            $this->form->addElement('static','cond_dis',"Total Symptom Count");
        $this->addHeader("<h3>Oppositional Defiant Disorder</h3>");
            $this->form->addElement('static','op_def_a1',"A1");
            $this->form->addElement('static','op_def_a2',"A2");
            $this->form->addElement('static','op_def_a3',"A3");
            $this->form->addElement('static','op_def_a4',"A4");
            $this->form->addElement('static','op_def_a5',"A5");
            $this->form->addElement('static','op_def_a6',"A6");
            $this->form->addElement('static','op_def_a7',"A7");
            $this->form->addElement('static','op_def_a8',"A8");
            $this->form->addElement('static','op_def',"Total Symptom Count");
        $this->addHeader("Screener Items");
        $this->addHeader("<h3>Anxiety</h3>");    
            $this->form->addElement('static','q058',"Worries");
            $this->form->addElement('static','q082',"Trouble Controlling Worries");
            $this->form->addElement('static','q087',"Nervous or Jumpy");
            $this->form->addElement('static','q058',"Irritable");
        $this->addHeader("<h3>Depression</h3>"); 
            $this->form->addElement('static','q095',"Worthlessness");
            $this->form->addElement('static','q067',"Tired; Low Energy");
            $this->form->addElement('static','q053',"Loss of Interest or Pleasure");
            $this->form->addElement('static','q049',"Sad, Gloomy or Irritable");
        $this->addHeader("Severe Conduct Critical Items");
            $this->form->addElement('static','q033',"Forced Sex");
            $this->form->addElement('static','q014',"Uses a Weapon");
            $this->form->addElement('static','q021',"Cruel to Animals");
            $this->form->addElement('static','q061',"Fire Setting");
            $this->form->addElement('static','q090',"Breaking and Entering");
            $this->form->addElement('static','q027',"Confrontational Stealing");

    }


    function _page1()
    {
        $this->addHeader("Questions");
        $this->form->addElement('select', 'q001', "1 - Leaves seat when she/he should stay seated.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q002', "2 - Gets overly excited.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q003', "3 - Has a short attention span.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q004', "4 - Fidgets or squirms in seat.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q005', "5 - Cannot do things right.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q006', "6 - Begins a task or project without making a plan.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q007', "7 - Restless or overactive.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q008', "8 - Threatens to hurt others.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q009', "9 - Blurts out answers before the question has been completed.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q010', "10 - Intentionally damages or destroys things that belond to others.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q011', "11 - Has trouble getting started on tasks or projects.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q012', "12 - Does not remeber what she/he reads.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q013', "13 - Excitable, impulsive.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q014', "14 - Uses a weapon (e.g., a bat, brick, broken bottle, knife, or gun.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q015', "15 - Is patient and content, even when waiting in a long line.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q016', "16 - Cannot decide which things are the most important.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q017', "17 - Acts as if driven by a motor.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q018', "18 - Forgets instructions quickly.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q019', "19 - Has trouble keeping friends.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q020', "20 - Completes projects at the lase minute.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q021', "21 - Is cruel to animals.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q022', "22 - Temper outbursts; explosive, unpredictable behavior.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q023', "23 - Is easily distracted by sights or sounds.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q024', "24 - Runs or climbs when she/he is not supposed to.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q025', "25 - Fails to finish things she/he starts.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q026', "26 - Talks out of turn.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q027', "27 - Steals while confronting a person (e.g., mugging, purse snatching, or armed robbery.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q028', "28 - Is perfect in every way.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q029', "29 - Interrupts others (e.g., butts into conversation or games).", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q030', "30 - Has to struggle to complete hard tasks.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q031', "31 - Steals secretly (e.g., shoplifting or forgery).", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q032', "32 - Is noisy and loud when playing or using free time.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q033', "33 - Has forced someone into sexual activity.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q034', "34 - Has no friends.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q035', "35 - Physically hurts people.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q036', "36 - Makes mistakes.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q037', "37 - Doesn't pay attention to details; makes careless mistakes.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q038', "38 - Is angry and resentful.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q039', "39 - Gets over-stimulated or \"wound up.\"", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q040', "40 - Lies to avoid having to do something or to get things.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q041', "41 - Gives up easily on difficult tasks.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q042', "42 - Appears to be unaccepted by groups.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q043', "43 - Is cold-hearted and cruel.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q044', "44 - Is sidetracked easily.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q045', "45 - Spelling is poor.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q046', "46 - Mood changes quickly and drastically.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q047', "47 - Argues with adults.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q048', "48 - Disturbs other children.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q049', "49 - Is sad, gloomy, or irritable for many days at a time.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q050', "50 - Talks too much.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q051', "51 - Tries to get even with people.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q052', "52 - Has trouble with reading.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q053', "53 - Has lost interest or pleasure in activites.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q054', "54 - Skips classes.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q055', "55 - Tells the truth; does not even tell \"little white lies.\"", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q056', "56 - Is irritable and easily annoyed by others.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q057', "57 - Fails to complete schoolwork or tasks (even when she/he understands and is trying to cooperate).", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q058', "58 - Becomes irritable when anxious.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q059', "59 - Annoys other people on purpose.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q060', "60 - Avoids or dislikes things that take a lot of effort and are not fun.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q061', "61 - Has intentionally set fires for the purpose of causing damage.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q062', "62 - Loses temper.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q063', "63 - Does not understand what she/he reads.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q064', "64 - Blames others for her/his mistakes or misbehavior.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q065', "65 - Forgets things already learned.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q066', "66 - Is good at planning ahead.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q067', "67 - Seems tired; has low energy.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q068', "68 - Gets into trouble with the police.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q069', "69 - Does not seem to listen to what is being said to her/him.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q070', "70 - Is selfish and self-centered with others.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q071', "71 - Actively refuses to do what adults tell her/him to do.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q072', "72 - Cannot grasp arithmetic.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q073', "73 - Does not follow through on instructions (even when she/he understands and is trying to cooperate.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q074', "74 - Interacts well with other children.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q075', "75 - Cries often and easily.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q076', "76 - Has difficulty waiting for her/his turn.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q077', "77 - Fidgeting.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q078', "78 - Is constantly moving.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q079', "79 - Worries about many things.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q080', "80 - Has poor social skills.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q081', "81 - Is happy, cheerful, and has a positive attitude.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q082', "82 - Has trouble controlling her/his worries.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q083', "83 - Talks non-stop.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q084', "84 - Demands must be met immediately - easily frustrated.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q085', "85 - Does not seem sorry for misbehaving.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q086', "86 - Gets bored.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q087', "87 - Appears \"on edge,\" nervous, or jumpy.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q088', "88 - Is forgetful in daily activities.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q089', "89 - Does no know how to make friends.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q090', "90 - Has broken into someone else's house, building, or car.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q091', "91 - Gets up and moves around during lessons.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q092', "92 - Loses things (e.g., schoolwork, pencils, books, tools, or toys).", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q093', "93 - Is difficult to please or amuse.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q094', "94 - Needs extra explanation of instructions.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q095', "95 - Feels worthless.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q096', "96 - Gets into trouble with teachers or school principal.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q097', "97 - Has trouble concentrating.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q098', "98 - Bullies, threatens, or scares others.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q099', "99 - Needs help to break a complex task into smaller, more manageable pieces.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q100', "100 - Inattentive, easily distracted.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q101', "101 - I cannot figure out what makes her/him happy.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q102', "102 - Acts in sneaky or manipulative ways.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q103', "103 - Has difficulty organizing tasks or activities.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q104', "104 - Is one of the last to be picked for teams or games.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q105', "105 - Intentionally starts fights with others.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q106', "106 - Forgets to turn in completed work.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q107', "107 - Is fun to be around.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q108', "108 - Has trouble changing from one task to another.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q109', "109 - Behaves like an angel.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q110', "110 - Is hard to motivate (even with highly desirable rewards).", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q111', "111 - Has trouble keeping her/his mind on work and play for long.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));

        
        
        $this->addHeader("Think about your answers so far, then answer the next two items.");
        $this->form->addElement('select', 'q112', "112 - The student's problems seriously affect schoolwork or grades.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q113', "113 - The student's problems seriously affect friendships and relationships.", array(''=>'', '0'=>"0 - Not true at all (Never, Seldom)", '1'=>"1 - Just a little true (Occasionally)", '2'=>"2 - Pretty much true (Often, Quite a bit)", '3'=>"3 - Very much true (Very often, Very frequently)", 'not_answered'=>'Not Answered'));
        $this->addHeader("Additional Questions");
        $this->addTextAreaElement('q114',"114 - Do you have and other concerns about this student?");
        $this->addTextAreaElement('q115',"115 - What strengths of skills does this student have?");
    }


}

?>