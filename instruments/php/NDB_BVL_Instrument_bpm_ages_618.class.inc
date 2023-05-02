<?php

/**
 * This file contains the NDB_BVL_Instrument_bpm_ages_618
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_bpm_ages_618 extends NDB_BVL_Instrument
{
    // use \LorisFormDictionaryImpl;
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

        $this->page = $page;            
        /* page label (number or string - used by user-defined child classes) */

        // set the object properties
        $this->testName = 'bpm_ages_618' ;           // test_names.Test_name
        $this->table = 'bpm_ages_618';              // name of database table corresponding to instrument
        // FULL NAME: bpm_ages_618
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
        $this->addHeader("Brief Problem Monitor (BPM) - Ages 6-18 ");

        $this->form->addElement('select', 'bpmt_q1', "Acts too young for his/her age.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q2', "Argues a lot.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q3', "Fails to finish things he/she starts.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q4', "Can&#39;t concentrate, can&#39;t pay attention for long.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q5', "Can&#39;t sit still, restless, or hyperactive.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q6', "Destroys property belonging to others.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q7', "Disobedient at school.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q8', "Feels worthless or inferior.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q9', "Impulsive or acts without thinking.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q10', "Too fearful or anxious.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q11', "Feels too guilty.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q12', "Self-conscious or easily embarrassed.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q13', "Inattentive or easily distracted.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q14', "Stubborn, sullen, or irritable.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q15', "Temper tantrums or hot temper.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q16', "Threatens people.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q17', "Unhappy, sad, or depressed.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
        $this->form->addElement('select', 'bpmt_q18', "Worries.", array("" => "","0" => "Not True (as far as you know)","1" => "Somewhat True","2" => "Very True") );
    }


}

?>