<?php

class NDB_BVL_Instrument_cdi_2_child extends NDB_BVL_Instrument
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
        $this->testName = 'cdi_2_child' ;           // test_names.Test_name
        $this->table = 'cdi_2_child';              // name of database table corresponding to instrument
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
        // display test name
        $this->addHeader("CDI2 Self-Report Short");

        $this->addHeader("Calculated Fields");
        $this->form->addElement('static','cdi_total',"Total Score");
        $this->form->addElement('static','cdi_t',"T-Score");

        $this->addHeader("Questions");

        $this->form->addElement('static','',"<div class='rich-text-field-label'><p><span style='font-weight: normal;'>Kids sometimes have different feelings and ideas.</span><br /><br /><span style='font-weight: normal;'>This form lists the feelings and ideas in groups. From each group of three sentences, pick </span>one<span style='font-weight: normal;'> sentence that describes you best for the </span>past two weeks<span style='font-weight: normal;'>. After you pick a sentence from the first group, go on to the next group.</span></p> <p><span style='font-weight: normal;'>There is no right or wrong answer. Just pick the sentence that best desribes the way you have been recently. Put a mark next to your answer. Put the mark in the circle next to the sentence that you pick.</span></p></div>");
        $this->form->addElement('select', 'cdi_1', "Item 1", array(''=>'', '1'=>"I am sad once in a while.", '2'=>"I am sad many times.", '3'=>"I am sad all the time."));
        $this->form->addElement('select', 'cdi_2', "Item 2", array(''=>'', '1'=>"Nothing will ever work out for me.", '2'=>"I am not sure if things will work out for me.", '3'=>"Things will work out for me O.K."));
        $this->form->addElement('select', 'cdi_3', "Item 3", array(''=>'', '1'=>"I do most things O.K.", '2'=>"I do many things wrong.", '3'=>"I do everything wrong."));
        $this->form->addElement('select', 'cdi_4', "Item 4", array(''=>'', '1'=>"I have fun in many things.", '2'=>"I have fun in some things.", '3'=>"Nothing is fun at all"));
        $this->form->addElement('select', 'cdi_5', "Item 5", array(''=>'', '1'=>"I am important to my family.", '2'=>"I am not sure if I am important to my family.", '3'=>"My family is better off without me."));
        $this->form->addElement('select', 'cdi_6', "Item 6", array(''=>'', '1'=>"I hate myself.", '2'=>"I do not like myself.", '3'=>"I like myself."));
        $this->form->addElement('select', 'cdi_7', "Item 7", array(''=>'', '1'=>"I feel cranky all the time.", '2'=>"I feel cranky many times.", '3'=>"I am almost never cranky."));
        $this->form->addElement('select', 'cdi_8', "Item 8", array(''=>'', '1'=>"I cannot make up my mind about things.", '2'=>"It is hard to make up my mind about things.", '3'=>"I make up my mind about things easily."));
        $this->form->addElement('select', 'cdi_9', "Item 9", array(''=>'', '1'=>"I have to push myself all the time to do my schoolwork.", '2'=>"I have to push myself many times to do my schoolwork.", '3'=>"Doing schoolwork is not a big problem."));
        $this->form->addElement('select', 'cdi_10', "Item 10", array(''=>'', '1'=>"I am tired once in a while.", '2'=>"I am tired many days.", '3'=>"I am tired all the time."));
        $this->form->addElement('select', 'cdi_11', "Item 11", array(''=>'', '1'=>"Most days I do not feel like eating.", '2'=>"Many days I do not feel like eating.", '3'=>"I eat pretty well."));
        $this->form->addElement('select', 'cdi_12', "Item 12", array(''=>'', '1'=>"I do not feel alone.", '2'=>"I feel alone many times.", '3'=>"I feel alone all the time."));
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
            'cdi_total' => null,
            'cdi_t' => null,
        );
        
        $forward_scores = array('cdi_1', 'cdi_3', 'cdi_4', 'cdi_5', 'cdi_10', 'cdi_12');
        $reverse_scores = array('cdi_2', 'cdi_6', 'cdi_7', 'cdi_8', 'cdi_9', 'cdi_11');

        foreach($forward_scores as $question) {
            $value = $record[$question] -1;
			$scores['cdi_total'] += $value;
		}

        foreach($reverse_scores as $question) {
            $value = $record[$question] -1;
            $score = 2 - $value;
            $scores['cdi_total'] += $score;
        }

        if($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $candidate   = \NDB_Factory::singleton()->candidate(
                $timepoint->getCandID()
            );
            $sex = $candidate->getCandidateSex();
        }

        $female_tscores = array( 0=>40, 1=>44, 2=>48, 3=>52, 4=>56, 5=>60, 6=>63, 7=>67, 8=>71, 9=>75, 10=>79, 11=>83, 12=>87, 13=>90 );
        $male_tscores = array( 0=>0, 1=>44, 2=>47, 3=>50, 4=>54, 5=>57, 6=>61, 7=>64, 8=>67, 9=>71, 10=>74, 11=>78, 12=>81, 13=>84, 14=>88, 15=>90);

        if($sex == 'Male') {
            $scores["cdi_t"] = $male_tscores[$scores["cdi_total"]];
        } elseif($sex == 'Female') {
            $scores["cdi_t"] = $female_tscores[$scores["cdi_total"]];
        }
        
        // save the scores
        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }

}

?>