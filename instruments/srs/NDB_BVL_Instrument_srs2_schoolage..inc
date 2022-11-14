<?php

class NDB_BVL_Instrument_srs2_schoolage extends NDB_BVL_Instrument
{
    use \LorisFormDictionaryImpl;
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

        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'srs2_schoolage' ;           // test_names.Test_name
        $this->table = 'srs2_schoolage';              // name of database table corresponding to instrument
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
        $this->addHeader("SRS - 2 School-Age");

        $this->addHeader("Scores");

        $this->form->addElement('static','srs_school_age_awr',"Social Awareness");
        $this->form->addElement('static','srs_school_age_awr_t',"<p style='background-color:silver'>Social Awareness T-Score</p>");

        $this->form->addElement('static','srs_school_age_cog',"Social Cognition");
        $this->form->addElement('static','srs_school_age_cog_t',"<p style='background-color:silver'>Social Cognition T-Score</p>");

        $this->form->addElement('static','srs_school_age_com',"Social Communication");
        $this->form->addElement('static','srs_school_age_com_t',"<p style='background-color:silver'>Social Communication T-Score</p>");

        $this->form->addElement('static','srs_school_age_mot',"Social Motivation");
        $this->form->addElement('static','srs_school_age_mot_t',"<p style='background-color:silver'>Social Motivation T-Score</p>");

        $this->form->addElement('static','srs_school_age_rrb',"Restricted Interests and Repetitive Behaviour");
        $this->form->addElement('static','srs_school_age_rrb_t',"<p style='background-color:silver'>Restricted Interests and Repetitive Behaviour T-Score</p>");

        $this->form->addElement('static','srs_school_age_sci',"DSM-5 Social Communication Index (SCI)");
        $this->form->addElement('static','srs_school_age_sci_t',"<p style='background-color:silver'>SCI T-Score</p>");

        $this->form->addElement('static','srs_school_age_total',"SRS-2 Total Score");
        $this->form->addElement('static','srs_school_age_total_t',"<p style='background-color:silver'>SRS-2 Total T-Score</p>");

        $this->addHeader("Questions");

        $this->form->addElement('select', 'srs_school_age_1', "1. Seems much more fidgety in social situations than when alone.", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_2', "2. Expressions on his/her face don't match what he/she is saying. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_3', "3. Seems self-confident when interacting with others. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_4', "4. When under stress, he or she shows rigid or inflexible patterns of behavior that seem odd. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_5', "5. Doesn't recognize when someone is trying to take advantage of him or her. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_6', "6. Would rather be alone than with others. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_7', "7. Is aware of what others are thinking or feeling. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_8', "8. Behaves in ways that seem strange or bizarre. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_9', "9. Clings to adults, seems too dependent on them. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_10', "10. Takes things too literally and doesn't get the real meaning of a conversation. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_11', "11. Has good self-confidence.", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_12', "12. Is able to communicate his or her feelings to others. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_13', "13. Is awkward in turn-taking interactions with peers (For example, doesn't seem to understand the give-and-take of conversations). ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_14', "14. Is not well coordinated. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_15', "15. Is able to understand the meaning of other people's tone of voice and facial expressions. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_16', "16. Avoids eye contact or has unusual eye contact. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_17', "17. Recognizes when something is unfair. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_18', "18. Has difficulty making friends, even when trying his or her best. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_19', "19. Gets frustrated trying to get ideas across in conversations. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_20', "20. Shows unusual sensory interests (for example, mouthing or spinning objects) or strange ways of playing with toys. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_21', "21. Is able to imitate others' actions.", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_22', "22. Plays appropriately with children his or her age. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_23', "23. Does not join group activities unless told to do so. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_24', "24. Has more difficulty than other children with changes in his or her routine. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_25', "25. Doesn't seem to mind being out of step with or 'not on the same wavelength' as others. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_26', "26. Offers comfort to others when they are sad. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_27', "27. Avoids starting social interactions with peers or adults.", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_28', "28. Thinks or talks about the same thing over and over.", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_29', "29. Is regarded by other children as odd or weird. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_30', "30. Becomes upset in a situation with lots of things going on. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_31', "31. Can't get his or her mind off something once he or she starts thinking about it. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_32', "32. Has good personal hygiene. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_33', "33. Is socially awkward, even when he or she is trying to be polite. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_34', "34. Avoids people who want to be emotionally close to him or her. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_35', "35. Has trouble keeping up with the flow of a normal conversation. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_36', "36. Has difficulty relating to adults. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_37', "37. Has difficulty relating to peers. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_38', "38. Responds appropriately to mood changes in others (for example, when a friend's or playmate's mood changes from happy to sad). ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_39', "39. Has an unusually narrow range of interests. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_40', "40. Is imaginative, good at pretending (without losing touch with reality). ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_41', "41. Wanders aimlessly from one activity to another. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_42', "42. Seems overly sensitive to sounds, textures, or smells. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_43', "43. Separates easily from caregivers. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_44', "44. Doesn't understand how events relate to one another (cause and effect) the way other children his or her age do. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_45', "45. Focuses his or her attention to where others are looking or listening. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_46', "46. Has overly serious facial expressions. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_47', "47. Is too silly or laughs inappropriately. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_48', "48. Has a sense of humor, understands jokes. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_49', "49. Does extremely well at a few tasks, but does not do as well at most other tasks. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_50', "50. Has repetitive, odd behavior such as hand flapping or rocking. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_51', "51. Has difficulty answering questions directly and ends up talking around the subject. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_52', "52. Knows when he or she is talking too loud or making too much noise. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_53', "53. Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture). ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_54', "54. Seems to react to people as if they are objects. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_55', "55. Knows when he or she is too close to someone or invading someone's space. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_56', "56. Walks in between people two people who are talking. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_57', "57. Gets teased a lot.  ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_58', "58. Concentrates too much on parts of things rather than seeing the whole picture. For example, if asked to describe what happened in a story, he or she may talk only about the kind of clothes the characters were wearing. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_59', "59. Is overly suspicious.", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_60', "60. Is emotionally distant, doesn't show his or her feelings. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_61', "61. Is inflexible, has a hard time changing his or her mind. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_62', "62. Gives unusual or illogical reasons for doing things. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_63', "63. Touches others in an unusual way (for example, he or she may touch someone just to make contact and then walk away without saying anything).  ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_64', "64. Is too tense in social settings. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
        $this->form->addElement('select', 'srs_school_age_65', "65. Stares or gazes off into space. ", array(''=>'', '1'=>"1: Not true", '2'=>"2: Sometimes True", '3'=>"3: Often True", '4'=>"4: Almost Always True", 'not_answered'=>'Not Answered'));
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
            "srs_school_age_awr" => null,
            "srs_school_age_cog" => null,
            "srs_school_age_com" => null,
            "srs_school_age_mot" => null,
            "srs_school_age_rrb" => null,
            "srs_school_age_awr_t" => null,
            "srs_school_age_cog_t" => null,
            "srs_school_age_com_t" => null,
            "srs_school_age_mot_t" => null,
            "srs_school_age_rrb_t" => null,
            "srs_school_age_sci" => null,
            "srs_school_age_sci_t" => null,
            "srs_school_age_total" => null,
            "srs_school_age_total_t" => null,
        );

