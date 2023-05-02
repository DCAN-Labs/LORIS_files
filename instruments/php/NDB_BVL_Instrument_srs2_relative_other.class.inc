<?php

/**
 * This file contains the NDB_BVL_Instrument_srs2_relative_other
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_srs2_relative_other extends NDB_BVL_Instrument
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
        $this->testName = 'srs2_relative_other' ;           // test_names.Test_name
        $this->table = 'srs2_relative_other';              // name of database table corresponding to instrument
        // FULL NAME: srs2_relative_other
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
        $this->addHeader("SRS2 - Other Bio Parent OR sibling (Adult ages 19+)");

        $this->form->addElement('select', 'srs_relative_other_1', "Seems much more comfortable in social situations than when alone.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_2', "Expressions on his or her face don&#39;t match what he or she is saying.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_3', "Seems self-confident when interacting with others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_4', "When under stress, he or she shows rigid or inflexible patterns of behavior that seem odd. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_5', "Doesn&#39;t recognize when others are trying to take advantage of him or her. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_6', "Would rather be alone than with others.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_7', "Is aware of what others are thinking or feeling. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_8', "Behaves in ways that seem strange or bizarre. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_9', "Seems too dependent on others for help with meeting basic needs. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_10', "Takes things too literally and doesn&#39;t get the real meaning of a conversation. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_11', "Has good self-confidence. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_12', "Is able to communicate his or her feelings to others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_13', "Is awkward in turn-taking interactions with others (for example, doesn&#39;t seem to understand the give-and-take of conversations). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_14', "Is not well coordinated.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_15', "Recognizes and appropriately responds to changes in other people&#39;s tone of voice and facial expressions. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_16', "Avoids eye contact or has unusual eye contact. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_17', "Recognizes when something is unfair. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_18', "Has difficulty making friends, even when trying his or her best. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_19', "Gets frustrated trying to get ideas across in conversations. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_20', "Shows unusual sensory interests (for example, smelling his or her friends frequently) or strange, repetitive ways of handling or manipulating small items within reach. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_21', "Is able to imitate others&#39; actions and demeanor when it is socially appropriate to do so. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_22', "Interacts appropriately with other adults. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_23', "Does not join group activities or social events unless forced to do so. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_24', "Has more difficulty than others with changes in his or her routine. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_25', "Doesn&#39;t seem to mind being out of step or &#34;not on the same wavelength&#34; as others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_26', "Offers comfort to others when they are sad. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_27', "Avoids starting social interactions with other adults.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_28', "Thinks or talks about the same thing over and over.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_29', "Is regarded by others as odd or weird. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_30', "Becomes upset in a situation with lots of things going on. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_31', "Can&#39;t get his or her mind off something once he or she starts thinking about it. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_32', "Has good personal hygiene. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_33', "Is socially awkward, even when trying to be polite. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_34', "Avoids people who want to be emotionally close to him or her. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_35', "Has trouble keeping up with the flow of a normal conversation.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_36', "Has difficulty relating to family members. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_37', "Has difficulty relating to other adults. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_38', "Responds appropriately to mood changes in others (for example, when a friend&#39;s mood changes from happy to sad). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_39', "Has an unusually narrow range of interests. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_40', "Is imaginative without losing touch with reality. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_41', "Wanders aimlessly from one activity to another. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_42', "Seems overly sensitive to sounds, textures, or smells. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_43', "Enjoys and is competent with small talk (casual conversation with others). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_44', "Doesn&#39;t understand how events relate to one another (cause and effect) the way other adults do. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_45', "Generally gets interested in what others nearby are paying attention to. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_46', "Has overly serious facial expressions. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_47', "Laughs at inappropriate times. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_48', "Has a sense of humor, understands jokes. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_49', "Does extremely well at a few intellectual or computational tasks, but does not do as well at most other tasks. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_50', "Has repetitive, odd behavior. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_51', "Has difficulty answering questions directly and ends up talking around the subject. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_52', "Knows when he or she is talking too loud or making too much noise. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_53', "Talks to people with an unusual tone of voice (for example, like a robot or like he or she is giving a lecture). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_54', "Seems to react to people as if they are objects. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_55', "Knows when he or she is too close to someone or invading someone&#39;s space. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_56', "Walks in between people two people who are talking. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_57', "Isolative; tends not to leave his or her home. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_58', "Concentrates too much on parts of things rather than seeing the whole picture. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_59', "Is overly suspicious.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_60', "Is emotionally distant, doesn&#39;t show his or her feelings. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_61', "Is inflexible, has a hard time changing his or her mind. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_62', "Gives unusual or illogical reasons for doing things. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_63', "Touches or greets others in an unusual way. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_64', "Is too tense in social gatherings. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_relative_other_65', "Stares or gazes off into space. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
    }


}

?>