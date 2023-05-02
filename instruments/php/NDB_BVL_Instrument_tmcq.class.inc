<?php

/**
 * This file contains the NDB_BVL_Instrument_tmcq
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_tmcq extends NDB_BVL_Instrument
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
        $this->testName = 'tmcq' ;           // test_names.Test_name
        $this->table = 'tmcq';              // name of database table corresponding to instrument
        // FULL NAME: tmcq
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
        $this->addHeader("Temperament in Middle Childhood Questionnaire (TMCQ)");

        $this->form->addElement('select', 'tmcq_1', "Likes poems.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_2', "Likes to be physically active. ", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_3', "Likes going down high slides or other adventurous activities.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_4', "Greatly enjoys playing games where s/he can win.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_5', "Is bothered by pain when s/he falls down.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_6', "Can stop him/herself when s/he is told to stop.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_7', "Is easily distracted when listening to a story.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_8', "Has a hard time settling down after an exciting activity.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_9', "Likes rough and rowdy games.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_10', "Likes the crunching sound of leaves in the fall.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_11', "Is afraid of fire.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_12', "Likes to think of new ideas.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_13', "Is afraid of heights.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_14', "Can&#39;t help touching things without getting permission.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_15', "Is always on the move.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_16', "Tends to say the first thing that comes to mind, without stopping to think about it.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_17', "Looks around the room when doing homework.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_18', "Would like to be friends with lots of people.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_19', "Is very difficult to soothe when s/he has become upset.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_20', "Can make her/himself do homework, even when s/he wants to play.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_21', "Prefers playing outdoors to indoors when weather permits.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_22', "Interrupts others when they are talking.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_23', "Would rather play a sport than watch TV.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_24', "Tends to become sad if plans don&#39;t work out.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_25', "Says the first thing that comes to mind.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_26', "Can say hello to a new child in class, even when feeling shy.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_27', "Sometimes appears to be downcast for no reason.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_28', "Has a hard time speaking when scared to answer a question.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_29', "Cheers up quickly.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_30', "Cries when given an injection.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_31', "Becomes sad when told to do something s/he does not want to do.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_32', "Likes to play quiet games.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_33', "Would like to spend time with a good friend every day.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_34', "Likes the sound of poems.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_35', "Cries sadly when a favorite toy gets lost or broken.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_36', "Notices the color of people&#39;s eyes.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_37', "Likes to get out of the house and do something physical.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_38', "Becomes quite uncomfortable when cold or wet.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_39', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;Can take a Band-Aid� off when needed, even when painful.&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_40', "Can stop him/herself from doing things too quickly.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_41', "Enjoys exciting and suspenseful TV shows.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_42', "Usually stops and thinks things over before deciding to do something.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_43', "Likes to run.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_44', "Notices the sound of birds.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_45', "Likes exploring new places.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_46', "Can make him/herself run fast, even when tired.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_47', "Becomes self-conscious when around people.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_48', "Likes to make up stories.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_49', "Becomes tearful when tired.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_50', "Enjoys making her/his own decisions.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_51', "Is warm and friendly.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_52', "Would find moving to a new, big city exciting.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_53', "Gets very angry when another child takes his/her toy away.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_54', "Likes reading or listening to make believe stories.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_55', "Is shy with new people.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_56', "Has an easy time waiting to open a present.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_57', "Notices odors like perfume, smoke, and cooking smells.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_58', "Likes to make others feel good.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_59', "Can generally think of something to say, even with strangers.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_60', "Is followed by other children.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_61', "Gets angry when called in from play before s/he is ready to quit.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_62', "Can tell if another person is sad or angry by the look on their face.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_63', "Is scared of injections by the doctor.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_64', "When s/he cries, tends to cry for more than a couple of minutes at a time.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_65', "Enjoys exciting places with big crowds.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_66', "Is energetic.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_67', "Likes listening to music.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_68', "Remains upset for hours when someone hurts his/her feelings.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_69', "Is bothered by loud or scratchy sounds.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_70', "Has a hard time making him/herself clean own room.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_71', "Enjoys drawing pictures.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_72', "Calls out answers before being called on by a teacher or group leader.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_73', "Enjoys looking at books.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_74', "Makes up mind suddenly.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_75', "Is afraid of burglars or the &#34;boogie man.&#34;", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_76', "When a child is left out, can ask that child to play.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_77', "Touches fabric or other soft material.  ", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_78', "When working on an activity, has a hard time keeping her/his mind on it.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_79', "Has a hard time waiting his/her turn to talk when excited.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_80', "Has a hard time paying attention.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_81', "Is bothered by light or color that is too bright.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_82', "Needs to be told by teacher to pay attention.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_83', "Often rushes into doing new things.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_84', "Is first to speak up in a group.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_85', "Is afraid of sleeping over at someone&#39;s house.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_86', "Likes quiet reading time.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_87', "Gets angry when s/he can&#39;t find something s/he is looking for.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_88', "Is very careful and cautious when crossing the street.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_89', "Has a hard time working on an assignment s/he finds boring.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_90', "Is afraid of loud noises.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_91', "Goes to school nurse&#39;s office for very minor complaints.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_92', "Likes the feel of warm water in a bath or shower.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_93', "Does a fun activity when s/he is supposed to do homework instead.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_94', "Gets angry when s/he has trouble with a task.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_95', "Likes to look at trees.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_96', "Likes to play so wildly and recklessly that s/he might get hurt.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_97', "Is told by others to &#34;cheer up&#34; and be happier.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_98', "When with other children, is the one to choose activities or games.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_99', "Gets angry when s/he makes a mistake.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_100', "Her/his feelings are easily hurt.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_101', "Can make him/herself get out of bed, even when tired.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_102', "Likes active games.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_103', "Can apologize or shake hands after a fight.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_104', "Has a big imagination.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_105', "When angry about something, s/he tends to stay upset for five minutes or longer.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_106', "Places great importance on friends.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_107', "Seems to feel down when unable to accomplish a task.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_108', "Gets into trouble because s/he does things without thinking first.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_109', "Notices small changes in the environment, like lights getting brighter in a room.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_110', "Has temper tantrums when s/he doesn&#39;t get what s/he wants.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_111', "Notices things others don&#39;t notice.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_112', "Has a hard time going back to sleep after waking in the night.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_113', "Likes to sit under a blanket.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_114', "Notices even little specks of dirt on objects.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_115', "Enjoys playing chase.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_116', "Likes to pretend.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_117', "Gets nervous about going to the dentist.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_118', "Is shy.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_119', "Likes to go high and fast on the swings.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_120', "Needs to be told to pay attention.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_121', "Would think that skiing or snowboarding fast sounds scary.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_122', "Usually wins arguments with other children.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_123', "Likes to run his/her hand over things to see if they are smooth or rough.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_124', "Grabs what s/he wants.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_125', "Becomes upset when hair is combed.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_126', "Enjoys riding bicycle fast and recklessly.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_127', "Likes to run around outside.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_128', "Decides what s/he wants very quickly and then goes after it.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_129', "Would like to confide in others.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_130', "Usually rushes into an activity without thinking about it.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_131', "Likes to be in charge.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_132', "Can make him/herself take medicine or eat food that s/he knows tastes bad.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_133', "Feels sad frequently.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_134', "Likes hugs and kisses.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_135', "Likes to plan carefully before doing something.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_136', "Acts insecure with others.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_137', "Feels nervous for a long time after being scared.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_138', "Is quite upset by a little cut or bruise.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_139', "Can make him/herself pick up something dirty in order to throw it away.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_140', "Is afraid of the dark.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_141', "Is able to keep secrets.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_142', "Is bothered by bathwater that is too hot or too cold.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_143', "Has a hard time slowing down when rules say to walk.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_144', "Tends to feel sad even when others are happy.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_145', "Loves pets and other small animals.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_146', "Gets mad when provoked by other children.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_147', "When s/he sees a toy or a game s/he wants, is eager to have it right away.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_148', "Likes to feel close to other people.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_149', "Gets distracted when trying to pay attention in class.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_150', "Notices when parents are wearing new clothing.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_151', "Likes to make things.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_152', "Has a hard time getting moving when tired.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_153', "Is very frightened by nightmares.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_154', "Is likely to cry when even a little bit hurt.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_155', "Enjoys winning arguments.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_156', "Likes just being with other people.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
        $this->form->addElement('select', 'tmcq_157', "Can make him/herself smile at someone, even when s/he dislikes them.", array("" => "","1" => "1 = Almost always untrue","2" => "2 = Usually untrue","3" => "3 = Sometimes true","4" => "4 = Usually true","5" => "5 = Almost always true","0" => "Does not apply") );
    }


}

?>