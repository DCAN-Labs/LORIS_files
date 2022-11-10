<?php

class NDB_BVL_Instrument_cars2_hf extends NDB_BVL_Instrument
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
        $this->testName = 'cars2_hf' ;           // test_names.Test_name
        $this->table = 'cars2_hf';              // name of database table corresponding to instrument
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
        $this->addHeader("Childhood Autism Rating Scale, Second Edition - High-Functioning Version");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addHeader("Summary");
            $this->form->addElement('text','total_raw_score',"Total Raw Score");
        $this->form->addElement('select', 'severity_group', "nan", array(''=>'', 'minimal'=>"Minimal-to-No Symptoms of Autism Specturm Disorder (15-27.5)", 'moderate'=>"Mild-to-Moderate Symptoms of Autism Specturm Disorder (28-33.5)", 'severe'=>"Severe Symptoms of Autism Spectrum Disorder (34 and higher)", 'not_answered'=>'Not Answered'));
            $this->form->addElement('text','tscore',"nan");
            $this->form->addElement('text','percentile',"nan");
    }


    function _page1()
    {
        $this->addHeader("Category Scores");
        $this->form->addElement('select', 'cat01', "1. Social-Emotional Understanding", array(''=>'', '1'=>"1 - Age-appropriate social-emotional understanding", '1.5'=>"1.5", '2'=>"2 - Mildly impaired social-emotional understanding", '2.5'=>"2.5", '3'=>"3 - Moderately impaired social-emotional understanding", '3.5'=>"3.5", '4'=>"4 - Severely impaired social-emotional understanding", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat02', "2. Emotional Expression and Regulation of Emotions", array(''=>'', '1'=>"1 - Age-appropriate and situation-appropriate emotional response", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal emotional response", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal emotional response", '3.5'=>"3.5", '4'=>"4 - Severely abnormal emotional response", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat03', "3. Relating to People", array(''=>'', '1'=>"1 - No evidence of difficulty or abnormality in relating to people", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal relationships", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal relationships", '3.5'=>"3.5", '4'=>"4 - Severely abnormal realtionships", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat04', "4. Body Use", array(''=>'', '1'=>"1 - Age-appropriate body use", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal body use", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal body use", '3.5'=>"3.5", '4'=>"4 - Severely abnormal body use", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat05', "5. Object Use in Play", array(''=>'', '1'=>"1 - Appropriate interest in, and creative use of, toys and other objects", '1.5'=>"1.5", '2'=>"2 - Mildly inappropriate interest in, or user of, toys and other objects", '2.5'=>"2.5", '3'=>"3 - Moderately inappropriate interest in, or use of, toys and other objects", '3.5'=>"3.5", '4'=>"4 - Severely inappropriate interest in, or use of, toys and other objects", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat06', "6. Adaptation to Change/Restricted Interests", array(''=>'', '1'=>"1 - Age-appropriate response to change/variety of interests", '1.5'=>"1.5", '2'=>"2- Mildly abnormal adaptation to change/variety of interests", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal adaptation to change/variety of interests", '3.5'=>"3.5", '4'=>"4 - Severely abnormal adaptation to change/variety of interests", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat07', "7. Visual Response", array(''=>'', '1'=>"1 - Age-appropriate visual response", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal visual response", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal visual response", '3.5'=>"3.5", '4'=>"4 - Severely abnormal visual response", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat08', "8. Listening Response", array(''=>'', '1'=>"1 - Age-appropriate listening response", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal listening response", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal listening response", '3.5'=>"3.5", '4'=>"4 - Severely abnormal listening response", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat09', "9. Taste, Smell, and Touch Response and Use", array(''=>'', '1'=>"1 - Normal use of, and response to taste smell and touch", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal use of, and response to taste smell and touch", '2.5'=>"2.5", '3'=>"3 - Moderately use of, and response to taste smell and touch", '3.5'=>"3.5", '4'=>"4 - Severely abnormal use of, and response to taste smell and touch", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat10', "10. Fear or Anxiety", array(''=>'', '1'=>"1 - Normal fear or anxiety", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal fear anxiety", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal fear anxiety", '3.5'=>"3.5", '4'=>"4 - Severely abnormal fear anxiety", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat11', "11. Verbal Communication", array(''=>'', '1'=>"1 - Normal verbal communication, age and situation appropriate", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal verbal communication", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal verbal communication", '3.5'=>"3.5", '4'=>"4 - Severely abnormal verbal communication", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat12', "12. Nonverbal Communication", array(''=>'', '1'=>"1 - Normal nonverbal communication, age and situation approprite", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal use of nonverbal communication", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal use of nonverbal communication", '3.5'=>"3.5", '4'=>"4 - Severely abnormal use of nonverbal communication", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat13', "13. Thinking/Cognitive Integration Skills", array(''=>'', '1'=>"1 - Age-appropriate thinking/cognitive integration skills", '1.5'=>"1.5", '2'=>"2 - Mildly impared in specific thinking/cognitive integration skills", '2.5'=>"2.5", '3'=>"3 - Moderately impared in specific thinking/cognitive integration skills", '3.5'=>"3.5", '4'=>"4 - Severe delay in thinking/cognitive integration skills", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat14', "14. Level and Consistency of Intellectual Response", array(''=>'', '1'=>"1 - Intelligence is at least normal and reasonably consistent across various areas", '1.5'=>"1.5", '2'=>"2 - Mildly abnormal intellectual functioning", '2.5'=>"2.5", '3'=>"3 - Moderately abnormal intellectual functioning", '3.5'=>"3.5", '4'=>"4 - Severely abnormal intellectual functioning", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'cat15', "15. General Impressions", array(''=>'', '1'=>"1 - No autism spectrum disorder", '1.5'=>"1.5", '2'=>"2 - Mild autism spectrum disorder", '2.5'=>"2.5", '3'=>"3 - Moderate autism spectrum disorder", '3.5'=>"3.5", '4'=>"4 - Severe autism specturm disorder", 'not_answered'=>'Not Answered'));
    }


}

?>