<?php

/**
 * This file contains the NDB_BVL_Instrument_aq_ages_1215
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_aq_ages_1215 extends NDB_BVL_Instrument
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
        $this->testName = 'aq_ages_1215' ;           // test_names.Test_name
        $this->table = 'aq_ages_1215';              // name of database table corresponding to instrument
        // FULL NAME: aq_ages_1215
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
        $this->addHeader("Adolescent Autism Spectrum Quotient (AQ) Ages 12-15 years");
        
        $this->addHeader("<h3>Calculated Fields</h3>");
        $this->form->addElement('text','aqt_score',"Score");

        $this->addHeader("<h3>Questions</h3>");
        $this->form->addElement('select', 'aqt_1', "1. S/he prefers to do things with others rather than on her/his own.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_2', "2. S/he prefers to do things the same way over and over again.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_3', "3. If s/he tries to imagine something, s/he finds it very easy to create a picture in her/his mind.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_4', "4. S/he frequently gets so strongly absorbed in one thing that s/he loses sight of other things.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_5', "5. S/he often notices small sounds when others do not.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_6', "6. S/he usually notices car number plates or similar strings of information.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_7', "7. Other people frequently tell her/him that what s/he has said is impolite, even though s/he thinks it is polite.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_8', "8. When s/he is reading a story, s/he can easily imagine what the characters might look like.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_9', "9. S/he is fascinated by dates.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_10', "10. In a social group, s/he can easily keep track of several different people&#39;s conversations.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_11', "11. S/he finds social situations easy.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_12', "12. S/he tends to notice details that others do not.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_13', "13. S/he would rather go to a library than a party.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_14', "14. S/he finds making up stories easy.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_15', "15. S/he finds her/himself drawn more strongly to people than to things.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_16', "16. S/he tends to have very strong interests, which s/he gets upset about if s/he can&#39;t pursue.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_17', "17. S/he enjoys social chit-chat.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_18', "18. When s/he talks, it isn&#39;t always easy for others to get a word in edgeways.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_19', "19. S/he is fascinated by numbers.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_20', "20. When s/he is reading a story, s/he finds it difficult to work out the characters&#39; intentions.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_21', "21. S/he doesn&#39;t particularly enjoy reading fiction.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_22', "22. S/he finds it hard to make new friends.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_23', "23. S/he notices patterns in things all the time.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_24', "24. S/he would rather go to the theatre than a museum.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_25', "25. It does not upset him/her if his/her daily routine is disturbed.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_26', "26. S/he frequently finds that s/he doesn&#39;t know how to keep a conversation going.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_27', "27. S/he finds it easy to &#34;read between the lines&#34; when someone is talking to her/him.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_28', "28. S/he usually concentrates more on the whole picture, rather than the small details.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_29', "29. S/he is not very good at remembering phone numbers.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_30', "30. S/he doesn&#39;t usually notice small changes in a situation or a person&#39;s appearance.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_31', "31. S/he knows how to tell if someone listening to him/her is getting bored.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_32', "32. S/he finds it easy to do more than one thing at once.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_33', "33. When s/he talks on the phone, s/he is not sure when it&#39;s her/his turn to speak.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_34', "34. S/he enjoys doing things spontaneously.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_35', "35. S/he is often the last to understand the point of a joke.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_36', "36. S/he finds it easy to work out what someone is thinking or feeling just by looking at their face.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_37', "37. If there is an interruption, s/he can switch back to what s/he was doing very quickly.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_38', "38. S/he is good at social chit-chat.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_39', "39. People often tell her/him that s/he keeps going on and on about the same thing.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_40', "40. When s/he was younger, s/he used to enjoy playing games involving pretending with other children.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_41', "41. S/he likes to collect information about categories of things (e.g. types of car, types of bird, types of train, types of plant, etc.).", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_42', "42. S/he finds it difficult to imagine what it would be like to be someone else.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_43', "43. S/he likes to plan any activities s/he participates in carefully.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_44', "44. S/he enjoys social occasions.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_45', "45. S/he finds it difficult to work out people&#39;s intentions.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_46', "46. New situations make him/her anxious.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_47', "47. S/he enjoys meeting new people.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_48', "48. S/he is a good diplomat.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_49', "49. S/he is not very good at remembering people&#39;s dates of birth.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqt_50', "50. S/he finds it very easy to play games with children that involve pretending.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
    }


}

?>