        $forward_scores = array(1, 2, 4, 5, 6, 8, 9, 10, 13, 14, 16, 18, 19, 20, 23, 24, 27, 28, 29, 30, 31, 33, 34, 35, 36, 37, 39, 41, 42, 44, 46, 47, 49, 50, 51, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65);
        $median_1 = array(1, 7, 11, 12, 25, 26, 38, 45, 52, 55);

        $categories = array(
            "awr" => array(2, 7, 25, 32, 45, 52, 54, 56),
            "cog" => array(5, 10, 15, 17, 30, 40, 42, 44, 48, 58, 59, 62),
            "com" => array(12, 13, 16, 18, 19, 21, 22, 26, 33, 35, 36, 37, 38, 41, 46, 47, 51, 53, 55, 57, 60, 61),
            "mot" => array(1, 3, 6, 9, 11, 23, 27, 34, 43, 64),
            "rrb" => array(4, 8, 14, 20, 24, 28, 29, 31, 39, 49, 50, 63),
        );

        foreach(array_keys($categories) as $category) {
            $category_name = "srs_school_age_" . $category;
            foreach($categories[$category] as $question) {
                $question_name = "srs_school_age_" . $question;
                $value = $record[$question_name];
                if ($value){
                    if (in_array($question, $forward_scores)) {
                        $scores[$category_name] += $value;
                    } else {
                        $adjusted_value = 3 - $value;
                        $scores["$category_name"] += $adjusted_value;
                    }
                } else {
                    if (in_array($question, $median_1)) {
                        $scores["$category_name"] += 1;
                    } else {
                        $scores["$category_name"] += 0;
                    }
                }
            }
        }

        $scores["srs_school_age_sci"] = $scores["srs_school_age_awr"] + $scores["srs_school_age_cog"] + $scores["srs_school_age_com"] + $scores["srs_school_age_mot"];
        $scores["srs_school_age_total"] = $scores["srs_school_age_sci"] + $scores["srs_school_age_rrb"];

        
        $tscores = array("awr", "cog", "com", "mot", "rrb", "sci", "total");
        foreach($tscores as $category) {
            $category_name = "srs_school_age_" . $category;
            $tscore_name = $category_name . "_t";
            $score = $scores[$category_name];
            $scores[$tscore_name] = $db->pselectRow("SELECT tscore FROM srs2_schoolage_lookup WHERE category=:c AND score=:s", array("c"=> $category, "s"=>$score))["tscore"];
        }
        
        // print_r($scores);
        // save the scores
        $result = $db->update($this->table, $scores, array("CommentID"=>$this->getCommentID()));
    }
}

?>