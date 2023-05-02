<?php

/**
 * This file contains the NDB_BVL_Instrument_caars_other_bio_parent
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_caars_other_bio_parent extends NDB_BVL_Instrument
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
        $this->testName = 'caars_other_bio_parent' ;           // test_names.Test_name
        $this->table = 'caars_other_bio_parent';              // name of database table corresponding to instrument
        // FULL NAME: caars_other_bio_parent
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
        $this->addHeader("Conners' Adult ADHD Rating Scales (CAARS) - Other Biological Parent");

        $this->form->addElement('select', 'caars_spouse_1', " Interrupts others when talking.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_2', " Is always on the go as if driven by a motor.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_3', "Is disorganized.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_4', "Has a hard time staying in one place very long.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_5', "Has a hard time keeping track of several things at once.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_6', "Is bored easily.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_7', "Has a short fuse/hot temper.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_8', "Throws tantrums.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_9', "Avoids new challenges because he/she lacks faith in his/her abilities.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_10', "Seeks out fast-paced, exciting activities.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_11', "Appears to be restless inside even when sitting still.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_12', "Is distracted by sights or sounds when trying to concentrate.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_13', "Is set off easily by many things.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_14', "Is an underachiever.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_15', "Gets down on self.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_16', "Acts okay on the outside, but appears unsure of self.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_17', "Can&#39;t get things done unless there&#39;s an absolute deadline.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_18', "Has trouble getting started on a task.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_19', "Intrudes on others&#39; activities.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_20', "Has unpredictable moods.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_21', "Is absent-minded in daily activities.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_22', "Sometimes overfocuses on details, at other times appears distracted by everything.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_23', "Tends to squirm or fidget.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_24', "Can&#39;t keep his/her mind in something unless it&#39;s really interesting.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_25', "Expresses lack of confidence in his/her abilities.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
        $this->form->addElement('select', 'caars_spouse_26', "Expresses lack of confidence in self because of past failures.", array("" => "","0" => "0 = Not at all","1" => "1 = Just a little","2" => "2 = Pretty much","3" => "3 = Very much") );
    }


}

?>