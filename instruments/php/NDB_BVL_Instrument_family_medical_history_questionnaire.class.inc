<?php

/**
 * This file contains the NDB_BVL_Instrument_family_medical_history_questionnaire
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_family_medical_history_questionnaire extends NDB_BVL_Instrument
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
        $this->testName = 'family_medical_history_questionnaire' ;           // test_names.Test_name
        $this->table = 'family_medical_history_questionnaire';              // name of database table corresponding to instrument
        // FULL NAME: family_medical_history_questionnaire
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
        $this->addHeader("Family Medical History Questionnaire");

        $this->form->addElement('select', 'child_full_sibp', " How many total sisters and brothers does the child have who are FULL siblings (same biological mother and biological father as the child)?
", array("" => "","0" => "0","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","999" => "Other {child_full_sib_oth}") );
        $this->form->addElement('select', 'child_half_sib', "How many total sisters and brothers does the child have who are HALF siblings (same biological mother or father BUT NOT BOTH)?
", array("" => "","0" => "0","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","999" => "Other {child_half_sib_oth}") );
        $this->form->addElement('select', 'bio_mom_full_sib', "How many total sisters and brothers does this child&#39;s Biological Mother have in her own family of origin who are FULL siblings (same biological mother and biological father as the child&#39;s mother)?
", array("" => "","0" => "0","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","999" => "Other {bio_mom_full_sib_oth}") );
        $this->form->addElement('select', 'bio_fath_full_sib', "How many total sisters and brothers does this child&#39;s Biological Father have in his own family of origin who are FULL siblings (same biological mother and biological father as the child&#39;s mother)?
", array("" => "","0" => "0","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","999" => "Other {bio_fath_full_sib_oth}") );
    }


}

?>