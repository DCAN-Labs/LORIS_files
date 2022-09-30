<?php

#require_once 'HTML/QuickForm.php';
#require_once 'HTML/QuickForm/Renderer/Array.php';

class NDB_BVL_Instrument_SRS2_SchoolAge extends NDB_BVL_Instrument
{
    use \LorisFormDictionaryImpl;
    use LegacyInstrumentTrait;
    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /*
    INSERT INTO test_names (Test_name, Full_name, LimitAge, Sub_Group)
        VALUES ('SRS2_SchoolAge', 'Social Responsiveness Scale (Preschool Version for 3-Year-Olds)', '0', '1');

    INSERT INTO instrument_subtests VALUES('', 'SRS2_SchoolAge', 'SRS2_SchoolAge_page1', 'Page 1 (1-32)', 1);
    INSERT INTO instrument_subtests VALUES('', 'SRS2_SchoolAge', 'SRS2_SchoolAge_page2', 'Page 2 (33-65', 2);
    -- No more page 3.
    -- INSERT INTO instrument_subtests VALUES('', 'SRS2_SchoolAge', 'SRS2_SchoolAge_page3', 'Page 3', 3);
    */
    /* array indexing from page number to question array for that page.
     * the _page($pageNum) function takes the appropriate page, and adds
     * all the questions to the page.
     */

