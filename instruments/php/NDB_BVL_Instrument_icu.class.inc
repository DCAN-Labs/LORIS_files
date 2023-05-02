<?php

/**
 * This file contains the NDB_BVL_Instrument_icu
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_icu extends NDB_BVL_Instrument
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
        $this->testName = 'icu' ;           // test_names.Test_name
        $this->table = 'icu';              // name of database table corresponding to instrument
        // FULL NAME: icu
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
        $this->addHeader("Inventory of Callous-Unemotional Traits (ICU) - Parent Version");

        $this->addHeader("<h3>Calculated Fields</h3>");
        $this->form->addElement('text','icup_self_total',"ICU Self Total Score");

        $this->addHeader("<h3>Questions</h3>");
        $this->form->addElement('select', 'icup_completed_by', "Completed by", array("" => "","1" => "Mother","2" => "Father","99" => "Other") );
        $this->form->addElement('select', 'icup_1', "1. Expresses his/her feelings openly.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_2', "2. Does not seem to know &#34;right&#34; from &#34;wrong&#34;.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_3', "3. Is concerned about schoolwork.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_4', "4. Does not care who he/she hurts to get what he/she wants.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_5', "5. Feels bad or guilty when he/she has done something wrong.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_6', "6. Does not show emotions.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_7', "7. Does not care about being on time.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_8', "8. Is concerned about the feelings of others.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_9', "9. Does not care if he/she is in trouble.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_10', "10. Does not let feelings control him/her.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_11', "11. Does not care about doing things well.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_12', "12. Seems very cold and uncaring.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_13', "13. Easily admits to being wrong.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_14', "14. It is easy to tell how he/she is feeling.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_15', "15. Always tries his/her best.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_16', "16. Apologizes (&#34;says he/she is sorry&#34;) to persons he/she has hurt.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_17', "17. Tries not to hurt others&#39; feelings.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_18', "18. Shows no remorse when he/she has done something wrong.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_19', "19. Is very expressive and emotional.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_20', "20. Does not like to put the time into doing things well.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_21', "21. The feelings of others are unimportant to him/her.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_22', "22. Hides his/her feelings from others.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_23', "23. Works hard on everything.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
        $this->form->addElement('select', 'icup_24', "24. Does things to make others feel good.", array("" => "","0" => "Not at all true","1" => "Somewhat true","2" => "Very true","3" => "Definitely true") );
    }


}

?>