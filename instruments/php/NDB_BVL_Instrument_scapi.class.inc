<?php

/**
 * This file contains the NDB_BVL_Instrument_scapi
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_scapi extends NDB_BVL_Instrument
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
        $this->testName = 'scapi' ;           // test_names.Test_name
        $this->table = 'scapi';              // name of database table corresponding to instrument
        // FULL NAME: scapi
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
        $this->addHeader("Services for Children and Adolescents - Parent Interview (SCAPI)");

        $this->form->addElement('select', 'scapi_any_stimulant', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;&lt;span style=&#34;font-weight: normal;&#34;&gt;Has your child taken any stimulant medication for ADD/ADHD?&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No (If no","1" => "Yes") );
        $this->form->addElement('text','scapi_stim_current_1',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;&lt;span style=&#34;font-weight: normal;&#34;&gt;OR&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('text','scapi_stim_current_2',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;&lt;span style=&#34;font-weight: normal;&#34;&gt;OR&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('text','scapi_stim_current_3',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;&lt;span style=&#34;font-weight: normal;&#34;&gt;OR&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('text','scapi_stim_current_4',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;&lt;span style=&#34;font-weight: normal;&#34;&gt;OR&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('select', 'scapi_curr_prescribed', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;Is your child &lt;span style=&#34;text-decoration: underline;&#34;&gt;currently &lt;/span&gt;prescribed (&lt;em&gt;even if they stop in the summer&lt;/em&gt;) any stimulant medication for ADD/ADHD?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No (If no","1" => "Yes (If yes") );
        $this->form->addElement('text','scapi_adderall',"-1");
        $this->form->addElement('select', 'scapi_adderall_dose', "Current Dosage", array("" => "","5" => "5","7.5" => "7.5","10" => "10","12.5" => "12.5","15" => "15","20" => "20","30" => "30") );
        $this->form->addElement('select', 'scapi_adderall_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_adderallxr',"-2");
        $this->form->addElement('select', 'scapi_adderallxr_dose', "Current Dosage", array("" => "","10" => "10","20" => "20","30" => "30") );
        $this->form->addElement('select', 'scapi_adderallxr_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_concerta',"-3");
        $this->form->addElement('select', 'scapi_concerta_dose', "Current Dosage", array("" => "","18" => "18","27" => "27","36" => "36","54" => "54") );
        $this->form->addElement('select', 'scapi_concerta_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_cylert',"-4");
        $this->form->addElement('select', 'scapi_cylert_dose', "Current Dosage", array("" => "","18.75" => "18.75","37.5" => "37.5","75" => "75") );
        $this->form->addElement('select', 'scapi_cylert_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_daytrana',"-5");
        $this->form->addElement('select', 'scapi_daytrana_dose', "Current Dosage", array("" => "","10" => "10","15" => "15","20" => "20","30" => "30") );
        $this->form->addElement('select', 'scapi_daytrana_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_desoxyn',"-6");
        $this->form->addElement('select', 'scapi_desoxyn_dose', "Current Dosage", array("" => "","5" => "5") );
        $this->form->addElement('select', 'scapi_desoxyn_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_dexe_tab',"-7");
        $this->form->addElement('select', 'scapi_dexe_tab_dose', "Current Dosage", array("" => "","5" => "5") );
        $this->form->addElement('select', 'scapi_dexe_tab_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_dexe_cap',"-8");
        $this->form->addElement('select', 'scapi_dexe_cap_dose', "Current Dosage", array("" => "","5" => "5","10" => "10","15" => "15") );
        $this->form->addElement('select', 'scapi_dexe_cap_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_dextrostat',"-9");
        $this->form->addElement('select', 'scapi_dextrostat_dose', "Current Dosage", array("" => "","5" => "5","10" => "10") );
        $this->form->addElement('select', 'scapi_dextrostat_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_focalin',"-10");
        $this->form->addElement('select', 'scapi_focalin_dose', "Current Dosage", array("" => "","2.5" => "2.5","5" => "5","10" => "10") );
        $this->form->addElement('select', 'scapi_focalin_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_metadatecd',"-11");
        $this->form->addElement('select', 'scapi_metadatecd_dose', "Current Dosage", array("" => "","20" => "20") );
        $this->form->addElement('select', 'scapi_metadatecd_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_metadateer',"-12");
        $this->form->addElement('select', 'scapi_metadateer_dose', "Current Dosage", array("" => "","10" => "10","20" => "20") );
        $this->form->addElement('select', 'scapi_metadateer_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_methyliner',"-13");
        $this->form->addElement('select', 'scapi_methyliner_dose', "Current Dosage", array("" => "","10" => "10","20" => "20") );
        $this->form->addElement('select', 'scapi_methyliner_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_methylin',"-14");
        $this->form->addElement('select', 'scapi_methylin_dose', "Current Dosage", array("" => "","5" => "5","10" => "10","20" => "20") );
        $this->form->addElement('select', 'scapi_methylin_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_ritalinhcl',"-15");
        $this->form->addElement('select', 'scapi_ritalinhcl_dose', "Current Dosage", array("" => "","5" => "5","10" => "10","20" => "20") );
        $this->form->addElement('select', 'scapi_ritalinhcl_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_ritalinla',"-16");
        $this->form->addElement('select', 'scapi_ritalinla_dose', "Current Dosage", array("" => "","5" => "5","10" => "10","20" => "20","30" => "30","40" => "40") );
        $this->form->addElement('select', 'scapi_ritalinla_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_vyvanse',"-17");
        $this->form->addElement('select', 'scapi_vyvanse_dose', "Current Dosage", array("" => "","30" => "30","50" => "50","70" => "70") );
        $this->form->addElement('select', 'scapi_vyvanse_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_oth_stim',"-18");
        $this->form->addElement('select', 'scapi_oth_stim_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_quillivant',"-19");
        $this->form->addElement('select', 'scapi_quillivant_dose', "Current Dosage", array("" => "","10" => "10","20" => "20","30" => "30","40" => "40","50" => "50","60" => "60") );
        $this->form->addElement('select', 'scapi_quillivant_freq', "How Often Each Day", array("" => "","1" => "1","2" => "2","3" => "3","99" => "Other (specify)") );
        $this->form->addElement('text','scapi_age_curr_dose',"1.	How old was your child when they first began taking the current dosage?");
        $this->form->addElement('select', 'scapi_reason_med', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;2. What is the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason the above medication was prescribed?&lt;span style=&#34;font-weight: normal;&#34;&gt; &lt;em&gt;(select one)&lt;/em&gt;&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD/ADD","2" => "learning","3" => "other behavioral/emotional concern","99" => "another (specify) {scapi_reason_med_spec}") );
        $this->form->addElement('select', 'scapi_who_monitor', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;3. Who does your child see for &lt;u&gt;monitoring&lt;/u&gt; of these medications?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "pediatrician","2" => "family doctor","3" => "nurse","4" => "physician's assistant","5" => "psychiatrist","6" => "neurologist","99" => "other (specify) {scapi_who_monitor_spec}") );
        $this->form->addElement('select', 'scapi_monitor_visits', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;4. How many &lt;span style=&#34;text-decoration: underline;&#34;&gt;monitoring&lt;/span&gt; visits has your child had for these medications?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "0","1" => "1-2","2" => "3-4","3" => "5-6","4" => "7+") );
        $this->form->addElement('select', 'scapi_monitor_minutes', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;5. About how long (on average) was &lt;span style=&#34;text-decoration: underline;&#34;&gt;each&lt;/span&gt; monitoring visit for these medications?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1-15 minutes","2" => "16-30 minutes","3" => "31-45 minutes","4" => "46+ minutes") );
        $this->form->addElement('select', 'scapi_seen_another', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;7. H&lt;u&gt;&lt;/u&gt;as your child seen anyone else to monitor the stimulant medications?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'scapi_seen_who', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;&lt;span style=&#34;font-weight: normal;&#34;&gt;If yes, please check:&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "pediatrician","2" => "family doctor","3" => "nurse","4" => "physician's assistant","5" => "psychiatrist","6" => "neurologist","99" => "other (specify) {scapi_seen_who_spec}") );
        $this->form->addElement('select', 'scapi_stopped', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;8. Did your child stop taking the stimulant medication for more than four weeks &lt;span style=&#34;text-decoration: underline;&#34;&gt;during the current or most recent summer&lt;/span&gt;?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'scapi_any_non_stim', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;9(b) Has your child been prescribed any non-stimulant medications?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'scapi_curr_non_stim', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;9(c) Is your child &lt;span style=&#34;text-decoration: underline;&#34;&gt;currently&lt;/span&gt; prescribed any non-stimulant medications?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','scapi_pm_001',"Abilify*");
        $this->form->addElement('text','scapi_pm_002',"Accolate");
        $this->form->addElement('text','scapi_pm_003',"Advair");
        $this->form->addElement('text','scapi_pm_004',"Aerobid");
        $this->form->addElement('text','scapi_pm_005',"Albuterol");
        $this->form->addElement('text','scapi_pm_006',"Allegra");
        $this->form->addElement('text','scapi_pm_007',"Ambien*");
        $this->form->addElement('text','scapi_pm_008',"Anafranil*");
        $this->form->addElement('text','scapi_pm_009',"Anexsia");
        $this->form->addElement('text','scapi_pm_010',"Astelin");
        $this->form->addElement('text','scapi_pm_011',"Ativan*");
        $this->form->addElement('text','scapi_pm_012',"Azelastine");
        $this->form->addElement('text','scapi_pm_013',"Azmacort");
        $this->form->addElement('text','scapi_pm_014',"Benadryl* (prescribed Benadryl only)");
        $this->form->addElement('text','scapi_pm_015',"Buspar*");
        $this->form->addElement('text','scapi_pm_016',"Catapres*");
        $this->form->addElement('text','scapi_pm_017',"Celexa");
        $this->form->addElement('text','scapi_pm_018',"Clarinex");
        $this->form->addElement('text','scapi_pm_019',"Claritin");
        $this->form->addElement('text','scapi_pm_020',"Clonidine*");
        $this->form->addElement('text','scapi_pm_021',"Co-Gesic");
        $this->form->addElement('text','scapi_pm_022',"Cymbalta*");
        $this->form->addElement('text','scapi_pm_023',"Cyntevo");
        $this->form->addElement('text','scapi_pm_024',"Cytomel");
        $this->form->addElement('text','scapi_pm_025',"Darvocet");
        $this->form->addElement('text','scapi_pm_026',"Darvon-N");
        $this->form->addElement('text','scapi_pm_027',"Decadron");
        $this->form->addElement('text','scapi_pm_028',"Depakote*");
        $this->form->addElement('text','scapi_pm_029',"Desmopressin (DDAVP)");
        $this->form->addElement('text','scapi_pm_030',"Effexor*");
        $this->form->addElement('text','scapi_pm_031',"Elavil/Endep*");
        $this->form->addElement('text','scapi_pm_032',"Emsam patch*");
        $this->form->addElement('text','scapi_pm_033',"Eskalith ER*");
        $this->form->addElement('text','scapi_pm_034',"Flovent");
        $this->form->addElement('text','scapi_pm_035',"Fluticasone");
        $this->form->addElement('text','scapi_pm_036',"Geodon*");
        $this->form->addElement('text','scapi_pm_037',"Growth Hormones");
        $this->form->addElement('text','scapi_pm_038',"Haldol*");
        $this->form->addElement('text','scapi_pm_039',"Hydrocet");
        $this->form->addElement('text','scapi_pm_040',"Keppra*");
        $this->form->addElement('text','scapi_pm_041',"Klonopin*");
        $this->form->addElement('text','scapi_pm_042',"Lamictal*");
        $this->form->addElement('text','scapi_pm_043',"Lexapro*");
        $this->form->addElement('text','scapi_pm_044',"Librium");
        $this->form->addElement('text','scapi_pm_045',"Lithobid*");
        $this->form->addElement('text','scapi_pm_046',"Lorcet");
        $this->form->addElement('text','scapi_pm_047',"Lortab");
        $this->form->addElement('text','scapi_pm_048',"Luvox*");
        $this->form->addElement('text','scapi_pm_049',"Maxair");
        $this->form->addElement('text','scapi_pm_050',"Maxidone");
        $this->form->addElement('text','scapi_pm_051',"Melatonin");
        $this->form->addElement('text','scapi_pm_052',"Morphine");
        $this->form->addElement('text','scapi_pm_053',"Nardil*");
        $this->form->addElement('text','scapi_pm_054',"Nasonex");
        $this->form->addElement('text','scapi_pm_055',"Navane*");
        $this->form->addElement('text','scapi_pm_056',"Neroxtonin");
        $this->form->addElement('text','scapi_pm_057',"Norco");
        $this->form->addElement('text','scapi_pm_058',"Norpramine*");
        $this->form->addElement('text','scapi_pm_059',"Oxycontin");
        $this->form->addElement('text','scapi_pm_060',"Pamelor*");
        $this->form->addElement('text','scapi_pm_061',"Parnate*");
        $this->form->addElement('text','scapi_pm_062',"Paxil*");
        $this->form->addElement('text','scapi_pm_063',"Periactin");
        $this->form->addElement('text','scapi_pm_064',"Pulmicort");
        $this->form->addElement('text','scapi_pm_065',"Prednisone");
        $this->form->addElement('text','scapi_pm_066',"Prelone");
        $this->form->addElement('text','scapi_pm_067',"Prilosec");
        $this->form->addElement('text','scapi_pm_068',"Proventil");
        $this->form->addElement('text','scapi_pm_069',"Provigil*");
        $this->form->addElement('text','scapi_pm_070',"Prozac*");
        $this->form->addElement('text','scapi_pm_071',"Pulmicort");
        $this->form->addElement('text','scapi_pm_072',"Remeron*");
        $this->form->addElement('text','scapi_pm_073',"Risperdal*");
        $this->form->addElement('text','scapi_pm_074',"Semprex");
        $this->form->addElement('text','scapi_pm_075',"Serevent");
        $this->form->addElement('text','scapi_pm_076',"Seroquel*");
        $this->form->addElement('text','scapi_pm_077',"Serzone*");
        $this->form->addElement('text','scapi_pm_078',"Singulair");
        $this->form->addElement('text','scapi_pm_079',"Soma");
        $this->form->addElement('text','scapi_pm_080',"Sonata*");
        $this->form->addElement('text','scapi_pm_081',"Strattera*");
        $this->form->addElement('text','scapi_pm_082',"Synthroid");
        $this->form->addElement('text','scapi_pm_083',"Tegretol*");
        $this->form->addElement('text','scapi_pm_084',"Tenex*");
        $this->form->addElement('text','scapi_pm_085',"Thyroxine");
        $this->form->addElement('text','scapi_pm_086',"Tofranil*");
        $this->form->addElement('text','scapi_pm_087',"Topamax*");
        $this->form->addElement('text','scapi_pm_088',"Trazadone*");
        $this->form->addElement('text','scapi_pm_089',"Trileptal");
        $this->form->addElement('text','scapi_pm_090',"Valium*");
        $this->form->addElement('text','scapi_pm_091',"Ventolin");
        $this->form->addElement('text','scapi_pm_092',"Vicodin");
        $this->form->addElement('text','scapi_pm_093',"Wellbutrin*");
        $this->form->addElement('text','scapi_pm_094',"Xanax*");
        $this->form->addElement('text','scapi_pm_095',"Xopenex");
        $this->form->addElement('text','scapi_pm_096',"Zantac");
        $this->form->addElement('text','scapi_pm_097',"Zoloft*");
        $this->form->addElement('text','scapi_pm_098',"Zydone");
        $this->form->addElement('text','scapi_pm_099',"Zyprexa*");
        $this->form->addElement('text','scapi_pm_100',"Zyrtec");
        $this->form->addElement('text','scapi_pm_101',"Other");
        $this->form->addElement('text','scapi_pm_102',"Additional Meds: {scapi_pm_102_name}");
        $this->form->addElement('text','scapi_pm_103',"{scapi_pm_103_name}");
        $this->form->addElement('text','scapi_pm_104',"{scapi_pm_104_name}");
        $this->form->addElement('text','scapi_pm_105',"{scapi_pm_105_name}");
        $this->form->addElement('select', 'scapi_pm4_or_more', "4 or more", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scapi_cm4_or_more', "4 or more", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scapi_sick_past_week', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;10(a) Has your child been sick/ill in the &lt;span style=&#34;text-decoration: underline;&#34;&gt;past week&lt;/span&gt; (cold, flu, fever, pink eye, etc.)?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'scapi_hospital_since', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;10(b) Has your child been hospitalized (ER, outpatient, extended stay, etc.)?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'scapi_injury_since', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;10(c) H&lt;u&gt;&lt;/u&gt;as your child had any injuries? (Broken bones, concussion, etc.)&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','scapi_slv_01',"Allergies/Hay fever");
        $this->form->addElement('text','scapi_slv_02',"Anemia");
        $this->form->addElement('text','scapi_slv_03',"Appendicitis");
        $this->form->addElement('text','scapi_slv_04',"Arthritis");
        $this->form->addElement('text','scapi_slv_05',"Asthma");
        $this->form->addElement('text','scapi_slv_06',"Bone Disease");
        $this->form->addElement('text','scapi_slv_07',"Brain Tumor");
        $this->form->addElement('text','scapi_slv_08',"Broken Bones");
        $this->form->addElement('text','scapi_slv_09',"Bronchitis");
        $this->form->addElement('text','scapi_slv_10',"Cancer / Leukemia");
        $this->form->addElement('text','scapi_slv_11',"Cerebral Palsy");
        $this->form->addElement('text','scapi_slv_12',"Chicken Pox / Measles");
        $this->form->addElement('text','scapi_slv_13',"Chronic Ear Infections");
        $this->form->addElement('text','scapi_slv_14',"Color Blindness");
        $this->form->addElement('text','scapi_slv_15',"Concussion / Head Injury");
        $this->form->addElement('text','scapi_slv_16',"Diabetes");
        $this->form->addElement('text','scapi_slv_17',"Epilepsy");
        $this->form->addElement('text','scapi_slv_18',"Eczema");
        $this->form->addElement('text','scapi_slv_19',"Genetic Disorder");
        $this->form->addElement('text','scapi_slv_20',"Heart Problems / Heart Murmur");
        $this->form->addElement('text','scapi_slv_21',"Infections");
        $this->form->addElement('text','scapi_slv_22',"Learning Disabilities");
        $this->form->addElement('text','scapi_slv_23',"Intellectual Disability");
        $this->form->addElement('text','scapi_slv_24',"Migraines");
        $this->form->addElement('text','scapi_slv_25',"Meningitis");
        $this->form->addElement('text','scapi_slv_26',"Muscular Dystrophy");
        $this->form->addElement('text','scapi_slv_27',"Pneumonia");
        $this->form->addElement('text','scapi_slv_28',"Respiratory Problems");
        $this->form->addElement('text','scapi_slv_29',"Ringworm");
        $this->form->addElement('text','scapi_slv_30',"Scoliosis");
        $this->form->addElement('text','scapi_slv_31',"Seizures");
        $this->form->addElement('text','scapi_slv_32',"Sleep Problems");
        $this->form->addElement('text','scapi_slv_33',"Speech Problems");
        $this->form->addElement('text','scapi_slv_34',"Thyroid Disease");
        $this->form->addElement('text','scapi_slv_35',"Tuberculosis");
        $this->form->addElement('text','scapi_slv_36',"Urinary Tract Infections");
        $this->form->addElement('text','scapi_slv_37',"Other: {scapi_slv_37_desc}");
        $this->form->addElement('text','scapi_slv_38',"Other: {scapi_slv_38_desc}");
        $this->form->addElement('text','scapi_slv_39',"Other: {scapi_slv_39_desc}");
        $this->form->addElement('text','scapi_slv_40',"Other: {scapi_slv_40_desc}");
        $this->form->addElement('select', 'scapi_cmht', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;12A. Has your child received &lt;span style=&#34;text-decoration: underline;&#34;&gt;any&lt;/span&gt; type of counseling or therapy?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No (skip to question 13A)","1" => "Yes") );
        $this->form->addElement('text','scapi_cmht_types',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;Treatments &lt;span style=&#34;font-weight: normal;&#34;&gt;(check all that apply)&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('select', 'scapi_cmht_reason_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_1})") );
        $this->form->addElement('select', 'scapi_cmht_who_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_1})") );
        $this->form->addElement('select', 'scapi_cmht_freq_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_2})") );
        $this->form->addElement('select', 'scapi_cmht_who_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_2})") );
        $this->form->addElement('select', 'scapi_cmht_freq_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_3})") );
        $this->form->addElement('select', 'scapi_cmht_who_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_3})") );
        $this->form->addElement('select', 'scapi_cmht_freq_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_4})") );
        $this->form->addElement('select', 'scapi_cmht_who_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_4})") );
        $this->form->addElement('select', 'scapi_cmht_freq_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) H&lt;u&gt;&lt;/u&gt;ow often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_5})") );
        $this->form->addElement('select', 'scapi_cmht_who_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_5})") );
        $this->addBasicDate('scapi_cmht_start_date_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) When did this help first begin?&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('select', 'scapi_cmht_freq_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_6})") );
        $this->form->addElement('select', 'scapi_cmht_who_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_6})") );
        $this->form->addElement('select', 'scapi_cmht_freq_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_7})") );
        $this->form->addElement('select', 'scapi_cmht_who_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_7})") );
        $this->form->addElement('select', 'scapi_cmht_freq_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_8})") );
        $this->form->addElement('select', 'scapi_cmht_who_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_8})") );
        $this->form->addElement('select', 'scapi_cmht_freq_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_cmht_reason_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) What was the &lt;span style=&#34;text-decoration: underline;&#34;&gt;main&lt;/span&gt; reason for receiving this service?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "other (specify{scapi_cmht_reason_spec_99})") );
        $this->form->addElement('select', 'scapi_cmht_who_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who did your child see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "counselor","4" => "psychologist <b>or</b> psychiatrist (when not sure which one)","5" => "social worker (MSW)","6" => "family therapist  (use ONLY if cannot use more specific providers above)","99" => "other (specify{scapi_cmht_who_spec_99})") );
        $this->form->addElement('select', 'scapi_cmht_freq_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often since has your child received this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","5" => "None") );
        $this->form->addElement('select', 'scapi_cmht_len_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;13A. Has your child received special help at school or elsewhere for any &lt;span style=&#34;text-decoration: underline;&#34;&gt;educational purposes&lt;/span&gt;?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No (If no","1" => "Yes") );
        $this->form->addElement('text','scapi_ces_types',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;School Assistance &lt;span style=&#34;font-weight: normal;&#34;&gt;(check all that apply)&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('select', 'scapi_ces_reason_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_1})") );
        $this->form->addElement('select', 'scapi_ces_who_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_1})") );
        $this->form->addElement('select', 'scapi_ces_freq_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_1})") );
        $this->form->addElement('select', 'scapi_ces_len_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_2})") );
        $this->form->addElement('select', 'scapi_ces_who_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_2})") );
        $this->form->addElement('select', 'scapi_ces_freq_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_2})") );
        $this->form->addElement('select', 'scapi_ces_len_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_3})") );
        $this->form->addElement('select', 'scapi_ces_who_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_3})") );
        $this->form->addElement('select', 'scapi_ces_freq_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_3})") );
        $this->form->addElement('select', 'scapi_ces_len_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_4})") );
        $this->form->addElement('select', 'scapi_ces_who_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_4})") );
        $this->form->addElement('select', 'scapi_ces_freq_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_4})") );
        $this->form->addElement('select', 'scapi_ces_len_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_5})") );
        $this->form->addElement('select', 'scapi_ces_who_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_5})") );
        $this->form->addElement('select', 'scapi_ces_freq_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_5})") );
        $this->form->addElement('select', 'scapi_ces_len_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_6})") );
        $this->form->addElement('select', 'scapi_ces_who_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_6})") );
        $this->form->addElement('select', 'scapi_ces_freq_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_6})") );
        $this->form->addElement('select', 'scapi_ces_len_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_7})") );
        $this->form->addElement('select', 'scapi_ces_who_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_7})") );
        $this->form->addElement('select', 'scapi_ces_freq_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_7})") );
        $this->form->addElement('select', 'scapi_ces_len_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_8})") );
        $this->form->addElement('select', 'scapi_ces_who_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_8})") );
        $this->form->addElement('select', 'scapi_ces_freq_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) �How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_8})") );
        $this->form->addElement('select', 'scapi_ces_len_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_9})") );
        $this->form->addElement('select', 'scapi_ces_who_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_9})") );
        $this->form->addElement('select', 'scapi_ces_freq_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_9})") );
        $this->form->addElement('select', 'scapi_ces_len_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_10})") );
        $this->form->addElement('select', 'scapi_ces_who_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_10})") );
        $this->form->addElement('select', 'scapi_ces_freq_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_10})") );
        $this->form->addElement('select', 'scapi_ces_len_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_11})") );
        $this->form->addElement('select', 'scapi_ces_who_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_11})") );
        $this->form->addElement('select', 'scapi_ces_freq_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) �How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_11})") );
        $this->form->addElement('select', 'scapi_ces_len_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_12})") );
        $this->form->addElement('select', 'scapi_ces_who_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_12})") );
        $this->form->addElement('select', 'scapi_ces_freq_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_12})") );
        $this->form->addElement('select', 'scapi_ces_len_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_13', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_13})") );
        $this->form->addElement('select', 'scapi_ces_who_13', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_13})") );
        $this->form->addElement('select', 'scapi_ces_freq_13', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_13})") );
        $this->form->addElement('select', 'scapi_ces_len_13', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_ces_reason_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Was this mainly for?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "ADHD","2" => "learning","3" => "other behavioral/emotional concerns","99" => "another (specify{scapi_ces_reason_spec_99})") );
        $this->form->addElement('select', 'scapi_ces_who_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;b) Who provided this help?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychiatrist (MD)","3" => "psychologist or psychiatrist","4" => "social worker (MSW)","5" => "speech/language therapist","6" => "occup/physical therapist","7" => "regular classroom teacher","8" => "classroom aide","9" => "special education teacher/resource teacher","10" => "principal of school","11" => "staff at IEP meeting","12" => "tutor  (if different from any of the above)","13" => "school/guidance counselor","99" => "other (specify{scapi_ces_who_spec_99})") );
        $this->form->addElement('select', 'scapi_ces_freq_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) How often has your child received this help at school?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "daily","2" => "2-4 times weekly","3" => "1x weekly","4" => "1-3 times monthly","5" => "other (specify{scapi_ces_freq_spec_99})") );
        $this->form->addElement('select', 'scapi_ces_len_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;e) About how many minutes &lt;span style=&#34;text-decoration: underline;&#34;&gt;on average&lt;/span&gt; was each session?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;14A. Have you or your partner attended any group, class, or counseling for any reason?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No (If no","1" => "Yes") );
        $this->form->addElement('text','scapi_pmh_types',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;School Assistance &lt;span style=&#34;font-weight: normal;&#34;&gt;(check all that apply)&lt;/span&gt;&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('select', 'scapi_pmh_who_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_1})") );
        $this->form->addElement('select', 'scapi_pmh_freq_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_1', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_2})") );
        $this->form->addElement('select', 'scapi_pmh_freq_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_3})") );
        $this->form->addElement('select', 'scapi_pmh_freq_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_3', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_4})") );
        $this->form->addElement('select', 'scapi_pmh_freq_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_4', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_5})") );
        $this->form->addElement('select', 'scapi_pmh_freq_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_5', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_6})") );
        $this->form->addElement('select', 'scapi_pmh_freq_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_6', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_7})") );
        $this->form->addElement('select', 'scapi_pmh_freq_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_7', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_8})") );
        $this->form->addElement('select', 'scapi_pmh_freq_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_8', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_9})") );
        $this->form->addElement('select', 'scapi_pmh_freq_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_9', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_10})") );
        $this->form->addElement('select', 'scapi_pmh_freq_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_10', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_11})") );
        $this->form->addElement('select', 'scapi_pmh_freq_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_11', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_12})") );
        $this->form->addElement('select', 'scapi_pmh_freq_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_12', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_pmh_who_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;a) Who did you or your partner see?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "psychologist (PhD)","2" => "psychologist or psychiatrist <i>(when not sure which one)</i>","3" => "psychiatrist (MD)","4" => "social worker (MSW)","5" => "counselor","6" => "family therapist","99" => "other (specify{scapi_pmh_who_spec_99})") );
        $this->form->addElement('select', 'scapi_pmh_freq_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;c) How often have you or your partner gone?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 or more times per week","2" => "1-3 times per month","3" => "5-10 times per year","4" => "less than 4 times in the last year","0" => "None") );
        $this->form->addElement('select', 'scapi_pmh_len_99', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;d) About how many minutes each time?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "1 - 30 minutes","2" => "31 - 45 minutes","3" => "46 - 60 minutes","4" => "61 + minutes") );
        $this->form->addElement('select', 'scapi_you_med_adhd', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;15. Have &lt;span style=&#34;text-decoration: underline;&#34;&gt;you&lt;/span&gt; taken medication for ADHD/ADD?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'scapi_you_med_adhd_2', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;16. Has &lt;span style=&#34;text-decoration: underline;&#34;&gt;your partner&lt;/span&gt; taken medication for ADHD/ADD?&lt;/p&gt;&lt;/div&gt;", array("" => "","0" => "No","1" => "Yes") );
    }


}

?>