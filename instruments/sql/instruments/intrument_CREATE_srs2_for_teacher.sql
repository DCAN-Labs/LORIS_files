CREATE TABLE `srs2_for_teacher` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `srs_teacher_1` enum("","1","2","3","4"),
    `srs_teacher_2` enum("","1","2","3","4"),
    `srs_teacher_3` enum("","1","2","3","4"),
    `srs_teacher_4` enum("","1","2","3","4"),
    `srs_teacher_5` enum("","1","2","3","4"),
    `srs_teacher_6` enum("","1","2","3","4"),
    `srs_teacher_7` enum("","1","2","3","4"),
    `srs_teacher_8` enum("","1","2","3","4"),
    `srs_teacher_9` enum("","1","2","3","4"),
    `srs_teacher_10` enum("","1","2","3","4"),
    `srs_teacher_11` enum("","1","2","3","4"),
    `srs_teacher_12` enum("","1","2","3","4"),
    `srs_teacher_13` enum("","1","2","3","4"),
    `srs_teacher_14` enum("","1","2","3","4"),
    `srs_teacher_15` enum("","1","2","3","4"),
    `srs_teacher_16` enum("","1","2","3","4"),
    `srs_teacher_17` enum("","1","2","3","4"),
    `srs_teacher_18` enum("","1","2","3","4"),
    `srs_teacher_19` enum("","1","2","3","4"),
    `srs_teacher_20` enum("","1","2","3","4"),
    `srs_teacher_21` enum("","1","2","3","4"),
    `srs_teacher_22` enum("","1","2","3","4"),
    `srs_teacher_23` enum("","1","2","3","4"),
    `srs_teacher_24` enum("","1","2","3","4"),
    `srs_teacher_25` enum("","1","2","3","4"),
    `srs_teacher_26` enum("","1","2","3","4"),
    `srs_teacher_27` enum("","1","2","3","4"),
    `srs_teacher_28` enum("","1","2","3","4"),
    `srs_teacher_29` enum("","1","2","3","4"),
    `srs_teacher_30` enum("","1","2","3","4"),
    `srs_teacher_31` enum("","1","2","3","4"),
    `srs_teacher_32` enum("","1","2","3","4"),
    `srs_teacher_33` enum("","1","2","3","4"),
    `srs_teacher_34` enum("","1","2","3","4"),
    `srs_teacher_35` enum("","1","2","3","4"),
    `srs_teacher_36` enum("","1","2","3","4"),
    `srs_teacher_37` enum("","1","2","3","4"),
    `srs_teacher_38` enum("","1","2","3","4"),
    `srs_teacher_39` enum("","1","2","3","4"),
    `srs_teacher_40` enum("","1","2","3","4"),
    `srs_teacher_41` enum("","1","2","3","4"),
    `srs_teacher_42` enum("","1","2","3","4"),
    `srs_teacher_43` enum("","1","2","3","4"),
    `srs_teacher_44` enum("","1","2","3","4"),
    `srs_teacher_45` enum("","1","2","3","4"),
    `srs_teacher_46` enum("","1","2","3","4"),
    `srs_teacher_47` enum("","1","2","3","4"),
    `srs_teacher_48` enum("","1","2","3","4"),
    `srs_teacher_49` enum("","1","2","3","4"),
    `srs_teacher_50` enum("","1","2","3","4"),
    `srs_teacher_51` enum("","1","2","3","4"),
    `srs_teacher_52` enum("","1","2","3","4"),
    `srs_teacher_53` enum("","1","2","3","4"),
    `srs_teacher_54` enum("","1","2","3","4"),
    `srs_teacher_55` enum("","1","2","3","4"),
    `srs_teacher_56` enum("","1","2","3","4"),
    `srs_teacher_57` enum("","1","2","3","4"),
    `srs_teacher_58` enum("","1","2","3","4"),
    `srs_teacher_59` enum("","1","2","3","4"),
    `srs_teacher_60` enum("","1","2","3","4"),
    `srs_teacher_61` enum("","1","2","3","4"),
    `srs_teacher_62` enum("","1","2","3","4"),
    `srs_teacher_63` enum("","1","2","3","4"),
    `srs_teacher_64` enum("","1","2","3","4"),
    `srs_teacher_65` enum("","1","2","3","4"),
    `srs_teacher_awr` tinyint unsigned DEFAULT NULL,
    `srs_teacher_cog` tinyint unsigned DEFAULT NULL,
    `srs_teacher_com` tinyint unsigned DEFAULT NULL,
    `srs_teacher_mot` tinyint unsigned DEFAULT NULL,
    `srs_teacher_rrb` tinyint unsigned DEFAULT NULL,
    `srs_teacher_awr_t` tinyint unsigned DEFAULT NULL,
    `srs_teacher_cog_t` tinyint unsigned DEFAULT NULL,
    `srs_teacher_com_t` tinyint unsigned DEFAULT NULL,
    `srs_teacher_mot_t` tinyint unsigned DEFAULT NULL,
    `srs_teacher_rrb_t` tinyint unsigned DEFAULT NULL,
    `srs_teacher_sci` tinyint unsigned DEFAULT NULL,
    `srs_teacher_sci_t` tinyint unsigned DEFAULT NULL,
    `srs_teacher_total` tinyint unsigned DEFAULT NULL,
    `srs_teacher_total_t` tinyint unsigned DEFAULT NULL,
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8