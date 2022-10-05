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
        $this->addHeader("Attention and Behavior Rating form, Home Version: Child (English)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addHeader("Inattention");
            $this->form->addElement('static','inatt_raw',"Inattention Raw Score");
            $this->form->addElement('static','inatt_sx',"Inattention SX");
            $this->form->addElement('static','inatt_tscore',"Innatention T-Score");
        $this->addHeader("Hyperactivity");
            $this->form->addElement('static','hyp_raw',"Hyperactivity Raw Score");
            $this->form->addElement('static','hyp_sx',"Hyperactivity SX");
            $this->form->addElement('static','hyp_tscore',"Hyperactivity T-Score");
    }


    function _page1()
    {
        $this->addHeader("How often does your child display this behavior?");
        $this->form->addElement('select', 'q01', "Fails to give close attention to details or makes careless mistakes in schoolwork or during other activites", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q02', "Has difficulty sustaining attention in tasks or play activites", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q03', "Does not seem to listen when spoken to directly", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q04', "Does not follow through on instructions and fails to finish schoolwork or chores", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q05', "Has difficulty organizing tasks and activities", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q06', "Avoids, dislikes, or is reluctant to engage in tasks hat require sustained mental effort (e.g., schoolwork or homework)", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q07', "Loses things necessary for tasks or activities (e.g., school materials, pencils, books, eyeglasses)", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q08', "Easily distracted", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q09', "Forgetful in daily activities (e.g., doing chores)", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->addHeader("How often do the nine behaviors in the previous question cause problems for your child?");
        $this->form->addElement('select', 'q10', "Getting along with family members", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q11', "Getting along with other children", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q12', "Completing or returning homework", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q13', "Performing academically in school", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q14', "Controlling behavior in school", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q15', "Feeling good about herself/himself", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
    }


    function _page2()
    {
        $this->addHeader("How often does your child display this behavior?");
        $this->form->addElement('select', 'q16', "Fidgets or taps hands or feet or squirms in seat", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q17', "Leaves seat in situations when remaining seated is expected", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q18', "Runs about or climbs in situations where it is inappropirate", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q19', "Unable to play or engage in leisure activities quietly", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q20', "'On the go' acts as if 'driven by a motor'", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q21', "Talks excessively", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q22', "Blurts our an answer before a question has been completed", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q23', "Has difficulty waiting their turn (e.g., while waiting in line)", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q24', "Interrupts or intrudes on others", array(''=>'', '0'=>"Rarely", '1'=>"Sometimes", '2'=>"Often", '3'=>"Very Often", 'not_answered'=>'Not Answered'));
        $this->addHeader("How often do the nine behaviors in the previous question cause problems for your child?");
        $this->form->addElement('select', 'q25', "Getting along with family members", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q26', "Getting along with other children", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q27', "Completing or returning homework", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q28', "Performing academically in school", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q29', "Controlling behavior in school", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'q30', "Feeling good about herself/himself", array(''=>'', '0'=>"No Problem", '1'=>"Minor Problem", '2'=>"Moderate Problem", '3'=>"Severe Problem", 'not_answered'=>'Not Answered'));
    }


}

?>