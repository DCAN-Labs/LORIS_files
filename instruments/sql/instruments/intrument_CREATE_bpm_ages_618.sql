CREATE TABLE `bpm_ages_618` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `bpmt_q1` enum("","0","1","2"),
    `bpmt_q2` enum("","0","1","2"),
    `bpmt_q3` enum("","0","1","2"),
    `bpmt_q4` enum("","0","1","2"),
    `bpmt_q5` enum("","0","1","2"),
    `bpmt_q6` enum("","0","1","2"),
    `bpmt_q7` enum("","0","1","2"),
    `bpmt_q8` enum("","0","1","2"),
    `bpmt_q9` enum("","0","1","2"),
    `bpmt_q10` enum("","0","1","2"),
    `bpmt_q11` enum("","0","1","2"),
    `bpmt_q12` enum("","0","1","2"),
    `bpmt_q13` enum("","0","1","2"),
    `bpmt_q14` enum("","0","1","2"),
    `bpmt_q15` enum("","0","1","2"),
    `bpmt_q16` enum("","0","1","2"),
    `bpmt_q17` enum("","0","1","2"),
    `bpmt_q18` enum("","0","1","2"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8