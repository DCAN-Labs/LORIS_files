<?php

/**
 * This file contains the NDB_BVL_Instrument_cbcl_ages_15_to_5
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_cbcl_ages_15_to_5 extends NDB_BVL_Instrument
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
        $this->testName = 'cbcl_ages_15_to_5' ;           // test_names.Test_name
        $this->table = 'cbcl_ages_15_to_5';              // name of database table corresponding to instrument
        // FULL NAME: cbcl_ages_15_to_5
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
        $this->addHeader("Child Behavior Checklist (CBCL) Ages 1.5-5");

        $this->addHeader("<h3>Questions</h3>");
        $this->form->addElement('select', 'cbcl_1_1', "1. Aches or pains (without medical cause; do not include stomach or headaches)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_2', "2. Acts too young for age", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_3', "3. Afraid to try new things", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_4', "4. Avoids looking others in the eye", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_5', "5. Can&#39;t concentrate, can&#39;t pay attention for long", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_6', "6. Can&#39;t sit still, restless, or hyperactive", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_7', "7. Can&#39;t stand having things out of place", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_8', "8. Can&#39;t stand waiting; wants everything now", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_9', "9. Chews on things that aren&#39;t edible", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_10', "10. Clings to adults or too dependent", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_11', "11. Constantly seeks help", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_12', "12. Constipated, doesn&#39;t move bowels (when not sick)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_13', "13. Cries a lot", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_14', "14. Cruel to animals", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_15', "15. Defiant", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_16', "16. Demands must be met immediately", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_17', "17. Destroys his/her own things", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_18', "18. Destroys things belonging to his/her family or other children", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_19', "19. Diarrhea or loose bowels (when not sick)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_20', "20. Disobedient", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_21', "21. Disturbed by any change in routine", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_22', "22. Doesn&#39;t want to sleep alone", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_23', "23. Doesn&#39;t answer when people talk to him/her", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_24', "24. Doesn&#39;t eat well (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_25', "25. Doesn&#39;t get along with other children", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_26', "26. Doesn&#39;t know how to have fun; acts like a little adult", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_27', "27. Doesn&#39;t seem to feel guilty after misbehaving", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_28', "28. Doesn&#39;t want to go out of home", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_29', "29. Easily frustrated", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_30', "30. Easily jealous", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_31', "31. Eats or drinks things that are not food-don&#39;t include sweets (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_32', "32. Fears certain animals, situations, or places (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_33', "33. Feelings are easily hurt", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_34', "34. Gets hurt a lot, accident-prone", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_35', "35. Gets in many fights", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_36', "36. Gets into everything", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_37', "37. Gets too upset when separated from parents", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_38', "38. Has trouble getting to sleep", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_39', "39. Headaches (without medical cause)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_40', "40. Hits others", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_41', "41. Holds his/her breath", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_42', "42. Hurts animals or people without meaning to", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_43', "43. Looks unhappy without good reason", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_44', "44. Angry moods", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_45', "45. Nausea, feels sick (without medical cause)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_46', "46. Nervous movements or twitching (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_47', "47. Nervous, high-strung, or tense", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_48', "48. Nightmares", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_49', "49. Overeating", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_50', "50. Overtired", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_51', "51. Shows panic for no good reason", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_52', "52. Painful bowel movements (without medical cause)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_53', "53. Physically attacks people", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_54', "54. Picks nose, skin, or other parts of body (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_55', "55. Plays with own sex parts too much", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_56', "56. Poorly coordinated or clumsy", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_57', "57. Problems with eyes (without medical cause) (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_58', "58. Punishment doesn&#39;t change his/her behavior", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_59', "59. Quickly shifts from one activity to another", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_60', "60. Rashes or other skin problems (without medical cause)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_61', "61. Refuses to eat", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_62', "62. Refuses to play active games", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_63', "63. Repeatedly rocks head or body", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_64', "64. Resists going to bed at night", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_65', "65. Resists toilet training (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_66', "66. Screams a lot", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_67', "67. Seems unresponsive to affection", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_68', "68. Self-conscious or easily embarrassed", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_69', "69. Selfish or won&#39;t share", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_70', "70. Shows little affection toward people", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_71', "71. Shows little interest in things around him/her", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_72', "72. Shows too little fear of getting hurt", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_73', "73. Too shy or timid", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_74', "74. Sleeps less than most kids during day and/or night (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_75', "75. Smears or plays with bowel movements", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_76', "76. Speech problem (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_77', "77. Stares into space or seems preoccupied", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_78', "78. Stomachaches or cramps (without medical cause)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_79', "79. Rapid shifts between sadness and excitement", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_80', "80. Strange behavior (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_81', "81. Stubborn, sullen, or irritable", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_82', "82. Sudden changes in mood or feelings", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_83', "83. Sulks a lot", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_84', "84. Talks or cries out in sleep", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_85', "85. Temper tantrums or hot temper", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_86', "86. Too concerned with neatness or cleanliness", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_87', "87. Too fearful or anxious", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_88', "88. Uncooperative", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_89', "89. Underactive, slow-moving, or lacks energy", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_90', "90. Unhappy, sad, or depressed", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_91', "91. Unusually loud", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_92', "92. Upset by new people or situations (describe below)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_93', "93. Vomiting, throwing up (without medical cause)", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_94', "94. Wakes up often at night", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_95', "95. Wanders away", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_96', "96. Wants a lot of attention", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_97', "97. Whining", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_98', "98. Withdrawn, doesn&#39;t get involved with others", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
        $this->form->addElement('select', 'cbcl_1_99', "99. Worries", array("" => "","0" => "0 = Not True <br/>(as far as you know)","1" => "1= Somewhat or <br/>Sometimes True","2" => "2 = Very True or <br/>Often True") );
    }


}

?>