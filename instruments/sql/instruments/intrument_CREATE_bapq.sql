CREATE TABLE `bapq` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `bapq_1` enum("","1","2","3","4","5","6"),
    `bapq_2` enum("","1","2","3","4","5","6"),
    `bapq_3` enum("","1","2","3","4","5","6"),
    `bapq_4` enum("","1","2","3","4","5","6"),
    `bapq_5` enum("","1","2","3","4","5","6"),
    `bapq_6` enum("","1","2","3","4","5","6"),
    `bapq_7` enum("","1","2","3","4","5","6"),
    `bapq_8` enum("","1","2","3","4","5","6"),
    `bapq_9` enum("","1","2","3","4","5","6"),
    `bapq_10` enum("","1","2","3","4","5","6"),
    `bapq_11` enum("","1","2","3","4","5","6"),
    `bapq_12` enum("","1","2","3","4","5","6"),
    `bapq_13` enum("","1","2","3","4","5","6"),
    `bapq_14` enum("","1","2","3","4","5","6"),
    `bapq_15` enum("","1","2","3","4","5","6"),
    `bapq_16` enum("","1","2","3","4","5","6"),
    `bapq_17` enum("","1","2","3","4","5","6"),
    `bapq_18` enum("","1","2","3","4","5","6"),
    `bapq_19` enum("","1","2","3","4","5","6"),
    `bapq_20` enum("","1","2","3","4","5","6"),
    `bapq_21` enum("","1","2","3","4","5","6"),
    `bapq_22` enum("","1","2","3","4","5","6"),
    `bapq_23` enum("","1","2","3","4","5","6"),
    `bapq_24` enum("","1","2","3","4","5","6"),
    `bapq_25` enum("","1","2","3","4","5","6"),
    `bapq_26` enum("","1","2","3","4","5","6"),
    `bapq_27` enum("","1","2","3","4","5","6"),
    `bapq_28` enum("","1","2","3","4","5","6"),
    `bapq_29` enum("","1","2","3","4","5","6"),
    `bapq_30` enum("","1","2","3","4","5","6"),
    `bapq_31` enum("","1","2","3","4","5","6"),
    `bapq_32` enum("","1","2","3","4","5","6"),
    `bapq_33` enum("","1","2","3","4","5","6"),
    `bapq_34` enum("","1","2","3","4","5","6"),
    `bapq_35` enum("","1","2","3","4","5","6"),
    `bapq_36` enum("","1","2","3","4","5","6"),
    `bapq_aloof` int,
    `bapq_prag_lang` int,
    `bapq_rigid` int,
    `bapq_total` int,
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8