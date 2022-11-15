<?php

class NDB_BVL_Instrument_adhd_rs_home extends NDB_BVL_Instrument
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
        $this->testName = 'adhd_rs_home' ;           // test_names.Test_name
        $this->table = 'adhd_rs_home';              // name of database table corresponding to instrument
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
        // display test name
        $this->addHeader("Attention and Behavior Rating form, Home Version: Child");

        $this->addHeader("Calculated Fields");

        $this->addHeader("<h3>Totals</h3>");
        $this->form->addElement("static", "adhd_rs_home_total", "Total Score");
        $this->form->addElement("static", "adhd_rs_home_total_t", "<p style='background-color:silver'>Total T-Score</p>");

        $this->addHeader("<h3>Inattention</h3>");
        $this->form->addElement("static", "adhd_rs_home_inattention_total", "Inattention Total Score");
        $this->form->addElement("static", "adhd_rs_home_inattention_symptoms", "Inattention Symptoms");
        $this->form->addElement("static", "adhd_rs_home_inattention_t", "<p style='background-color:silver'>Inattention T-Score</p>");
        
        $this->addHeader("<h3>Hyperactivity</h3>");
        $this->form->addElement("static", "adhd_rs_home_hyperactivity_total", "Hyperactivity Total Score");
        $this->form->addElement("static", "adhd_rs_home_hyperactivity_symptoms", "Hyperactivity Symptoms");
        $this->form->addElement("static", "adhd_rs_home_hyperactivity_t", "<p style='background-color:silver'>Hyperactivity T-Score</p>");

        $this->addHeader("<h3>Questions");        
        $this->addHeader("<h3>Inattention</h3>");
        $this->form->addElement('select', 'adhd_rs_home_q1', "Fails to give close attention to details or makes careless mistakes in schoolwork or during other activities ", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q2', "Has difficulty sustaining attention in tasks or play activities", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q3', "Does not seem to listen when spoken to directly", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q4', "Does not follow through on instructions and fails to finish schoolwork or chores", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q5', "Has difficulty organizing tasks and activities", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q6', "Avoids, dislikes, or is reluctant to engage in tasks that require sustained mental effort (e.g., schoolwork or homework)", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q7', "Loses things necessary for tasks or activities (e.g., school materials, pencils, books, eyeglasses)", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q8', "Easily distracted", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q9', "Forgetful in daily activities (e.g., doing chores)", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->addHeader("<h4>Inattention Impairment</h4>");
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_1', "Getting along with family members ", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_2', "Getting along with other children ", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_3', "Completing or returning homework", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_4', "Performing academically in school", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_5', "Controlling behavior in school", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_6', "Feeling good about himself/herself", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        
        $this->addHeader("<h3>Hyperactivity</h3>");
        $this->form->addElement('select', 'adhd_rs_home_q10', "Fidgets or taps hands or feet or squirms in seat ", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q11', "Leaves seat in situations when remaining seated is expected", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q12', "Runs about or climbs in situations where it is inappropriate", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q13', "Unable to play or engage in leisure activities quietly", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q14', "'On the go' acts as if 'driven by a motor'", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q15', "Talks excessively", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q16', "Blurts out an answer before a question has been completed", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q17', "Has difficulty waiting his or her turn (e.g., while waiting in line)", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_q18', "Interrupts or intrudes on others", array(''=>'', '0'=>"0 = Never or Rarely", '1'=>"1 = Sometimes", '2'=>"2 = Often", '3'=>"3 = Very Often", 'not_answered'=>'Not Answered'));
        $this->addHeader("<h4>Hyperactivity Impairment</h4>");
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_7', "Getting along with family members ", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_8', "Getting along with other children ", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_9', "Completing or returning homework", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_10', "Performing academically in school", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_11', "Controlling behavior in school", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'adhd_rs_home_problem_severity_12', "Feeling good about himself/herself", array(''=>'', '0'=>"0 = No Problem", '1'=>"1 = Minor Problem", '2'=>"2 = Moderate Problem", '3'=>"3 = Severe Problem", 'not_answered'=>'Not Answered'));
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
            'adhd_rs_home_inattention_total' => null,
            'adhd_rs_home_inattention_symptoms' => null,
            'adhd_rs_home_inattention_t' => null,
            'adhd_rs_home_hyperactivity_total' => null,
            'adhd_rs_home_hyperactivity_symptoms' => null,
            'adhd_rs_home_hyperactivity_t' => null,
        );
        
        $inattention_scores = array('adhd_rs_home_q1', 'adhd_rs_home_q2', 'adhd_rs_home_q3', 'adhd_rs_home_q4', 'adhd_rs_home_q5', 'adhd_rs_home_q6', 'adhd_rs_home_q7', 'adhd_rs_home_q8', 'adhd_rs_home_q9');
        $hyperactivity_scores = array('adhd_rs_home_q10', 'adhd_rs_home_q11', 'adhd_rs_home_q12', 'adhd_rs_home_q13', 'adhd_rs_home_q14', 'adhd_rs_home_q15', 'adhd_rs_home_q16', 'adhd_rs_home_q17', 'adhd_rs_home_q18');

        foreach($hyperactivity_scores as $question) {
            $value = $record[$question];
			$scores['adhd_rs_home_hyperactivity_total'] += $value;
            if ($value >= 2) {
                $scores["adhd_rs_home_hyperactivity_symptoms"] += 1;
            } else {
                $scores["adhd_rs_home_hyperactivity_symptoms"] += 0;
            }
		}

        foreach($inattention_scores as $question) {
            $value = $record[$question];
			$scores['adhd_rs_home_inattention_total'] += $value;
            if ($value >= 2) {
                $scores["adhd_rs_home_inattention_symptoms"] += 1;
            } else {
                $scores["adhd_rs_home_inattention_symptoms"] += 0;
            }
		}

        if($this->getSessionID() != NULL) {
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $candidate   = \NDB_Factory::singleton()->candidate(
                $timepoint->getCandID()
            );
            $sex = $candidate->getCandidateSex()->value;
        }

        $inatt_normative_means = array(
            'Female' => 4.79,
            'Male' => 5.74,
        );
        $inatt_normative_stand_devs = array(
            'Female' => 5.24,
            'Male' => 5.40,
        );

        $hyper_normative_means = array(
            'Female' => 3.38,
            'Male' => 4.48,
        );
        $hyper_normative_stand_devs = array(
            'Female' => 4.25,
            'Male' => 5.58,
        );

        $total_normative_means = array(
            'Female' => 8.17,
            'Male' => 10.21,
        );
        $total_normative_stand_devs = array(
            'Female' => 8.65,
            'Male' => 10.20,
        );

        $scores['adhd_rs_home_inattention_t'] = intval((($scores["adhd_rs_home_inattention_total"] - $inatt_normative_means[$sex]) / $inatt_normative_stand_devs[$sex]) * 10 + 50);
        $scores['adhd_rs_home_hyperactivity_t'] = intval((($scores["adhd_rs_home_hyperactivity_total"] - $hyper_normative_means[$sex]) / $hyper_normative_stand_devs[$sex]) * 10 + 50);

        $scores['adhd_rs_home_total'] = $scores['adhd_rs_home_inattention_total'] + $scores["adhd_rs_home_hyperactivity_total"];
        $scores['adhd_rs_home_total_t'] = intval((($scores["adhd_rs_home_total"] - $total_normative_means[$sex]) / $total_normative_stand_devs[$sex]) * 10 + 50);

        // save the scores
        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }

}

?>