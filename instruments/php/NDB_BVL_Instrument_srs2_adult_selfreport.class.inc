<?php

/**
 * This file contains the NDB_BVL_Instrument_srs2_adult_selfreport
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_srs2_adult_selfreport extends NDB_BVL_Instrument
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
        $this->testName = 'srs2_adult_selfreport' ;           // test_names.Test_name
        $this->table = 'srs2_adult_selfreport';              // name of database table corresponding to instrument
        // FULL NAME: srs2_adult_selfreport
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
        $this->addHeader("SRS2 Adult Self Report");

        $this->form->addElement('select', 'srs_adult_self_report_1', "I am much more uncomfortable in social situations than when I am by myself. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_2', "My facial expressions send the wrong message to others about how I actually feel. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_3', "I feel self-confident when interacting with others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_4', "When under stress, I engage in rigid or inflexible patterns of behavior that seem odd to people. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_5', "I do not recognize when others are trying to take advantage of me.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_6', "I would rather be alone than with others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_7', "I am usually aware of how others are feeling. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_8', "I behave in ways that seem strange or bizarre to others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_9', "I am overly dependent on others for help with meeting my everyday needs. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_10', "I take things too literally, and because of that, I misinterpret the intended meaning of parts of a conversation. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_11', "I have good self-confidence.", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_12', "I am able to communicate my feelings to others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_13', "I am awkward in turn-taking interactions with others (for example, I have a hard time keeping up with the give-and-take of a conversation. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_14', "I am not well coordinated. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_15', "When people change their tone or facial expression, I usually pick up on that and understand what it means. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_16', "I avoid eye contact or am told that I have unusual eye contact. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_17', "I recognize when something is unfair. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_18', "I have difficulty making friends, even when trying my best. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_19', "I get frustrated trying to get ideas across in conversations. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_20', "I have sensory interests that others find unusual (for example, smelling or looking at things in a special way). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_21', "I am able to imitate others&#39; actions and expressions when it is socially appropriate to do so. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_22', "I interact appropriately with other adults. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_23', "I do not join group activities or social events unless prompted or strongly urged to do so. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_24', "I have more difficulty than others with changes in my routine. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_25', "I do not mind being out of step with or &#34;not on the same wavelength&#34; as others. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_26', "I offer comfort to others when they are sad. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_27', "I avoid starting social interaction with other adults. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_28', "I think or talk about the same thing over and over. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_29', "I am regarded by others as odd or weird. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_30', "I become upset in situations with lots of things going on. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_31', "I can&#39;t get my mind off something once I start thinking about it. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_32', "I have good personal hygiene. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_33', "My behavior is socially awkward, even when trying to be polite. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_34', "I avoid people who want to be emotionally close to me. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_35', "I have trouble keeping up with the flow of a normal conversation. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_36', "I have difficulty relating to family members. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_37', "I have difficulty relating to other adults outside of my family. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_38', "I respond appropriately to mood changes in others (for example, when a friend&#39;s mood changes from happy to sad). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_39', "People think I am interested in too few topics, or that I get too carried away with those topics. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_40', "I am imaginative. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_41', "I sometimes seem to wander aimlessly from one activity to another. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_42', "I am overly sensitive to certain sounds, textures, or smells. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_43', "I enjoy small talk (casual conversation with others). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_44', "I have more trouble than most people with understanding chains of causations (in other words, how events are related to one another). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_45', "When others around me are paying close attention to something, I get interested in what they are attending to. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_46', "Others feel that I have overly serious facial expressions. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_47', "I laugh at inappropriate times. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_48', "I have a good sense of humor and can understand jokes. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_49', "I do extremely well at certain kinds of intellectual tasks, but do not do as well at most other tasks. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_50', "I have repetitive behaviors that others consider odd. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_51', "I have difficulty answering questions directly and end up talking around the subject. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_52', "I get overly loud without realizing it. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_53', "I tend to talk in a monotone voice (in other words, less inflection of voice than most people demonstrate). ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_54', "I tend to think about people in the same way I do objects. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_55', "I get too close to others or invade their personal space without realizing it. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_56', "I sometimes make the mistake of walking between two people who are trying to talk to one another. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_57', "I tend to isolate myself. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_58', "I concentrate too much on parts of things rather than seeing the whole picture. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_59', "I am more suspicious than most people. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_60', "Other people think I am emotionally distant and do not show my feelings. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_61', "I tend to be inflexible. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_62', "When I tell someone my reason for doing something, it strikes the person as unusual or illogical. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_63', "My way of greeting another person is unusual. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_64', "I am much more tense in social settings than when I am by myself. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
        $this->form->addElement('select', 'srs_adult_self_report_65', "I find myself staring or gazing off into space. ", array("" => "","1" => "1: Not true","2" => "2: Sometimes True","3" => "3: Often True","4" => "4: Almost Always True") );
    }


}

?>