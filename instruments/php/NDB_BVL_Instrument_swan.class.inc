<?php

/**
 * This file contains the NDB_BVL_Instrument_swan
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_swan extends NDB_BVL_Instrument
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
        $this->testName = 'swan' ;           // test_names.Test_name
        $this->table = 'swan';              // name of database table corresponding to instrument
        // FULL NAME: swan
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
        $this->addHeader("Strengths and Weaknesses of Attention-Deficit/Hyperactivity Disorder Symptoms and Normal Behavior Scale (SWAN)");

        $this->form->addElement('select', 'swan_1', "Give close attention to detail and avoid careless mistakes? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_2', "Sustain attention on tasks or play activities?", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_3', "Listen when spoken to directly?", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_4', "Follow through on instructions and finish schoolwork/chores? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_5', "Organize tasks and activities? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_6', "Engage in tasks that require sustained mental effort? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_7', "Keep track of things necessary for activities? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_8', "Ignore extraneous stimuli?", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_9', "Remember daily activities? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_10', "Sit still (control movement of hands/feet or control squirming)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_11', "Stay seated (when required by class rules/social conventions)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_12', "Modulate motor activity (inhibit inappropriate running/climbing)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_13', "Play quietly (keep noise level reasonable)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_14', "Settle down and rest (control constant activity)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_15', "Modulate verbal activity (control excess talking)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_16', "Reflect on questions (control blurting out answers)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_17', "Await turn (stand in line and take turns)? ", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
        $this->form->addElement('select', 'swan_18', "Enter into conversation and games (control interrupting/intruding)?", array("" => "","1" => "Far below","2" => "Below","3" => "Slightly below","4" => "Average","5" => "Slightly above","6" => "Above","7" => "Far above") );
    }


}

?>