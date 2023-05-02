<?php

/**
 * This file contains the NDB_BVL_Instrument_ccc_2
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_ccc_2 extends NDB_BVL_Instrument
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
        $this->testName = 'ccc_2' ;           // test_names.Test_name
        $this->table = 'ccc_2';              // name of database table corresponding to instrument
        // FULL NAME: ccc_2
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
        $this->addHeader("Children's Communication Checklist - Second Edition (CCC 2)");
        
        $this->form->addElement('select', 'ccc_perm_hear_loss', "1. Does the child have a permanent hearing loss?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'ccc_english', "2. Does the child speak English as his or her primary language (the language the child speaks most frequently and is most comfortable using)?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'ccc_sentences', "3. Is the child able to put words together in sentences?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'ccc_1', "1. Gets mixed up between &lt;i&gt;he&lt;/i&gt; and &lt;i&gt;she&lt;/i&gt; (e.g. says &#34;he&#34; when talking about a girl or &#34;she&#34; when talking about a boy)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_2', "2. Simplifies words by leaving out some sounds (e.g., pronouces &#34;crocodile&#34; as &#34;cockadile,&#34; or &#34;stranger&#34; as &#34;staynger&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_3', "3. Appears anxious in the company of other children", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_4', "4. Makes false starts, and seems to search for the right words (e.g. says &#34;can I -- can I -- can I -- can I -- can I have an -- have ice cream&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_5', "5. Talks repetitively about things that no one is interested in", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_6', "6. Forgets words he or she knows (e.g., instead of &#34;rhinoceros&#34; may say &#34;you know, the animal with the horn on its nose...&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_7', "7. With familiar adults, seems inattentive, distant, or preoccupied", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_8', "8. Looks blank in a situation where most children would show a clear facial expressison (e.g., when angry, fearful, or happy)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_9', "9. When given the opportunity to do what he or she likes, chooses the same favorite activity (e.g., playing a specific computer game)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_10', "10. Uses terms like &lt;i&gt;he&lt;/i&gt; or &lt;i&gt;it&lt;/i&gt; without making it clear what he or she is talking about (e.g., when talking about a movie, says &#34;he was really great&#34; without explainig who &#34;he&#34; is)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_11', "11. Says things he or she does not seem to fully understand or seems to be repeating somthing he or she heard an adult say (e.g., a 5-year-old describing a teacher by saying &#34;she&#39;s got a very good reputation&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_12', "12. Mixes up words of similar meaning (e.g., says &#34;dog&#34; for &#34;fox&#34; or &#34;screwdriver&#34; for &#34;hammer&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_13', "13. Is babied, teased, or bullied by other children", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_14', "14. Does not look at the person he or she is talking to", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_15', "15. Misses the point of jokes and puns (though may be amused by nonverbal humor such as slapstick)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_16', "16. Is left out of joint activities by other children", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_17', "17. Gets mixed up between &lt;i&gt;he/him&lt;/i&gt; or &lt;i&gt;she/her&lt;/i&gt; (e.g., says &#34;him is working&#34; rather than &#34;&lt;/i&gt;he&lt;/i&gt; is working,&#34; or &#34;her has a cake&#34; rather than &#34;&lt;i&gt;she&lt;/i&gt; has a cake&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_18', "18. Uses favorite phrases, sentences, or longer sequences in inappropriate contexts (e.g., says &#34;all of a sudden&#34; instead of &#34;then,&#34; as in &#34;We went to the park and all of a sudden we had a picnic;&#34; or routinely starts utterances with &#34;by the way&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_19', "19. Gets confused when a word is used differently from its usual meaning (e.g., does not understand when an unfriendly person is described as &#34;cold&#34; and assumes the person is shivering)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_20', "20. Stands too close to other people when talking to them", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_21', "21. Talks to people without any encouragement or starts conversations with strangers", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_22', "22. Talks about lists of things he or she has memorized (e.g., the names of state capitals or the names of dinosaurs)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_23', "23. Pronounes words in an over-precise manner (e.g., as if child is mimicking a TV personality rather than talking like those around him or her)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_24', "24. Pronouces words in a babyish way (e.g., &#34;chimbley&#34; for &#34;chimney&#34; or &#34;bokkle&#34; for &#34;bottle&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_25', "25. It is difficult to tell if he or she is talking about something real or make-believe", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_26', "26. Moves the conversation to a favorite topic, even if others do not seem interested in it", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_27', "27. Utterances sound babyish because they are just two or three words long (e.g., &#34;me got ball&#34; instead of &#34;I&#39;ve got a ball&#34; or &#34;give doll&#34; instead of &#34;give me the doll&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_28', "28. Ability to communicate varies from situation to situation (e.g., talks easily one-to-one with a familiar adult, but has difficulty expressing himself or herself in a group of children)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_29', "29. Leaves off beginnings or endings of words (e.g., says &#34;roe&#34; instead of &#34;road&#34; or &#34;nana&#34; instead of &#34;banana&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_30', "30. Repeats what others have just said (e.g., if asked &#34;What did you eat?&#34; says, &#34;What did you eat?&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_31', "31. Ignores conversational overtures form others (e.g., if asked, &#34;What are you making?&#34; does not look up and just continues working)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_32', "32. Mixes up words that sound similar (e.g., say &#34;telephone&#34; for &#34;television&#34; or &#34;magician&#34; for &#34;musician&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_33', "33. Hurts or upsets other children without meaning to", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_34', "34. Takes in just one to two words in a sentence, and so misinterprets what has been said (e.g., if someone says &#34;I want to go skating next week,&#34; the child may think that person has been skating or wants to go now)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_35', "35. It is difficutlt to stop him or her from talking", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_36', "36. Leaves off past tense -ed endings on words (e.g., says &#34;John kick the ball&#34; instead of &#34;John &lt;i&gt;kicked&lt;/i&gt; the ball,&#34; or &#34;Sally play over there&#34; instead of &#34;Sally &lt;i&gt;played&lt;/i&gt; over there&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_37', "37. Tells people things they know already", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_38', "38. Makes mistakes in pronouncing long words (e.g., says &#34;vegebable&#34; instead of &#34;vegetable&#34; or &#34;trellistope&#34; instead of &#34;telescope&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_39', "39. Does not recognize when other people are upset or angry", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_40', "40. Confuses the sequence of events when trying to tell a story or describe a recent event (e.g., if describing a movie, might talk about the ending before the beginning)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_41', "41. Is too literal (e.g., if asked &#34;Is it hard to get up in the morning?&#34; replies, &#34;No, you just put one leg out of the bed and then the other and stand up;&#34; or if told &#34;watch your hands&#34; when using scissors, proceeds to stare at his or her fingers)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_42', "42. Provides over-precise information in his or her talk (e.g., if asked &#34;When did you go on vacation?&#34; may say &#34;July 13, 2005&#34; instead of &#34;in the summer&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_43', "43. Leaves out &#34;is&#34; (e.g., says &#34;Daddy going to work&#34; instead of &#34;Daddy &lt;i&gt;is&lt;/i&gt; going to work&#34; or &#34;&lt;i&gt;Daddy&#39;s&#34;&lt;/i&gt; going to work,&#34; or says &#34;the boy big&#34; instead of &#34;the boy &lt;i&gt;is&lt;/i&gt; big&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_44', "44. Mispronounces &lt;i&gt;th&lt;/i&gt; for &lt;i&gt;s&lt;/i&gt; or &lt;i&gt;w&lt;/i&gt; for &lt;i&gt;r&lt;/i&gt; (e.g., &#34;thoap&#34; instead of &#34;soap&#34; or &#34;wabbit&#34; instead of &#34;rabbit&#34;", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_45', "45. Asks a question, even though he or she has been given the answer", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_46', "46. Is vague in choice of words, making it unclear what he or she is talking about (e.g., says &#34;that thing&#34; rather than &#34;pan&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_47', "47. Shows interest in things or activities that most people would find unusual (e.g., traffic lights, washing machines, weather)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_48', "48. Does not explain what he or she is talking about to someone who does not share his or her experiences (e.g., talks about &#34;Johnny&#34; without explaining who Johnny is)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_49', "49. Surprises people by his or her knowledge of unusual words (e.g. uses terms you expect to hear from an adult rather than a child)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_50', "50. It is hard to make sense of what he or she is saying, even though the words are clearly spoken", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_51', "51. Speaks clearly so that the words can easily be understood by someone who does not know him or her well", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_52', "52. Reacts positively when a new and unfamiliar activity is suggested", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_53', "53. Talks clearly about what he or she plans to do in the future (e.g., what he or she will do tomorrow or plans for going on vacation)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_54', "54. Appreciates the humor expressed by irony (e.g., would be amused rather than confused if someone said &#34;Isn&#39;t it a nice day?&#34; when it is pouring rain)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_55', "55. Produces long and complicated sentences (e.g., When I went to the park I went on the swing,&#34; or &#34;I saw this man standing on the corner.&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_56', "56. Makes good use of gestures to get his or her meaning across", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_57', "57. Shows concern when other people are upset", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_58', "58. Speaks fluently and clearly, producing all speech sounds accurately and without any hesitation", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_59', "59. Keeps quiet in situations when someone else is trying to talk or concentrate (e.g., when someone else is watching TV or during formal occasions, such as a school assembly or a religious ceremony)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_60', "60. Realizes the need to be polite (e.g. would act pleased if given a present he or she did not really like; would avoid making personal comments about strangers)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_61', "61. When answering a question, provides enough information without being over-precise", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_62', "62. You can have an enjoyable, interesting conversations with him or her.", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_63', "63. Shows flexibility in adapting to unexpected situations (e.g., does not get upset if he or she planned to play on the computer but has to do something else because it is not working)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_64', "64. Uses abstract words that refer to general concepts rather than something you can see (e.g., knowledge, politics, courage)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_65', "65. Smiles appropriately when talking to people", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_66', "66. Uses words that refer to whole classes of objects, rather than a specific item (e.g., refers to a table, chair, and drawers as &#34;furniture&#34; or to apples, bananas, and pears as &#34;fruit&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_67', "67. Talks about his or her friends; shows interest in what they do and say", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_68', "68. Explains a past event clearly (e.g., what he or she did at school or what happened at a football game)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_69', "69. Produces sentences containing &#34;because&#34; (e.g., &#34;John got a cake because it was his birthday&#34;)", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
        $this->form->addElement('select', 'ccc_70', "70. Talks to others about their interests", array("" => "","0" => "Less than once a week (or never)<br>0","1" => "At least once a week","2" => "Once or twice a day (or frequently)<br>2","3" => "Several times (more than twice) a day (or always)<br>3") );
    }


}

?>