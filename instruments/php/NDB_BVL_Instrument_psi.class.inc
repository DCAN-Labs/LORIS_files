<?php

/**
 * This file contains the NDB_BVL_Instrument_psi
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_psi extends NDB_BVL_Instrument
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
        $this->testName = 'psi' ;           // test_names.Test_name
        $this->table = 'psi';              // name of database table corresponding to instrument
        // FULL NAME: psi
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
        $this->addHeader("Parenting Stress Index (PSI)");

        $this->form->addElement('select', 'psi_1', "Divorce?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_2', "Marital reconciliation?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_3', "Marriage?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_4', "Separation?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_5', "Pregnancy?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_6', "Other relative moved into household? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_7', "Income increased substantially (20% or more)?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_8', "Went deeply into debt?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_9', "Moved to new home?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_10', "Promotion at work?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_11', "Income decreased substantially (20%  or more)? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_12', "Alcohol or drug problem?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_13', "Death of a close family friend? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_14', "Began new job?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_15', "Child entered new school?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_16', "Trouble with supervisors at work?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_17', "Child had trouble with teachers at school?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_18', "Legal problems?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_19', "Death of immediate family member?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'psi_20', "Child suspended or expelled from school?", array("" => "","1" => "Yes","0" => "No") );
    }


}

?>