CREATE TABLE `puberty_scale_child` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `pdy_male` enum("","1","0"),
    `pdy_height` enum("","1","2","3","4","5","6"),
    `pdy_skin` enum("","1","2","3","4","5","6"),
    `pdy_body_hair` enum("","1","2","3","4","5","6"),
    `pdy_breasts` enum("","1","2","3","4","5","6"),
    `pdy_menstruate` enum("","1","0","5","6"),
    `pdy_menstruate_age` int,
    `pdy_menstruate_age_dk` enum("","5","6"),
    `pdy_voice` enum("","1","2","3","4","5","6"),
    `pdy_facial_hair` enum("","1","2","3","4","5","6"),
    `pdy_days_between` int,
    `pdy_days_between_dk` enum("","5","6"),
    `pdy_cycle_reg` enum("","1","0","5","6"),
    `pdy_cycle_length` enum("","1","2","3"),
    `pdy_cycle_flow` enum("","1","2","3"),
    `pdy_horm_birth_control` enum("","1","0","5","6"),
    `pdy_form_birth_control` enum("","1","2","3","4","5","6","7"),
    `pdy_birth_control_pill` enum("","1","0","5","6"),
    `pdy_premen` enum("","0","1","2","3","5","6"),
    `pdy_premen_interfere` enum("","0","1","2","3","5","6"),
    `pdy_men_pain_int` enum("","0","1","2","3","4","5","6","7","8","9","10"),
    `pdy_men_pain_length` enum("","0","1","2","3","4"),
    `pdy_men_pain_act` enum("","0","1","2","3","4","5","6","7","8","9","10"),
    `pdy_admin` varchar(255),
    `pdy_device` varchar(255),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8