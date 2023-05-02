<?php

/**
 * This file contains the NDB_BVL_Instrument_scq_lifetime
 * class
 *
 * @category Instrument
 * @package  LORIS Instrument Builder
 * @author   False 
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/ 
 * @updated  2023-05-02 
 */

class NDB_BVL_Instrument_scq_lifetime extends NDB_BVL_Instrument
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
        $this->testName = 'scq_lifetime' ;           // test_names.Test_name
        $this->table = 'scq_lifetime';              // name of database table corresponding to instrument
        // FULL NAME: scq_lifetime
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
        $this->addHeader("Social Communication Questionnaire (SCQ) - Lifetime");

        $this->addHeader("<h3>Calculated Fields</h3>");
        $this->form->addElement('static', 'scql_total', "Total Score");

        $this->addHeader("<h3>Questions</h3>");
        $this->form->addElement('select', 'scql_1', "1. Is she/he now able to talk using short phrases or sentences? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_2', "2. Can you have a to and fro &#34;conversation&#34; with her/him that involves taking turns or building on what you have said? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_3', "3. Has she/he ever used odd phrases or said the same thing over and over in almost exactly the same way (either phrases that she/he has heard other people use or ones that she/he made up)? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_4', "4. Has she/he ever used socially inappropriate questions or statements? For example, has she/he ever regularly asked personal questions or made personal comments at awkward times? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_5', "5. Has she/he ever got her/his pronouns mixed up (e.g., saying &lt;em&gt;you&lt;/em&gt; or &lt;em&gt;she/he&lt;/em&gt;  for &lt;em&gt;I&lt;/em&gt;)?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_6', "6. Has she/he ever used words that she/he seemed to have invented or made up her/himself; put things in odd, indirect ways; or used metaphorical ways of saying things (e.g., saying &lt;em&gt;hot rain&lt;/em&gt; for &lt;em&gt;steam&lt;/em&gt;)?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_7', "7. Has she/he ever said the same thing over in over in exactly the same way or insisted that you say the same thing over and over again? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_8', "8. Has she/he ever had things that she/he seemed to have to do in a very particular order or rituals that she/he insisted that you go through?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_9', "9. Has her/his facial expression seemed appropriate to the particular situation, as far as you could tell? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_10', "10. Has she/he ever used your hand like a tool as if it were part of her/his own body (e.g., pointing with your finger, putting your hand on a doorknob to get you to open the door)?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_11', "11. Has she/he ever had any interests that preoccupy her/him and might seem odd to other people (e.g., traffic lights, drainpipes, or timetables)? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_12', "12. Has she/he ever seemed to be more interested in parts of a toy or an object (e.g., spinning wheels of a car), rather than using the object as it was intended? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_13', "13. Has she/he ever had any special interests that were &lt;em&gt;unusual&lt;/em&gt; in their intensity but otherwise appropriate for her/his age and peer group (e.g., trains, dinosaurs)? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_14', "14. Has she/he ever seemed to be &lt;em&gt;unusually&lt;/em&gt; interested in the feel, sound, taste, or smell of things or people? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_15', "15. Has she/he ever had any mannerisms or odd ways of moving her/his hands or fingers, such as flapping or moving her/his fingers in front of her/his eyes?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_16', "16. Has she/he ever had any complicated movements of her/his body, such as spinning or repeatedly bouncing up and down?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_17', "17. Has she/he ever injured her/himself deliberately, such as by biting her/his arm or banging her/his head? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_18', "18. Has she/he ever had any objects (&lt;em&gt;other&lt;/em&gt; than a soft toy or comfort blanket) that she/he &lt;em&gt;had&lt;/em&gt; to carry around? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_19', "19. Does she/he have any particular friends or a best friend? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_20', "20. When she/he was 4 to 5, did she/he ever talk with you just to be friendly (rather than to get something)? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_21', "21. When she/he was 4 to 5, did she/he ever &lt;em&gt;spontaneously&lt;/em&gt; copy you (or other people) or what you were doing (such as vacuuming, gardening, or mending things)?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_22', "22. When she/he was 4 to 5, did she/he ever spontaneously point at things around her/him just to show you things (not just because she/he wanted them)?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_23', "23. When she/he was 4 to 5, did she/he ever use gestures, other than pointing or pulling your hand, to let you know what she/he wanted?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_24', "24. When she/he was 4 to 5, did she/he nod her/his head to mean &lt;em&gt;yes&lt;/em&gt; ?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_25', "25. When she/he was 4 to 5, did she/he shake her/his head to mean &lt;em&gt;no&lt;/em&gt; ?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_26', "26. When she/he was 4 to 5,  did she/he usually look at you directly in the face when doing things with you or talking with you? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_27', "27. When she/he was 4 to 5, did she/ he smile back if someone smiled at her/him?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_28', "28. When she/he was 4 to 5, did she/he ever show you things that interested her/him to engage your attention? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_29', "29. When she/he was 4 to 5, did she/he ever offer to share things other than food with you? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_30', "30. When she/he was 4 to 5, did she/he ever seem to want you to join in her/his enjoyment of something? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_31', "31. When she/he was 4 to 5, did she/he ever try to comfort you if you were sad or hurt?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_32', "32. When she/he was 4 to 5,  when she/he wanted something or wanted help, did she/he look at you and use gestures with sounds or words to get your attention? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_33', "33. When she/he was 4 to 5, did she/he show a normal range of facial expressions?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_34', "34. When she/he was 4 to 5, did she/he ever spontaneously join in and try to copy the actions in social games, such as &lt;em&gt;The Mulberry Bush&lt;/em&gt; or &lt;em&gt;London Bridge is Falling Down&lt;/em&gt; ? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_35', "35. When she/he was 4 to 5, did she/he play any pretend or make-believe games?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_36', "36. When she/he was 4 to 5, did she/he seem interested in other children of approximately the same age whom she/he did not know?", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_37', "37. When she/he was 4 to 5, did she/he respond positively when another child approached her/him? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_38', "38. When she/he was 4 to 5, if you came into a room and started talking to her/him without calling her/his name, did she/he usually look up and pay attention to you? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_39', "39. When she/he was 4 to 5, did she/he ever pay imaginative games with another child in such a way that you could tell that they each understood what the other was pretending? ", array("" => "","1" => "Yes","0" => "No") );
        $this->form->addElement('select', 'scql_40', "40. When she/he was 4 to 5, did she/he play cooperatively in games that required joining in with a group of other children, such as hide-and-seek or ball games? ", array("" => "","1" => "Yes","0" => "No") );
    }

    /**
    * Scoring function
    *
    * @return void
    * @access public
    */
    function score():void
    {
        if ($this->_determineRequiredElementsCompletedFlag() == "Incomplete") {
            return;
        }

        $db =& Database::singleton();
        //Get raw questions point values
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));

        $scores = array(
            'scql_total' => null,
        );

        $reverse_scores = array(2, 9, 19);
        $score_start = 2;
        if ($record["scql_1"] == 0) {
            $score_start = 8;
        }

        foreach (range($score_start, 40) as $number) {
            $question_name = "scql_" . $number;
            $value = $record[$question_name];

            if (in_array($number, $reverse_scores) or ($number >= 20)) {
                $scores['scql_total'] += (1 - $value);
            } else {
                $scores['scql_total'] += $value;
            }
        }

        // save the scores
        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }
}

?>