<?php

/**
 * This file contains the NDB_BVL_Instrument_bapq
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_bapq extends NDB_BVL_Instrument
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
        $this->testName = 'bapq' ;           // test_names.Test_name
        $this->table = 'bapq';              // name of database table corresponding to instrument
        // FULL NAME: bapq
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
        $this->addHeader("The Broad Autism Phenotype Questionnaire (BAPQ)");

        $this->addHeader("Calculated Fields");

        $this->form->addElement('static','bapq_aloof',"Aloof score");
        $this->form->addElement('static','bapq_prag_lang',"Pragmatic Language score");
        $this->form->addElement('static','bapq_rigid',"Rigid score");
        $this->form->addElement('static','bapq_total',"Total score");
        
        
        $this->addHeader("Questions");

        $this->form->addElement('select', 'bapq_1', "1. I like being around other people", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_2', "2. I find it hard to get my words out smoothly", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_3', "3. I am comfortable with unexpected changes in plans", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_4', "4. It&#39;s hard for me to avoid getting sidetracked in conversation", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_5', "5. I would rather talk to people to get information than to socialize", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_6', "6. People have to talk me into trying something new", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_7', "7. I am &#39;&#39;in-tune&#39;&#39; with the other person during conversation***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_8', "8. I have to warm myself up to the idea of visiting an unfamiliar place", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_9', "9. I enjoy being in social situations", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_10', "10. My voice has a flat or monotone sound to it", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_11', "11. I feel disconnected or &#39;&#39;out of sync&#39;&#39; in conversations with others***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_12', "12. People find it easy to approach me***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_13', "13. I feel a strong need for sameness from day to day", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_14', "14. People ask me to repeat things I&#39;ve said because they don&#39;t understand", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_15', "15. I am flexible about how things should be done", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_16', "16. I look forward to situations where I can meet new people", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_17', "17. I have been told that I talk too much about certain topics", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_18', "18. When I make conversation it is just to be polite***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_19', "19. I look forward to trying new things", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_20', "20. I speak too loudly or softly", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_21', "21. I can tell when someone is not interested in what I am saying***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_22', "22. I have a hard time dealing with changes in my routine", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_23', "23. I am good at making small talk***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_24', "24. I act very set in my ways", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_25', "25. I feel like I am really connecting with other people", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_26', "26. People get frustrated by my unwillingness to bend", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_27', "27. Conversation bores me***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_28', "28. I am warm and friendly in my interactions with others***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_29', "29. I leave long pauses in conversation", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_30', "30. I alter my daily routine by trying something different", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_31', "31. I prefer to be alone rather than with others", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_32', "32. I lose track of my original point when talking to people", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_33', "33. I like to closely follow a routine while working", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_34', "34. I can tell when it is time to change topics in conversation ***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_35', "35. I keep doing things the way I know, even if another way might be better", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
        $this->form->addElement('select', 'bapq_36', "36. I enjoy chatting with people ***", array("" => "","1" => "Very rarely","2" => "Rarely","3" => "Occasionally","4" => "Somewhat often","5" => "Often","6" => "Very often") );
    }


}

?>