    var $questions = array(
        1 => array(
            "q1_uncomfortable_socialsituations"     => "1. Seems much more fidgety in social situations than when alone",
            "q2_wrong_facialexpressions"            => "2. Expressions on his or her face don't match what he or she is saying",
            "q3_self_confident"                     => "3. Seems self-confident when interacting with others",
            "q4_rigid_inflexible"                   => "4. When under stress, he or she shows rigid or inflexible patterns of behavior that seem odd",
            "q5_others_take_advantage"              => "5. Doesn't recognize when others are trying to take advantage of him or her",
            "q6_rather_be_alone"                    => "6. Would rather be alone than with others",
            "q7_aware_others_feeling"               => "7. Is aware of what others are thinking or feeling",
            "q8_behave_strange_bizarre"             => "8. Behaves in ways that seem strange or bizarre",
            "q9_overly_dependent"                   => "9. Clings to adults, seems too dependent on them",
            "q10_takethings_literally"              => "10. Takes things too literally, and doesn't get the real meaning of a conversation",
            "q11_has_selfconfidence"                => "11. Has good self-confidence",
            "q12_communicate_toothers"              => "12. Is able to communicate his or her feelings to others",
            "q13_awkward_turn_takingtalk"           => "13. Is awkward in turn-taking interactions with peers (for example, doesn't seem to understand the give-and-take of conversations)",
            "q14_notwell_coordinated"               => "14. Is not well coordinated",
            "q15_changefacialexp_understandmeaning" => "15. Is able to understand the meaning of other people's tone of voice and facial expressions",
            "q16_avoideyecontact"           => "16. Avoids eye contact or has unusual eye contact",
            "q17_recognize_unfair"          => "17. Recognizes when something is unfair",
            "q18_difficulty_makingfriends"  => "18. Has difficulty making friends, even when trying his or her best",
            "q19_frustrated_conveyingideas" => "19. Gets frustrated trying to get ideas across in conversations",
            "q20_unusual_interests"         => "20. Shows unusual sensory interests (for example, mouthing or spinning objects) or strange ways of playing with toys",
            "q21_imitate_actions"           => "21. Is able to imitate others' actions",
            "q22_interact_appropriately"    => "22. Plays appropriately with children his or her age",
            "q23_joingroups_activities"     => "23. Does not join group activities unless told to do so",
            "q24_diff_changeroutine"        => "24. Has more difficulty than other children with changes in his or her routine",
            "q25_diff_wavelength"           => "25. Doesn't seem to mind being out of step with or \"not on the same wavelength\" as others",
            "q26_offer_comfort"             => "26. Offers comfort to others when they are sad",
            "q27_avoid_socialinteractions"  => "27. Avoids starting social interactions with peers or adults",
            "q28_think_overandover"         => "28. Thinks or talks about the same thing over and over",
            "q29_odd_weird"                 => "29. Is regarded by other children as odd or weird",
            "q30_upset_situations"          => "30. Becomes upset in a situation with lots of things going on",
            "q31_cant_getmind_off"          => "31. Can't get his or her mind off something once he or she starts thinking about it",
            "q32_good_personal_hygiene"     => "32. Has good personal hygiene"),
        2 => array(
            "q33_socially_awkward"           => "33. Is socially awkward, even when he or she is trying to be polite",
            "q34_avoid_emotionallyclose"     => "34. Avoids people who want to be emotionally close to him or her",
            "q35_trouble_keepingup"          => "35. Has trouble keeping up with the flow of a normal conversation",
            "q36_difficulty_relating_adults" => "36. Has difficulty relating to adults",
            "q37_difficulty_relating_peers"  => "37. Has difficulty relating to peers",
            "q38_respond_moodchange"         => "38. Responds appropriately to mood changes in others (for example when a friend's or playmate's mood changes from happy to sad)",
            "q39_interested_toofew_topics"   => "39. Has an unusually narrow range of interests",
            "q40_imaginative"                => "40. Is imaginative, good at pretending (without losing touch with reality)",
            "q41_wander_aimlessly"           => "41. Wanders aimlessly from one activity to another",
            "q42_overly_sensitive"           => "42. Seems overly sensitive to sounds, textures, or smells",
            "q43_separates_easily"           => "43. Separates easily from caregivers",
            "q44_chains_causation"           => "44. Doesn't understand how events relate to one another (cause and effect) the way other children his or her age do",
            "q45_pay_attention"              => "45. Focuses his or her attention to where others are looking or listening",
            "q46_serious_facialexp"          => "46. Has overly serious facial expressions",
            "q47_laugh_inappropriately"      => "47. Is too silly or laughs inappropriately",
            "q48_goodsense_humor"            => "48. Has a sense of humor, understands jokes",
            "q49_wellat_tasks"               => "49. Does extremely well at a few tasks, but does not do as well at most other tasks",
            "q50_repetitive_behavior"        => "50. Has repetitive, odd behaviors such as hand flapping or rocking",
            "q51_diff_directqstn"            => "51. Has difficulty answering questions directly and ends up talking around the subject",
            "q52_overly_loud"            => "52. Knows when he or she is talking too loud or making too much noise",
            "q53_monotone_voice"         => "53. Talks to people with an unusual tone of voice (for example, talks like a robot or like he or she is giving a lecture)",
            "q54_thinkpeople_as_objects" => "54. Seems to react to people as if they are objects",
            "q55_invade_personalspace"   => "55. Knows when he or she is too close to someone or is invading someone's space",
            "q56_walk_btwn_people"       => "56. Walks in between two people who are talking",
            "q57_gets_teased"            => "57. Gets teased a lot",
            "q58_concentration_parts"    => "58. Concentrates too much on parts of things rather than seeing the whole picture. For example, if asked to describe what happened in a story, he or she may talk only about the kind of clothes the characters were wearing",
            "q59_suspicious_ofpeople"    => "59. Is overly suspicious",
            "q60_emotionally_distant"    => "60. Is emotionally distant, doesn't show his or her feelings",
            "q61_inflexible"             => "61. Is inflexible, has a hard time changing his or her mind ",
            "q62_reason_unusual"         => "62. Gives unusual or illogical reasons for doing things",
            "q63_touching_unusual"       => "63. Touches or greets others in an unusual way (for example, he or she may touch someone just to make contact and then walk away without saying anything)",
            "q64_tense_socialsituations" => "64. Is too tense in social settings",
            "q65_staring_gazing"         => "65. Stares or gazes off into space"
        )
    );

    var $scoreCols = array("srs_score", "awareness_score", "cognition_score", "communication_score", "motivation_score", "rrb_score");

