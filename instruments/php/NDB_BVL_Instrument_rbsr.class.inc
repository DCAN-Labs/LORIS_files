<?php

/**
 * This file contains the NDB_BVL_Instrument_rbsr
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_rbsr extends NDB_BVL_Instrument
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
        $this->testName = 'rbsr' ;           // test_names.Test_name
        $this->table = 'rbsr';              // name of database table corresponding to instrument
        // FULL NAME: rbsr
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
        $this->addHeader("Repetitive Behavior Scale, Revised (RBS-R)");

        $this->form->addElement('select', 'repetitive_behavior_scale_', "Have you read the instructions?", array("" => "","1" => "Yes","2" => "No") );
        $this->form->addElement('select', 'repetitive_behavior_scale_1', "WHOLE BODY (Body rocking, Body swaying)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_2', "HEAD (Rolls Head, Nods head, Turns head) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_3', "HAND / FINGER (Flaps hands, Wiggles or flicks fingers, Claps hands, Waves or shakes hand or arm)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_4', "LOCOMOTION (Turns in circles, Whirls, Jumps, Bounces) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_5', "OBJECT USAGE (Spins or twirls objects, Twiddles or slaps or throws objects, Lets objects fall out of hands)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_6', "SENSORY (Covers eyes, Looks closely or gazes at hands or objects, Covers ears, Smells or sniffs items, Rubs surfaces)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_7', "HITS SELF WITH BODY PART (Hits or slaps head, face, or other body area) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_8', "HITS SELF AGAINST SURFACE OR OBJECT (Hits or bangs head or other body part on table, floor or other surface)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_9', "HITS SELF WITH OBJECT (Hits or bangs head or other body area with objects) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_10', "BITES SELF (Bites hand, wrist, arm, lips or tongue) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_11', "PULLS (Pulls hair or skin) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_12', "RUBS OR SCRATCHES SELF (Rubs or scratches marks on arms, legs, face, or torso)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_13', "INSERTS FINGER OR OBJECT (Eye-poking, Ear-poking) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_14', "SKIN PICKING (Picks at skin on face, hands, arms, legs, or torso) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_15', "ARRANGING / ORDERING (Arranges certain objects in a particular pattern or place; Need for things to be even or symmetrical) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_16', "COMPLETENESS (Must have doors open or closed; Takes all items out of a container or area)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_17', "WASHING / CLEANING (Excessively cleans certain body parts; Picks at lint or loose threads) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_18', "CHECKING (Repeatedly checks doors, windows, drawers, appliances, clocks, locks, etc.) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_19', "COUNTING (Counts items or objects; Counts to a certain number or in a certain way)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_20', "HOARDING / SAVING (Collects, hoards, or hides specific items)", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_21', "REPEATING (Need to repeat routine events; In/out door, up/down from a chair, clothing on/off ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_22', "TOUCH / TAP (Need to touch, tap, or rub items, surfaces, or people) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_23', "EATING / MEALTIME (Strongly prefers/insists on eating/drinking only certain things; Eats or drinks items in a set order; Insists that meal related items are arranged in a certain way) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_24', "SLEEPING / BEDTIME (Insists on certain pre-bedtime routines; Arranges items in room &#34;just so&#34; prior to bedtime; Insists that certain items be present with him/her during sleep; Insists that another person be present prior to or during sleep) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_25', "SELF-CARE -- BATHROOM AND DRESSING  (Insists on specific order of activities or tasks related to using the bathroom, to washing, showering, bathing or dressing; Arranges items in a certain way in the bathroom or insists that bathroom items not be moved; Insists on wearing certain clothing items) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_26', "TRAVEL / TRANSPORTATION (Insists on taking certain routes/paths; Must sit in specific location in vehicles; Insists that certain items must be present during travel, e.g., toy or material; Insists on seeing or touching certain things or places during travel such as a sign or store) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_27', "PLAY / LEISURE (Insists on certain play activities; Follows a rigid routine during play/leisure; Insists that certain items be present/available during play/leisure; Insists that other persons do certain things during play) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_28', "COMMUNICATION / SOCIAL INTERACTIONS (Repeats same topic(s) during social interactions; Repetitive questioning; Insists on certain topics of conversation; Insists that others say certain things or respond in certain ways during interactions) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_29', "Insists that things remain in the same place(s) (e.g. toys, supplies, furniture, pictures, etc.) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_30', "Objects to visiting new places ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_31', "Becomes upset if interrupted in what he/she is doing ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_32', "Insists on walking in a particular pattern (e.g., straight line) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_33', "Insists on sitting at the same place", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_34', "Dislikes changes in appearance or behavior of the people around him/her ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_35', "Insists on using a particular door ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_36', "Likes the same CD, tape, record, or piece of music played continually; Likes the same movie/video or part of movie/video ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_37', "Resists changing activities; Difficulty with transitions", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_38', "Insists on same routine, household, school or work schedule everyday ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_39', "Insists that specific things take place at specific times ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_40', "Fascination, preoccupation with one subject or activity (e.g., trains, computers, weather, dinosaurs) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_41', "Strongly attached to one specific object ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_42', "Preoccupation with part(s) of object rather than the whole object (e.g., buttons on clothes, wheels on toy cars) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
        $this->form->addElement('select', 'repetitive_behavior_scale_43', "Fascination, preoccupation with movement / things that move (e.g., fans, clocks) ", array("" => "","0" => "0 = Behavior does not occur","1" => "1 = Behavior occurs and is a mild problem","2" => "2 = Behavior occur and is a moderate problem","3" => "3 = Behavior occurs and is a severe problem") );
    }


}

?>