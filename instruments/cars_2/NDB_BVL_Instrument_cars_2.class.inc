<?php

class NDB_BVL_Instrument_cars_2 extends NDB_BVL_Instrument
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
        $this->testName = 'cars_2' ;           // test_names.Test_name
        $this->table = 'cars_2';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array(
            "cars_2_test_date","form_completed_cars2"
        );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // Get the subject age in months for scoring

        $db =& Database::singleton();
        // required fields for data entry completion status
        $this->_requiredElements = array(
            
        );

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
        $this->addHeader("Childhood Autism Rating Scale, Second Edition");

        $this->addBasicDate('cars_2_test_date', "Test Date:");
        $this->form->addElement('text','cars_2_raters_name',"Rater's Name:");
        $this->form->addElement('text','cars_2_partic_age_yr',"Age (years):");
        $this->form->addElement('select', 'cars_2_socio_emo', "1. Social-Emotional Understanding", array(''=>'', '1'=>"1 - Age-appropriate social-emotional understanding", '1.5'=>"1.5", '2'=>"2 - Mildly impaired social-emotional understanding", '2.5'=>"2.5", '3'=>"3 - Moderately impaired social-emotional understanding", '3.5'=>"3.5", '4'=>"4 - Severely impaired social-emotional understanding", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_emo_exp_reg', "2. Emotional Expression and Regulation of Emotions", array(''=>'', '1'=>"1 - Age-appropriate and situation-appropriate emotional response", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal emotional response", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal emotional response", '3.5'=>"3.5", '4'=>"4 - Severely abnormal emotional response", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_relat_ppl', "3. Relating to People", array(''=>'', '1'=>"1 - No evidence of difficulty or abnormality in relating to people", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal relationships", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal relationships", '3.5'=>"3.5", '4'=>"4 - Severely abnormal realtionships", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_bod_use', "4. Body Use", array(''=>'', '1'=>"1 - Age-appropriate body use", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal body use", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal body use", '3.5'=>"3.5", '4'=>"4 - Severely abnormal body use", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_obj_use_play', "5. Object Use in Play", array(''=>'', '1'=>"1 - Appropriate interest in, and creative use of, toys and other objects", '1.5'=>"1.5", '2'=>"2 - Mildly inappropriate interest in, or user of, toys and other objects", '2.5'=>"2.5", '3'=>"3 - Moderately inappropriate interest in, or use of, toys and other objects", '3.5'=>"3.5", '4'=>"4 - Severely inappropriate interest in, or use of, toys and other objects", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_adapt_change', "6. Adaptation to Change/Restricted Interests", array(''=>'', '1'=>"1 - Age-appropriate response to change/variety of interests", '1.5'=>"1.5", '2'=>"2- Mildly abnormal adaptation to change/variety of interests", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal adaptation to change/variety of interests", '3.5'=>"3.5", '4'=>"4 - Severely abnormal adaptation to change/variety of interests", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_vis_resp', "7. Visual Response", array(''=>'', '1'=>"1 - Age-appropriate visual response", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal visual response", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal visual response", '3.5'=>"3.5", '4'=>"4 - Severely abnormal visual response", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cars_2_listen_resp', "8. Listening Response", array(''=>'', '1'=>"1 - Age-appropriate listening response", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal listening response", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal listening response", '3.5'=>"3.5", '4'=>"4 - Severely abnormal listening response", 'not_answered'=>'Not Answered'));
        $this->form->addElement('text','cars_total',"Sum of fields");
        $this->form->addElement('text','form_completed_by',"Form completed by: ");
        $this->addBasicDate('form_completed_cars2', "Form completed on: ");

}


}

?>