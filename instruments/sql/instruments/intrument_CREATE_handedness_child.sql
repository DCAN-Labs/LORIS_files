CREATE TABLE `handedness_child` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `ehi1b` enum("","100","50","0","-50","-100"),
    `ehi2b` enum("","100","50","0","-50","-100"),
    `ehi3b` enum("","100","50","0","-50","-100"),
    `ehi4b` enum("","100","50","0","-50","-100"),
    `ehi_y_ss_scoreb` int,
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8