CREATE TABLE `teacher_survey_cover_page` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `gift_card` enum("","1","2"),
    `distance_learn` varchar(255),
    `inperson_learn` varchar(255),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8