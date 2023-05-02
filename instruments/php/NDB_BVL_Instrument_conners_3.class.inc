<?php

class NDB_BVL_Instrument_conners_3 extends NDB_BVL_Instrument
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
        $this->testName = 'conners_3' ;           // test_names.Test_name
        $this->table = 'conners_3';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array(
            "con3_p_dob"
        );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // Get the subject age in months for scoring

        $db =& Database::singleton();
        // required fields for data entry completion status
        $this->_requiredElements = array();


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
        //Get raw questions point values
        $db =& Database::singleton();
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));

        // display test name
        $this->addHeader("Conners 3 - Parent");

        $this->addHeader("Calculated Fields");

        $this->addHeader("<h3>Conners 3 ADHD Index");
        $this->form->addElement('static','con3_p_probability', "Conners 3 ADHD Index Probability Score (%)");

        $this->addHeader("<h3>DSM-5 Symptom Counts</h3>");

        $this->form->addElement('static','con3_p_an_symptoms',"ADHD Inattentive");
        if ($record['con3_p_an_symptoms'] >= 6) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 6, symptom criteria probably met.</h5>");
        } elseif ($record['con3_p_an_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 6, symptom criteria probably not met.</h5>");
        }

        $this->form->addElement('static','con3_p_ah_symptoms',"ADHD Hyperactive-Impulsive");
        if ($record['con3_p_ah_symptoms'] >= 6) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 6, symptom criteria probably met.</h5>");
        } elseif ($record['con3_p_ah_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 6, symptom criteria probably not met.</h5>");
        }
        
        $this->form->addElement('static','con3_p_cd_symptoms',"Conduct Disorder");
        if ($record['con3_p_cd_symptoms'] >= 3) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 3, symptom criteria probably met.</h5>");
        } elseif ($record['con3_p_cd_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 3, symptom criteria probably not met.</h5>");
        }

        $this->form->addElement('static','con3_p_od_symptoms',"Oppositional Defiant Disorder");
        if ($record['con3_p_od_symptoms'] >= 4) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 4, symptom criteria probably met.</h5>");
        } elseif ($record['con3_p_od_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 4, symptom criteria probably not met.</h5>");
        }

        $this->addHeader("<h3>Scores</h3>");

        $this->form->addElement('static','con3_p_in',"Inattention");
        $this->form->addElement('static','con3_p_in_t',"<p style='background-color:silver'>Inattention T-Score</p>");
        $this->form->addElement('static','con3_p_hy',"Hyperactivity/Impulsivity");
        $this->form->addElement('static','con3_p_hy_t',"<p style='background-color:silver'>Hyperactivity/Impulsivity T-Score</p>");
        $this->form->addElement('static','con3_p_lp',"Learning Problems");
        $this->form->addElement('static','con3_p_lp_t',"<p style='background-color:silver'>Learning Problems T-Score</p>");
        $this->form->addElement('static','con3_p_ef',"Executive Function");
        $this->form->addElement('static','con3_p_ef_t',"<p style='background-color:silver'>Executive Function T-Score</p>");
        $this->form->addElement('static','con3_p_ag',"Defiance/Aggression");
        $this->form->addElement('static','con3_p_ag_t',"<p style='background-color:silver'>Defiance/Aggression T-Score</p>");
        $this->form->addElement('static','con3_p_pr',"Peer Relations");
        $this->form->addElement('static','con3_p_pr_t',"<p style='background-color:silver'>Peer Relations T-Score</p>");
        $this->form->addElement('static','',"--------------------");
        $this->form->addElement('static','con3_p_gi',"Conners 3 Global Index Total");
        $this->form->addElement('static','con3_p_an',"DSM-5 ADHD Inattentive");
        $this->form->addElement('static','con3_p_ah',"DSM-5 ADHD Hyperactive-Impulsive");
        $this->form->addElement('static','con3_p_cd',"DSM-5 Conduct Disorder");
        $this->form->addElement('static','con3_p_od',"DSM-5 Oppositional Defiant Disorder");

        $this->addHeader("<h3>Response Style Analysis</h3>");

        $this->form->addElement('static', 'con3_p_inconsistency_a', "Inconsistency Index Total (A)");
        $this->form->addElement('static', 'con3_p_inconsistency_b', "Number of Absolute Differences = 2 or 3 (B)");
        if ($record['con3_p_inconsistency_a'] >= 7 and $record['con3_p_inconsitency_b'] >= 2) {
            $this->form->addElement('static', '', "<h5 style='color:red'><span style='font-weight:bold'>A</span> greater than or equal to 7 and <span style='font-weight:bold'>B</span> greater than or equal to 2. Possible inconsistent response style indicated.</h5>");
        } else {
            $this->form->addElement('static', '', "<h5><span style='font-weight:bold'>A</span> less than 7 and/or <span style='font-weight:bold'>B</span> less than 2. inconsistent response style not indicated.</h5>");
        }

        $this->form->addElement('static','con3_p_pi',"Positive Impression");
        if ($record['con3_p_pi'] >= 5) {
            $this->form->addElement('static', '', "<h5 style='color:red'>Raw PI score greater than or equal to 5, possible positive response style indicated.</h5>");
        } elseif ($record['con3_p_pi'] != null) {
            $this->form->addElement('static', '', "<h5>Raw PI score less than 5, positive response style not indicated.</h5>");
        }
        $this->form->addElement('static','con3_p_ni',"Negative Impression");
        if ($record['con3_p_ni'] >= 5) {
            $this->form->addElement('static', '', "<h5 style='color:red'>Raw NI score greater than or equal to 5, possible negative response style indicated.</h5>");
        } elseif ($record['con3_p_ni'] != null) {
            $this->form->addElement('static', '', "<h5>Raw NI score less than 5, negative response style not indicated.</h5>");
        }

        $this->addHeader("Questions");

        $this->form->addElement('select', 'con3_p_1', "1. Is happy, cheerful, and has a positive attitude.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_2', "Is forgetful in daily activities.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_3', "Talks too much.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_4', "Worries about many things.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_5', "Spelling is poor.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_6', "Skips classes.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_7', "Does not understand what he/she reads.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_8', "Is fun to be around.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_9', "Is good at memorizing facts.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_10', "Does not get invited to play or go out with others.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_11', "Has forced someone into sexual activity.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_12', "Has trouble staying focused on one thing at a time.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_13', "Has no friends.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_14', "Loses temper.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_15', "Forgets things already learned.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_16', "Bullies, threatens, or scares others.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_17', "Feels worthless.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_18', "I cannot figure out what makes him/her happy.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_19', "Fidgeting.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_20', "Has trouble controlling his/her worries.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_21', "Blames others for his/her mistakes or misbehaviors.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_22', "Is cold-hearted and cruel.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_23', "Has a short attention span.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_24', "Has trouble keeping friends.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_25', "Cries often and easily.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_26', "Cannot do things right.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_27', "Uses a weapon (for example, a bat, brick, broken bottle, knife, or gun).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_28', "Avoids or dislikes things that take a lot of effort and are not fun.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_29', "Mood changes quickly and drastically.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_30', "Starts fights with others on purpose.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_31', "Makes mistakes.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_32', "Is difficult to please or amuse.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_33', "Tells the truth; doesn't even tell 'little white lies'.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_34', "Fails to finish things he/she starts.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_35', "Does not seem to listen to what is being said to him/her.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_36', "Has trouble with reading.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_37', "Has trouble getting started on tasks or projects.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_38', "Has to struggle to complete hard tasks.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_39', "Physically hurts people.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_40', "Demands must be met immediately - easily frustrated.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_41', "Is cruel to animals.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_42', "Is hard to motivate (even with rewards like candy or money).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_43', "Blurts out answers before the question has been completed.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_44', "Has trouble concentrating.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_45', "Is constantly moving.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_46', "Tells lies to hurt other people.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_47', "Doesn't pay attention to details; makes careless mistakes.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_48', "Is angry and resentful.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_49', "Has trouble changing from one activity to another.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_50', "Excitable, impulsive.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_51', "Needs extra explanation of instructions.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_52', "Gets over-stimulated.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_53', "Learns information as separate facts; does not 'get the big picture'.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_54', "Acts as if driven by a motor.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_55', "Blurts out the first thing that comes to mind.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_56', "Lies to avoid having to do something or to get things.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_57', "Tries to get even with people.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_58', "Steals secretly (for example, shoplifting or forgery).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_59', "Annoys other people on purpose.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_60', "Reads slowly and with a lot of effort.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_61', "Has difficulty waiting for his/her turn.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_62', "Is one of the last to be picked for teams or games.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_63', "Completes projects at the last minute.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_64', "Interacts well with other children.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_65', "Intentionally damages or destroys things that belong to others.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_66', "Seems tired; has low energy.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_67', "Inattentive; easily distracted.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_68', "Does not follow through on instructions (even when he/she understands and is trying to cooperate).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_69', "Runs or climbs when he/she is not supposed to. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_70', "Appears 'on edge', nervous, or jumpy.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_71', "Is noisy and loud when playing or using free time.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_72', "Is good at planning ahead.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_73', "Is irritable and easily annoyed by others.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_74', "Behaves like an angel.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_75', "Forgets to turn in completed work.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_76', "Runs away from home for at least one night.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_77', "Gets bored.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_78', "Has intentionally set fires for the purpose of causing damage.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_79', "Fails to complete schoolwork, chores, or tasks (even when he/she understands and is trying to cooperate).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_80', "Is patient and content, even when waiting in a long line.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_81', "Temper outbursts.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_82', "Has lost interest or pleasure in activities.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_83', "Threatens to hurt others.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_84', "Has trouble organizing tasks or activities.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_85', "Disturbs other children.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_86', "Swears or uses bad language.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_87', "Cannot grasp arithmetic.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_88', "Gives up easily on difficult tasks.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_89', "Has broken into someone else's house, building, or car.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_90', "Is messy or disorganized.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_91', "Goes out at night even though it breaks the rules.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_92', "Does not know how to make friends.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_93', "Leaves seat when he/she should stay seated.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_94', "Actively refuses to do what adults tell him/her to do.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_95', "Has trouble keeping his/her mind on work or play for long.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_96', "Steals while confronting a person (for example, mugging, purse snatching, or armed robbery).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_97', "Loses things (for example, schoolwork, pencils, books, tools, or toys).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_98', "Fidgets or squirms in seat.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_99', "Restless or overactive.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_100', "Becomes irritable when anxious.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_101', "Is easily distracted by sights or sounds.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_102', "Argues with adults.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_103', "Is sad, gloomy, or irritable for many days at a time.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_104', "Interrupts others (for example, butts into conversations or games).", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_105', "Is perfect in every way.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_106', "Your child's problems seriously affect schoolwork or grades.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_107', "Your child's problems seriously affect friendships and relationships.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
        $this->form->addElement('select', 'con3_p_108', "Your child's problems seriously affect home life.", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often"));
    }
    
    /**
    * Scoring function
    *
    * @return void
    * @access public
    */
    function score():void
    {
        if ($this->_determineRequiredElementsCompletedFlag() == "Incomplete") {
            return;
        }
            
        $db =& Database::singleton();
        //Get raw questions point values
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));
            
        $scores = array(
            'con3_p_in' => null,
            'con3_p_hy' => null,
            'con3_p_lp' => null,
            'con3_p_ef' => null,
            'con3_p_ag' => null,
            'con3_p_pr' => null,
            'con3_p_gi' => null,
            'con3_p_an' => null,
            'con3_p_ah' => null,
            'con3_p_cd' => null,
            'con3_p_od' => null,
            'con3_p_pi' => null,
            'con3_p_ni' => null,
            'con3_p_in_t' => null,
            'con3_p_hy_t' => null,
            'con3_p_lp_t' => null,
            'con3_p_ef_t' => null,
            'con3_p_ag_t' => null,
            'con3_p_pr_t' => null,
            'con3_p_an_symptoms' => null,
            'con3_p_ah_symptoms' => null,
            'con3_p_cd_symptoms' => null,
            'con3_p_od_symptoms' => null,
            'con3_p_inconsistency_a' => null,
            'con3_p_inconsistency_b' => null,
            'con3_p_probability' => null,
        );

        $in_questions = array(
             'con3_p_12' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_23' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_28' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_44' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_47' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_49' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_67' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_77' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_88' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_95' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $hy_questions = array(
             'con3_p_19' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_43' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_45' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_50' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_52' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_54' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_55' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_61' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_69' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_71' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_93' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_98' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_99' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_104' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $lp_questions = array(
             'con3_p_5' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_7' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_9' => array(0=>3, 1=>2, 2=>1, 3=>0),
             'con3_p_15' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_36' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_51' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_53' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_60' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_87' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $ef_questions = array(
             'con3_p_34' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_37' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_63' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_72' => array(0=>3, 1=>2, 2=>1, 3=>0),
             'con3_p_75' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_79' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_84' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_90' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_97' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $ag_questions = array(
             'con3_p_16' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_22' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_27' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_30' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_39' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_46' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_48' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_57' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_58' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_65' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_83' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_86' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_94' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_102' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $pr_questions = array(
             'con3_p_10' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_13' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_24' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_62' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_64' => array(0=>3, 1=>2, 2=>1, 3=>0),
             'con3_p_92' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $gi_questions = array(
             'con3_p_19' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_25' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_29' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_34' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_40' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_50' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_67' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_81' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_85' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_99' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $an_questions = array(
             'con3_p_2' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_28' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_35' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_47' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_68' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_79' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_84' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_95' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_97' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_101' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $ah_questions = array(
             'con3_p_3' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_43' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_45' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_54' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_61' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_69' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_71' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_93' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_98' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_99' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_104' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $cd_questions = array(
             'con3_p_6' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_11' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_16' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_27' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_30' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_39' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_41' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_56' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_58' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_65' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_76' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_78' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_89' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_91' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_96' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $od_questions = array(
             'con3_p_14' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_21' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_48' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_57' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_59' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_73' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_94' => array(0=>0, 1=>1, 2=>2, 3=>3),
             'con3_p_102' => array(0=>0, 1=>1, 2=>2, 3=>3)
        );
        $pi_questions = array(
             'con3_p_31' => array(0=>1, 1=>0, 2=>0, 3=>0),
             'con3_p_33' => array(0=>0, 1=>0, 2=>0, 3=>1),
             'con3_p_38' => array(0=>1, 1=>0, 2=>0, 3=>0),
             'con3_p_74' => array(0=>0, 1=>0, 2=>0, 3=>1),
             'con3_p_80' => array(0=>0, 1=>0, 2=>0, 3=>1),
             'con3_p_105' => array(0=>0, 1=>0, 2=>0, 3=>1)
        );
        $ni_questions = array(
             'con3_p_1' => array(0=>1, 1=>1, 2=>0, 3=>0),
             'con3_p_8' => array(0=>1, 1=>1, 2=>0, 3=>0),
             'con3_p_18' => array(0=>0, 1=>0, 2=>1, 3=>1),
             'con3_p_26' => array(0=>0, 1=>0, 2=>1, 3=>1),
             'con3_p_32' => array(0=>0, 1=>0, 2=>1, 3=>1),
             'con3_p_42' => array(0=>0, 1=>0, 2=>1, 3=>1)
        );
        
        foreach(array_keys($in_questions) as $question) {
            $answer = $record[$question];
            $value = $in_questions[$question][$answer];
			$scores['con3_p_in'] += $value;
		}

        foreach(array_keys($hy_questions) as $question) {
            $answer = $record[$question];
            $value = $hy_questions[$question][$answer];
			$scores['con3_p_hy'] += $value;
		}

        foreach(array_keys($lp_questions) as $question) {
            $answer = $record[$question];
            $value = $lp_questions[$question][$answer];
			$scores['con3_p_lp'] += $value;
		}

        foreach(array_keys($ef_questions) as $question) {
            $answer = $record[$question];
            $value = $ef_questions[$question][$answer];
			$scores['con3_p_ef'] += $value;
		}

        foreach(array_keys($ag_questions) as $question) {
            $answer = $record[$question];
            $value = $ag_questions[$question][$answer];
			$scores['con3_p_ag'] += $value;
		}

        foreach(array_keys($pr_questions) as $question) {
            $answer = $record[$question];
            $value = $pr_questions[$question][$answer];
			$scores['con3_p_pr'] += $value;
		}

        foreach(array_keys($gi_questions) as $question) {
            $answer = $record[$question];
            $value = $gi_questions[$question][$answer];
			$scores['con3_p_gi'] += $value;
		}

        foreach(array_keys($an_questions) as $question) {
            $answer = $record[$question];
            $value = $an_questions[$question][$answer];
			$scores['con3_p_an'] += $value;
            if ($question != 'con3_p_68' and $question != 'con3_p_79') {
                if ($value >= 2) {
                    $scores['con3_p_an_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con3_p_an_symptoms'] += 0;
                }
            }
		}
        if ($an_questions['con3_p_68'][$record['con3_p_68']] >= 2 and $an_questions['con3_p_79'][$record['con3_p_79']] >= 2) {
            $scores['con3_p_an_symptoms'] += 1;
        }

        foreach(array_keys($ah_questions) as $question) {
            $answer = $record[$question];
            $value = $ah_questions[$question][$answer];
			$scores['con3_p_ah'] += $value;
            if ($question != 'con3_p_69' and $question != 'con3_p_99' and $question != 'con3_p_54' and $question != 'con3_p_45') {
                if ($value >= 2) {
                    $scores['con3_p_ah_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con3_p_ah_symptoms'] += 0;
                }
            }
		}
        if ($ah_questions['con3_p_69'][$record['con3_p_69']] >= 1 or $ah_questions['con3_p_99'][$record['con3_p_99']] >= 1) {
            $scores['con3_p_ah_symptoms'] += 1;
        }
        if ($ah_questions['con3_p_54'][$record['con3_p_54']] >= 1 or $ah_questions['con3_p_45'][$record['con3_p_45']] >= 1) {
            $scores['con3_p_ah_symptoms'] += 1;
        }

        foreach(array_keys($cd_questions) as $question) {
            $answer = $record[$question];
            $value = $cd_questions[$question][$answer];
			$scores['con3_p_cd'] += $value;

            if ($question != 'con3_p_56') {
                if ($value >= 1) {
                    $scores['con3_p_cd_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con3_p_cd_symptoms'] += 0;
                }
            }
		}
        if ($cd_questions['con3_p_56'][$record['con3_p_56']] >= 2) {
            $scores['con3_p_cd_symptoms'] += 1;
        }

        foreach(array_keys($od_questions) as $question) {
            $answer = $record[$question];
            $value = $od_questions[$question][$answer];
			$scores['con3_p_od'] += $value;
		
            if ($question != 'con3_p_48' and $question != 'con3_p_57') {
                if ($value >= 2) {
                    $scores['con3_p_od_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con3_p_od_symptoms'] += 0;
                }
            }
		}
        if ($od_questions['con3_p_48'][$record['con3_p_48']] >= 1) {
            $scores['con3_p_od_symptoms'] += 1;
        }
        if ($od_questions['con3_p_57'][$record['con3_p_57']] >= 1) {
            $scores['con3_p_od_symptoms'] += 1;
        }

        foreach(array_keys($pi_questions) as $question) {
            $answer = $record[$question];
            $value = $pi_questions[$question][$answer];
			$scores['con3_p_pi'] += $value;
		}

        foreach(array_keys($ni_questions) as $question) {
            $answer = $record[$question];
            $value = $ni_questions[$question][$answer];
			$scores['con3_p_ni'] += $value;
		}

        $inconsistency = array(
            abs($record['con3_p_44'] - $record['con3_p_67']),
            abs($record['con3_p_12'] - $record['con3_p_23']),
            abs($record['con3_p_36'] - $record['con3_p_60']),
            abs($record['con3_p_14'] - $record['con3_p_81']),
            abs($record['con3_p_19'] - $record['con3_p_98']),
            abs($record['con3_p_45'] - $record['con3_p_99']),
            abs($record['con3_p_94'] - $record['con3_p_102']),
            abs($record['con3_p_75'] - $record['con3_p_79']),
            abs($record['con3_p_13'] - $record['con3_p_92']),
            abs($record['con3_p_39'] - $record['con3_p_83']),
        );

        foreach($inconsistency as $item) {
            if ($item >= 2) {
                $scores['con3_p_inconsistency_b'] += 1;
            } else {
                $scores['con3_p_inconsistency_b'] += 0;
            }
            $scores['con3_p_inconsistency_a'] += $item;
        }


        $transposed = array(
            'con3_p_19' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con3_p_35' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con3_p_47' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con3_p_67' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con3_p_84' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con3_p_88' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con3_p_98' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con3_p_99' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con3_p_101' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con3_p_104' => array(0=>0, 1=>0, 2=>1, 3=>2),
        );
        $total_transposed = 0;
        $probability = array(
            0 => 11,
            1 => 29,
            2 => 41,
            3 => 51,
            4 => 56,
            5 => 64,
            6 => 71,
            7 => 77,
            8 => 82,
            9 => 87,
            10 => 91,
            11 => 94,
            12 => 97,
            13 => 98,
            14 => 99,
            15 => 99,
            16 => 99,
            17 => 99,
            18 => 99,
            19 => 99,
            20 => 99,
        );

        foreach(array_keys($transposed) as $question) {
            $total_transposed += $transposed[$question][$record[$question]];
        }

        $scores['con3_p_probability'] = $probability[$total_transposed];

        if($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $candidate   = \NDB_Factory::singleton()->candidate(
                $timepoint->getCandID()
            );
            $sex = $candidate->getCandidateSex();
            $dob = $timepoint->getEffectiveDateOfBirth();
            $age = Utility::calculateAge($dob, $timepoint->getDateOfVisit());
        }


        $scores['con3_p_in_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"parent", "s"=>$sex, "a"=>$age['year'], "att"=>"in", "sc"=>$scores["con3_p_in"] ))["t_score"];
        $scores['con3_p_hy_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"parent", "s"=>$sex, "a"=>$age['year'], "att"=>"hy", "sc"=>$scores["con3_p_hy"] ))["t_score"];
        $scores['con3_p_lp_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"parent", "s"=>$sex, "a"=>$age['year'], "att"=>"lp", "sc"=>$scores["con3_p_lp"] ))["t_score"];
        $scores['con3_p_ef_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"parent", "s"=>$sex, "a"=>$age['year'], "att"=>"ef", "sc"=>$scores["con3_p_ef"] ))["t_score"];
        $scores['con3_p_ag_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"parent", "s"=>$sex, "a"=>$age['year'], "att"=>"ag", "sc"=>$scores["con3_p_ag"] ))["t_score"];
        $scores['con3_p_pr_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"parent", "s"=>$sex, "a"=>$age['year'], "att"=>"pr", "sc"=>$scores["con3_p_pr"] ))["t_score"];

        // save the scores
        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }


}

?>