<?php

/**
 * This file contains the NDB_BVL_Instrument_sleep_habits
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_sleep_habits extends NDB_BVL_Instrument
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
        $this->testName = 'sleep_habits' ;           // test_names.Test_name
        $this->table = 'sleep_habits';              // name of database table corresponding to instrument
        // FULL NAME: sleep_habits
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
        $this->addHeader("Sleep Habits");

        $this->form->addElement('select', 'sleepdisturb1_p', "How many hours of sleep does your child get on most nights?", array("" => "","1" => "9-11 hours","2" => "8-9 hours","3" => "7-8 hours","4" => "5-7 hours","5" => "Less than 5 hours") );
        $this->form->addElement('select', 'sleepdisturb2_p', "How long after going to bed does your child usually fall asleep? ", array("" => "","1" => "Less than 15 minutes","2" => "15-30 minutes","3" => "30-45 minutes","4" => "45-60 minutes","5" => "More than 60 minutes") );
        $this->form->addElement('select', 'sleepdisturb3_p', "The child goes to bed reluctantly.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb4_p', "The child has difficulty getting to sleep at night.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb5_p', "The child feels anxious or afraid when falling asleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb6_p', "The child startles or jerks parts of the body while falling asleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb7_p', "The child shows repetitive actions such as rocking or head-banging while falling asleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb8_p', "The child experiences vivid dream-like scenes while falling asleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb9_p', "The child sweats excessively while falling asleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb10_p', "The child wakes up more than twice per night.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb11_p', "After waking up in the night, the child has difficulty falling asleep again.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb12_p', "The child has frequent twitching or jerking of legs while asleep or often changes position during the night or kicks the covers off the bed.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb13_p', "The child has difficulty breathing during the night.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb14_p', "The child gasps for breaths or is unable to breathe during sleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb15_p', "The child snores.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb16_p', "The child sweats excessively during the night.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb17_p', "You have observed the child sleepwalking.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb18_p', "You have observed the child talking in his/her sleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb19_p', "The child grinds his/her teeth during sleep.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb20_p', "The child wakes from sleep screaming or confused so you cannot seem to get through to him/her but has no memory of these events the next morning.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb21_p', "The child has nightmares which he/she doesn&#39;t remember the next day.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb22_p', "The child is unusually difficult to wake up in the morning.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb23_p', "The child awakes in the morning feeling tired.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb24_p', "The child feels unable to move when waking up in the morning.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb25_p', "The child experiences daytime sleepiness.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
        $this->form->addElement('select', 'sleepdisturb26_p', "The child falls asleep suddenly in inappropriate situations.", array("" => "","1" => "Never","2" => "Occasionally (once or twice per month or less)","3" => "Sometimes (once or twice per week)","4" => "Often (3 or 5 times per week)","5" => "Always (daily)") );
    }


}

?>