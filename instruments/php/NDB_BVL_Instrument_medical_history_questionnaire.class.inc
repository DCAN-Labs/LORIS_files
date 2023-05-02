<?php

/**
 * This file contains the NDB_BVL_Instrument_medical_history_questionnaire
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_medical_history_questionnaire extends NDB_BVL_Instrument
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
        $this->testName = 'medical_history_questionnaire' ;           // test_names.Test_name
        $this->table = 'medical_history_questionnaire';              // name of database table corresponding to instrument
        // FULL NAME: medical_history_questionnaire
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
        $this->addHeader("Medical History Questionnaire");

        $this->form->addElement('select', 'medhx_1a_l', "&lt;b&gt;During the past year, has your child been to see a doctor, nurse, nurse practitioner, dentist, or any other health professional, OTHER than for regular checkups?", array("" => "","1" => "Yes","0" => "No","6" => "Don't know") );
        $this->form->addElement('select', 'medhx_2a_l', "Asthma", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2b_l', "Allergies", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2c_l', "Brain Injury", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2d_l', "Bronchitis", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2e_l', "Cancer/Leukemia", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2f_l', "Cerebral Palsy", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2g_l', "Diabetes", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2h_l', "Epilepsy or Seizures", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2i_l', "Hearing Problem", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2j_l', "Kidney Disease", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2k_l', "Lead Poisoning", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2l_l', "Muscular Dystrophy", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2m_l', "Multiple Sclerosis", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2n_l', "Problems with Vision (including the need for glasses)", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2o_l', "Problems with Heart", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2p_l', "Sickle Cell Anemia", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2q_l', "Very Bad Headaches", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2r_l', "An Operation", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2t_l', "Rare Medical Condition not on this list", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_2_notes2_l', "Any Other Illness", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_4a_l', "Has he/she ever been to an emergency room?", array("" => "","1" => "Yes","0" => "No","6" => "Don't know","7" => "Refuse to answer") );
        $this->form->addElement('select', 'medhx_4b_l', "How many times has he/she been to the emergency room?", array("" => "","1" => "1 time","2" => "2 times","3" => "3-4 times","4" => "5-9 times","5" => "10+ times") );
        $this->form->addElement('select', 'medhx_6a_l', "Broken Bones", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6a_notes_l',"&lt;center&gt;Broken bones: How many times?&lt;/center&gt;");
        $this->form->addElement('select', 'medhx_6b_l', "Sprains", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6b_notes_l',"&lt;center&gt;Sprains: How many times?");
        $this->form->addElement('select', 'medhx_6c_l', "Cuts or Scrapes", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6c_times_l',"&lt;center&gt;Cuts or Scrapes: How many times?");
        $this->form->addElement('select', 'medhx_6d_l', "Stitches", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6d_notes_l',"&lt;center&gt;Stitches: How many times?");
        $this->form->addElement('select', 'medhx_6e_l', "Other Serious Wounds", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6e_times_l',"&lt;center&gt;Other Serious Wounds: How many times?");
        $this->form->addElement('select', 'medhx_6f_l', "Falls", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6f_notes_l',"&lt;center&gt;Falls: How many times?");
        $this->form->addElement('select', 'medhx_6g_l', "Burns", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6g_times_l',"&lt;center&gt;Burns: How many times?");
        $this->form->addElement('select', 'medhx_6h_l', "High Fever
", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6h_times_l',"&lt;center&gt;High Fever: How many times?");
        $this->form->addElement('select', 'medhx_6i_l', "Head Injury", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6i_times_l',"&lt;center&gt;Head Injury: How many times?");
        $this->form->addElement('select', 'medhx_6j_l', "Knocked Unconscious", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6j_times_l',"&lt;center&gt;Knocked Unconscious: How many times?");
        $this->form->addElement('select', 'medhx_6k_l', "Bruises", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6k_times_l',"&lt;center&gt;Bruises: How many times?");
        $this->form->addElement('select', 'medhx_6l_l', "Asthma Attack", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6l_notes_l',"&lt;center&gt;Asthma Attack: How many times?");
        $this->form->addElement('select', 'medhx_6m_l', "Broken Teeth", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6m_times_l',"&lt;center&gt;Broken Teeth: How many times?");
        $this->form->addElement('select', 'medhx_6n_l', "Animal Bite", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6n_notes_l',"&lt;center&gt;Animal Bite: How many times?");
        $this->form->addElement('select', 'medhx_6o_l', "Overdose", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6o_notes_l',"&lt;center&gt;Overdose: How many times?");
        $this->form->addElement('select', 'medhx_6p_l', "Seizure", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6p_notes_l',"&lt;center&gt;Seizure: How many times?");
        $this->form->addElement('select', 'medhx_6q_l', "Accidental Poisoning", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6q_notes_l',"&lt;center&gt;Accidental Poisoning: How many times?");
        $this->form->addElement('select', 'medhx_6r_l', "Gun Shot Wound", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6r_notes_l',"&lt;center&gt;Gun Shot Wound: How many times?");
        $this->form->addElement('select', 'medhx_6s_l', "Wound from knife or any other weapon", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6s_times_l',"&lt;center&gt;Knife or Other Weapon Wound: How many times?");
        $this->form->addElement('select', 'medhx_6t_l', "Other", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','medhx_6t_times_l',"&lt;center&gt;Other: How many times?");
        $this->form->addElement('select', 'medhx_8a_l', "Has he/she ever been in the hospital overnight or longer?", array("" => "","1" => "Yes","0" => "No","6" => "Don't know") );
        $this->form->addElement('select', 'medhx_9a_l', "Has he/she ever had general anesthesia or sedation for any surgery or procedure?
", array("" => "","1" => "Yes","0" => "No","6" => "Don't know") );
        $this->form->addElement('text','medhx_9b_l',"&lt;center&gt;General Anesthesia or Sedation: How many times?");
        $this->form->addElement('text','medhx_9c_l',"&lt;center&gt;At what age for the most recent time?");
        $this->form->addElement('select', 'medhx_11_l', "&lt;b&gt;Is he/she able to see the difference between blue and green?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medhx_12_l', "&lt;b&gt;How about the difference between blue and yellow?

", array("" => "","1" => "Yes","0" => "No") );
    }


}

?>