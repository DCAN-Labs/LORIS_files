<?php

/**
 * This file contains the NDB_BVL_Instrument_biofeedback_user_survey
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_biofeedback_user_survey extends NDB_BVL_Instrument
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
        $this->testName = 'biofeedback_user_survey' ;           // test_names.Test_name
        $this->table = 'biofeedback_user_survey';              // name of database table corresponding to instrument
        // FULL NAME: biofeedback_user_survey
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
        $this->addHeader("Biofeedback User Survey");

        $this->form->addElement('select', 'biofeedback_1', "Which biofeedback did you watch during your scan today? ", array("" => "","1" => "Puppy Dreams","2" => "Luma Cave","3" => "Friendly Forest") );
        $this->form->addElement('select', 'biofeedback_3', "Did the games/movie help you stay still?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'biofeedback_4', "How did you know if you were moving too much?", array("" => "","1" => "The screen got smaller","2" => "Someone told me","3" => "I could feel that I was moving","4" => "Other (describe in the box below)") );
        $this->form->addElement('select', 'biofeedback_2', "How did you like watching a movie/playing a game during the MRI exam on a scale of 1 (did not like it at all) to 5 (liked it a lot)?", array("" => "","1" => "1 (did not like it at all)","2" => "2 (didn't really like it)","3" => "3 (neutral)","4" => "4 (kind of liked it)","5" => "5 (liked it a lot)") );
        $this->form->addElement('select', 'biofeedback_5', "How well did you understand when the game/movie was telling you to stay still on a scale of 1 (did not understand) to 5 (completely understood)?", array("" => "","1" => "1 (did not understand)","2" => "2 (had a hard time understanding)","3" => "3 (neutral)","4" => "4 (sort of understood)","5" => "5 (completely understood)") );
    }


}

?>