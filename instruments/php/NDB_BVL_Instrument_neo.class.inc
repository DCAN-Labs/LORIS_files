<?php

/**
 * This file contains the NDB_BVL_Instrument_neo
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_neo extends NDB_BVL_Instrument
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
        $this->testName = 'neo' ;           // test_names.Test_name
        $this->table = 'neo';              // name of database table corresponding to instrument
        // FULL NAME: neo
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
        $this->addHeader("NEO Personality Inventory");

        $this->form->addElement('select', 'neo1', "&lt;p&gt;1. I am not a worrier.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo2', "&lt;p&gt;2. I like to have a lot of people around me.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo3', "&lt;p&gt;3. I don&#39;t like to waste my time daydreaming.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo4', "&lt;p&gt;4. I try to be courteous to everyone I meet.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo5', "&lt;p&gt;5. I keep my belongings clean and neat.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo6', "&lt;p&gt;6. I often feel inferior to others.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo7', "&lt;p&gt;7. I laugh easily.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo8', "&lt;p&gt;8. Once I find the right way to do something, I stick to it.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo9', "&lt;p&gt;9. I often get into arguments with my family and co-workers.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo10', "&lt;p&gt;10. I&#39;m pretty good about pacing myself so as to get things done on time.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo11', "&lt;p&gt;11. When I&#39;m under a great deal of stress, sometimes I feel like I&#39;m going to pieces.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo12', "&lt;p&gt;12. I don&#39;t consider myself especially &#34;light-hearted.&#34;&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo13', "&lt;p&gt;13. I am intrigued by the patterns I find in art and nature.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo14', "&lt;p&gt;14. Some people think I&#39;m selfish and egotistical.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo15', "&lt;p&gt;15. No, am not a very methodical person. &lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo16', "&lt;p&gt;16. I rarely feel lonely or blue. &lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo17', "&lt;p&gt;17. I really enjoy talking to people. &lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo18', "&lt;p&gt;18. I believe letting students hear controversial speakers can only confuse and mislead them.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo19', "&lt;p&gt;19. I would rather cooperate with others than compete with them.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo20', "&lt;p&gt;20. I try to perform all the tasks assigned to me conscientiously.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo21', "&lt;p&gt;21. I often feel tense and jittery.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo22', "&lt;p&gt;22. I like to be where the action is.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo23', "&lt;p&gt;23. Poetry has little or no effect on me. &lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo24', "&lt;p&gt;24. I tend to be cynical and skeptical of others&#39; intentions. &lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo25', "&lt;p&gt;25. I have a clear set of goals and work toward them in an orderly fashion.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo26', "&lt;p&gt;26. Sometime I feel completely worthless.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo27', "&lt;p&gt;27. I usually prefer to do things alone.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo28', "&lt;p&gt;28. I often try new and foreign foods.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo29', "&lt;p&gt;29. I believe that most people will take advantage of you if you let them.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo30', "&lt;p&gt;30. I waste a lot of time before settling down to work.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo31', "&lt;p&gt;31. I rarely feel fearful or anxious.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo32', "&lt;p&gt;32. I often feel as if I&#39;m bursting with energy. &lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo33', "&lt;p&gt;33. I seldom notice the moods or feelings that different environments produce.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo34', "&lt;p&gt;34. Most people I know like me.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo35', "&lt;p&gt;35. I work hard to accomplish my goals.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo36', "&lt;p&gt;36. I often get angry at the way people treat me.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo37', "&lt;p&gt;37. I am a cheerful, high-spirited person.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo38', "&lt;p&gt;38. I believe we should look to our religious authorities for decisions on moral issues.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo39', "&lt;p&gt;39. Some people think of me as cold and calculating.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo40', "&lt;p&gt;40. When I make a commitment, I can always be counted on to follow through.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo41', "&lt;p&gt;41. Too often, when things go wrong, I get discouraged and feel like giving up.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo42', "&lt;p&gt;42. I am not a cheerful optimist.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo43', "&lt;p&gt;43. Sometimes when I am reading poetry or looking at a work of art, I feel a chill or wave of excitement.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo44', "&lt;p&gt;44. I&#39;m hard-headed and tough-minded in my attitudes.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo45', "&lt;p&gt;45. Sometimes I&#39;m not as dependable or reliable as I should be.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo46', "&lt;p&gt;46. I am seldom sad or depressed.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo47', "&lt;p&gt;47. My life is fast-paced.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo48', "&lt;p&gt;48. I have little interest in speculating on the nature of the universe or the human condition.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo49', "&lt;p&gt;49. I generally try to be thoughtful and considerate.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo50', "&lt;p&gt;50. I am a productive person who always gets the job done.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo51', "&lt;p&gt;51. I often feel helpless and want someone else to solve my problems.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo52', "&lt;p&gt;52. I am a very active person&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo53', "&lt;p&gt;53. I have a lot of intellectual curiosity.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo54', "&lt;p&gt;54. If I don&#39;t like people, I let them know it.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo55', "&lt;p&gt;55. I never seem to be able to get organized.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo56', "&lt;p&gt;56. At times I have been so ashamed I just want to hide.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo57', "&lt;p&gt;57. I would rather go my own way than be a leader of others.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo58', "&lt;p&gt;58. I often enjoy playing with theories or abstract ideas.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo59', "&lt;p&gt;59. If necessary, I am willing to manipulate people to get what I want.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
        $this->form->addElement('select', 'neo60', "&lt;p&gt;60. I strive for excellence in everything I do.&lt;/p&gt;", array("" => "","1" => "Strongly Disagree","2" => "Disagree","3" => "Neutral","4" => "Agree","5" => "Strongly Agree") );
    }


}

?>