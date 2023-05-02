CREATE TABLE `pss` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `perceived_stress_scale_1` enum("","0","1","2","3","4"),
    `perceived_stress_scale_2` enum("","0","1","2","3","4"),
    `perceived_stress_scale_3` enum("","0","1","2","3","4"),
    `perceived_stress_scale_4` enum("","0","1","2","3","4"),
    `perceived_stress_scale_5` enum("","0","1","2","3","4"),
    `perceived_stress_scale_6` enum("","0","1","2","3","4"),
    `perceived_stress_scale_7` enum("","0","1","2","3","4"),
    `perceived_stress_scale_8` enum("","0","1","2","3","4"),
    `perceived_stress_scale_9` enum("","0","1","2","3","4"),
    `perceived_stress_scale_10` enum("","0","1","2","3","4"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8