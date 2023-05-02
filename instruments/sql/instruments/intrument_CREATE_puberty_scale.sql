CREATE TABLE `puberty_scale` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `pdp_male` enum("","1","0"),
    `pdp_height` enum("","1","2","3","4","5"),
    `pdp_body_hair` enum("","1","2","3","4","5"),
    `pdp_skin` enum("","1","2","3","4","5"),
    `pdp_facial_hair` enum("","1","2","3","4","5"),
    `pdp_voice` enum("","1","2","3","4","5"),
    `pdp_breasts` enum("","1","2","3","4","5"),
    `pdp_menstruate` enum("","1","0","5"),
    `pdp_menstruate_age` int,
    `pdp_menstruate_age_dk` enum("","5"),
    `pdp_days_between` int,
    `pdp_days_between_dk` enum("","5"),
    `pdp_cycle_reg` enum("","1","0","5"),
    `pdp_horm_birth_control` enum("","1","0","5"),
    `pdp_premen` enum("","0","1","2","3","5"),
    `pdp_premen_interfere` enum("","0","1","2","3","5"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8