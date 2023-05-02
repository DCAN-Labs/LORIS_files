CREATE TABLE `family_medical_history_questionnaire` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `child_full_sibp` enum("","0","1","2","3","4","5","6","7","8","9","999"),
    `child_half_sib` enum("","0","1","2","3","4","5","6","7","8","9","999"),
    `bio_mom_full_sib` enum("","0","1","2","3","4","5","6","7","8","9","999"),
    `bio_fath_full_sib` enum("","0","1","2","3","4","5","6","7","8","9","999"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8