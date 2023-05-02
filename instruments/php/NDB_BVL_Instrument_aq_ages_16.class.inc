<?php

/**
 * This file contains the NDB_BVL_Instrument_aq_ages_16
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_aq_ages_16 extends NDB_BVL_Instrument
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
        $this->testName = 'aq_ages_16' ;           // test_names.Test_name
        $this->table = 'aq_ages_16';              // name of database table corresponding to instrument
        // FULL NAME: aq_ages_16
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
        $this->addHeader("Adult Autism Spectrum Quotient (AQ) Ages 16+");
        
        $this->addHeader("<h3>Calculated Fields</h3>");
        $this->form->addElement('text','aqa_score',"Score");

        $this->addHeader("<h3>Questions</h3>");
        $this->form->addElement('select', 'aqa_1', "1. I prefer to do things with others rather than on my own.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_2', "2. I prefer to do things the same way over and over again.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_3', "3. If I try to imagine something, I find it very easy to create a picture in my mind.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_4', "4. I frequently get so strongly absorbed in one thing that I lose sight of other things.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_5', "5. I often notice small sounds when others do not.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_6', "6. I usually notice car number plates or similar strings of information.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_7', "7. Other people frequently tell me that what I&#39;ve said is impolite, even though I think it is polite.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_8', "8. When I&#39;m reading a story, I can easily imagine what the characters might look like.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_9', "9. I am fascinated by dates.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_10', "10. In a social group, I can easily keep track of several different people&#39;s conversations.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_11', "11. I find social situations easy.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_12', "12. I tend to notice details that others do not.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_13', "13. I would rather go to a library than a party.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_14', "14. I find making up stories easy.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_15', "15. I find myself drawn more strongly to people than to things.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_16', "16. I tend to have very strong interests which I get upset about if I can&#39;t pursue.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_17', "17. I enjoy social chit-chat.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_18', "18. When I talk, it isn&#39;t always easy for others to get a word in edgeways.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_19', "19. I am fascinated by numbers.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_20', "20. When I&#39;m reading a story, I find it difficult to work out the characters&#39; intentions.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_21', "21. I don&#39;t particularly enjoy reading fiction.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_22', "22. I find it hard to make new friends.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_23', "23. I notice patterns in things all the time.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_24', "24. I would rather go to the theatre than a museum.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_25', "25. It does not upset me if my daily routine is disturbed.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_26', "26. I frequently find that I don&#39;t know how to keep a conversation going.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_27', "27. I find it easy to &#34;read between the lines&#34; when someone is talking to me.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_28', "28. I usually concentrate more on the whole picture, rather than the small details.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_29', "29. I am not very good at remembering phone numbers.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_30', "30. I don&#39;t usually notice small changes in a situation or a person&#39;s appearance.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_31', "31. I know how to tell if someone listening to me is getting bored.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_32', "32. I find it easy to do more than one thing at once.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_33', "33. When I talk on the phone, I&#39;m not sure when it&#39;s my turn to speak.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_34', "34. I enjoy doing things spontaneously.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_35', "35. I am often the last to understand the point of a joke.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_36', "36. I find it easy to work out what someone is thinking or feeling just by looking at their face.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_37', "37. If there is an interruption, I can switch back to what I was doing very quickly.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_38', "38. I am good at social chit-chat.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_39', "39. People often tell me that I keep going on and on about the same thing.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_40', "40. When I was young, I used to enjoy playing games involving pretending with other children.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_41', "41. I like to collect information about categories of things (e.g. types of car, types of bird, types of train, types of plant, etc.).", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_42', "42. I find it difficult to imagine what it would be like to be someone else.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_43', "43. I like to plan any activities I participate in carefully.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_44', "44. I enjoy social occasions.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_45', "45. I find it difficult to work out people&#39;s intentions.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_46', "46. New situations make me anxious.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_47', "47. I enjoy meeting new people.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_48', "48. I am a good diplomat.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_49', "49. I am not very good at remembering people&#39;s dates of birth.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
        $this->form->addElement('select', 'aqa_50', "50. I find it very easy to play games with children that involve pretending.", array("" => "","1" => "definitely agree","2" => "slightly agree","3" => "slightly disagree","4" => "definitely disagree") );
    }


}

?>