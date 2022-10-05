<?php
/**
 * This file contains the NDB_BVL_Instrument_FIRMM_database_dump
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  FIRMM_database_dump
 * @author   Barry Tikalsky tikal004@umn.edu
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

/**
 * Creates the form elements for the Boston_Diagnostic_Aphasia_Exam instrument
 *
 * @category Instrument
 * @package  FIRMM_database_dump
 * @author   Barry Tikalsky tikal004@umn.edu
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */
class NDB_BVL_Instrument_FIRMM_database_dump extends NDB_BVL_Instrument
{
    use \LorisFormDictionaryImpl;

    /**
    * sets up basic data.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    function setup(?string $commentID = null, ?string $page = null, ?string $candID = null, ?string $sessionID = null, ?string $downloadFile = null): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "FIRMM_database_dump";           // test_names.Test_name
        $this->table = 'FIRMM_database_dump';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        $this->candID = $candID;
        $this->sessionID = $sessionID;

        //The array of selects with multiple answers allowed
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner', 'file_path');

        // setup the form
        $this->_setupForm();
        if(isset($_GET['downloadFile']))
        {
            $this->downloadJson();
        }


   }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * method to build the object into a paginated form
    *
    * @return void
    * @access private
    */
    function _setupForm(){
        switch($this->page) {
            case "FIRMM_database_dump_page1":
            $this->_page1();
            break;

            default:
            $this->_main();
            break;
        }
        //Defines the call back function to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
    }

    /**
    * generates the main page of the form.
    *
    * @return void
    * @access private
    *
    */
    function _main(){
        // display test name
        $this->addHeader("Upload the FIRMM database dump file");

        $config      = \NDB_Config::singleton();
        $dateOptions = [
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        ];

        $this->dateOptions = $dateOptions;
        $examiners = $this->_getExaminerNames();
        $this->addBasicDate('Date_taken', 'Date of Upload', $dateOptions);
        $this->addSelect('Examiner', 'Examiner', $examiners);

        //upload file
        $this->form->addElement('file', 'upload_file', 'Upload a file');
        $this->form->addElement('static', 'file_name', "Uploaded File");
    }

    function _page1(){

       $download_link = '/instruments/FIRMM_database_dump/?commentID='.$this->commentID.'&sessionID='.$this->sessionID.'&candID='.$this->candID.'&downloadFile=true';
       $this->addHeader("Download the FIRMM database dump file");
       $this->form->addElement('static', 'file_name', "Uploaded File");
       $this->form->addElement('link', 'download_link', "Click to download file", $download_link, 'Download File');



    }

    function _saveValues($values) :void
    {
         $timepoint = TimePoint::singleton($this->getSessionID());
         $candidate = Candidate::singleton($timepoint->getCandID());

         if(isset($values['upload_file']) && !empty($values['upload_file']['name'])) {
            include_once "File_Upload.class.inc";
            $file=new File_Upload;

            //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
            $file->registerForm($this->form);


            //Tell File_Upload what file handlers to use.
            $file->setFileHandler("upload_file", $this);

            //Set the target directory that you want files moved into once they are validated and processed.
            $config = NDB_Config::singleton();
            $dir = $config->getSetting("mediaPath");
            if(empty($dir)) {
                $dir = ".";
            };
            $file->setBaseUploadDirectory($dir . "FIRMM_database_dump/");

            //Set the prefix to prepend to the filenames
            //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

            //set the the IDs to the handler functions.
            $user =& User::singleton();
            $file->setHandlerArgs(array("CommentID"=>$this->getCommentID(),
                        "candID"=>$candidate->getCandID(),
                        "PSCID"=>$candidate->getPSCID(),
                        "visitLabel"=>$timepoint->getVisitLabel(),
                        "username"=>$user->getUsername(),
                        "values"=>$values)
                    );



            //If the form is validated, call File_Upload::processFiles() which loops through the files and
            //proccesses them (including verify, move, and import steps)
            $file->processFiles();
        }
        //echo error messages
        if(!empty($file->errorLog)){
        while(list($fileType,$fileErrors)=each($file->errorLog)){
            foreach($fileErrors AS $error){
                 echo "<span style='color:red'><b>Upload Error</b> $fileType: $error</span><br>";
            }
         }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'],
              $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'],
              $values['upload_file']);
      $this->_save($values);

   }

   /**
     * getTargetDirectory retrieves info about where the file should be stored.
     *
     * The returned directory is ADDED to the baseUploadDirectory property.  It should have a trailing slash.
     *
     * @param     string  $file    The full filename including directory.
     *
     * @return    bool    $success     if operation succeeded
     * @access    public
     */
    function getTargetDirectory(&$file, $args){
        $output=$args['candID']."/";
        return $output;
    }

   /*
    * Import data from the uploaded file
    *
    * @param $file Reference to file object
    * @param $args An associative array set by setHandlerArgs function
    *
    * @return true If operation succeeded
    */
   function importFile(&$file, $args) {
        $fp=fopen($file->fileInfo['tmp_name'], "r");

        $db=& Database::singleton();
        ///Setting trackchanges to false because getting error messages
        $db->_trackChanges = false;
        ////////////////////////////////////////////////////////////////
        $file_name=$file->getDestinationFilename();
        $directory=$file->getDestinationDirectory();
        $file_path=$directory.$file_name;
        $upload_values = array(
            'file_name' => $file_name,
            'file_path' => $file_path
        ); //uploading values to FIRMM_database_dump table

       /*parse the file and store the values to upload in the array above
       * and save to the database
       */

       // update database
       $result = $db->update($this->testName, $upload_values, array('CommentID'=>$args['CommentID']));

       echo "<span style='color:red'><b>Upload Successful : </b>".$upload_values[$field]."</span><br>";
       return true;
   }

    function isValid(&$file, $args)
    {
        return true;
    }

    /**
     * {@inheritDoc}
     *
     * @return string|null
     */
    public function getFullName(): ?string
    {
        return "FIRMM_database_dump";
    }

    /**
     * {@inheritDoc}
     *
     * @return array
     */
    function getSubtestList(): array
    {
        $subtest = [
            ['Name'=>'FIRMM_database_dump_page1','Description'=>'Download File'],
        ];
        return $subtest;
    }

    //https://stackoverflow.com/questions/32329586/how-do-i-download-a-file-using-php-and-mysql-db
    function downloadJson()
    {

        $db = \Database::singleton();
        $fullPath = $db->pselectOne(
            "SELECT file_path FROM FIRMM_database_dump WHERE CommentID=:CID",
            ['CID' => $this->getCommentID()]
        );

        if( headers_sent() )
            die('Headers Sent');


        if(ini_get('zlib.output_compression'))
            ini_set('zlib.output_compression', 'Off');


        if( file_exists($fullPath) )
        {

            $fsize = filesize($fullPath);
            $path_parts = pathinfo($fullPath);

            $ctype="application/json";

            header("Pragma: public"); 
            header("Expires: 0");
            header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
            header("Cache-Control: private",false); 
            header("Content-Type: $ctype");
            header("Content-Disposition: attachment; filename=\"".basename($fullPath)."\";" );
            header("Content-Transfer-Encoding: binary");
            header("Content-Length: ".$fsize);
            ob_clean();
            flush();
            readfile( $fullPath );

        } 
        else
            die('File Not Found');
        
    }
}
