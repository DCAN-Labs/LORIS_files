CREATE TABLE `cdi_2_child` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `cdi_1` enum("","1","2","3"),
    `cdi_2` enum("","1","2","3"),
    `cdi_3` enum("","1","2","3"),
    `cdi_4` enum("","1","2","3"),
    `cdi_5` enum("","1","2","3"),
    `cdi_6` enum("","1","2","3"),
    `cdi_7` enum("","1","2","3"),
    `cdi_8` enum("","1","2","3"),
    `cdi_9` enum("","1","2","3"),
    `cdi_10` enum("","1","2","3"),
    `cdi_11` enum("","1","2","3"),
    `cdi_12` enum("","1","2","3"),
    `cdi_total` tinyint DEFAULT NULL,
    `cdi_t` tinyint DEFAULT NULL,
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8