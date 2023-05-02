CREATE TABLE `scapi` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `scapi_any_stimulant` enum("","0","1"),
    `scapi_stim_current_1` varchar(255),
    `scapi_stim_current_2` varchar(255),
    `scapi_stim_current_3` varchar(255),
    `scapi_stim_current_4` varchar(255),
    `scapi_curr_prescribed` enum("","0","1"),
    `scapi_adderall` varchar(255),
    `scapi_adderall_dose` enum("","5","7.5","10","12.5","15","20","30"),
    `scapi_adderall_freq` enum("","1","2","3","99"),
    `scapi_adderallxr` varchar(255),
    `scapi_adderallxr_dose` enum("","10","20","30"),
    `scapi_adderallxr_freq` enum("","1","2","3","99"),
    `scapi_concerta` varchar(255),
    `scapi_concerta_dose` enum("","18","27","36","54"),
    `scapi_concerta_freq` enum("","1","2","3","99"),
    `scapi_cylert` varchar(255),
    `scapi_cylert_dose` enum("","18.75","37.5","75"),
    `scapi_cylert_freq` enum("","1","2","3","99"),
    `scapi_daytrana` varchar(255),
    `scapi_daytrana_dose` enum("","10","15","20","30"),
    `scapi_daytrana_freq` enum("","1","2","3","99"),
    `scapi_desoxyn` varchar(255),
    `scapi_desoxyn_dose` enum("","5"),
    `scapi_desoxyn_freq` enum("","1","2","3","99"),
    `scapi_dexe_tab` varchar(255),
    `scapi_dexe_tab_dose` enum("","5"),
    `scapi_dexe_tab_freq` enum("","1","2","3","99"),
    `scapi_dexe_cap` varchar(255),
    `scapi_dexe_cap_dose` enum("","5","10","15"),
    `scapi_dexe_cap_freq` enum("","1","2","3","99"),
    `scapi_dextrostat` varchar(255),
    `scapi_dextrostat_dose` enum("","5","10"),
    `scapi_dextrostat_freq` enum("","1","2","3","99"),
    `scapi_focalin` varchar(255),
    `scapi_focalin_dose` enum("","2.5","5","10"),
    `scapi_focalin_freq` enum("","1","2","3","99"),
    `scapi_metadatecd` varchar(255),
    `scapi_metadatecd_dose` enum("","20"),
    `scapi_metadatecd_freq` enum("","1","2","3","99"),
    `scapi_metadateer` varchar(255),
    `scapi_metadateer_dose` enum("","10","20"),
    `scapi_metadateer_freq` enum("","1","2","3","99"),
    `scapi_methyliner` varchar(255),
    `scapi_methyliner_dose` enum("","10","20"),
    `scapi_methyliner_freq` enum("","1","2","3","99"),
    `scapi_methylin` varchar(255),
    `scapi_methylin_dose` enum("","5","10","20"),
    `scapi_methylin_freq` enum("","1","2","3","99"),
    `scapi_ritalinhcl` varchar(255),
    `scapi_ritalinhcl_dose` enum("","5","10","20"),
    `scapi_ritalinhcl_freq` enum("","1","2","3","99"),
    `scapi_ritalinla` varchar(255),
    `scapi_ritalinla_dose` enum("","5","10","20","30","40"),
    `scapi_ritalinla_freq` enum("","1","2","3","99"),
    `scapi_vyvanse` varchar(255),
    `scapi_vyvanse_dose` enum("","30","50","70"),
    `scapi_vyvanse_freq` enum("","1","2","3","99"),
    `scapi_oth_stim` varchar(255),
    `scapi_oth_stim_freq` enum("","1","2","3","99"),
    `scapi_quillivant` varchar(255),
    `scapi_quillivant_dose` enum("","10","20","30","40","50","60"),
    `scapi_quillivant_freq` enum("","1","2","3","99"),
    `scapi_age_curr_dose` int,
    `scapi_reason_med` enum("","1","2","3","99"),
    `scapi_who_monitor` enum("","1","2","3","4","5","6","99"),
    `scapi_monitor_visits` enum("","0","1","2","3","4"),
    `scapi_monitor_minutes` enum("","1","2","3","4"),
    `scapi_seen_another` enum("","0","1"),
    `scapi_seen_who` enum("","1","2","3","4","5","6","99"),
    `scapi_stopped` enum("","0","1"),
    `scapi_any_non_stim` enum("","0","1"),
    `scapi_curr_non_stim` enum("","0","1"),
    `scapi_pm_001` varchar(255),
    `scapi_pm_002` varchar(255),
    `scapi_pm_003` varchar(255),
    `scapi_pm_004` varchar(255),
    `scapi_pm_005` varchar(255),
    `scapi_pm_006` varchar(255),
    `scapi_pm_007` varchar(255),
    `scapi_pm_008` varchar(255),
    `scapi_pm_009` varchar(255),
    `scapi_pm_010` varchar(255),
    `scapi_pm_011` varchar(255),
    `scapi_pm_012` varchar(255),
    `scapi_pm_013` varchar(255),
    `scapi_pm_014` varchar(255),
    `scapi_pm_015` varchar(255),
    `scapi_pm_016` varchar(255),
    `scapi_pm_017` varchar(255),
    `scapi_pm_018` varchar(255),
    `scapi_pm_019` varchar(255),
    `scapi_pm_020` varchar(255),
    `scapi_pm_021` varchar(255),
    `scapi_pm_022` varchar(255),
    `scapi_pm_023` varchar(255),
    `scapi_pm_024` varchar(255),
    `scapi_pm_025` varchar(255),
    `scapi_pm_026` varchar(255),
    `scapi_pm_027` varchar(255),
    `scapi_pm_028` varchar(255),
    `scapi_pm_029` varchar(255),
    `scapi_pm_030` varchar(255),
    `scapi_pm_031` varchar(255),
    `scapi_pm_032` varchar(255),
    `scapi_pm_033` varchar(255),
    `scapi_pm_034` varchar(255),
    `scapi_pm_035` varchar(255),
    `scapi_pm_036` varchar(255),
    `scapi_pm_037` varchar(255),
    `scapi_pm_038` varchar(255),
    `scapi_pm_039` varchar(255),
    `scapi_pm_040` varchar(255),
    `scapi_pm_041` varchar(255),
    `scapi_pm_042` varchar(255),
    `scapi_pm_043` varchar(255),
    `scapi_pm_044` varchar(255),
    `scapi_pm_045` varchar(255),
    `scapi_pm_046` varchar(255),
    `scapi_pm_047` varchar(255),
    `scapi_pm_048` varchar(255),
    `scapi_pm_049` varchar(255),
    `scapi_pm_050` varchar(255),
    `scapi_pm_051` varchar(255),
    `scapi_pm_052` varchar(255),
    `scapi_pm_053` varchar(255),
    `scapi_pm_054` varchar(255),
    `scapi_pm_055` varchar(255),
    `scapi_pm_056` varchar(255),
    `scapi_pm_057` varchar(255),
    `scapi_pm_058` varchar(255),
    `scapi_pm_059` varchar(255),
    `scapi_pm_060` varchar(255),
    `scapi_pm_061` varchar(255),
    `scapi_pm_062` varchar(255),
    `scapi_pm_063` varchar(255),
    `scapi_pm_064` varchar(255),
    `scapi_pm_065` varchar(255),
    `scapi_pm_066` varchar(255),
    `scapi_pm_067` varchar(255),
    `scapi_pm_068` varchar(255),
    `scapi_pm_069` varchar(255),
    `scapi_pm_070` varchar(255),
    `scapi_pm_071` varchar(255),
    `scapi_pm_072` varchar(255),
    `scapi_pm_073` varchar(255),
    `scapi_pm_074` varchar(255),
    `scapi_pm_075` varchar(255),
    `scapi_pm_076` varchar(255),
    `scapi_pm_077` varchar(255),
    `scapi_pm_078` varchar(255),
    `scapi_pm_079` varchar(255),
    `scapi_pm_080` varchar(255),
    `scapi_pm_081` varchar(255),
    `scapi_pm_082` varchar(255),
    `scapi_pm_083` varchar(255),
    `scapi_pm_084` varchar(255),
    `scapi_pm_085` varchar(255),
    `scapi_pm_086` varchar(255),
    `scapi_pm_087` varchar(255),
    `scapi_pm_088` varchar(255),
    `scapi_pm_089` varchar(255),
    `scapi_pm_090` varchar(255),
    `scapi_pm_091` varchar(255),
    `scapi_pm_092` varchar(255),
    `scapi_pm_093` varchar(255),
    `scapi_pm_094` varchar(255),
    `scapi_pm_095` varchar(255),
    `scapi_pm_096` varchar(255),
    `scapi_pm_097` varchar(255),
    `scapi_pm_098` varchar(255),
    `scapi_pm_099` varchar(255),
    `scapi_pm_100` varchar(255),
    `scapi_pm_101` varchar(255),
    `scapi_pm_102` varchar(255),
    `scapi_pm_103` varchar(255),
    `scapi_pm_104` varchar(255),
    `scapi_pm_105` varchar(255),
    `scapi_pm4_or_more` enum("","1","0"),
    `scapi_cm4_or_more` enum("","1","0"),
    `scapi_sick_past_week` enum("","0","1"),
    `scapi_hospital_since` enum("","0","1"),
    `scapi_injury_since` enum("","0","1"),
    `scapi_slv_01` varchar(255),
    `scapi_slv_02` varchar(255),
    `scapi_slv_03` varchar(255),
    `scapi_slv_04` varchar(255),
    `scapi_slv_05` varchar(255),
    `scapi_slv_06` varchar(255),
    `scapi_slv_07` varchar(255),
    `scapi_slv_08` varchar(255),
    `scapi_slv_09` varchar(255),
    `scapi_slv_10` varchar(255),
    `scapi_slv_11` varchar(255),
    `scapi_slv_12` varchar(255),
    `scapi_slv_13` varchar(255),
    `scapi_slv_14` varchar(255),
    `scapi_slv_15` varchar(255),
    `scapi_slv_16` varchar(255),
    `scapi_slv_17` varchar(255),
    `scapi_slv_18` varchar(255),
    `scapi_slv_19` varchar(255),
    `scapi_slv_20` varchar(255),
    `scapi_slv_21` varchar(255),
    `scapi_slv_22` varchar(255),
    `scapi_slv_23` varchar(255),
    `scapi_slv_24` varchar(255),
    `scapi_slv_25` varchar(255),
    `scapi_slv_26` varchar(255),
    `scapi_slv_27` varchar(255),
    `scapi_slv_28` varchar(255),
    `scapi_slv_29` varchar(255),
    `scapi_slv_30` varchar(255),
    `scapi_slv_31` varchar(255),
    `scapi_slv_32` varchar(255),
    `scapi_slv_33` varchar(255),
    `scapi_slv_34` varchar(255),
    `scapi_slv_35` varchar(255),
    `scapi_slv_36` varchar(255),
    `scapi_slv_37` varchar(255),
    `scapi_slv_38` varchar(255),
    `scapi_slv_39` varchar(255),
    `scapi_slv_40` varchar(255),
    `scapi_cmht` enum("","0","1"),
    `scapi_cmht_types` varchar(255),
    `scapi_cmht_reason_1` enum("","1","2","3","99"),
    `scapi_cmht_who_1` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_1` enum("","1","2","3","4","5"),
    `scapi_cmht_len_1` enum("","1","2","3","4"),
    `scapi_cmht_reason_2` enum("","1","2","3","99"),
    `scapi_cmht_who_2` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_2` enum("","1","2","3","4","5"),
    `scapi_cmht_len_2` enum("","1","2","3","4"),
    `scapi_cmht_reason_3` enum("","1","2","3","99"),
    `scapi_cmht_who_3` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_3` enum("","1","2","3","4","5"),
    `scapi_cmht_len_3` enum("","1","2","3","4"),
    `scapi_cmht_reason_4` enum("","1","2","3","99"),
    `scapi_cmht_who_4` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_4` enum("","1","2","3","4","5"),
    `scapi_cmht_len_4` enum("","1","2","3","4"),
    `scapi_cmht_reason_5` enum("","1","2","3","99"),
    `scapi_cmht_who_5` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_start_date_5` date,
    `scapi_cmht_freq_5` enum("","1","2","3","4","5"),
    `scapi_cmht_len_5` enum("","1","2","3","4"),
    `scapi_cmht_reason_6` enum("","1","2","3","99"),
    `scapi_cmht_who_6` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_6` enum("","1","2","3","4","5"),
    `scapi_cmht_len_6` enum("","1","2","3","4"),
    `scapi_cmht_reason_7` enum("","1","2","3","99"),
    `scapi_cmht_who_7` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_7` enum("","1","2","3","4","5"),
    `scapi_cmht_len_7` enum("","1","2","3","4"),
    `scapi_cmht_reason_8` enum("","1","2","3","99"),
    `scapi_cmht_who_8` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_8` enum("","1","2","3","4","5"),
    `scapi_cmht_len_8` enum("","1","2","3","4"),
    `scapi_cmht_reason_99` enum("","1","2","3","99"),
    `scapi_cmht_who_99` enum("","1","2","3","4","5","6","99"),
    `scapi_cmht_freq_99` enum("","1","2","3","4","5"),
    `scapi_cmht_len_99` enum("","1","2","3","4"),
    `scapi_ces` enum("","0","1"),
    `scapi_ces_types` varchar(255),
    `scapi_ces_reason_1` enum("","1","2","3","99"),
    `scapi_ces_who_1` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_1` enum("","1","2","3","4","5"),
    `scapi_ces_len_1` enum("","1","2","3","4"),
    `scapi_ces_reason_2` enum("","1","2","3","99"),
    `scapi_ces_who_2` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_2` enum("","1","2","3","4","5"),
    `scapi_ces_len_2` enum("","1","2","3","4"),
    `scapi_ces_reason_3` enum("","1","2","3","99"),
    `scapi_ces_who_3` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_3` enum("","1","2","3","4","5"),
    `scapi_ces_len_3` enum("","1","2","3","4"),
    `scapi_ces_reason_4` enum("","1","2","3","99"),
    `scapi_ces_who_4` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_4` enum("","1","2","3","4","5"),
    `scapi_ces_len_4` enum("","1","2","3","4"),
    `scapi_ces_reason_5` enum("","1","2","3","99"),
    `scapi_ces_who_5` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_5` enum("","1","2","3","4","5"),
    `scapi_ces_len_5` enum("","1","2","3","4"),
    `scapi_ces_reason_6` enum("","1","2","3","99"),
    `scapi_ces_who_6` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_6` enum("","1","2","3","4","5"),
    `scapi_ces_len_6` enum("","1","2","3","4"),
    `scapi_ces_reason_7` enum("","1","2","3","99"),
    `scapi_ces_who_7` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_7` enum("","1","2","3","4","5"),
    `scapi_ces_len_7` enum("","1","2","3","4"),
    `scapi_ces_reason_8` enum("","1","2","3","99"),
    `scapi_ces_who_8` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_8` enum("","1","2","3","4","5"),
    `scapi_ces_len_8` enum("","1","2","3","4"),
    `scapi_ces_reason_9` enum("","1","2","3","99"),
    `scapi_ces_who_9` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_9` enum("","1","2","3","4","5"),
    `scapi_ces_len_9` enum("","1","2","3","4"),
    `scapi_ces_reason_10` enum("","1","2","3","99"),
    `scapi_ces_who_10` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_10` enum("","1","2","3","4","5"),
    `scapi_ces_len_10` enum("","1","2","3","4"),
    `scapi_ces_reason_11` enum("","1","2","3","99"),
    `scapi_ces_who_11` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_11` enum("","1","2","3","4","5"),
    `scapi_ces_len_11` enum("","1","2","3","4"),
    `scapi_ces_reason_12` enum("","1","2","3","99"),
    `scapi_ces_who_12` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_12` enum("","1","2","3","4","5"),
    `scapi_ces_len_12` enum("","1","2","3","4"),
    `scapi_ces_reason_13` enum("","1","2","3","99"),
    `scapi_ces_who_13` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_13` enum("","1","2","3","4","5"),
    `scapi_ces_len_13` enum("","1","2","3","4"),
    `scapi_ces_reason_99` enum("","1","2","3","99"),
    `scapi_ces_who_99` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","99"),
    `scapi_ces_freq_99` enum("","1","2","3","4","5"),
    `scapi_ces_len_99` enum("","1","2","3","4"),
    `scapi_pmh` enum("","0","1"),
    `scapi_pmh_types` varchar(255),
    `scapi_pmh_who_1` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_1` enum("","1","2","3","4","0"),
    `scapi_pmh_len_1` enum("","1","2","3","4"),
    `scapi_pmh_who_2` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_2` enum("","1","2","3","4","0"),
    `scapi_pmh_len_2` enum("","1","2","3","4"),
    `scapi_pmh_who_3` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_3` enum("","1","2","3","4","0"),
    `scapi_pmh_len_3` enum("","1","2","3","4"),
    `scapi_pmh_who_4` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_4` enum("","1","2","3","4","0"),
    `scapi_pmh_len_4` enum("","1","2","3","4"),
    `scapi_pmh_who_5` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_5` enum("","1","2","3","4","0"),
    `scapi_pmh_len_5` enum("","1","2","3","4"),
    `scapi_pmh_who_6` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_6` enum("","1","2","3","4","0"),
    `scapi_pmh_len_6` enum("","1","2","3","4"),
    `scapi_pmh_who_7` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_7` enum("","1","2","3","4","0"),
    `scapi_pmh_len_7` enum("","1","2","3","4"),
    `scapi_pmh_who_8` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_8` enum("","1","2","3","4","0"),
    `scapi_pmh_len_8` enum("","1","2","3","4"),
    `scapi_pmh_who_9` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_9` enum("","1","2","3","4","0"),
    `scapi_pmh_len_9` enum("","1","2","3","4"),
    `scapi_pmh_who_10` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_10` enum("","1","2","3","4","0"),
    `scapi_pmh_len_10` enum("","1","2","3","4"),
    `scapi_pmh_who_11` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_11` enum("","1","2","3","4","0"),
    `scapi_pmh_len_11` enum("","1","2","3","4"),
    `scapi_pmh_who_12` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_12` enum("","1","2","3","4","0"),
    `scapi_pmh_len_12` enum("","1","2","3","4"),
    `scapi_pmh_who_99` enum("","1","2","3","4","5","6","99"),
    `scapi_pmh_freq_99` enum("","1","2","3","4","0"),
    `scapi_pmh_len_99` enum("","1","2","3","4"),
    `scapi_you_med_adhd` enum("","0","1"),
    `scapi_you_med_adhd_2` enum("","0","1"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8