<?php

/**
 * This file contains the NDB_BVL_Instrument_caars
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_caars extends NDB_BVL_Instrument
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
        $this->testName = 'caars' ;           // test_names.Test_name
        $this->table = 'caars';              // name of database table corresponding to instrument
        // FULL NAME: caars
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
        $this->addHeader("Conners' Adult ADHD Rating Scales (CAARS)");

        $this->form->addElement('select', 'caars_1', "I like to be doing active things ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_2', "I lose things necessary for tasks or activities (e.g., to-do lists, pencils, books, or tools", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_3', "I don&#39;t plan ahead ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_4', "I blurt out things ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_5', "I am a risk-taker or a daredevil ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_6', "I get down on myself ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_7', "I don&#39;t finish things I start ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_8', "I am easily frustrated ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_9', "I talk too much ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_10', "I am always on the go, as if driven by a motor ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_11', "I&#39;m disorganized", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_12', "I say things without thinking ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_13', "It&#39;s hard for me to stay in one place very long ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_14', "I have trouble doing leisure activities quietly ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_15', "I&#39;m not sure of myself ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_16', "It&#39;s hard for me to keep track of several things at once ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_17', "I&#39;m always moving even when I should be still ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_18', "I forget to remember things ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_19', "I have a short fuse/hot temper ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_20', "I&#39;m bored easily ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_21', "I leave my seat when I&#39;m not supposed to ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_22', "I still have trouble waiting in line or taking turns with others ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_23', "I still throw tantrums", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_24', "I have trouble keeping my attention focused when working ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_25', "I seek out fast-paced, exciting activities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_26', "I avoid new challenges because I lack faith in my abilities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_27', "I feel restless inside even when I am sitting still ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_28', "Things I hear or see distract me from my work", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_29', "I am forgetful in my daily activities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_30', "Many things set me off easily ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_31', "I dislike quiet, introspective activities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_32', "I lose things that I need ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_33', "I have trouble listening to what other people are saying ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_34', "I am an underachiever", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_35', "I interrupt others when talking ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_36', "I change plans/jobs midstream ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_37', "I act okay on the outside, but inside I&#39;m unsure of myself ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_38', "I am always on the go ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_39', "I make comments/remarks that I wish I could take back ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_40', "I can&#39;t get things done unless there&#39;s an absolute deadline ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_41', "I fidget (with my hands or feet) or squirm in my seat ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_42', "I make careless mistakes or have trouble paying close attention to detail ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_43', "I step on people&#39;s toes without meaning to ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_44', "I have trouble getting started on a task ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_45', "I intrude on others&#39; activities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_46', "It takes a great deal of effort for me to sit still ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_47', "My moods are unpredictable ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_48', "I don&#39;t like homework or job activities where I have to think a lot ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_49', "I&#39;m absent-minded in my daily activities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_50', "I am restless or overactive ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_51', "I depend on others to keep my life in order and attend to the details ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_52', "I annoy other people without meaning to ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_53', "Sometimes my attention narrows so much that I&#39;m oblivious to everything else; other times it&#39;s so broad that everything distracts me ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_54', "I tend to squirm or fidget ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_55', "I can&#39;t keep my mind on something unless it&#39;s really interesting ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_56', "I wish I had greater confidence in my abilities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_57', "I can&#39;t sit still for very long ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_58', "I give answers to questions before the questions have been completed", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_59', "I like to be up and on the go rather than being in one place ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_60', "I have trouble finishing job tasks or schoolwork ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_61', "I am irritable ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_62', "I interrupt others when they are working or playing ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_63', "My past failures make it hard for me to believe in myself ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_64', "I am distracted when things are going on around me ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_65', "I have problems  organizing my tasks and activities ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
        $this->form->addElement('select', 'caars_66', "I misjudge how long it takes to do something or go somewhere ", array("" => "","0" => "0: Not at all","1" => "1: Just a little","2" => "2: Pretty much","3" => "3: Very much") );
    }


}

?>