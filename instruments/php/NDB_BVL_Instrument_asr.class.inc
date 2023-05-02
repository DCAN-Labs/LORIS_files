<?php

/**
 * This file contains the NDB_BVL_Instrument_asr
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_asr extends NDB_BVL_Instrument
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
        $this->testName = 'asr' ;           // test_names.Test_name
        $this->table = 'asr';              // name of database table corresponding to instrument
        // FULL NAME: asr
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
        $this->addHeader("<em>A</em>dult <em>S</em>elf <em>R</em>eport (ASR)");
        
        $this->form->addElement('select', 'asr_highest_education', "Please check your highest education", array("" => "","1" => "No high school diploma and no GED","2" => "General Equivalency Diploma (GED)","3" => "High school graduate","4" => "Some college but no college degree","5" => "Associate's Degree","6" => "Bachelor's or RN Degree","7" => "Some graduate school but no graduate degree","8" => "Master's Degree","9" => "Doctoral or Law Degree","10" => "Other - Please specify  {asr_education_other}") );
        $this->form->addElement('select', 'asr_friends_a', "About how many close friends do you have? (Do not include family members.)", array("" => "","1" => "None","2" => "1","3" => "2 or 3","4" => "4 or more") );
        $this->form->addElement('select', 'asr_friends_b', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;About how many times &lt;span style=&#34;text-decoration: underline;&#34;&gt;a month&lt;/span&gt; do you have contact with any of your close friends? (Include in-person contacts, phone, letters, e-mail)&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "Less than one","2" => "1 or 2","3" => "3 or 4","4" => "5 or more") );
        $this->form->addElement('select', 'asr_friends_c', "How well do you get along with your close friends? ", array("" => "","1" => "Not as well as I'd like","2" => "Average","3" => "Above average","4" => "Far above average") );
        $this->form->addElement('select', 'asr_friends_d', "About how many times a month do any friends or family visit you? ", array("" => "","1" => "Less than 1","2" => "1 or 2","3" => "3 or 4","4" => "5 or more") );
        $this->form->addElement('select', 'asr_marital_status', "What is your marital status? ", array("" => "","1" => "Never been married","2" => "Married","3" => "Widowed","4" => "Married but separated from spouse","5" => "Divorced","6" => "Other - Please describe  {asr_marital_status_other}") );
        $this->form->addElement('select', 'asr_live_with_spouse', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;At any time in the &lt;span style=&#34;text-decoration: underline;&#34;&gt;past 6 months&lt;/span&gt;, did you live with your spouse or with a partner?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "No","2" => "Yes") );
        $this->form->addElement('select', 'asr_live_with_spouse_a', "I get along well with my spouse or partner", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_b', "My spouse or partner and I have trouble sharing responsibilities ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_c', "I feel satisfied with my spouse or partner ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_d', "My spouse or partner and I enjoy similar activities ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_e', "My spouse or partner and I disagree about living arrangements, such as where we live ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_f', "I have trouble with my spouse or partner&#39;s family ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_g', "I like my spouse or partner&#39;s friends ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_live_with_spouse_h', "My spouse or partner&#39;s behavior annoys me ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_family_a', "Get along with your brothers? ", array("" => "","1" => "I have no brothers","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_family_b', "Get along with your sisters?", array("" => "","1" => "I have no sisters","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_family_c', "Get along with your mother? ", array("" => "","1" => "Mother is deceased","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_family_d', "Get along with your father? ", array("" => "","1" => "Father is deceased","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_family_e', "Get along with your biological or adopted children? ", array("" => "","1" => "I have no children","2" => "I have children") );
        $this->form->addElement('select', 'asr_oldest_child', "Get along with your oldest child? ", array("" => "","1" => "Not applicable","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_2nd_oldest_child', "Get along with your 2nd oldest child?", array("" => "","1" => "Not applicable","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_3rd_oldest_child', "Get along with your 3rd oldest child? ", array("" => "","1" => "Not applicable","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_other_children', "Get along with other children? ", array("" => "","1" => "Not applicable","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_step_children', "Get along with your step children?", array("" => "","1" => "I have no step children","2" => "Worse than average","3" => "Variable or Average","4" => "Better than Average","5" => "No Contact") );
        $this->form->addElement('select', 'asr_employment', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;At any time in the &lt;span style=&#34;text-decoration: underline;&#34;&gt;past 6 months&lt;/span&gt;, did you have any paid jobs (including self-employment and military service)?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "No","2" => "Yes - Please describe") );
        $this->form->addElement('select', 'asr_employment_a', "I work well with others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_b', "I have trouble getting along with bosses ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_c', "I do my work well ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_d', "I have trouble finishing my work ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_e', "I am satisfied with my work situation ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_f', "I do things that cause me to lose my job ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_g', "I stay away from my job even when I&#39;m not sick or not on vacation ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_h', "My job is too stressful for me ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_employment_i', "I worry too much about work ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_education', "At any time in the past 6 months, did you attend school, college, or any other educational or training program? ", array("" => "","1" => "No","2" => "Yes") );
        $this->form->addElement('select', 'asr_education_a', "I get along well with other students ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_education_b', "I achieve what I am capable of ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_education_c', "I have trouble finishing assignments ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_education_d', "I am satisfied with my educational situation", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_education_e', "I do things that may cause me to fail ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_disability', "Do you have any illness, disability, or handicap? ", array("" => "","1" => "No","2" => "Yes - Please describe") );
        $this->form->addElement('select', 'asr_worries', "Do you have any concerns or worries about family, work, education, or other things?", array("" => "","1" => "No Concerns","2" => "Yes - Please describe") );
        $this->form->addElement('select', 'asr_1', "I am too forgetful ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_2', "I make good use of my opportunities ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_3', "I argue a lot ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_4', "I work up to my ability ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_5', "I blame others for my problems ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_6', "I use drugs (other than alcohol and nicotine) for nonmedical purposes (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_7', "I brag", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_8', "I have trouble concentrating or paying attention for long ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_9', "I can&#39;t get my mind off certain thoughts (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_10', "I have trouble sitting still ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_11', "I am too dependent on others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_12', "I feel lonely ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_13', "I feel confused or in a fog ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_14', "I cry a lot ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_15', "I am pretty honest ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_16', "I am mean to others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_17', "I daydream a lot ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_18', "I deliberately try to hurt or kill myself ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_19', "I try to get a lot of attention ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_20', "I damage or destroy my things ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_21', "I damage or destroy things belonging to others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_22', "I worry about my future ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_23', "I break rules at work or elsewhere ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_24', "I don&#39;t eat as well as I should ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_25', "I don&#39;t get along with other people ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_26', "I don&#39;t feel guilty after doing something I shouldn&#39;t ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_27', "I am jealous of others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_28', "I get along badly with my family ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_29', "I am afraid of certain animals, situations, or places (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_30', "My relations with the opposite sex are poor ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_31', "I am afraid I might think or do something bad", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_32', "I feel that I have to be perfect ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_33', "I feel that no one loves me ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_34', "I feel that others are out to get me ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_35', "I feel worthless or inferior ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_36', "I accidentally get hurt a lot, accident-prone ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_37', "I get in many fights ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_38', "My relations with neighbors are poor ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_39', "I hang around people who get in trouble ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_40', "I hear sounds or voices that other people think aren&#39;t there (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_41', "I am impulsive or act without thinking", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_42', "I would rather be alone than with others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_43', "I lie or cheat ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_44', "I feel overwhelmed by my responsibilities ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_45', "I am nervous or tense ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_46', "Parts of my body twitch or make nervous movements (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_47', "I lack self-confidence ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_48', "I am not liked by others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_49', "I can do certain things better than other people ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_50', "I am too fearful or anxious ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_51', "I feel dizzy or lightheaded", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_52', "I feel too guilty ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_53', "I have trouble planning for the future", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_54', "I feel tired without good reason ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_55', "My moods swing between elation and depression ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_a', "Aches or pains (not stomach or headaches) ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_b', "Headaches", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_c', "Nausea, feel sick ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_d', "Problems with eyes (not if corrected by glasses) (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_e', "Rashes or other skin problems ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_f', "Stomachaches", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_g', "Vomiting, throwing up ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_h', "Heart pounding or racing ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_56_i', "Numbness or tingling in body parts ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_57', "I physically attack people ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_58', "I pick my skin or other parts of my body (describe) ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_59', "I fail to finish things I should do ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_60', "There is very little that I enjoy ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_61', "My work performance is poor ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_62', "I am poorly coordinated or clumsy ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_63', "I would rather be with older people than with people of my own age ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_64', "I have trouble setting priorities ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_65', "I refuse to talk ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_66', "I repeat certain acts over and over ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_67', "I have trouble making or keeping friends ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_68', "I scream or yell a lot ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_69', "I am secretive or keep things to myself ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_70', "I see things that other people think aren&#39;t there (describe) ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_71', "I am self-conscious or easily embarrassed ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_72', "I worry about my family ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_73', "I meet my responsibilities to my family ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_74', "I show off or clown ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_75', "I am too shy or timid ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_76', "My behavior is irresponsible ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_77', "I sleep more than most other people during the day and/or night (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_78', "I have trouble making decisions", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_79', "I have a speech problem", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_80', "I stand up for my rights ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_81', "My behavior is very changeable ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_82', "I steal ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_83', "I am easily bored ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_84', "I do things that other people think are strange (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_85', "I have thoughts that other people would think are strange (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_86', "I am stubborn, sullen, or irritable ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_87', "My moods or feelings change suddenly ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_88', "I enjoy being with people ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_89', "I rush into things without considering the risks ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_90', "I drink too much alcohol or get drunk ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_91', "I think about killing myself ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_92', "I do things that may cause me trouble with the law (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_93', "I talk too much ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_94', "I tease others a lot ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_95', "I have a hot temper ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_96', "I think about sex too much ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_97', "I threaten to hurt people ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_98', "I like to help others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_99', "I dislike staying in one place for very long ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_100', "I have trouble sleeping (describe): ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_101', "I stay away from my job even when I&#39;m not sick or not on vacation ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_102', "I don&#39;t have much energy ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_103', "I am unhappy, sad, or depressed ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_104', "I am louder than others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_105', "People think I am disorganized ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_106', "I try to be fair to others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_107', "I feel that I can&#39;t succeed ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_108', "I tend to lose things ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_109', "I like to try new things ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_110', "I wish I were of the opposite sex ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_111', "I keep from getting involved with others ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_112', "I worry a lot ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_113', "I worry about my relations with the opposite sex ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_114', "I fail to pay my debts or meet other financial responsibilities ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_115', "I feel restless or fidgety ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_116', "I get upset too easily ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_117', "I have trouble managing money or credit cards ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_118', "I am too impatient ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_119', "I am not good with details ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_120', "I drive too fast ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_121', "I tend to be late for appointments ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_122', "I have trouble keeping a job ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
        $this->form->addElement('select', 'asr_123', "I am a happy person ", array("" => "","0" => "0 = Not True","1" => "1 = Somewhat or Sometimes True","2" => "2 = Very True or Often True") );
    }


}

?>