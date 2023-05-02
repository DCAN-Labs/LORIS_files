<?php

/**
 * This file contains the NDB_BVL_Instrument_developmental_history_questionnaire
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_developmental_history_questionnaire extends NDB_BVL_Instrument
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
        $this->testName = 'developmental_history_questionnaire' ;           // test_names.Test_name
        $this->table = 'developmental_history_questionnaire';              // name of database table corresponding to instrument
        // FULL NAME: developmental_history_questionnaire
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
        $this->addHeader("Developmental History Questionnaire");

        $this->form->addElement('select', 'devhx_1_p', "Are you the child&#39;s biological mother?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','devhx_2_p',"At birth, how much did the child weigh in &lt;u&gt;pounds&lt;/u&gt;?");
        $this->form->addElement('select', 'devhx_2_p_dk', "At birth, how much did the child weigh in &lt;u&gt;pounds&lt;/u&gt;?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_2b_p',"&lt;b&gt;and ounces?");
        $this->form->addElement('select', 'devhx_2b_p_dk', "&lt;b&gt;and ounces?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_3_p',"How old were you/biological mother when the child was born?");
        $this->form->addElement('select', 'devhx_3_p_dk', "How old were you/biological mother when the child was born?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_4_p',"How old was the child&#39;s biological father when he/she was born?");
        $this->form->addElement('select', 'devhx_4_p_dk', "How old was the child&#39;s biological father when he/she was born?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_5_p', "Does your child have a twin?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_6_p', "Was the pregnancy with this child a planned pregnancy?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_7_p',"How far along (in weeks) were you with your child when you found out that you were pregnant?");
        $this->form->addElement('select', 'devhx_7_p_dk', "How far along (in weeks) were you with your child when you found out that you were pregnant?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_prescript_med', "Prescription medications? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_med1_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_med1_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_med1_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_med1_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_8_med1_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_med1_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_med1_fu', "Any other prescription medications?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'devhx_8_med2_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_med2_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_med2_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_med2_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_8_med2_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_med2_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_med2_fu', "Any other prescription medications?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'devhx_8_med3_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_med3_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_med3_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_med3_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_8_med3_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_med3_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_tobacco', "Tobacco?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_cigs_per_day',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_cigs_per_day_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_alcohol', "Alcohol?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_alchohol_max',"Maximum drinks in one sitting?");
        $this->form->addElement('select', 'devhx_8_alchohol_max_dk', "Maximum drinks in one sitting?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_alchohol_avg',"Average drinks per/week");
        $this->form->addElement('select', 'devhx_8_alchohol_avg_dk', "Average drinks per/week", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_alcohol_effects',"How many drinks did it take to feel the effects of alcohol?");
        $this->form->addElement('select', 'devhx_8_alcohol_effects_dk', "How many drinks did it take to feel the effects of alcohol?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_marijuana', "Marijuana?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_marijuana_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_marijuana_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_coc_crack', "Cocaine/Crack?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_coc_crack_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_coc_crack_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_her_morph', "Heroin/Morphine?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_her_morph_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_her_morph_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_oxycont', "Oxycontin?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_oxycont_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_oxycont_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other_drugs', "Any other drugs?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other1_name_2', "Name of drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_other1_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_other1_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_other1_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_8_other1_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other1_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_other2_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_other2_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_other2_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_other2_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_8_other2_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other2_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_other3_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","14" => "Steroids (arnolds","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_other3_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_other3_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_other3_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_8_other3_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other3_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_other4_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_other4_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_other4_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_other4_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_8_other4_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other4_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_8_other5_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_8_other5_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_8_other5_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_8_other5_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_8_other5_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_8_other5_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_prescript_med', "Prescription medications? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_med1_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_med1_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_med1_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_med1_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_9_med1_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_med1_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_med1_fu', "Any other prescription medications?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'devhx_9_med2_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_med2_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_med2_rxnorm_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_med2_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_9_med2_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_med2_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_med2_fu2', "Any other prescription medications?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'devhx_9_med3_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_med3_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_med3_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_med3_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_9_med3_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_med3_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_med3_fu', "Any other prescription medications?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'devhx_9_med4_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_med4_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_med4_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_med4_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_9_med4_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_med4_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_med4_fu', "Any other prescription medications?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'devhx_9_med5_prn', "PRN (as needed) Medication? ", array("" => "","1" => "Yes","0" => "No","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_med5_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_med5_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_med5_how_much',"How much each time?");
        $this->form->addElement('select', 'devhx_9_med5_how_much_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_med5_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_tobacco', "Tobacco?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_cigs_per_day',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_cigs_per_day_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_alcohol', "Alcohol?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_alchohol_max',"Maximum drinks in one sitting?");
        $this->form->addElement('select', 'devhx_9_alchohol_max_dk', "Maximum drinks in one sitting?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_alchohol_avg',"Average drinks per/week");
        $this->form->addElement('select', 'devhx_9_alchohol_avg_dk', "Average drinks per/week", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_alcohol_effects',"How many drinks did it take to feel the effects of alcohol?");
        $this->form->addElement('select', 'devhx_9_alcohol_effects_dk', "How many drinks did it take to feel the effects of alcohol?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_marijuana', "Marijuana?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_marijuana_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_marijuana_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_coc_crack', "Cocaine/Crack?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_coc_crack_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_coc_crack_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_her_morph', "Heroin/Morphine?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_her_morph_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_her_morph_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_oxycont', "Oxycontin?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_oxycont_amt',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_oxycont_amt_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other_drugs', "Any other drugs? (not ones prescribed by your doctor and not ones that are over the counter)&lt;/span&gt;", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other1_name_2', "Name of drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_other1_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_other1_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_other1_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_9_other1_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other1_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_other2_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_other2_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_other2_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_other2_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_9_other2_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other2_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_other3_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_other3_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_other3_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other3_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('text','devhx_9_other3_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_9_other3_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other4_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_other4_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_other4_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_other4_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_9_other4_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other4_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_9_other5_name_2', "Name of additional drug", array("" => "","0" => "None","1" => "Amphetamines or methamphetamine (meth","13" => "Barbituates","14" => "Steroids (arnolds","2" => "Benzodiazepines","4" => "Cathinones (bath salts","5" => "Fake or synthetic marijuana (like spice or K2)","6" => "GHB (liquid G or Georgia home boy)","7" => "Hallucinogens (LSD or acid","8" => "Inhalants","9" => "Ketamine (special K)","10" => "MDMA (ecstasy","11" => "Opioids","12" => "Other","999" => "Don't Know") );
        $this->form->addElement('text','devhx_9_other5_times',"How many times per day?");
        $this->form->addElement('select', 'devhx_9_other5_times_dk', "How many times per day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_9_other5_amt',"How much each time?");
        $this->form->addElement('select', 'devhx_9_other5_amt_dk', "How much each time?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_9_other5_unit', "Unit(s):", array("" => "","1" => "gram (g)","2" => "microgram (mcg)","3" => "milligram (mg)","4" => "kilogram (kg)","5" => "megagram (mgg)","6" => "liter (L)","7" => "ounce (oz)","8" => "pound (lb)","9" => "quart (qt)","10" => "International Units (IU)") );
        $this->form->addElement('select', 'devhx_10', "Did you/biological mother take prenatal vitamins during the pregnancy?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know","-1" => "Not applicable") );
        $this->form->addElement('select', 'devhx_caffeine_11', "Did you/biological mother have any caffeine during pregnancy (from conception until delivery)?", array("" => "","1" => "Yes - at least once a day","2" => "Yes - less than once a day but more than once a week","3" => "Yes - less than once a week","0" => "No","999" => "Don't know","-1" => "Not applicable") );
        $this->form->addElement('text','devhx_caffeine_amt',"How much caffeine/day?");
        $this->form->addElement('select', 'devhx_caffeine_amt_dk', "How much caffeine/day?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_caff_amt_week',"How much caffeine/week?");
        $this->form->addElement('select', 'devhx_caff_amt_week_dk', "How much caffeine/week?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_caff_amt_month',"How much caffeine/month?");
        $this->form->addElement('select', 'devhx_caff_amt_month_dk', "How much caffeine/month?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10a3_p', "Severe nausea and vomiting extending past the 6th month or accompanied by weight loss?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10b3_p', "Heavy bleeding requiring bed rest or special treatment?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10c3_p', "Pre-eclampsia, eclampsia, or toxemia?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10d3_p', "Severe gall bladder attack?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10e3_p', "Persistent proteinuria?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10f3_p', "Rubella (German measles) during first 3 months of pregnancy?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10g3_p', "Severe anemia?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10h3_p', "Urinary tract infections?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10i3_p', "Pregnancy-related diabetes?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10j3_p', "Pregnancy-related high blood pressure?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10k3_p', "Previa, abruptio, or other problems with the placenta?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10l3_p', "An accident or injury requiring medical care?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_10m3_p', "Any other conditions requiring medical care?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_11_p',"About how many times did you/biological mother see a doctor or other medical professional for prenatal care during this pregnancy?");
        $this->form->addElement('select', 'devhx_11_p_dk', "About how many times did you/biological mother see a doctor or other medical professional for prenatal care during this pregnancy?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'weeks_born_unknown', "At how many weeks was the child born? ", array("" => "","1" => "Don't know") );
        $this->form->addElement('select', 'devhx_12a_p', "Was the child born prematurely?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_12_p', "About how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;weeks&lt;/span&gt; premature was the child when they were born?", array("" => "","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","10" => "10","11" => "11","12" => "12","13" => "Greater than 12","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_13_3_p', "Was he/she born by Caesarian section?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14a3_p', "Blue at birth?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14b3_p', "Slow heart beat?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14c3_p', "Did not breathe at first?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14d3_p', "Convulsions?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14e3_p', "Jaundice needing treatment?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14f3_p', "Required oxygen?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14g3_p', "Required blood transfusion?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_14h3_p', "Rh incompatibility?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('text','devhx_15',"For how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;days&lt;/span&gt; after birth was he/she in an incubator?");
        $this->form->addElement('select', 'devhx_15_dk', "For how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;days&lt;/span&gt; after birth was he/she in an incubator?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_16_p',"About how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;days&lt;/span&gt; in the first 12 months of life, did he/she have a fever of 104 degrees or greater?");
        $this->form->addElement('select', 'devhx_16_p_dk', "About how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;days&lt;/span&gt; in the first 12 months of life, did he/she have a fever of 104 degrees or greater?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_17_p',"About how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;days&lt;/span&gt; in the first 12 months of life did he/she have any infections or serious illnesses?");
        $this->form->addElement('select', 'devhx_17_p_dk', "About how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;days&lt;/span&gt; in the first 12 months of life did he/she have any infections or serious illnesses?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_18_p',"For how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;months&lt;/span&gt; was he/she breast fed?");
        $this->form->addElement('select', 'devhx_18_p_dk', "For how many &lt;span style=&#34;text-decoration: underline;&#34;&gt;months&lt;/span&gt; was he/she breast fed?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_19a_p',"Roll over?");
        $this->form->addElement('select', 'devhx_19a_p_dk', "Roll over?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_19b_p',"Sit without assistance?");
        $this->form->addElement('select', 'devhx_19b_p_dk', "Sit without assistance?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_19c_p',"Walk without assistance?");
        $this->form->addElement('select', 'devhx_19c_p_dk', "Walk without assistance?", array("" => "","999" => "Don't know") );
        $this->form->addElement('text','devhx_19d_p',"Say his/her first word?");
        $this->form->addElement('select', 'devhx_19d_p_dk', "Say his/her first word?", array("" => "","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_20_p', "Would you say his/her motor development (sitting, crawling, walking) was earlier, average, or later than most other children?", array("" => "","1" => "Much earlier","2" => "Somewhat earlier","3" => "About average","4" => "Somewhat later","5" => "Much later","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_21_p', "Would you say his/her speech development was earlier, average,  or later than most other children?", array("" => "","1" => "Much earlier","2" => "Somewhat earlier","3" => "About average","4" => "Somewhat later","5" => "Much later","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_22_3_p', "Has your child ever wet the bed at night?", array("" => "","1" => "Yes","0" => "No","999" => "Don't know") );
        $this->form->addElement('select', 'devhx_23b_p', "At what age &lt;span style=&#34;text-decoration: underline;&#34;&gt;(in years)&lt;/span&gt; did he/she stop wetting the bed at night?", array("" => "","1" => "1","2" => "2","3" => "3","4" => "4","5" => "5","6" => "6","7" => "7","8" => "8","9" => "9","10" => "10","12" => "Still wets bed","999" => "Don't know") );
    }


}

?>