CREATE TABLE `cars_2` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `cars_2_test_date` date DEFAULT NULL,
  `cars_2_raters_name` varchar(255) DEFAULT NULL,
  `cars_2_partic_age_yr` varchar(255) DEFAULT NULL,
  `cars_2_socio_emo` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_emo_exp_reg` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_relat_ppl` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_bod_use` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_obj_use_play` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_adapt_change` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_vis_resp` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_2_listen_resp` enum('1','1.5','2','2.5','3','3.5','4','not_answered') DEFAULT NULL,
  `cars_total` decimal(3,1) DEFAULT NULL,
  `form_completed_by` varchar(255) DEFAULT NULL,
  `form_completed_cars2` date DEFAULT NULL,
  `UserID` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
