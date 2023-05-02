<?php

/**
 * This file contains the NDB_BVL_Instrument_puberty_scale_child
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_puberty_scale_child extends NDB_BVL_Instrument
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
        $this->testName = 'puberty_scale_child' ;           // test_names.Test_name
        $this->table = 'puberty_scale_child';              // name of database table corresponding to instrument
        // FULL NAME: puberty_scale_child
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
        $this->addHeader("Puberty Scale (Child)");

        $this->form->addElement('select', 'pdy_male', "Do you consider yourself male or female?", array("" => "","1" => "Male","0" => "Female") );
        $this->form->addElement('select', 'pdy_height', "Would you say that your growth in height:", array("" => "","1" => "Has not yet begun to spurt (spurt means grow faster than usual)","2" => "Has barely started","3" => "Is definitely underway (has definitely started)","4" => "Seems complete","5" => "I don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_skin', "Have you noticed any skin changes, especially pimples?", array("" => "","1" => "Skin has not yet started changing","2" => "Skin has barely started changing","3" => "Skin changes are definitely underway (has definitely started)","4" => "Skin changes seem complete","5" => "I don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_body_hair', "And how about the growth of your body hair? (&#34;Body hair&#34; means hair any place other than their head, such as under their arms)? Would you say that your body hair growth:", array("" => "","1" => "Has not yet begun to spurt (spurt means grow faster than usual)","2" => "Has barely started","3" => "Is definitely underway (has definitely started)","4" => "Seems complete","5" => "I don't know","6" => "Refuse to answer") );

        $this->addHeader("<h3>Female Only Questions</h3>");
        $this->form->addElement('select', 'pdy_breasts', "Have you noticed that your breasts have begun to grow?", array("" => "","1" => "Have not yet started growing","2" => "Have barely started growing","3" => "Breast growth is definitely underway (has definitely started)","4" => "Breast growth seems complete","5" => "I don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_menstruate', "Have you begun to menstruate (started to have your period)?", array("" => "","1" => "Yes","0" => "No","5" => "I don't know","6" => "Refuse to answer") );
        $this->form->addElement('text','pdy_menstruate_age',"If yes, how old were you when you started to menstruate?");
        $this->form->addElement('select', 'pdy_menstruate_age_dk', "If yes, how old were you when you started to menstruate?", array("" => "","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('text','pdy_days_between',"On average, how many days are there between the first day of your period and the first day of your next period? For example, if the first day of bleeding is typically at the beginning of each month, the interval between periods is 30 days.");
        $this->form->addElement('select', 'pdy_days_between_dk', "On average, how many days are there between the first day of your period and the first day of your next period?", array("" => "","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_cycle_reg', "Is your menstrual cycle regular?", array("" => "","1" => "Yes","0" => "No","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_cycle_length', "On average, how long does your menstrual period 1-2 days (bleeding) last?", array("" => "","1" => "1-2 days","2" => "3-7 days","3" => "More than 7 days") );
        $this->form->addElement('select', 'pdy_cycle_flow', "Do you experience a light, medium, or heavy flow?", array("" => "","1" => "Light","2" => "Medium","3" => "Heavy") );
        $this->form->addElement('select', 'pdy_horm_birth_control', "Are you currently using hormonal birth control (eg. the pill, hormone patch, hormone injection)?", array("" => "","1" => "Yes","0" => "No","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_form_birth_control', "What form of birth control do you use?", array("" => "","1" => "Birth control pill (e.g. Yasmin","2" => "Birth control patch","3" => "Birth control shot (e.g. depo-provera shot)","4" => "Birth control implant (e.g. Nexplanon)","5" => "Hormonal IUD (e.g. Mirena)","6" => "Other","7" => "Don't know") );
        $this->form->addElement('select', 'pdy_birth_control_pill', "Do you use the birth control pill (e.g. Yasmin, Yaz)?", array("" => "","1" => "Yes","0" => "No","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_premen', "Do you experience premenstrual symptoms, such as irritability, fatigue, etc., which start before your period and stop within a few days of bleeding?", array("" => "","0" => "Not at all","1" => "Mild","2" => "Moderate","3" => "Severe","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_premen_interfere', "Do your premenstrual symptoms interfere with your relationships with family and friends, productivity, and/or social life activities?", array("" => "","0" => "Not at all","1" => "Mild","2" => "Moderate","3" => "Severe","5" => "Don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_men_pain_int', "On average, how would you rate the intensity of your menstrual pain on a scale of 0-10? 0 (No pain at all) - 10 (the worst pain I have ever felt)", array("" => "","0" => "0","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","10" => "10") );
        $this->form->addElement('select', 'pdy_men_pain_length', "How long does your menstrual pain last?", array("" => "","0" => "0 days","1" => "1 day","2" => "2 days","3" => "3 days","4" => "4 days or more") );
        $this->form->addElement('select', 'pdy_men_pain_act', "How much does your menstrual pain stop you from doing your usual activities? 0 (Not at all) - 10 (stops me from doing anything)", array("" => "","0" => "0","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","10" => "10") );

        $this->addHeader("<h3>Male Only Questions</h3>");
        $this->form->addElement('select', 'pdy_voice', "Have you noticed a deepening of your voice?", array("" => "","1" => "Voice has not yet started changing","2" => "Voice has barely started changing","3" => "Voice changes are definitely underway","4" => "Voice changes seem complete","5" => "I don't know","6" => "Refuse to answer") );
        $this->form->addElement('select', 'pdy_facial_hair', "Have you begun to grow hair on your face?", array("" => "","1" => "Facial hair has not yet started growing","2" => "Facial hair has barely started growing","3" => "Facial hair has definitely started","4" => "Facial growth seems complete","5" => "I don't know","6" => "Refuse to answer") );
        
        $this->addHeader("<h3>Administration</h3>");

        $this->form->addElement('text','pdy_admin',"Remote method of Pubertal Developmental Scale administration [Check all that apply]:");
        $this->form->addElement('text','pdy_device',"Youth&#39;s Device");
    }


}

?>