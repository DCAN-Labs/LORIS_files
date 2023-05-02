<?php

/**
 * This file contains the NDB_BVL_Instrument_cbcl_ages_6
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_cbcl_ages_6 extends NDB_BVL_Instrument
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
        $this->testName = 'cbcl_ages_6' ;           // test_names.Test_name
        $this->table = 'cbcl_ages_6';              // name of database table corresponding to instrument
        // FULL NAME: cbcl_ages_6
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
        $this->addHeader("Child Behavior Checklist (CBCL) Ages 6-18");

        $this->addHeader("<h3>Questions</h3>");
        $this->form->addElement('select', 'cbcl_q01_p', "&lt;b&gt;Acts too young for his/her age", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q02_p', "&lt;b&gt;Drinks alcohol without parents&#39; approval", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q03_p', "&lt;b&gt;Argues a lot", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q04_p', "&lt;b&gt;Fails to finish things he/she starts", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q05_p', "&lt;b&gt;There is very little he/she enjoys", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q06_p', "&lt;b&gt;Bowel movements outside toilet", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q07_p', "&lt;b&gt;Bragging, boasting", array("" => "","0" => "<b>Not True</b>","1" => "<b> Somewhat/Sometimes True","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q08_p', "&lt;b&gt;Can&#39;t concentrate, can&#39;t pay attention for long&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q09_p', "&lt;b&gt;Can&#39;t get his/her mind off certain thoughts; obsessions&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q10_p', "&lt;b&gt;Can&#39;t sit still, restless, or hyperactive&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q11_p', "&lt;b&gt;Clings to adults or too dependent&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q12_p', "&lt;b&gt;Complains of loneliness&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q13_p', "&lt;b&gt;Confused or seems to be in a fog&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q14_p', "&lt;b&gt;Cries a lot&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q15_p', "&lt;b&gt;Cruel to animals&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q16_p', "&lt;b&gt;Cruelty, bullying, or meanness to others&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q17_p', "&lt;b&gt;Daydreams or gets lost in his/her thoughts&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q18_p', "&lt;b&gt;Deliberately harms self or attempts suicide&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q19_p', "&lt;b&gt;Demands a lot of attention&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q20_p', "&lt;b&gt;Destroys his/her own things&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q21_p', "&lt;b&gt;Destroys things belonging to his/her family or others&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q22_p', "&lt;b&gt;Disobedient at home&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q23_p', "&lt;b&gt;Disobedient at school&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q24_p', "&lt;b&gt;Doesn&#39;t eat well&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q25_p', "&lt;b&gt;Doesn&#39;t get along with other kids&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q26_p', "&lt;b&gt;Doesn&#39;t seem to feel guilty after misbehaving&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q27_p', "&lt;b&gt;Easily jealous&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q28_p', "&lt;b&gt;Breaks rules at home, school or elsewhere&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q29_p', "&lt;b&gt;Fears certain animals, situations, or places, other than school&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q30_p', "&lt;b&gt;Fears going to school&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q31_p', "&lt;b&gt;Fears he/she might think or do something bad&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q32_p', "&lt;b&gt;Feels he/she has to be perfect&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q33_p', "&lt;b&gt;Feels or complains that no one loves him/her&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q34_p', "&lt;b&gt;Feels others are out to get him/her&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q35_p', "&lt;b&gt;Feels worthless or inferior&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q36_p', "&lt;b&gt;Gets hurt a lot, accident prone&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q37_p', "&lt;b&gt;Gets in many fights&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q38_p', "&lt;b&gt;Gets teased a lot&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q39_p', "&lt;b&gt;Hangs around with others who get in trouble&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q40_p', "&lt;b&gt;Hears sound or voices that aren&#39;t there&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q41_p', "&lt;b&gt;Impulsive or acts without thinking&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q42_p', "&lt;b&gt;Would rather be alone than with others&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q43_p', "&lt;b&gt;Lying or cheating&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q44_p', "&lt;b&gt;Bites fingernails&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q45_p', "&lt;b&gt;Nervous, high-strung, or tense&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q46_p', "&lt;b&gt;Nervous movements or twitching&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q47_p', "&lt;b&gt;Nightmares&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q48_p', "&lt;b&gt;Not liked by other kids&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q49_p', "&lt;b&gt;Constipated, doesn&#39;t move bowels&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q50_p', "&lt;b&gt;Too fearful or anxious&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q51_p', "&lt;b&gt;Feels dizzy or lightheaded&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q52_p', "&lt;b&gt;Feels too guilty&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q53_p', "&lt;b&gt;Overeating&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q54_p', "&lt;b&gt;Overtired without good reason&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q55_p', "&lt;b&gt;Overweight&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56a_p', "&lt;b&gt;Aches or pains (not stomach or headaches)&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56b_p', "&lt;b&gt;Headaches&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56c_p', "&lt;b&gt;Nausea, feels sick&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56d_p', "&lt;b&gt;Problems with eyes (not if corrected by glasses)&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56e_p', "&lt;b&gt;Rashes or other skin problems&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56f_p', "&lt;b&gt;Stomachaches&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56g_p', "&lt;b&gt;Vomiting, throwing up&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q56h_p', "&lt;b&gt;Other (physical problems without known physical cause)&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q57_p', "&lt;b&gt;Physically attacks people&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q58_p', "&lt;b&gt;Picks nose, skin, or other parts of body&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q59_p', "&lt;b&gt;Plays with own sex parts in public&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q60_p', "&lt;b&gt;Plays with own sex parts too much&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q61_p', "&lt;b&gt;Poor school work&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q62_p', "&lt;b&gt;Poorly coordinated or clumsy&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q63_p', "&lt;b&gt;Prefers being with older kids&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q64_p', "&lt;b&gt;Prefers being with younger kids&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q65_p', "&lt;b&gt;Refuses to talk&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q66_p', "&lt;b&gt;Repeats certain acts over and over; compulsions&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q67_p', "&lt;b&gt;Runs away from home&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q68_p', "&lt;b&gt;Screams a lot&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q69_p', "&lt;b&gt;Secretive, keeps things to self&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q70_p', "&lt;b&gt;Sees things that aren&#39;t there&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q71_p', "&lt;b&gt;Self-conscious or easily embarrassed&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q72_p', "&lt;b&gt;Sets fires&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q73_p', "Sexual problems", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q74_p', "Showing off or clowning", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q75_p', "Too shy or timid", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q76_p', "Sleeps less than most kids", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q77_p', "Sleeps more than most kids during day and/or night", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q78_p', "&lt;b&gt;Inattentive or easily distracted&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q79_p', "Speech problem", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q80_p', "Stares blankly", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q81_p', "Steals at home", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q82_p', "Steals outside the home", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q83_p', "Stores up too many things he/she doesn&#39;t need", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q84_p', "Strange behavior", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q85_p', "&lt;b&gt;Strange ideas&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q86_p', "Stubborn, sullen, or irritable", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q87_p', "Sudden changes in mood or feelings", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q88_p', "Sulks a lot", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q89_p', "Suspicious", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q90_p', "Swearing or obscene language", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q91_p', "Talks about killing self", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q92_p', "&lt;b&gt;Talks or walks in sleep&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q93_p', "Talks too much", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q94_p', "Teases a lot", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q95_p', "Temper tantrums or hot temper", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q96_p', "Thinks about sex too much", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q97_p', "Threatens people", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q98_p', "Thumb-sucking", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q99_p', "&lt;b&gt;Smokes, chews, or sniffs tobacco&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q100_p', "Trouble sleeping", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q101_p', "Truancy, skips school", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q102_p', "Underactive, slow-moving, or lacks energy", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q103_p', "Unhappy, sad, or depressed", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q104_p', "Unusually loud", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q105_p', "Uses drugs for non-medical purposes (don&#39;t include alcohol or tobacco)", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q106_p', "&lt;b&gt;Vandalism&lt;/b&gt;", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q107_p', "Wets self during the day", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q108_p', "Wets the bed", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q109_p', "Whining", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q110_p', "Wishes to be of opposite sex", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q111_p', "Withdrawn, doesn&#39;t get involved with others", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
        $this->form->addElement('select', 'cbcl_q112_p', "Worries", array("" => "","0" => "<b>Not True</b>","1" => "<b>Somewhat/Sometimes True</b>","2" => "<b>Very True/Often True</b>") );
    }


}

?>