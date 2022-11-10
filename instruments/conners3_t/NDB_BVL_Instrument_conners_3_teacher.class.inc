<?php

class NDB_BVL_Instrument_conners_3_teacher extends NDB_BVL_Instrument
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
        $this->testName = 'conners_3_teacher' ;           // test_names.Test_name
        $this->table = 'conners_3_teacher';              // name of database table corresponding to instrument
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
        $this->addHeader("Conners 3 - Teacher");
        $this->addHeader("Calculated Fields");

        $this->addHeader("<h3>Conners 3 ADHD Index");
        $this->form->addElement('static','con_t_probability', "Conners 3 ADHD Index Probability Score (%)");

        $this->addHeader("<h3>DSM-5 Symptom Counts</h3>");

        $this->form->addElement('static','con_t_an_symptoms',"ADHD Inattentive");
        if ($record['con_t_an_symptoms'] >= 6) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 6, symptom criteria probably met.</h5>");
        } elseif ($record['con_t_an_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 6, symptom criteria probably not met.</h5>");
        }

        $this->form->addElement('static','con_t_ah_symptoms',"ADHD Hyperactive-Impulsive");
        if ($record['con_t_ah_symptoms'] >= 6) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 6, symptom criteria probably met.</h5>");
        } elseif ($record['con_t_ah_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 6, symptom criteria probably not met.</h5>");
        }
        
        $this->form->addElement('static','con_t_cd_symptoms',"Conduct Disorder");
        if ($record['con_t_cd_symptoms'] >= 3) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 3, symptom criteria probably met.</h5>");
        } elseif ($record['con_t_cd_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 3, symptom criteria probably not met.</h5>");
        }

        $this->form->addElement('static','con_t_od_symptoms',"Oppositional Defiant Disorder");
        if ($record['con_t_od_symptoms'] >= 4) {
            $this->form->addElement('static', '', "<h5>Total symptom count greter than or equal to 4, symptom criteria probably met.</h5>");
        } elseif ($record['con_t_od_symptoms'] != null) {
            $this->form->addElement('static', '', "<h5>Total symptom count less than 4, symptom criteria probably not met.</h5>");
        }

        $this->addHeader("<h3>Scores</h3>");

        $this->form->addElement('static','con_t_in',"Inattention");
        $this->form->addElement('static','con_t_in_t',"<p style='background-color:silver'>Inattention T-Score</p>");
        $this->form->addElement('static','con_t_hy',"Hyperactivity/Impulsivity");
        $this->form->addElement('static','con_t_hy_t',"<p style='background-color:silver'>Hyperactivity/Impulsivity T-Score</p>");
        $this->form->addElement('static','con_t_le',"Learning Problems/Executive Functioning");
        $this->form->addElement('static','con_t_lp',"Learning Problems");
        $this->form->addElement('static','con_t_ef',"Executive Function");
        $this->form->addElement('static','con_t_le_t',"<p style='background-color:silver'>Learning Problems/Executive Functioning T-Score</p>");
        $this->form->addElement('static','con_t_ag',"Defiance/Aggression");
        $this->form->addElement('static','con_t_ag_t',"<p style='background-color:silver'>Defiance/Aggression T-Score</p>");
        $this->form->addElement('static','con_t_pr',"Peer Relations");
        $this->form->addElement('static','con_t_pr_t',"<p style='background-color:silver'>Peer Relations T-Score</p>");
        $this->form->addElement('static','',"--------------------");
        $this->form->addElement('static','con_t_gi',"Conners 3 Global Index Total");
        $this->form->addElement('static','con_t_an',"DSM-5 ADHD Inattentive");
        $this->form->addElement('static','con_t_ah',"DSM-5 ADHD Hyperactive-Impulsive");
        $this->form->addElement('static','con_t_cd',"DSM-5 Conduct Disorder");
        $this->form->addElement('static','con_t_od',"DSM-5 Oppositional Defiant Disorder");

        $this->addHeader("<h3>Response Style Analysis</h3>");

        $this->form->addElement('static', 'con_t_inconsistency_a', "Inconsistency Index Total (A)");
        $this->form->addElement('static', 'con_t_inconsistency_b', "Number of Absolute Differences = 2 or 3 (B)");
        if ($record['con_t_inconsistency_a'] >= 6 and $record['con_t_inconsitency_b'] >= 2) {
            $this->form->addElement('static', '', "<h5 style='color:red'><span style='font-weight:bold'>A</span> greater than or equal to 6 and <span style='font-weight:bold'>B</span> greater than or equal to 2. Possible inconsistent response style indicated.</h5>");
        } else {
            $this->form->addElement('static', '', "<h5><span style='font-weight:bold'>A</span> less than 6 and/or <span style='font-weight:bold'>B</span> less than 2. inconsistent response style not indicated.</h5>");
        }

        $this->form->addElement('static','con_t_pi',"Positive Impression");
        if ($record['con_t_pi'] >= 5) {
            $this->form->addElement('static', '', "<h5 style='color:red'>Raw PI score greater than or equal to 5, possible positive response style indicated.</h5>");
        } elseif ($record['con_t_pi'] != null) {
            $this->form->addElement('static', '', "<h5>Raw PI score less than 5, positive response style not indicated.</h5>");
        }
        $this->form->addElement('static','con_t_ni',"Negative Impression");
        if ($record['con_t_ni'] >= 5) {
            $this->form->addElement('static', '', "<h5 style='color:red'>Raw NI score greater than or equal to 5, possible negative response style indicated.</h5>");
        } elseif ($record['con_t_ni'] != null) {
            $this->form->addElement('static', '', "<h5>Raw NI score less than 5, negative response style not indicated.</h5>");
        }

        $this->addHeader("Questions");

        $this->form->addElement('select', 'con_t_1', "Leaves seat when he/she should stay seated. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_2', "Gets overly excited. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_3', "Has a short attention span. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_4', "Fidgets or squirms in seat. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_5', "Cannot do things right. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_6', "Begins a task or project without making a plan. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_7', "Restless or overactive. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_8', "Threatens to hurt others. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_9', "Blurts out answers before the question has been completed. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_10', "Intentionally damages or destroys things that belong to others. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_11', "Has trouble getting started on tasks or projects. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_12', "Does not remember what he/she reads. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_13', "Excitable, impulsive. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_14', "Uses a weapon (e.g., a bat, brick, broken bottle, knife, or gun). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_15', "Is patient and content, even when waiting in a long line. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_16', "Cannot decide which things are the most important. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_17', "Acts as if driven by a motor. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_18', "Forgets instructions quickly. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_19', "Has trouble keeping friends. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_20', "Completes projects at the last minute. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_21', "Is cruel to animals. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_22', "Temper outbursts; explosive, unpredictable behavior. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_23', "Is easily distracted by sights or sounds. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_24', "Runs or climbs when he/she is not supposed to. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_25', "Fails to finish things he/she starts. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_26', "Talks out of turn. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_27', "Steals while confronting a person (e.g., mugging, purse snatching, or armed robbery). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_28', "Is perfect in every way. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_29', "Interrupts others (e.g., butts into conversations or games). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_30', "Has to struggle to complete hard tasks. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_31', "Steals secretly (e.g., shoplifting or forgery). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_32', "Is noisy and loud when playing or using free time. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_33', "Has forced someone into sexual activity. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_34', "Has no friends. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_35', "Physically hurts people. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_36', "Makes mistakes. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_37', "Doesn't pay attention to details; makes careless mistakes. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_38', "Is angry and resentful. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_39', "Gets over-stimulated or 'wound up'. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_40', "Lies to avoid having to do something or to get things. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_41', "Gives up easily on difficult tasks. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_42', "Appears to be unaccepted by group. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_43', "Is cold-hearted and cruel. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_44', "Is sidetracked easily. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_45', "Spelling is poor. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_46', "Mood changes quickly and drastically. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_47', "Argues with adults. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_48', "Disturbs other children. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_49', "Is sad, gloomy, or irritable for many days at a time. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_50', "Talks too much. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_51', "Tries to get even with people. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_52', "Has trouble with reading. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_53', "Has lost interest or pleasure in activities. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_54', "Skips classes. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_55', "Tells the truth; does not even tell 'little white lies'. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_56', "Is irritable and easily annoyed by others. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_57', "Fails to complete schoolwork or tasks (even when he/she understands and is trying to cooperate). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_58', "Becomes irritable when anxious. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_59', "Annoys other people on purpose. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_60', "Avoids or dislikes things that take a lot of effort and are not fun. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_61', "Has intentionally set fires for the purpose of causing damage. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_62', "Loses temper. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_63', "Does not understand what he/she reads. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_64', "Blames others for his/her mistakes or misbehavior. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_65', "Forgets things already learned. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_66', "Is good at planning ahead. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_67', "Seems tired; has low energy. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_68', "Gets into trouble with the police. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_69', "Does not seem to listen to what is being said to him/her. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_70', "Is selfish and self-centered with others. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_71', "Actively refuses to do what adults tell him/her to do. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_72', "Cannot grasp arithmetic. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_73', "Does not follow through on instructions (even when he/she understands and is trying to cooperate). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_74', "Interacts well with other children. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_75', "Cries often and easily. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_76', "Has difficulty waiting for his/her turn. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_77', "Fidgeting. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_78', "Is constantly moving. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_79', "Worries about many things. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_80', "Has poor social skills. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_81', "Is happy, cheerful, and has a positive attitude. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_82', "Has trouble controlling his/her worries. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_83', "Talks non-stop. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_84', "Demands must be met immediately - easily frustrated. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_85', "Does not seem to worry for misbehaving. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_86', "Gets bored. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_87', "Appears 'on edge', nervous, or jumpy. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_88', "Is forgetful in daily activities. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_89', "Does not know how to make friends. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_90', "Has broken into someone else's house, building, or car. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_91', "Gets up and moves around during lessons. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_92', "Loses things (e.g., schoolwork, pencils, books, tools, and toys). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_93', "Is difficult to please or amuse. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_94', "Needs extra explanation of instructions. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_95', "Feels worthless. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_96', "Gets into trouble with teachers or school principals. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_97', "Has trouble concentrating. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_98', "Bullies, threatens, or scares others. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_99', "Needs help to break a complex task into smaller, more manageable pieces. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_100', "Inattentive, easily distracted. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_101', "I cannot figure out what makes him/her happy. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_102', "Acts in sneaky or manipulative ways. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_103', "Has difficulty organizing tasks or activities. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_104', "Is one of the last to be picked for teams or games. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_105', "Intentionally starts fights with others. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_106', "Forgets to turn in completed work. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_107', "Is fun to be around. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_108', "Has trouble changing from one task to another. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_109', "Behaves like an angel. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_110', "Is hard to motivate (even with highly desirable rewards). ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_111', "Has trouble keeping his/her mind on work or play for long. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_112', "The student's problems seriously affect schoolwork or grades. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'con_t_113', "The student's problems seriously affect friendships and relationships. ", array(''=>'', '0'=>"0 = Not true at all (Never", '1'=>"1 = Just  a little true (Occasionally)", '2'=>"2 = Pretty much true (Often", '3'=>"3 = Very much true (Very often", 'not_answered'=>'Not Answered'));
        $this->addTextAreaElement('con_t_114',"Do you have any other concerns about this student? ");
        $this->addTextAreaElement('con_t_115',"What strengths or skills does this student have? ");
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
            'con_t_in' => null,
            'con_t_hy' => null,
            'con_t_le' => null,
            'con_t_lp' => null,
            'con_t_ef' => null,
            'con_t_ag' => null,
            'con_t_pr' => null,
            'con_t_gi' => null,
            'con_t_an' => null,
            'con_t_ah' => null,
            'con_t_cd' => null,
            'con_t_od' => null,
            'con_t_pi' => null,
            'con_t_ni' => null,
            'con_t_in_t' => null,
            'con_t_hy_t' => null,
            'con_t_le_t' => null,
            'con_t_ag_t' => null,
            'con_t_pr_t' => null,
            'con_t_an_symptoms' => null,
            'con_t_ah_symptoms' => null,
            'con_t_cd_symptoms' => null,
            'con_t_od_symptoms' => null,
            'con_t_inconsistency_a' => null,
            'con_t_inconsistency_b' => null,
            'con_t_probability' => null,
        );

        $in_questions = array(
            'con_t_3' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_37' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_41' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_44' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_60' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_86' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_97' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_100' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_108' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_111' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $hy_questions = array(
            'con_t_1' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_2' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_4' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_7' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_9' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_13' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_17' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_24' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_26' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_29' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_32' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_39' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_50' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_76' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_77' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_78' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_83' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_91' => array(0=>0, 1=>1, 2=>2, 3=>3),

        );
        $le_questions = array(
            'con_t_6' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_11' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_12' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_16' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_18' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_20' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_25' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_45' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_52' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_63' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_65' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_66' => array(0=>3, 1=>2, 2=>1, 3=>0),
            'con_t_72' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_94' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_99' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_106' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $lp_questions = array(
            'con_t_12' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_45' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_52' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_63' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_65' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_72' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $ef_questions = array(
            'con_t_6' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_11' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_16' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_20' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_25' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_66' => array(0=>3, 1=>2, 2=>1, 3=>0),
            'con_t_106' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $ag_questions = array(
            'con_t_8' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_10' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_35' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_38' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_40' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_43' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_47' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_51' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_59' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_62' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_68' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_70' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_71' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_85' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_96' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_98' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_102' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_105' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $pr_questions = array(
            'con_t_19' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_34' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_42' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_74' => array(0=>3, 1=>2, 2=>1, 3=>0),
            'con_t_80' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_89' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_104' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $gi_questions = array(
            'con_t_7' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_13' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_22' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_25' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_46' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_48' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_75' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_77' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_84' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_100' => array(0=>0, 1=>1, 2=>2, 3=>3),

        );
        $an_questions = array(
            'con_t_23' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_37' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_57' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_60' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_69' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_73' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_88' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_93' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_103' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_111' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $ah_questions = array(
            'con_t_1' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_4' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_7' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_9' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_17' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_24' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_29' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_32' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_50' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_76' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_78' => array(0=>0, 1=>1, 2=>2, 3=>3),

        );
        $cd_questions = array(
            'con_t_10' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_14' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_21' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_27' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_31' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_33' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_35' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_40' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_54' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_61' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_90' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_98' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_105' => array(0=>0, 1=>1, 2=>2, 3=>3),
        );
        $od_questions = array(
            'con_t_38' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_47' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_51' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_56' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_59' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_62' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_64' => array(0=>0, 1=>1, 2=>2, 3=>3),
            'con_t_71' => array(0=>0, 1=>1, 2=>2, 3=>3),

        );
        $pi_questions = array(
            'con_t_15' => array(0=>0, 1=>0, 2=>0, 3=>1),
            'con_t_28' => array(0=>0, 1=>0, 2=>0, 3=>1),
            'con_t_30' => array(0=>1, 1=>0, 2=>0, 3=>0),
            'con_t_36' => array(0=>1, 1=>0, 2=>0, 3=>0),
            'con_t_55' => array(0=>0, 1=>0, 2=>0, 3=>1),
            'con_t_109' => array(0=>0, 1=>0, 2=>0, 3=>1),

        );
        $ni_questions = array(
            'con_t_5' => array(0=>0, 1=>0, 2=>1, 3=>1),
            'con_t_81' => array(0=>1, 1=>1, 2=>0, 3=>0),
            'con_t_93' => array(0=>0, 1=>0, 2=>1, 3=>1),
            'con_t_101' => array(0=>0, 1=>0, 2=>1, 3=>1),
            'con_t_107' => array(0=>1, 1=>1, 2=>0, 3=>0),
            'con_t_110' => array(0=>0, 1=>0, 2=>1, 3=>1),

        );
        
        foreach(array_keys($in_questions) as $question) {
            $answer = $record[$question];
            $value = $in_questions[$question][$answer];
			$scores['con_t_in'] += $value;
		}

        foreach(array_keys($hy_questions) as $question) {
            $answer = $record[$question];
            $value = $hy_questions[$question][$answer];
			$scores['con_t_hy'] += $value;
		}

        foreach(array_keys($le_questions) as $question) {
            $answer = $record[$question];
            $value = $le_questions[$question][$answer];
			$scores['con_t_le'] += $value;
		}

        foreach(array_keys($lp_questions) as $question) {
            $answer = $record[$question];
            $value = $lp_questions[$question][$answer];
			$scores['con_t_lp'] += $value;
		}

        foreach(array_keys($ef_questions) as $question) {
            $answer = $record[$question];
            $value = $ef_questions[$question][$answer];
			$scores['con_t_ef'] += $value;
		}

        foreach(array_keys($ag_questions) as $question) {
            $answer = $record[$question];
            $value = $ag_questions[$question][$answer];
			$scores['con_t_ag'] += $value;
		}

        foreach(array_keys($pr_questions) as $question) {
            $answer = $record[$question];
            $value = $pr_questions[$question][$answer];
			$scores['con_t_pr'] += $value;
		}

        foreach(array_keys($gi_questions) as $question) {
            $answer = $record[$question];
            $value = $gi_questions[$question][$answer];
			$scores['con_t_gi'] += $value;
		}

        foreach(array_keys($an_questions) as $question) {
            $answer = $record[$question];
            $value = $an_questions[$question][$answer];
			$scores['con_t_an'] += $value;
            if ($question != 'con_t_73' and $question != 'con_t_57') {
                if ($value >= 2) {
                    $scores['con_t_an_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con_t_an_symptoms'] += 0;
                }
            }
		}
        if ($an_questions['con_t_73'][$record['con_t_73']] >= 2 and $an_questions['con_t_57'][$record['con_t_57']] >= 2) {
            $scores['con_t_an_symptoms'] += 1;
        }

        foreach(array_keys($ah_questions) as $question) {
            $answer = $record[$question];
            $value = $ah_questions[$question][$answer];
			$scores['con_t_ah'] += $value;
            if ($question != 'con_t_24' and $question != 'con_t_7' and $question != 'con_t_17' and $question != 'con_t_78') {
                if ($value >= 2) {
                    $scores['con_t_ah_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con_t_ah_symptoms'] += 0;
                }
            }
		}
        if ($ah_questions['con_t_24'][$record['con_t_24']] >= 1 or $ah_questions['con_t_7'][$record['con_t_7']] >= 1) {
            $scores['con_t_ah_symptoms'] += 1;
        }
        if ($ah_questions['con_t_17'][$record['con_t_17']] >= 1 or $ah_questions['con_t_78'][$record['con_t_78']] >= 1) {
            $scores['con_t_ah_symptoms'] += 1;
        }

        foreach(array_keys($cd_questions) as $question) {
            $answer = $record[$question];
            $value = $cd_questions[$question][$answer];
			$scores['con_t_cd'] += $value;

            if ($question != 'con_t_40') {
                if ($value >= 1) {
                    $scores['con_t_cd_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con_t_cd_symptoms'] += 0;
                }
            }
		}
        if ($cd_questions['con_t_40'][$record['con_t_40']] >= 2) {
            $scores['con_t_cd_symptoms'] += 1;
        }

        foreach(array_keys($od_questions) as $question) {
            $answer = $record[$question];
            $value = $od_questions[$question][$answer];
			$scores['con_t_od'] += $value;
		
            if ($question != 'con_t_47' and $question != 'con_t_59') {
                if ($value >= 2) {
                    $scores['con_t_od_symptoms'] += 1;
                } elseif ($answer != null) {
                    $scores['con_t_od_symptoms'] += 0;
                }
            }
		}
        if ($od_questions['con_t_47'][$record['con_t_47']] >= 1) {
            $scores['con_t_od_symptoms'] += 1;
        }
        if ($od_questions['con_t_59'][$record['con_t_59']] >= 1) {
            $scores['con_t_od_symptoms'] += 1;
        }

        foreach(array_keys($pi_questions) as $question) {
            $answer = $record[$question];
            $value = $pi_questions[$question][$answer];
			$scores['con_t_pi'] += $value;
		}

        foreach(array_keys($ni_questions) as $question) {
            $answer = $record[$question];
            $value = $ni_questions[$question][$answer];
			$scores['con_t_ni'] += $value;
		}

        $inconsistency = array(
            abs($record['con_t_97'] - $record['con_t_100']),
            abs($record['con_t_52'] - $record['con_t_63']),
            abs($record['con_t_4'] - $record['con_t_77']),
            abs($record['con_t_7'] - $record['con_t_13']),
            abs($record['con_t_26'] - $record['con_t_29']),
            abs($record['con_t_98'] - $record['con_t_105']),
            abs($record['con_t_25'] - $record['con_t_57']),
            abs($record['con_t_23'] - $record['con_t_44']),
            abs($record['con_t_34'] - $record['con_t_89']),
            abs($record['con_t_47'] - $record['con_t_71']),
        );

        foreach($inconsistency as $item) {
            if ($item >= 2) {
                $scores['con_t_inconsistency_b'] += 1;
            } else {
                $scores['con_t_inconsistency_b'] += 0;
            }
            $scores['con_t_inconsistency_a'] += $item;
        }


        $transposed = array(
            'con_t_4' => array(0=>0, 1=>0, 2=>1, 3=>2),
            'con_t_7' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_13' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_23' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_44' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_57' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_60' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_69' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_97' => array(0=>0, 1=>0, 2=>2, 3=>2),
            'con_t_100' => array(0=>0, 1=>0, 2=>2, 3=>2),
        );
        $total_transposed = 0;
        $probability = array(
            0 => 19,
            1 => 39,
            2 => 51,
            3 => 52,
            4 => 58,
            5 => 64,
            6 => 69,
            7 => 73,
            8 => 77,
            9 => 81,
            10 => 84,
            11 => 87,
            12 => 89,
            13 => 91,
            14 => 92,
            15 => 93,
            16 => 95,
            17 => 96,
            18 => 97,
            19 => 98,
            20 => 99,
        );

        foreach(array_keys($transposed) as $question) {
            $total_transposed += $transposed[$question][$record[$question]];
        }

        $scores['con_t_probability'] = $probability[$total_transposed];

        if($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $candidate   = \NDB_Factory::singleton()->candidate(
                $timepoint->getCandID()
            );
            $sex = $candidate->getCandidateSex();
            $dob = $timepoint->getEffectiveDateOfBirth();
            $age = Utility::calculateAge($dob, $timepoint->getDateOfVisit());
        }
        $scores['con_t_in_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"teacher", "s"=>$sex, "a"=>$age['year'], "att"=>"in", "sc"=>$scores["con_t_in"] ))["t_score"];
        $scores['con_t_hy_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"teacher", "s"=>$sex, "a"=>$age['year'], "att"=>"hy", "sc"=>$scores["con_t_hy"] ))["t_score"];
        $scores['con_t_le_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"teacher", "s"=>$sex, "a"=>$age['year'], "att"=>"le", "sc"=>$scores["con_t_le"] ))["t_score"];
        $scores['con_t_ag_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"teacher", "s"=>$sex, "a"=>$age['year'], "att"=>"ag", "sc"=>$scores["con_t_ag"] ))["t_score"];
        $scores['con_t_pr_t'] = $db->pselectRow("SELECT t_score FROM conners3_lookup WHERE version=:v AND sex=:s AND age=:a AND attribute=:att AND score=:sc",array("v" =>"teacher", "s"=>$sex, "a"=>$age['year'], "att"=>"pr", "sc"=>$scores["con_t_pr"] ))["t_score"];

        // save the scores
        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }

}

?>