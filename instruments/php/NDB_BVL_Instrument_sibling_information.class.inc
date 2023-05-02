<?php

/**
 * This file contains the NDB_BVL_Instrument_sibling_information
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_sibling_information extends NDB_BVL_Instrument
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
        $this->testName = 'sibling_information' ;           // test_names.Test_name
        $this->table = 'sibling_information';              // name of database table corresponding to instrument
        // FULL NAME: sibling_information
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
        $this->addHeader("Sibling Information");

        $this->form->addElement('select', 'sib_y_n', "Does the child that is participating in this study have any full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_2', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender_2', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_3', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender_3', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_4', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender_4', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_5', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender_5', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_6', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender_6', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_7', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'sib_1_gender_7', "Sibling&#39;s gender: ", array("" => "","0" => "Male","1" => "Female","2" => "Transgender male","3" => "Transgender female","4" => "Gender variant/non-conforming","5" => "Not listed","6" => "Skip") );
        $this->form->addElement('select', 'sib_y_n_8', "Does the child that is participating in this study have more full of half siblings? ", array("" => "","0" => "No","1" => "Yes") );
    }


}

?>