    // Question numbers where not true = 0 and always true = 3
    // in the scoring algorithm
    var $ForwardCoded = array(1, 2, 4, 5, 6, 8, 9, 10, 13, 14,
        16, 18, 19, 20, 23, 24, 25, 27, 28, 29, 30, 31, 33,
        34, 35, 36, 37, 39, 41, 42, 44, 46, 47, 49, 50, 51,
        53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65);
    // Question numbers where not true = 3 and always true = 0
    // in the scoring algorithm
    var $ReverseCoded = array(3, 7, 11, 12, 15, 17, 21, 22, 26,
        32, 38, 40, 43, 45, 48, 52, 55);

    var $subscales = array(
        'awareness_score' => array(2, 7, 25, 32, 45, 52, 54, 56),
        'cognition_score' => array(5, 10, 15, 17, 30, 40, 42, 44, 48, 58, 59, 62),
        'communication_score' => array(12, 13, 16, 18, 19, 21, 22, 26, 33, 35, 36, 37, 38, 41, 46, 47, 51, 53, 55, 57, 60, 61),
        'motivation_score' => array(1, 3, 6, 9, 11, 23, 27, 34, 43, 64, 65),
        'rrb_score' => array(4, 8, 14, 20, 24, 28, 29, 31, 39, 49, 50, 63)
    );


    /**
     * sets up basic data, such as the HTML_Quickform object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        #$this->form = new HTML_Quickform('test_form');
        $this->form = new LorisForm('test_form');

        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "SRS2_SchoolAge";           // test_names.Test_name
        $this->table = 'SRS2_SchoolAge';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // Get the subject age in months for scoring

        $db =& Database::singleton();
        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner', "Date_taken", 'q1_uncomfortable_socialsituations',
            "q17_recognize_unfair",
            "q43_separates_easily"
        );

        //MODIFY THIS WHEN THE SCORING IS IMPLEMENTED

        $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age',
            'Data_entry_completion_status',
            'srs_score', 'sci_score',
            "awareness_score",
            "cognition_score",
            "communication_score",
            "motivation_score",
            "rrb_score"

        );

        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/SRS2_SchoolAge_page([0-9]+)/", $this->page, $matches)) {
            #$this->_page($matches[1]);
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function _addDropdown($question_name, $question)
    {
        $this->form->addElement("select", "$question_name", $question,
            array('' => '',
                '1_not_true' => "Not True",
                '2_sometimes_true' => "Sometimes True",
                '3_often_true' => "Often True",
                '4_almost_always_true' => "Almost Always True",
                'not_answered' => "Not Answered"
            )
        );

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
        $this->form->addElement('header', 'instrument_title', "Social Responsiveness Scale (SRS2 School Age)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement("select", "completed_by", "This form filled out by",
            array('' => '', 'mother' => "Mother", 'father' => "Father", 'other' => "Other", 'not_answered' => "Not Answered")
        );
        $this->addTextElement("completed_by_other", "Specify (if other):",
            array("completed_by{@}=={@}other"), "Required if filled out by other"
        );


        $this->form->addElement("static", "srs_score", "SRS Total Score:");
        $this->form->addElement("static", "sci_score", "SCI Raw Score:");
        $this->form->addElement("static", "awareness_score", "Social Awareness Score:");
        $this->form->addElement("static", "cognition_score", "Social Cognition Score:");
        $this->form->addElement("static", "communication_score", "Social Communication Score:");
        $this->form->addElement("static", "motivation_score", "Social Motivation Score:");
        $this->form->addElement("static", "rrb_score", "RRB Score:");

        /*   function _page($pageNum) { */
        //$this->form->addElement('header', 'instrument_title', "Social Responsiveness Scale Page (SRS2_SchoolAge) - Page $pageNum");
        //$this->form->addElement('header', 'instrument_title', "Social Responsiveness Scale Page (SRS2_SchoolAge)");
        $this->form->addElement('static', '', '<br />');
        $this->form->addElement('static', '', '<br />');
	
