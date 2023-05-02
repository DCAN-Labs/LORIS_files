<?php

/**
 * This file contains the NDB_BVL_Instrument_phonescreen
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_phonescreen extends NDB_BVL_Instrument
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
        $this->testName = 'phonescreen' ;           // test_names.Test_name
        $this->table = 'phonescreen';              // name of database table corresponding to instrument
        // FULL NAME: phonescreen
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
        $this->addHeader("Phonescreen");

        $this->form->addElement('select', 'research_site', "Research site", array("" => "","1" => "UMN","2" => "WashU") );
        $this->form->addElement('select', 'wash_u_recruit', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;How did you first hear about our study?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "Website","2" => "Recruiter","3" => "Peachjar","4" => "Flyer/Poster - WUSTL","5" => "Flyer - Clinic","6" => "Flyer - Community","7" => "VFH: (Study search","8" => "Other study","9" => "Doctor's Referral","10" => "IDDRC","11" => "Word of mouth/friend","12" => "Skip - I'd rather not say","13" => "Other   {wash_u_recruit_oth}") );
        $this->form->addElement('select', 'umn_recruit', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;How did you first hear about our study?&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "Website","13" => "Peachjar","2" => "Flyer/Poster - UMN","3" => "Flyer - Clinic","4" => "Flyer - Community","5" => "Coordinator call","12" => "Coordinator Email","6" => "Other study","7" => "Doctor's referral","8" => "Word of mouth/friend","9" => "ASD clinic","10" => "Skip - I'd rather not say","11" => "Other   {umn_recruit_other}") );
        $this->form->addElement('text','dobunsure',"");
        $this->form->addElement('select', 'caller_relat_to_child', "Caller&#39;s relationship to the child", array("" => "","1" => "Bio-mom","2" => "Bio-dad","3" => "Non-bio female caregiver","4" => "Non-bio male caregiver","5" => "Skip - I'd rather not say","6" => "Other  {caller_relat_other}") );
        $this->form->addElement('text','unsure_child_name',"");
        $this->form->addElement('text','child_age_calc',"Child&#39;s age at phone screen");
        $this->form->addElement('select', 'birth_cert_access', "Do you have access to the child&#39;s birth certificate? ", array("" => "","1" => "Yes","0" => "No","999" => "Unsure","4" => "Skip - I'd rather not say") );
        $this->form->addElement('select', 'child_sex', "Child&#39;s sex assigned at birth", array("" => "","1" => "Male","2" => "Female") );
        $this->form->addElement('select', 'child_gender', "Child&#39;s gender identification", array("" => "","1" => "Male","2" => "Female","3" => "Transgender female","4" => "Transgender male","5" => "Gender variant/non-conforming","6" => "Not listed","7" => "Skip") );
        $this->form->addElement('select', 'child_handedness', "Child Handedness", array("" => "","1" => "Right","2" => "Left","3" => "Ambidextrous","999" => "Unknown") );
        $this->form->addElement('select', 'participating_adult', "Who will be the primary participating adult? ", array("" => "","1" => "Bio-Mother","2" => "Bio-Father","999" => "Unsure","4" => "Non-bio Caregiver  (specify)  {non_bio_care_specif}") );
        $this->form->addElement('text','parent_name_unsure',"");
        $this->form->addElement('text','parent_dob_unsure',"");
        $this->form->addElement('select', 'parent_birth_cert', "Do you have access to the primary participating parent&#39;s birth certificate? ", array("" => "","1" => "Yes","0" => "No","999" => "Unsure","4" => "Skip - I'd rather not say") );
        $this->form->addElement('select', 'parent_lang', "&lt;div class=&#34;rich-text-field-label&#34;&gt;&lt;p&gt;Primary participating parent&#39;s first or primary language&lt;/p&gt;&lt;/div&gt;", array("" => "","1" => "English","2" => "Other {parent_lang_other}") );
        $this->form->addElement('select', 'child_lang', "Child&#39;s first or primary language", array("" => "","1" => "English","2" => "Other {child_lang_other}") );
        $this->form->addElement('select', 'child_autism', "Has your child been diagnosed with Autism? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'child_adhd', "Has your child been diagnosed with ADHD?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'fam_adhd', "Are there any other biological family members with diagnosed ADHD?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'fam_asd', "Are there any biological family members with diagnosed Autism?", array("" => "","1" => "Yes","2" => "No") );
        $this->form->addElement('select', 'orthodontia_current', "Does your child currently have any type of metal orthodontia, including braces?{unsure_ortho_current}", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','unsure_ortho_current',"");
        $this->form->addElement('select', 'ortho_current_remove', "Able to remove for study visits?", array("" => "","1" => "Yes","0" => "No") );
        $this->addBasicDate('ortho_current_expec_off', "When expected to have orthodontia off?");
        $this->form->addElement('select', 'antic_ortho', "Do you anticipate your child getting any new metal orthodontia within the next 6 months?{unsure_antic_ortho}", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','unsure_antic_ortho',"");
        $this->form->addElement('select', 'antic_ortho_remov', "Can the orthodontia be removed for study visits? ", array("" => "","1" => "Yes","0" => "No","999" => "Unsure") );
        $this->addBasicDate('antic_ortho_expect', "When are they expected to have new orthodontia? ");
        $this->form->addElement('select', 'cardiac_pacemaker', "Cardiac Pacemaker", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'implant_cardio_defib', "Implanted Cardiac Defibrillator", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'pacer_wires', "Pacer Wires", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'art_heart_valve', "Artificial Heart Valve", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'cardio_stents', "Cardiac Stents", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'eye_spring_retinal_tracks', "Eyelid Spring or Retinal Tracks", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'ear_implant', "Cochlear or Other Ear Implants", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'tatoos', "Tatoos, Tatoo Eye or Lip Liner", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'metal_eye', "Metal in eye", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'bullets', "Bullets, BBs, Shrapnel", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'drug_pump', "Any Implanted Drug Pumps", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'bladder_ring', "Diaphragm, IUD or Bladder Ring", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'claustrophobic', "Claustrophobic", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'preg_breastfeed', "Pregnant or Breastfeeding", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'kiddisease_dialysis', "Kidney Disease or Dialysis", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'penile_implant', "Penile Implant, Prostate or other Radiation Seeds", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'tiss_exp_tracheo', "Tissue Expanders or Tracheotomy", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'endo_camera_pill', "Endoscopy Camera and/or Pill", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'aneur_clip', "Brain Aneurysm Clip", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'neurostim', "Neurostimulator", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'spine_stim', "Spine Stimulator", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'spine_vent_shunt', "Spinal or Ventricular Shunt", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'implant_metal_misc', "Any other Implanted Metal or Device", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'coil_filter_stent', "Any other Coils, Filters or Stents", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'hearing_aid', "Hearing Aid", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'medpatch_dressing', "Medication Patch or Metal Dressing", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'artificial_limb', "Artificial Limb", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'artificial_limb_elec', "Artificial Limb Electronics", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'false_teeth', "False Teeth or Partial Plate", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'body_piercing', "Body Piercing", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'hair_implants', "Wig, Hair Implants, Clips or Pins", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'insulin_pump', "Insulin Pump or Glucose Monitor", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'hearing_aid_remove', "Can the hearing aid be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'med_patch_remove', "Can the medication patch/metal dressing be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'artificial_limb_remove', "Can the artificial limb be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'artificial_limb_elec_remove', "Can the artificial limb electronics be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'false_teeth_remove', "Can the false teeth/partial plate be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'body_piercing_remove', "Can the body piercing be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'hair_implant_remove', "Can the wig/hair implants/clips/pins  be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'insuln_pump_remove', "Can the insulin pump/glucose monitor be removed for study visits?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','child_no_surgery',"");
        $this->form->addElement('select', 'fearful_loud_noise', "Is your child fearful of loud sounds or noises of household appliances (such as a vacuum)? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'behavior_loud_enviro', "Is your child overwhelmed by loud, noisy environments? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'child_claustro', "Is your child claustrophobic? ", array("" => "","0" => "No","1" => "Yes","999" => "Unsure") );
        $this->form->addElement('select', 'child_hyperactive', "Is your child restless, not able to stay still for long, or overactive?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'sit_still_mri', "Do you feel that your child would be able to lie still for short periods of time during the MRI?", array("" => "","1" => "Yes","2" => "Maybe","0" => "No") );
        $this->form->addElement('select', 'tolerate_headphone', "Does your child dislike anything touching her/his face or wearing headphones? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'happen_next', "Does your child always need to know what is going to happen next? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'respond_verbal', "Does your child respond to questions verbally?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'ipad', "Is your child able to use an iPad tablet?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('text','exclusion_child_diag',"Has your child ever been formally diagnosed with the following? (Check all that apply) ");
        $this->form->addElement('select', 'radio_chemo', "Does your child have a history of chemotherapy or radiation therapy?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'brain_tumor_cancer', "Does your child have a history of a brain tumor or cancer?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'phys_disability', "Does your child have any physical disabilities?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'conduct_disorder', "Has your child ever been formally diagnosed with Conduct Disorder?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'impaired_vision', "Does your child have impaired vision?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'vision_correctable', "Is the impaired vision correctable? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'speech_difficulties', "Does your child have any speech or language difficulties?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'lang_delay', "Does your child currently have a language delay?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'color_blind', "Does your child have color blindness?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'allergies', "Does your child have any allergies? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'head_trauma', "Has your child experienced any type of head trauma?", array("" => "","1" => "Yes","0" => "No","999" => "Unknown") );
        $this->form->addElement('select', 'head_injury_uncon', "Has your child experienced any head injury that caused unconsciousness? ", array("" => "","1" => "Yes","0" => "No","999" => "Unknown") );
        $this->form->addElement('select', 'head_injury_uncon_hospital', "Hospitalized?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'head_injury_uncon_concus', "Concussion diagnosed?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'head_injury_uncon_pt', "Physical Therapy?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'med_diag_other', "Does your child have any other diagnoses or ongoing medical concerns? (Genetics, behavioral, medical, etc.)", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'stimulant', "Is your child currently on any medications, including stimulants?", array("" => "","1" => "Yes","0" => "No","999" => "Unknown") );
        $this->form->addElement('text','no_med_checkbox',"");
        $this->form->addElement('select', 'med_allergy', "Is your child allergic to any medications? ", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'stimulants_coordinator', "Child on stimulants? ", array("" => "","1" => "Yes","0" => "No","3" => "Skip") );
        $this->form->addElement('select', 'stimulation_cessation', "Would you be willing to have your child stop taking their stimulant medication if approved by their doctor? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'iq_test', "Has your child ever had an IQ test?", array("" => "","1" => "Yes","0" => "No","3" => "Skip","4" => "Other","999" => "Unsure") );
        $this->form->addElement('select', 'iq_test_results', "Do you know the results, or could you obtain records from the testing and agree to share them with our medical team?", array("" => "","1" => "Yes","0" => "No","3" => "Skip") );
        $this->form->addElement('select', 'psych_test_other', "Has your child ever had any other formal psychological testing?", array("" => "","1" => "Yes","0" => "No","3" => "Skip","999" => "Unsure") );
        $this->form->addElement('text','psych_test_specify',"Please select which tests your child has taken");
        $this->form->addElement('select', 'psych_test_records', "Would you be willing to provide copies to our medical review team? ", array("" => "","1" => "Yes","0" => "No","3" => "Skip") );
        $this->form->addElement('select', 'iep', "Does your child have an Individualized Education Program (IEP)? ", array("" => "","1" => "Yes","0" => "No","3" => "Skip","999" => "Unsure") );
        $this->form->addElement('select', 'iep_record_release', "If so, would you be willing to provide copies of their IEP to our medical review team? ", array("" => "","1" => "Yes","0" => "No","3" => "Skip") );
        $this->form->addElement('select', 'child_ethnicity', "Child Ethnicity", array("" => "","1" => "Hispanic/Latino","2" => "Non-Hispanic/Latino","999" => "Unknown","4" => "Declined") );
        $this->form->addElement('text','child_racial_group',"What racial group(s) is your child primarily identified with? (Check all that apply)");
        $this->form->addElement('select', 'parent_ethnicity', "Parent 1 Ethnicity: ", array("" => "","1" => "Hispanic/Latino","2" => "Non-Hispanic/Latino","999" => "Unknown","3" => "Declined") );
        $this->form->addElement('text','parent_racial_group',"What racial group(s) do you (Parent 1) primarily identified with? (Check all that apply)");
        $this->form->addElement('select', 'phone_screen_complete', "Phone screen completed?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'd_team_review', "D-Team review needed? ", array("" => "","1" => "Yes","0" => "No","999" => "Unsure") );
        $this->form->addElement('select', 'eligibility', "Eligibility", array("" => "","1" => "Eligible","2" => "Ineligible","999" => "Unsure") );
        $this->form->addElement('text','ineligibility_reason',"If &#39;Ineligible&#39; check all reasons:");
    }


}

?>