<?php

/**
 * This file contains the NDB_BVL_Instrument_mri_data_entry_summary
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_mri_data_entry_summary extends NDB_BVL_Instrument
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
        $this->testName = 'mri_data_entry_summary' ;           // test_names.Test_name
        $this->table = 'mri_data_entry_summary';              // name of database table corresponding to instrument
        // FULL NAME: mri_data_entry_summary
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
        $this->addHeader("MRI Data Entry Summary");

        $this->form->addElement('select', 'scan_site', "Scanning Site ", array("" => "","1" => "UMN","2" => "WashU") );
        $this->form->addElement('select', 'mri_studytype', "Participant study enrollment", array("" => "","1" => "Sub-populations in ADHD and ASD","2" => "Biofeedback") );
        $this->form->addElement('select', 'mri_scanner_umn', "Scanner Type", array("" => "","1" => "3T-A","2" => "3T-D") );
        $this->form->addElement('select', 'scanner_type_washu', "Scanner Type", array("" => "","1" => "Bay 1") );
        $this->form->addElement('select', 'mri_late_start', "Did scan start late?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','mri_late_start_issues',"Reason for late start");
        $this->form->addElement('select', 'mri_washout_meds', "Is the participant currently prescribed any washout medications?", array("" => "","3" => "Yes","1" => "No","0" => "Unknown") );
        $this->form->addElement('select', 'mri_washout_time', "Length of washout", array("" => "","1" => "24 hours","2" => "48 hours") );
        $this->form->addElement('select', 'mri_washout_verified', "Washout Verified", array("" => "","3" => "yes","1" => "no","2" => "unknown","4" => "N/A") );
        $this->form->addElement('select', 'mri_movie_yesno', "Did the participant watch a movie during localization, T1, and/or T2? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_music_yesno', "Did the participant listen to music? (Localization, T1 and/or T2 ONLY)", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','nnl_equip',"Additional equipment used:");
        $this->form->addElement('text','mri_scan_set_up',"Scan setup");
        $this->form->addElement('select', 'rs_run_times', "Participant&#39;s resting state run times:", array("" => "","1" => "16 min","2" => "16 min","3" => "10 min") );
        $this->form->addElement('select', 'vid_sequence', "Which video sequence was used? ", array("" => "","1" => "Old video sequence","2" => "New video sequence") );
        $this->form->addElement('select', 'mri_physio', "Was physio equipment used? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_t1_1_complete', "Was Anatomical (T1) started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t1_stim', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t1_pixar_choice', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t1_aqu_error_1',"Acquisition errors during Anatomical 1 (T1)");
        $this->form->addElement('select', 'mri_t1_artifact_1', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t1_1',"Quality Score %");
        $this->form->addElement('select', 'mri_t1_2_complete', "Was a 2nd T1 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t1_stim_2', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t1_2_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t1_aqu_error_2',"Acquisition errors during Anatomical 2 (T1)");
        $this->form->addElement('select', 'mri_t1_artifact_2', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t1_2',"Quality Score %");
        $this->form->addElement('select', 'mri_t1_3_complete', "Was a 3rd T1 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t1_stim_3', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t1_3_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t1_aqu_error_3',"Acquisition errors during Anatomical 3 (T1)");
        $this->form->addElement('select', 'mri_t1_artifact_3', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t1_3',"Quality Score %");
        $this->form->addElement('select', 'mri_t1_4_complete', "Was a 4th T1 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t1_stim_4', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Ice Cave game","3" => "Ruins game","4" => "Item Set 1 game","5" => "Item Set 2 game","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t1_4_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t1_aqu_error_4',"Acquisition errors during Anatomical 4 (T1)");
        $this->form->addElement('select', 'mri_t1_artifact_4', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t1_4',"Quality Score %");
        $this->form->addElement('select', 'mri_t1_5_complete', "Was a 5th T1 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t1_stim_5', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t1_5_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t1_aqu_error_5',"Acquisition errors during Anatomical 5 (T1)");
        $this->form->addElement('select', 'mri_t1_artifact_5', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t1_5',"Quality Score %");
        $this->form->addElement('select', 'mri_t2_1_complete', "Was a T2 scan started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t2_stim_1', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t2_1_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t2_aqu_error_1',"Acquisition errors during 1st T2");
        $this->form->addElement('select', 'mri_t2_artifact_1', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t2_1',"Quality Score %");
        $this->form->addElement('select', 'mri_t2_2_complete', "Was a 2nd T2 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t2_stim_2', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t2_2_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t2_aqu_error_2',"Acquisition errors during 2nd T2");
        $this->form->addElement('select', 'mri_t2_artifact_2', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t2_2',"Quality Score %");
        $this->form->addElement('select', 'mri_t2_3_complete', "Was a 3rd T2 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t2_stim_3', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t2_3_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t2_aqu_error_3',"Acquisition errors during 3rd T2");
        $this->form->addElement('select', 'mri_t2_artifact_3', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t2_3',"Quality Score %");
        $this->form->addElement('select', 'mri_t2_4_complete', "Was a 4th T2 started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_t2_stim_4', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_t2_4_pixar_choice', " Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_t2_aqu_error_4',"Acquisition errors during 4th T2");
        $this->form->addElement('select', 'mri_t2_artifact_4', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_t2_4',"Quality Score %");
        $this->form->addElement('select', 'dti_ap_1_complete', "Was DTI-AP started? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_dti_ap_stim_1', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_dti_1_pixar_choice', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_dti_ap_aqu_error_1',"Acquisition errors during 1st DTI-AP");
        $this->form->addElement('select', 'mri_dti_ap_1_artif', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_dti_ap_1',"Quality Score %");
        $this->form->addElement('select', 'dti_ap_extra_2', "Was an extra DTI-AP started?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_dti_ap_stim_2', "Which stimulus presentation did the participant view? ", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_dti_1_pixar_choice_2', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_dti_ap_aqu_error_2',"Acquisition errors during 2nd DTI-AP");
        $this->form->addElement('select', 'mri_dti_ap_1_artif_2', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','q_score_dti_ap_2',"Quality Score %");
        $this->form->addElement('select', 'dti_pa_complete_1', "Was DTI-PA started?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'dti_pa_stim_1', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'dti_pa_pixar_choice_1', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','dti_pa_aqui_err_1',"Acquisition errors during 1st DTI-PA");
        $this->form->addElement('select', 'dti_pa_artif_1', "Is there any artifact?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','q_score_dti_pa_1',"Quality Score %");
        $this->form->addElement('select', 'dti_pa_extra', "Was an extra DTI-PA started?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'dti_pa_stim_2', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","2" => "Luma Cave - Ice Cave game","3" => "Luma Cave - Ruins game","4" => "Friendly Forest - Bleeps and Treats game","5" => "Friendly Forest - Wilderness Fun","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'dti_pa_pixar_choice_2', "Which video did the participant watch?", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','dti_pa_aqui_err_2',"Acquisition errors during 1st DTI-PA");
        $this->form->addElement('select', 'dti_pa_artif_2', "Is there any artifact?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_rs_1_complete', "Was a resting state scan started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'video_rs_1', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('select', 'mri_rs_stim_1', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_rs_video_1', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_rs_aqu_error_1',"Acquisition errors during RS1");
        $this->form->addElement('select', 'mri_rs_artifact_1', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_rs_2_complete', "Was a 2nd resting state started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'video_rs_2', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('select', 'mri_rs_stim_2', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_rs_video_2', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_rs_aqu_error_2',"Acquisition errors during RS2");
        $this->form->addElement('select', 'mri_rs_artifact_2', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_rs_3_complete', "Was a 3rd resting state started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'video_rs_3', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('select', 'mri_rs_stim_3', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_rs_video_3', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_rs_aqu_error_3',"Acquisition errors during RS3");
        $this->form->addElement('select', 'mri_rs_artifact_3', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_rs_4_complete', "Was an additional resting state started?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('select', 'mri_rs_stim_4', "Which stimulus presentation did the participant view?", array("" => "","1" => "Crosshair","6" => "Puppy Dreams") );
        $this->form->addElement('select', 'mri_rs_video_4', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('select', 'video_rs_4', "Which video did the participant watch? ", array("" => "","1" => "Rest-TR1.7s-ADHD 1-16min","2" => "Rest-TR1.7s-ADHD 2-16min","3" => "Rest-TR1.7s-ADHD 3-16min","4" => "Rest-TR1.7s-ADHD 4-16min","5" => "Rest-TR1.7s-ADHD 5-16min","6" => "Rest-TR1.7s-ADHD 6-16min","7" => "Rest-TR1.7s-ADHD 7-16min","8" => "Rest-TR1.7s-ADHD 8-16min","9" => "Rest-TR1.7s-ADHD 9-16min","10" => "Rest-TR1.7s-ADHD 10-16min","11" => "Rest-TR1.7s-ADHD 1-10min","12" => "Rest-TR1.7s-ADHD 2-10min","13" => "Rest-TR1.7s-ADHD 3-10min","14" => "Rest-TR1.7s-ADHD 4-10min","15" => "Rest-TR1.7s-ADHD 5-10min") );
        $this->form->addElement('text','mri_rs_aqu_error_4',"Acquisition errors during RS4");
        $this->form->addElement('select', 'mri_rs_artifact_4', "Is there any artifact?", array("" => "","1" => "No","3" => "Yes") );
        $this->form->addElement('text','mri_firmm_total',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;FIRMM total minutes of good &lt;em&gt;filtered&lt;/em&gt; data (&lt; .2 mm)&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('text','firmm_unfilt_total',"&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;FIRMM total minutes of good &lt;em&gt;unfiltered&lt;/em&gt; data (&lt;.2mm):&lt;/p&gt;&lt;/div&gt;");
        $this->form->addElement('select', 'mri_anatom_review_complete', "Is anatomical review complete?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_review_need', "Is radiology follow-up needed for potential brain abnormality?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'data_sent_to_radiology_rev', "Data sent to radiology review? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'mri_abnorm_confirm', "Confirmed brain abnormality?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'physio_data_sent_to', "Physio data sent to Concierge?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'dicoms_sent_to', "Dicoms sent to Concierge or Naxos? ", array("" => "","0" => "No","1" => "Yes") );
    }


}

?>