	//Add field for Grade
        $field = 'child_grade';$label = "Child's grade in school <br><h5><i>(Please enter a numeric value between 1-12, K, or write NA if you don't know.)</i></h5>";
        $group[] = $this->createText($field, $label);
        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);

        $qNum = 1;
        $page_questions = array_merge($this->questions[1], $this->questions[2]);

        foreach ($page_questions as $field => $question) {
            $this->_addDropdown($field, $question);
            $qNum++;
        }
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        $this->_nullScores($this->scoreCols);
        $db =& Database::singleton();
        $Answers = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));

        if ($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $dob = $timepoint->getEffectiveDateOfBirth();
        }

        if (!empty($dob) && !empty($Answers['Date_taken'])) {
            $age = Utility::calculateAge($dob, $Answers["Date_taken"]);
            if(is_array($age)) {
                $age_months = $age['year'] * 12 + $age['mon'];
            } else {
                $scores['srs_score'] = "Error calculating age. Must specify date of administration.";
                $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
                return;
            }
        }

        if ($age_months < 48) {
            $scores['srs_score'] = "Child too young to score.";
            $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
            return;
        } else if ($age_months > 216) {
            $scores['srs_score'] = "Participant too old to score.";
            $db->update($this->table, $scores, array('CommentID' => $this->getCommentID()));
            return;
        }

        $scores = array();

        // add an arbitrary 0 index, so that index n maps to question n
        $fields_array = array(0 => "no question zero");
        foreach ($this->questions as $page => $questions) {
            $fields_array = array_merge($fields_array, array_keys($questions));
        }

        $score = 0;
        $not_answered = 0;

        $currentSubscale = null;
        $totals = array();

        foreach($this->ForwardCoded as $QuestionNumber) {

            foreach($this->subscales as $subscale => $questions) {
                if(in_array($QuestionNumber, $questions)) {
                    $currentSubscale = $subscale;
                }
                if ($currentSubscale != null) {
                    break;
                }
            }

            switch($Answers[$fields_array[$QuestionNumber]]) {
                case '1_not_true':
                    $score += 0;
                    $totals[$currentSubscale] += 0;
                    break;
                case '2_sometimes_true':
                    $score += 1;
                    $totals[$currentSubscale] += 1;
                    break;
                case '3_often_true':
                    $score += 2;
                    $totals[$currentSubscale] += 2;
                    break;
                case '4_almost_always_true':
                    $score += 3;
                    $totals[$currentSubscale] += 3;
                    break;
                case 'not_answered':
                    $not_answered += 1;
                    $scores[$currentSubscale] = 0;
                    break;
            }

            $currentSubscale = null;
        }

        foreach($this->ReverseCoded as $QuestionNumber) {

            foreach($this->subscales as $subscale => $questions) {
                if(in_array($QuestionNumber, $questions)) {
                    $currentSubscale = $subscale;
                }
                if ($currentSubscale != null) {
                    break;
                }
            }

            switch($Answers[$fields_array[$QuestionNumber]]) {
                case '1_not_true':
                    $score += 3;
                    $totals[$currentSubscale] += 3;
                    break;
                case '2_sometimes_true':
                    $score += 2;
                    $totals[$currentSubscale] += 2;
                    break;
                case '3_often_true':
                    $score += 1;
                    $totals[$currentSubscale] += 1;
                    break;
                case '4_almost_always_true':
                    $score += 0;
                    $totals[$currentSubscale] += 0;
                    break;
                case 'not_answered':
                    $not_answered += 1;
                    $scores[$currentSubscale] = 0;
                    break;
            }

            $currentSubscale = null;
        }
        $scores['srs_score'] = $score;

        if($not_answered > 7) {
            $scores['srs_score'] = "More than 7 questions not answered. Score is invalid.";
        }

        foreach($this->scoreCols as $scoreCol) {
            if ($scoreCol != 'srs_score') {
                if ($scores[$scoreCol] === 0 || $totals[$scoreCol] == null) {
                    $scores[$scoreCol] = "Not all questions in the subscale were answered. Score is invalid.";
                } else {
                    $scores[$scoreCol] = $totals[$scoreCol];
                }
            }
        }
	$scores['sci_score'] = $scores['awareness_score'] + $scores['cognition_score'] + $scores['communication_score'] + $scores['motivation_score'];  

        // save the resultant total
        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }
}

?>
