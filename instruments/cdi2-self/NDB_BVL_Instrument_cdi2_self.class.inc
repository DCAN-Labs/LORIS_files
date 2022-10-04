<?php

class NDB_BVL_Instrument_cdi2_self extends NDB_BVL_Instrument
{
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
        $this->testName = 'cdi2_self' ;           // test_names.Test_name
        $this->table = 'cdi2_self';              // name of database table corresponding to instrument
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
        $this->addHeader("CDI2 Self-Report Short");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

            $this->addTextElement('cdi_total_raw',"Total Raw Score");
            $this->addTextElement('cdi_t_score',"T Score");
    }


    function _page1()
    {
        $this->form->addElement('select', 'cdi_item_1', "Item 1", array(''=>'', '0'=>"I am sad once in a while.", '1'=>"I am sad many times.", '2'=>"I am sad all the time.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_2', "Item 2", array(''=>'', '2'=>"Nothing will ever work out for me.", '1'=>"I am not sure if things will work out for me.", '0'=>"Things will work out for me O.K.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_3', "Item 3", array(''=>'', '0'=>"I do most things O.K.", '1'=>"I do many things wrong.", '2'=>"I do everything wrong", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_4', "Item 4", array(''=>'', '0'=>"I have fun in many things.", '1'=>"I have fun in some things.", '2'=>"Nothing is fun at all.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_5', "Item 5", array(''=>'', '0'=>"I am important to my family.", '1'=>"I am not sure if I am important to my family.", '2'=>"My family is better off without me.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_6', "Item 6", array(''=>'', '2'=>"I hate myself.", '1'=>"I do not like myself.", '0'=>"I like myself.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_7', "Item 7", array(''=>'', '2'=>"I feel cranky all the time.", '1'=>"I feel cranky many times.", '0'=>"I am almost never cranky.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_8', "Item 8", array(''=>'', '2'=>"I cannot make up my mind about things.", '1'=>"It is hard to make up my mind about things.", '0'=>"I make up my mind about things easily.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_9', "Item 9", array(''=>'', '2'=>"I have to push myself all the time to do my schoolwork.", '1'=>"I have to push myself many times to do my schoolwork.", '0'=>"Doing schoolwork is not a big problem.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_10', "Item 10", array(''=>'', '0'=>"I am tired once in a while.", '1'=>"I am tired many days.", '2'=>"I am tired all the time.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_11', "Item 11", array(''=>'', '2'=>"Most days I do not feel like eating.", '1'=>"Many days I do not feel like eating.", '0'=>"I eat pretty well.", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cdi_item_12', "Item 12", array(''=>'', '0'=>"I do not feel alone.", '1'=>"I feel alone many times.", '2'=>"I feel alone all the time.", 'not_answered'=>'Not Answered'));
    }


}

?>