<?php

/**
 * This file contains the NDB_BVL_Instrument_pss
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_pss extends NDB_BVL_Instrument
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
        $this->testName = 'pss' ;           // test_names.Test_name
        $this->table = 'pss';              // name of database table corresponding to instrument
        // FULL NAME: pss
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
        $this->addHeader("Perceived Stress Scale (PSS)");

        $this->form->addElement('select', 'perceived_stress_scale_1', "In the last month, how often have you been upset because of something that happened unexpectedly? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_2', "In the last month, how often have you felt that you were unable to control the important things in your life? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_3', "In the last month, how often have you felt nervous and &#34;stressed&#34;? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_4', "In the last month, how often have you felt confident about your ability to handle your personal problems? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_5', "In the last month, how often have you felt that things were going your way? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_6', "In the last month, how often have you found that you could not cope with all the things you had to do?", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_7', "In the last month, how often have you been able to control irritations in your life? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_8', "In the last month, how often have you felt that you were on top of things? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_9', "In the last month, how often have you been angered because of things that were outside of your control? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
        $this->form->addElement('select', 'perceived_stress_scale_10', "In the last month, how often have you felt difficulties were piling up so high that you could not overcome them? ", array("" => "","0" => "0 = Never","1" => "1 = Almost Never","2" => "2 = Sometimes","3" => "3 = Fairly Often","4" => "4 = Very Often") );
    }


}

?>