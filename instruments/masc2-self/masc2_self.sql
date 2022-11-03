CREATE TABLE `masc2_self` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `UserID` varchar(255) DEFAULT NULL,
  `Examiner` varchar(255) DEFAULT NULL,
  `Testdate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL DEFAULT 'Incomplete',
  `Date_taken` date DEFAULT NULL,
  `Candidate_Age` varchar(255) DEFAULT NULL,
  `Window_Difference` int(11) DEFAULT NULL,
  `masc2_q01` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q02` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q03` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q04` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q05` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q06` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q07` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q08` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q09` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q10` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q11` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q12` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q13` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q14` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q15` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q16` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q17` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q18` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q19` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q20` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q21` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q22` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q23` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q24` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q25` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q26` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q27` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q28` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q29` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q30` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q31` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q32` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q33` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q34` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q35` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q36` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q37` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q38` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q39` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q40` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q41` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q42` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q43` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q44` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q45` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q46` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q47` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q48` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q49` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_q50` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_total` smallint DEFAULT NULL,
  `masc2_total_t` tinyint DEFAULT NULL,
  `masc2_anx_prob_score` enum('0', '1', '2', '3', 'not_answered') DEFAULT NULL,
  `masc2_inconsistency_index` tinyint DEFAULT NULL,
  `masc2_sp` tinyint DEFAULT NULL,
  `masc2_sp_t` tinyint DEFAULT NULL,
  `masc2_gad` tinyint DEFAULT NULL,
  `masc2_gad_t` tinyint DEFAULT NULL,
  `masc2_sa` tinyint DEFAULT NULL,
  `masc2_sa_t` tinyint DEFAULT NULL,
  `masc2_hr` tinyint DEFAULT NULL,
  `masc2_hr_t` tinyint DEFAULT NULL,
  `masc2_pf` tinyint DEFAULT NULL,
  `masc2_pf_t` tinyint DEFAULT NULL,
  `masc2_oc` tinyint DEFAULT NULL,
  `masc2_oc_t` tinyint DEFAULT NULL,
  `masc2_ps` tinyint DEFAULT NULL,
  `masc2_ps_t` tinyint DEFAULT NULL,
  `masc2_p` tinyint DEFAULT NULL,
  `masc2_p_t` tinyint DEFAULT NULL,
  `masc2_tr` tinyint DEFAULT NULL,
  `masc2_tr_t` tinyint DEFAULT NULL,
  `masc2_ha` tinyint DEFAULT NULL,
  `masc2_ha_t` tinyint DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8