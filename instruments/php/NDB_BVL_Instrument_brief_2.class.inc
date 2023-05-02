<?php

/**
 * This file contains the NDB_BVL_Instrument_brief_2
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_brief_2 extends NDB_BVL_Instrument
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
        $this->testName = 'brief_2' ;           // test_names.Test_name
        $this->table = 'brief_2';              // name of database table corresponding to instrument
        // FULL NAME: brief_2
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
        $this->addHeader("Behavior Rating Inventory of Executive Function 2 (BRIEF2)");

        $this->form->addElement('select', 'brief_q_1', "Is fidgety", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_2', "Resists or has trouble accepting a different way to solve a problem with schoolwork, friends, tasks, etc. ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_3', "When given three things to do, only remembers the first or last ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_4', "Is unaware of how his/her behavior affects or bothers others", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_5', "Work is sloppy", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_6', "Has explosive, angry outbursts", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_7', "Does not plan ahead for school assignments", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_8', "Cannot find things in room or school desk", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_9', "Is not a self-starter", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_10', "Does not think before doing (is impulsive)", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_11', "Has trouble getting used to new situations (classes, groups, friends, etc.)", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_12', "Has a short attention span ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_13', "Has poor understanding of own strengths and weaknesses", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_14', "Has outbursts for little reason ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_15', "Gets caught up in details and misses the big picture ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_16', "Gets out of control more than friends", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_17', "Gets stuck on one topic or activity ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_18', "Forgets his/her name", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_19', "Has trouble with chores or tasks that have more than one step ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_20', "Does not realize that certain actions bother others ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_21', "Written work is poorly organized ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_22', "Small events trigger big reactions ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_23', "Has good ideas but does not get job done (lacks follow-through)", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_24', "Talks at the wrong time ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_25', "Has trouble finishing tasks (chores, homework, etc.)", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_26', "Does not notice when his/her behavior causes negative reactions ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_27', "Reacts more strongly to situations than other children ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_28', "Has trouble remembering things, even for a few minutes ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_29', "Makes careless errors ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_30', "Gets out of seat at the wrong times ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_31', "Becomes upset with new situations ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_32', "Has trouble concentrating on tasks, schoolwork, etc. ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_33', "Has poor handwriting ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_34', "Mood changes frequently ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_35', "Has good ideas but cannot get them on paper", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_36', "Has trouble counting to three", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_37', "Leaves messes that others have to clean up ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_38', "Needs to be told to begin a task even when willing ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_39', "Acts too wild or &#34;out of control&#34;", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_40', "Thinks too much about the same topic ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_41', "Forgets what he/she was doing ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_42', "Does not check work for mistakes ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_43', "Angry or tearful outbursts are intense but end suddenly ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_44', "Becomes overwhelmed by large assignments ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_45', "Loses lunch box, lunch money, permission slips, homework, etc. ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_46', "Needs help from an adult to stay on task ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_47', "Forgets to hand in homework, even when completed ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_48', "Has trouble putting the brakes on his/her actions ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_49', "Resists change of routine, food, places, etc. ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_50', "Has trouble getting started on homework or tasks ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_51', "Mood is easily influenced by the situation ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_52', "Underestimates time needed to finish tasks ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_53', "Does not bring home homework, assignment sheets, materials, etc. ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_54', "Cannot find the front door of home ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_55', "Does not take initiative ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_56', "Becomes upset too easily ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_57', "Starts assignments or tasks at the last minute ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_58', "Has trouble moving from one activity to another ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_59', "Has trouble carrying out the actions needed to reach goals (saving money for special item, studying to get a good grade, etc.) ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_60', "Is disturbed by change of teacher or class ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_61', "Has trouble organizing activities with friends ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_62', "Becomes too silly ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
        $this->form->addElement('select', 'brief_q_63', "Leaves a trail of belongings wherever he/she goes ", array("" => "","0" => "Never","1" => "Sometimes","2" => "Often") );
    }


}

?>