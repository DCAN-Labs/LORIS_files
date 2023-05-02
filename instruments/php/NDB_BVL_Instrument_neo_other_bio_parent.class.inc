<?php

/**
 * This file contains the NDB_BVL_Instrument_neo_other_bio_parent
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_neo_other_bio_parent extends NDB_BVL_Instrument
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
        $this->testName = 'neo_other_bio_parent' ;           // test_names.Test_name
        $this->table = 'neo_other_bio_parent';              // name of database table corresponding to instrument
        // FULL NAME: neo_other_bio_parent
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
        $this->addHeader("NEO Personality Inventory - Other Biological Parent");

        $this->form->addElement('select', 'neo_spouse_1', "He/she is not a worrier ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_2', "He/she likes to have a lot of people around", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_3', "He/she doesn&#39;t like to waste time daydreaming ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_4', "He/she tries to be courteous to everyone he/she meets", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_5', "He/she keeps his/her belongings neat and clean ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_6', "He/she often feels inferior to others ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_7', "He/she laughs easily ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_8', "Once he/she finds the right way to do something, he/she sticks to it ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_9', " He/she often gets into arguments with family and coworkers ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_10', " He/she is pretty good about pacing him/herself so as to get things done on time ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_11', "When he/she is under a great deal of stress, sometimes he/she feels like going to pieces ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_12', " He/she doesn&#39;t consider himself/herself especially &#34;light-hearted&#34; ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_13', " He/she is intrigued by the patterns he/she finds in art and nature ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_14', "Some people think he/she is selfish and egotistical ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_15', "He/she is not a very methodical person ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_16', "He/she rarely feels lonely or blue ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_17', "He/she enjoys talking to people ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_18', "He/she believes letting students hear controversial speakers can only confuse and mislead them", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_19', "He/she would rather cooperate with others than compete with them ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_20', "He/she tries to perform the tasks assigned to him/her conscientiously", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_21', "He/she often feels tense and jittery ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_22', "He/she likes to be where the action is ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_23', "Poetry has little or no effect on him/her ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_24', "He/she tends to be cynical and skeptical of others&#39; intentions ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_25', "He/she has a clear set of goals and works toward them in an orderly fashion ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_26', "Sometimes he/she feels completely worthless ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_27', "He/she usually prefers to do things alone ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_28', "He/she often tries new and foreign foods ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_29', "He/she believes that most people will take advantage of you if you let them ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_30', "He/she wastes a lot of time before settling down to work ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_31', "He/she rarely feels fearful or anxious ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_32', "He/she often feels as if he/she is bursting with energy ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_33', "He/she seldom notices the moods or feelings that different environments produce ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_34', "Most people he/she knows like him/her ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_35', "He/she works hard to accomplish his/her goals ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_36', "He/she often gets angry at the way people treat him/her ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_37', "He/she is a cheerful, high spirited person ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_38', "He/she believes we should look to our religious authorities for decisions on moral issues ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_39', "Some people think of him/her as cold and calculating ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_40', "When he/she makes a commitment, he/she can always be counted on to follow through ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_41', "Too often, when things go wrong, he/she gets discouraged and feels like giving up ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_42', "He/she is not a cheerful optimist ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_43', "Sometimes, when he/she is reading poetry or looking at a work of art, he/she feels a wave of excitement ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_44', "He/she is hard-headed and tough-minded in his/her attitudes ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_45', "Sometimes he/she is not as dependable or reliable as he/she should be ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_46', "He/she is seldom sad or depressed ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_47', "His/her life is fast-paced ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_48', "He/she has little interest in speculating on the nature of the universe or the human condition ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_49', "He/she generally tries to be thoughtful and considerate ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_50', "He/she is a productive person who always gets the job done ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_51', "He/she often feels helpless and wants someone to solve his/her problems ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_52', "He/she is a very active person ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_53', "He/she has a lot of intellectual curiosity ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_54', "If he/she doesn&#39;t like people, he/she lets them know it ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_55', "He/she never seems to be able to get organized ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_56', "At times he/she has been so ashamed he/she just wanted to hide ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_57', "He/she would rather go their own way than be a leader of others ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_58', "He/she often enjoys playing with theories or abstract ideas", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_59', "If necessary, he/she is willing to manipulate people to get what he/she wants ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
        $this->form->addElement('select', 'neo_spouse_60', "He/she strives for excellence in everything he/she does ", array("" => "","0" => "Strongly Disagree","1" => "Disagree","2" => "Neutral","3" => "Agree","4" => "Strongly Agree") );
    }


}

?>