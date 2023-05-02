<?php

/**
 * This file contains the NDB_BVL_Instrument_cohort_and_comorbid_diagnoses
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_cohort_and_comorbid_diagnoses extends NDB_BVL_Instrument
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
        $this->testName = 'cohort_and_comorbid_diagnoses' ;           // test_names.Test_name
        $this->table = 'cohort_and_comorbid_diagnoses';              // name of database table corresponding to instrument
        // FULL NAME: cohort_and_comorbid_diagnoses
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
        $this->addHeader("Cohort and Comorbid Diagnoses");

        $this->form->addElement('select', 'cohort_tracking', "Cohort Tracking", array("" => "","1" => "Control","2" => "ADHD","3" => "ASD","4" => "ASD and ADHD","5" => "Ineligible for Subpopulations") );
        $this->form->addElement('select', 'pri_vs_sec', "Primary vs Secondary ADHD", array("" => "","1" => "N/A","2" => "Primary ADHD","3" => "Secondary ADHD") );
        $this->form->addElement('text','inatt',"Inattentive");
        $this->form->addElement('text','hyper',"Hyperactive");
        $this->form->addElement('text','combined',"Combined");
        $this->form->addElement('text','subthres',"Subthreshold");
        $this->form->addElement('text','no_converg',"No Convergence");
        $this->form->addElement('select', 'subtype_rea', "ADHD Subtype Reasoning", array("" => "","1" => "N/A","2" => "Default: ever combined","3" => "Developmentally does not make sense","4" => "Parent OVER reports","5" => "Parent UNDER reports","6" => "Teacher OVER reports","7" => "Teacher UNDER reports","8" => "Symptom picture at variance from history","9" => "No Convergence","10" => "Other") );
        $this->form->addElement('select', 'adhd_severity', "ADHD Severity", array("" => "","1" => "Mild","2" => "Moderate","3" => "Severe","4" => "N/A") );
        $this->form->addElement('select', 'adhd_conf_rate', "Confidence Rating - ADHD", array("" => "","1" => "Not enough information - ineligible for D-Team","2" => "Low Confidence","3" => "High Confidence") );
        $this->form->addElement('text','average_gaf',"Average GAF");
        $this->form->addElement('select', 'health_concerns', "Health concerns affecting participation", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'comor_dx', "Did this participant have any comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current',"Current");
        $this->form->addElement('text','past',"Past");
        $this->form->addElement('select', 'add_comorbid_dx', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current2',"Current");
        $this->form->addElement('text','past2',"Past");
        $this->form->addElement('select', 'add_comorbid_dx_2', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current3',"Current");
        $this->form->addElement('text','past3',"Past");
        $this->form->addElement('select', 'add_codx3', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current4',"Current");
        $this->form->addElement('text','past4',"Past");
        $this->form->addElement('select', 'add_codx4', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current5',"Current");
        $this->form->addElement('text','past5',"Past");
        $this->form->addElement('select', 'add_codx5', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current6',"Current");
        $this->form->addElement('text','past6',"Past");
        $this->form->addElement('select', 'add_codx6', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current7',"Current");
        $this->form->addElement('text','past7',"Past");
        $this->form->addElement('select', 'add_codx7', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current8',"Current");
        $this->form->addElement('text','past8',"Past");
        $this->form->addElement('select', 'add_codx8', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current9',"Current");
        $this->form->addElement('text','past9',"Past");
        $this->form->addElement('select', 'add_codx9', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current10',"Current");
        $this->form->addElement('text','past10',"Past");
        $this->form->addElement('select', 'add_codx10', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current11',"Current");
        $this->form->addElement('text','past11',"Past");
        $this->form->addElement('select', 'add_codx11', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current12',"Current");
        $this->form->addElement('text','past12',"Past");
        $this->form->addElement('select', 'add_codx12', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current13',"Current");
        $this->form->addElement('text','past13',"Past");
        $this->form->addElement('select', 'add_codx13', "Does this participant have any additional comorbid diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('text','current14',"Current");
        $this->form->addElement('text','past14',"Past");
        $this->form->addElement('select', 'add_codx14', "Does this participant have any additional diagnoses?", array("" => "","0" => "No","1" => "Yes") );
        $this->form->addElement('select', 'current15', "Current", array("" => "","1" => "Full Dx","2" => "Subthreshold","3" => "NOS","4" => "Rule Out") );
        $this->form->addElement('select', 'past15', "Past", array("" => "","1" => "Full Dx","2" => "Subthreshold","3" => "NOS","4" => "Rule Out") );
        $this->form->addElement('select', 'conf_rate_comorbid', "Confidence Rating - Comorbidities", array("" => "","1" => "Low Confidence","2" => "High Confidence") );
    }


}

?>