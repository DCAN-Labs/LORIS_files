CREATE TABLE `phonescreen` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `research_site` enum("","1","2"),
    `wash_u_recruit` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13"),
    `umn_recruit` enum("","1","13","2","3","4","5","12","6","7","8","9","10","11"),
    `dobunsure` varchar(255),
    `caller_relat_to_child` enum("","1","2","3","4","5","6"),
    `unsure_child_name` varchar(255),
    `child_age_calc` int,
    `birth_cert_access` enum("","1","0","999","4"),
    `child_sex` enum("","1","2"),
    `child_gender` enum("","1","2","3","4","5","6","7"),
    `child_handedness` enum("","1","2","3","999"),
    `participating_adult` enum("","1","2","999","4"),
    `parent_name_unsure` varchar(255),
    `parent_dob_unsure` varchar(255),
    `parent_birth_cert` enum("","1","0","999","4"),
    `parent_lang` enum("","1","2"),
    `child_lang` enum("","1","2"),
    `child_autism` enum("","1","0"),
    `child_adhd` enum("","1","0"),
    `fam_adhd` enum("","1","0"),
    `fam_asd` enum("","1","2"),
    `orthodontia_current` enum("","1","0"),
    `unsure_ortho_current` varchar(255),
    `ortho_current_remove` enum("","1","0"),
    `ortho_current_expec_off` date,
    `antic_ortho` enum("","1","0"),
    `unsure_antic_ortho` varchar(255),
    `antic_ortho_remov` enum("","1","0","999"),
    `antic_ortho_expect` date,
    `cardiac_pacemaker` enum("","1","0"),
    `implant_cardio_defib` enum("","1","0"),
    `pacer_wires` enum("","1","0"),
    `art_heart_valve` enum("","1","0"),
    `cardio_stents` enum("","1","0"),
    `eye_spring_retinal_tracks` enum("","1","0"),
    `ear_implant` enum("","1","0"),
    `tatoos` enum("","1","0"),
    `metal_eye` enum("","1","0"),
    `bullets` enum("","1","0"),
    `drug_pump` enum("","1","0"),
    `bladder_ring` enum("","1","0"),
    `claustrophobic` enum("","1","0"),
    `preg_breastfeed` enum("","1","0"),
    `kiddisease_dialysis` enum("","1","0"),
    `penile_implant` enum("","1","0"),
    `tiss_exp_tracheo` enum("","1","0"),
    `endo_camera_pill` enum("","1","0"),
    `aneur_clip` enum("","1","0"),
    `neurostim` enum("","1","0"),
    `spine_stim` enum("","1","0"),
    `spine_vent_shunt` enum("","1","0"),
    `implant_metal_misc` enum("","1","0"),
    `coil_filter_stent` enum("","1","0"),
    `hearing_aid` enum("","1","0"),
    `medpatch_dressing` enum("","1","0"),
    `artificial_limb` enum("","1","0"),
    `artificial_limb_elec` enum("","1","0"),
    `false_teeth` enum("","1","0"),
    `body_piercing` enum("","1","0"),
    `hair_implants` enum("","1","0"),
    `insulin_pump` enum("","1","0"),
    `hearing_aid_remove` enum("","0","1"),
    `med_patch_remove` enum("","0","1"),
    `artificial_limb_remove` enum("","0","1"),
    `artificial_limb_elec_remove` enum("","0","1"),
    `false_teeth_remove` enum("","0","1"),
    `body_piercing_remove` enum("","0","1"),
    `hair_implant_remove` enum("","0","1"),
    `insuln_pump_remove` enum("","0","1"),
    `child_no_surgery` varchar(255),
    `fearful_loud_noise` enum("","1","0"),
    `behavior_loud_enviro` enum("","0","1"),
    `child_claustro` enum("","0","1","999"),
    `child_hyperactive` enum("","1","0"),
    `sit_still_mri` enum("","1","2","0"),
    `tolerate_headphone` enum("","1","0"),
    `happen_next` enum("","1","0"),
    `respond_verbal` enum("","1","0"),
    `ipad` enum("","1","0"),
    `exclusion_child_diag` varchar(255),
    `radio_chemo` enum("","1","0"),
    `brain_tumor_cancer` enum("","1","0"),
    `phys_disability` enum("","1","0"),
    `conduct_disorder` enum("","1","0"),
    `impaired_vision` enum("","1","0"),
    `vision_correctable` enum("","0","1"),
    `speech_difficulties` enum("","1","0"),
    `lang_delay` enum("","1","0"),
    `color_blind` enum("","1","0"),
    `allergies` enum("","0","1"),
    `head_trauma` enum("","1","0","999"),
    `head_injury_uncon` enum("","1","0","999"),
    `head_injury_uncon_hospital` enum("","1","0"),
    `head_injury_uncon_concus` enum("","1","0"),
    `head_injury_uncon_pt` enum("","1","0"),
    `med_diag_other` enum("","1","0"),
    `stimulant` enum("","1","0","999"),
    `no_med_checkbox` varchar(255),
    `med_allergy` enum("","0","1"),
    `stimulants_coordinator` enum("","1","0","3"),
    `stimulation_cessation` enum("","1","0"),
    `iq_test` enum("","1","0","3","4","999"),
    `iq_test_results` enum("","1","0","3"),
    `psych_test_other` enum("","1","0","3","999"),
    `psych_test_specify` varchar(255),
    `psych_test_records` enum("","1","0","3"),
    `iep` enum("","1","0","3","999"),
    `iep_record_release` enum("","1","0","3"),
    `child_ethnicity` enum("","1","2","999","4"),
    `child_racial_group` varchar(255),
    `parent_ethnicity` enum("","1","2","999","3"),
    `parent_racial_group` varchar(255),
    `phone_screen_complete` enum("","0","1"),
    `d_team_review` enum("","1","0","999"),
    `eligibility` enum("","1","2","999"),
    `ineligibility_reason` varchar(255),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8