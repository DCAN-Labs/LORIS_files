<?php

/**
 * This file contains the NDB_BVL_Instrument_puberty_scale
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_puberty_scale extends NDB_BVL_Instrument
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
        $this->testName = 'puberty_scale' ;           // test_names.Test_name
        $this->table = 'puberty_scale';              // name of database table corresponding to instrument
        // FULL NAME: puberty_scale
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
        $this->addHeader("Puberty Scale (Parent)");

        $this->form->addElement('select', 'pdp_male', "1. What sex was your child assigned at birth?", array("" => "","1" => "Male","0" => "Female") );
        $this->form->addElement('select', 'pdp_height', "2. Would you say that your child&#39;s growth in height:", array("" => "","1" => "has not yet begun to spurt","2" => "has barely started","3" => "is definitely underway","4" => "seems complete","5" => "I don't know") );
        $this->form->addElement('select', 'pdp_body_hair', "3. And how about the growth of your child&#39;s body hair (&#34;body hair&#34; means hair any place other than their head, such as under their arms)? Would you say that your child&#39;s body hair growth:", array("" => "","1" => "has not yet begun to grow","2" => "has barely started to grow","3" => "is definitely underway","4" => "seems complete","5" => "I don't know") );
        $this->form->addElement('select', 'pdp_skin', "4. Have you noticed any changes to their skin, especially pimples?", array("" => "","1" => "skin has not yet started changing","2" => "skin has barely started changing","3" => "skin changes are definitely underway","4" => "skin changes seem complete","5" => "I don't know") );
        
        $this->addHeader("<h3>Female Only Questions</h3>");
        $this->form->addElement('select', 'pdp_breasts', "5. Have you noticed that your child&#39;s breasts have begun to grow?", array("" => "","1" => "have not yet started growing","2" => "have barely started growing","3" => "breast growth is definitely underway","4" => "breast growth seems complete","5" => "I don't know") );
        $this->form->addElement('select', 'pdp_menstruate', "6. Has your child begun to menstruate?", array("" => "","1" => "Yes","0" => "No","5" => "I don't know") );
        $this->form->addElement('text','pdp_menstruate_age',"7. How old were they when they started to menstruate?");
        $this->form->addElement('select', 'pdp_menstruate_age_dk', "7. How old were they when they started to menstruate?", array("" => "","5" => "Don't know") );
        $this->form->addElement('text','pdp_days_between',"9. On average, how many days are there between the first day of their period and the first day of their next period? (e.g., 30 days)");
        $this->form->addElement('select', 'pdp_days_between_dk', "9. On average, how many days are there between the first day of their period and the first day of their next period? (e.g., 30 days)", array("" => "","5" => "Don't know") );
        $this->form->addElement('select', 'pdp_cycle_reg', "10. Is your child&#39;s menstrual cycle regular?", array("" => "","1" => "Yes","0" => "No","5" => "Don't know") );
        $this->form->addElement('select', 'pdp_horm_birth_control', "11. Is your child currently using hormonal birth control (e.g. the pill, hormone patch, hormone injection)?", array("" => "","1" => "Yes","0" => "No","5" => "Don't know") );
        $this->form->addElement('select', 'pdp_premen', "12. Do they experience premenstrual irritability, fatigue, tearfulness, etc., which start before their period and stop within a few days of bleeding?", array("" => "","0" => "Not at all","1" => "Mild","2" => "Moderate","3" => "Severe","5" => "Don't know") );
        $this->form->addElement('select', 'pdp_premen_interfere', "13. Do their premenstrual symptoms interfere with their relationships with family and friends, productivity, and/or social life activities?", array("" => "","0" => "Not at all","1" => "Mild","2" => "Moderate","3" => "Severe","5" => "Don't know") );
        
        $this->addHeader("<h3>Male Only Questions</h3>");
        $this->form->addElement('select', 'pdp_facial_hair', "5. Has he begun to grow hair on his face?", array("" => "","1" => "facial hair has not yet started growing","2" => "facial hair has barely started growing","3" => "facial hair has definitely started","4" => "facial growth seems complete","5" => "I don't know") );
        $this->form->addElement('select', 'pdp_voice', "6. Have you noticed a deepening of his voice?", array("" => "","1" => "voice has not yet started changing","2" => "voice has barely started changing","3" => "voice changes are definitely underway","4" => "voice changes seem complete","5" => "I don't know") );
    }


}

?>