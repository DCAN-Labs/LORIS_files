CREATE TABLE `masc_2_child` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `masc_1` enum("","0","1","2","3"),
    `masc_2` enum("","0","1","2","3"),
    `masc_3` enum("","0","1","2","3"),
    `masc_4` enum("","0","1","2","3"),
    `masc_5` enum("","0","1","2","3"),
    `masc_6` enum("","0","1","2","3"),
    `masc_7` enum("","0","1","2","3"),
    `masc_8` enum("","0","1","2","3"),
    `masc_9` enum("","0","1","2","3"),
    `masc_10` enum("","0","1","2","3"),
    `masc_11` enum("","0","1","2","3"),
    `masc_12` enum("","0","1","2","3"),
    `masc_13` enum("","0","1","2","3"),
    `masc_14` enum("","0","1","2","3"),
    `masc_15` enum("","0","1","2","3"),
    `masc_16` enum("","0","1","2","3"),
    `masc_17` enum("","0","1","2","3"),
    `masc_18` enum("","0","1","2","3"),
    `masc_19` enum("","0","1","2","3"),
    `masc_20` enum("","0","1","2","3"),
    `masc_21` enum("","0","1","2","3"),
    `masc_22` enum("","0","1","2","3"),
    `masc_23` enum("","0","1","2","3"),
    `masc_24` enum("","0","1","2","3"),
    `masc_25` enum("","0","1","2","3"),
    `masc_26` enum("","0","1","2","3"),
    `masc_27` enum("","0","1","2","3"),
    `masc_28` enum("","0","1","2","3"),
    `masc_29` enum("","0","1","2","3"),
    `masc_30` enum("","0","1","2","3"),
    `masc_31` enum("","0","1","2","3"),
    `masc_32` enum("","0","1","2","3"),
    `masc_33` enum("","0","1","2","3"),
    `masc_34` enum("","0","1","2","3"),
    `masc_35` enum("","0","1","2","3"),
    `masc_36` enum("","0","1","2","3"),
    `masc_37` enum("","0","1","2","3"),
    `masc_38` enum("","0","1","2","3"),
    `masc_39` enum("","0","1","2","3"),
    `masc_40` enum("","0","1","2","3"),
    `masc_41` enum("","0","1","2","3"),
    `masc_42` enum("","0","1","2","3"),
    `masc_43` enum("","0","1","2","3"),
    `masc_44` enum("","0","1","2","3"),
    `masc_45` enum("","0","1","2","3"),
    `masc_46` enum("","0","1","2","3"),
    `masc_47` enum("","0","1","2","3"),
    `masc_48` enum("","0","1","2","3"),
    `masc_49` enum("","0","1","2","3"),
    `masc_50` enum("","0","1","2","3"),
    `masc_total` smallint DEFAULT NULL,
    `masc_total_t` tinyint DEFAULT NULL,
    `masc_anx_prob_score` enum('0','1','2','3','not_answered') DEFAULT NULL,
    `masc_inconsistency_index` tinyint DEFAULT NULL,
    `masc_sp` tinyint DEFAULT NULL,
    `masc_sp_t` tinyint DEFAULT NULL,
    `masc_gad` tinyint DEFAULT NULL,
    `masc_gad_t` tinyint DEFAULT NULL,
    `masc_sa` tinyint DEFAULT NULL,
    `masc_sa_t` tinyint DEFAULT NULL,
    `masc_hr` tinyint DEFAULT NULL,
    `masc_hr_t` tinyint DEFAULT NULL,
    `masc_pf` tinyint DEFAULT NULL,
    `masc_pf_t` tinyint DEFAULT NULL,
    `masc_oc` tinyint DEFAULT NULL,
    `masc_oc_t` tinyint DEFAULT NULL,
    `masc_ps` tinyint DEFAULT NULL,
    `masc_ps_t` tinyint DEFAULT NULL,
    `masc_p` tinyint DEFAULT NULL,
    `masc_p_t` tinyint DEFAULT NULL,
    `masc_tr` tinyint DEFAULT NULL,
    `masc_tr_t` tinyint DEFAULT NULL,
    `masc_ha` tinyint DEFAULT NULL,
    `masc_ha_t` tinyint DEFAULT NULL,
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8