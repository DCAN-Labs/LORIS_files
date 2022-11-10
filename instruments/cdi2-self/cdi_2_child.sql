CREATE TABLE `cdi_2_child` (
  `CommentID` varchar(255) NOT NULL DEFAULT '',
  `cdi_d_instructions` varchar(255) DEFAULT NULL,
  `cdi_1` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_2` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_3` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_4` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_5` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_6` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_7` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_8` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_9` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_10` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_11` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_12` enum('1','2','3','not_answered') DEFAULT NULL,
  `cdi_total` tinyint DEFAULT NULL,
  `cdi_t` tinyint DEFAULT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
