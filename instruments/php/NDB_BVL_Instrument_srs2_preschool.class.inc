<?php

/**
 * This file contains the NDB_BVL_Instrument_srs2_preschool
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_srs2_preschool extends NDB_BVL_Instrument
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
        $this->testName = 'srs2_preschool' ;           // test_names.Test_name
        $this->table = 'srs2_preschool';              // name of database table corresponding to instrument
        // FULL NAME: srs2_preschool
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
        $this->addHeader("SRS 2 Preschool");

        $this->form->addElement('select', 'srs_preschool_1', "Seems much more fidgety in social situations than when alone.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_2', "Expressions on his or her face don&#39;t match what he or she is saying. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_3', "Seems self-confident when interacting with others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_4', "When under stress, child seems to go on &#34;autopilot&#34; (for example, shows rigid or inflexible patterns of behavior that seem odd). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_5', "Doesn&#39;t recognize when someone is trying to take advantage of him or her. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_6', "Would rather be alone than with others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_7', "Is aware of what others are thinking or feeling. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_8', "Behaves in ways that seem strange or bizarre. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_9', "Clings to adults, seems too dependent on them. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_10', "Unable to pick up on any of the meaning of conversations of older children or adults. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_11', "Has good self-confidence.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_12', "Is able to communicate his or her feelings to others in words or gestures. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_13', "Is slow or awkward in turn-taking interactions with peers. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_14', "Is not well coordinated in physical activities. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_15', "Is able to understand the meaning of other people&#39;s tone of voice and facial expressions. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_16', "Avoids eye contact or has unusual eye contact. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_17', "Recognizes when something is unfair. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_18', "When on the playground or in a group with other young children, child does not attempt to interact with other children. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_19', "Gets frustrated trying to get ideas across in conversations. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_20', "Has a strange way of playing with a toy. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_21', "Is able to imitate others&#39; actions.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_22', "Plays appropriately with children his or her age. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_23', "Does not join group activities unless told to do so. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_24', "Has more difficulty than other children with changes in his or her routine. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_25', "Doesn&#39;t seem to mind being out of step or &#34;not on the same wavelength&#34; as others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_26', "Offers comfort to others when they are sad. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_27', "Avoids starting social interactions with peers or adults.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_28', "Thinks or talks about the same thing over and over.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_29', "Is regarded by other children as odd or weird. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_30', "Becomes upset in a situation with lots of things going on. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_31', "Can&#39;t get his or her mind off something once he or she starts thinking about it. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_32', "Wants to be changed when diaper or underwear is soiled or wet.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_33', "Is socially awkward, even when trying to be polite. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_34', "Avoids people who want to be emotionally close to him or her. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_35', "Has trouble keeping up with the flow of normal interaction with other children. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_36', "Has difficulty relating to adults. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_37', "Has difficulty relating to peers. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_38', "Responds appropriately to mood changes in others (for example, when a friend&#39;s or playmate&#39;s mood changes from happy to sad). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_39', "Has a restricted (or unusually narrow) range of interests. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_40', "Is imaginative, good at pretending (without losing touch with reality). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_41', "Wanders aimlessly from one activity to another. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_42', "Seems overly sensitive to sounds, textures, or smells. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_43', "Separates easily from caregivers. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_44', "Doesn&#39;t understand how events are related to one another the way other children his or her age do.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_45', "Focuses his or her attention to where others are looking or listening. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_46', "Has overly serious facial expressions. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_47', "Is too silly or laughs inappropriately. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_48', "Has a sense of humor, understands jokes. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_49', "Does extremely well at a few tasks, but does not do as well at most other tasks. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_50', "Has repetitive, odd behavior such as hand flapping or rocking. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_51', "Responds to clear, direct questions in ways that don&#39;t seem to make any sense. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_52', "Knows when he or she is talking too loud or making too much noise. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_53', "Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_54', "Seems to react to people as if they are objects. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_55', "Knows when he or she is too close to someone or invading someone&#39;s space. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_56', "Walks in between two people who are talking. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_57', "Other children do not like to play with him or her. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_58', "Concentrates too much on parts of things rather than seeing the whole picture. For example, spins the wheels of a toy car but doesn&#39;t play with it as a car, or plays with doll&#39;s hair but not with the whole doll. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_59', "Is overly suspicious.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_60', "Is emotionally distant, doesn&#39;t show his or her feelings. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_61', "Is inflexible, has a hard time changing his or her mind. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_62', "Gives unusual or illogical reasons for doing things. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_63', "Touches others in an unusual way (for example, he or she may touch someone just to make contact and then walk away without saying anything).  ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_64', "Is too tense in social gatherings. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_preschool_65', "Stares or gazes off into space. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
    }


}

?>