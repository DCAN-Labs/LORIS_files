CREATE TABLE `adhd_rs_home` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `adhd_rs_home_q1` enum("","0","1","2","3"),
    `adhd_rs_home_q2` enum("","0","1","2","3"),
    `adhd_rs_home_q3` enum("","0","1","2","3"),
    `adhd_rs_home_q4` enum("","0","1","2","3"),
    `adhd_rs_home_q5` enum("","0","1","2","3"),
    `adhd_rs_home_q6` enum("","0","1","2","3"),
    `adhd_rs_home_q7` enum("","0","1","2","3"),
    `adhd_rs_home_q8` enum("","0","1","2","3"),
    `adhd_rs_home_q9` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_1` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_2` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_3` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_4` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_5` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_6` enum("","0","1","2","3"),
    `adhd_rs_home_q10` enum("","0","1","2","3"),
    `adhd_rs_home_q11` enum("","0","1","2","3"),
    `adhd_rs_home_q12` enum("","0","1","2","3"),
    `adhd_rs_home_q13` enum("","0","1","2","3"),
    `adhd_rs_home_q14` enum("","0","1","2","3"),
    `adhd_rs_home_q15` enum("","0","1","2","3"),
    `adhd_rs_home_q16` enum("","0","1","2","3"),
    `adhd_rs_home_q17` enum("","0","1","2","3"),
    `adhd_rs_home_q18` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_7` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_8` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_9` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_10` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_11` enum("","0","1","2","3"),
    `adhd_rs_home_problem_severity_12` enum("","0","1","2","3"),
    `adhd_rs_home_hyperactivity_total` tinyint DEFAULT NULL,
    `adhd_rs_home_hyperactivity_symptoms` tinyint DEFAULT NULL,
    `adhd_rs_home_hyperactivity_t` tinyint DEFAULT NULL,
    `adhd_rs_home_inattention_total` tinyint DEFAULT NULL,
    `adhd_rs_home_inattention_symptoms` tinyint DEFAULT NULL,
    `adhd_rs_home_inattention_t` tinyint DEFAULT NULL,
    `adhd_rs_home_total` tinyint DEFAULT NULL,
    `adhd_rs_home_total_t` tinyint DEFAULT NULL,
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8