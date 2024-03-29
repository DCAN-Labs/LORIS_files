CREATE TABLE `mri_data_entry_summary` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `scan_site` enum("","1","2"),
    `mri_studytype` enum("","1","2"),
    `mri_scanner_umn` enum("","1","2"),
    `scanner_type_washu` enum("","1"),
    `mri_late_start` enum("","0","1"),
    `mri_late_start_issues` varchar(255),
    `mri_washout_meds` enum("","3","1","0"),
    `mri_washout_time` enum("","1","2"),
    `mri_washout_verified` enum("","3","1","2","4"),
    `mri_movie_yesno` enum("","0","1"),
    `mri_music_yesno` enum("","0","1"),
    `nnl_equip` varchar(255),
    `mri_scan_set_up` varchar(255),
    `rs_run_times` enum("","1","2","3"),
    `vid_sequence` enum("","1","2"),
    `mri_physio` enum("","0","1"),
    `mri_t1_1_complete` enum("","1","3"),
    `mri_t1_stim` enum("","1","2","3","4","5","6"),
    `mri_t1_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t1_aqu_error_1` varchar(255),
    `mri_t1_artifact_1` enum("","1","3"),
    `q_score_t1_1` varchar(255),
    `mri_t1_2_complete` enum("","1","3"),
    `mri_t1_stim_2` enum("","1","2","3","4","5","6"),
    `mri_t1_2_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t1_aqu_error_2` varchar(255),
    `mri_t1_artifact_2` enum("","1","3"),
    `q_score_t1_2` varchar(255),
    `mri_t1_3_complete` enum("","1","3"),
    `mri_t1_stim_3` enum("","1","2","3","4","5","6"),
    `mri_t1_3_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t1_aqu_error_3` varchar(255),
    `mri_t1_artifact_3` enum("","1","3"),
    `q_score_t1_3` varchar(255),
    `mri_t1_4_complete` enum("","1","3"),
    `mri_t1_stim_4` enum("","1","2","3","4","5","6"),
    `mri_t1_4_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t1_aqu_error_4` varchar(255),
    `mri_t1_artifact_4` enum("","1","3"),
    `q_score_t1_4` varchar(255),
    `mri_t1_5_complete` enum("","1","3"),
    `mri_t1_stim_5` enum("","1","2","3","4","5","6"),
    `mri_t1_5_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t1_aqu_error_5` varchar(255),
    `mri_t1_artifact_5` enum("","1","3"),
    `q_score_t1_5` varchar(255),
    `mri_t2_1_complete` enum("","1","3"),
    `mri_t2_stim_1` enum("","1","2","3","4","5","6"),
    `mri_t2_1_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t2_aqu_error_1` varchar(255),
    `mri_t2_artifact_1` enum("","1","3"),
    `q_score_t2_1` varchar(255),
    `mri_t2_2_complete` enum("","1","3"),
    `mri_t2_stim_2` enum("","1","2","3","4","5","6"),
    `mri_t2_2_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t2_aqu_error_2` varchar(255),
    `mri_t2_artifact_2` enum("","1","3"),
    `q_score_t2_2` varchar(255),
    `mri_t2_3_complete` enum("","1","3"),
    `mri_t2_stim_3` enum("","1","2","3","4","5","6"),
    `mri_t2_3_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t2_aqu_error_3` varchar(255),
    `mri_t2_artifact_3` enum("","1","3"),
    `q_score_t2_3` varchar(255),
    `mri_t2_4_complete` enum("","1","3"),
    `mri_t2_stim_4` enum("","1","2","3","4","5","6"),
    `mri_t2_4_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_t2_aqu_error_4` varchar(255),
    `mri_t2_artifact_4` enum("","1","3"),
    `q_score_t2_4` varchar(255),
    `dti_ap_1_complete` enum("","0","1"),
    `mri_dti_ap_stim_1` enum("","1","2","3","4","5","6"),
    `mri_dti_1_pixar_choice` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_dti_ap_aqu_error_1` varchar(255),
    `mri_dti_ap_1_artif` enum("","1","3"),
    `q_score_dti_ap_1` varchar(255),
    `dti_ap_extra_2` enum("","0","1"),
    `mri_dti_ap_stim_2` enum("","1","2","3","4","5","6"),
    `mri_dti_1_pixar_choice_2` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_dti_ap_aqu_error_2` varchar(255),
    `mri_dti_ap_1_artif_2` enum("","1","3"),
    `q_score_dti_ap_2` varchar(255),
    `dti_pa_complete_1` enum("","0","1"),
    `dti_pa_stim_1` enum("","1","2","3","4","5","6"),
    `dti_pa_pixar_choice_1` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `dti_pa_aqui_err_1` varchar(255),
    `dti_pa_artif_1` enum("","0","1"),
    `q_score_dti_pa_1` varchar(255),
    `dti_pa_extra` enum("","0","1"),
    `dti_pa_stim_2` enum("","1","2","3","4","5","6"),
    `dti_pa_pixar_choice_2` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `dti_pa_aqui_err_2` varchar(255),
    `dti_pa_artif_2` enum("","0","1"),
    `mri_rs_1_complete` enum("","1","3"),
    `video_rs_1` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_stim_1` enum("","1","6"),
    `mri_rs_video_1` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_aqu_error_1` varchar(255),
    `mri_rs_artifact_1` enum("","1","3"),
    `mri_rs_2_complete` enum("","1","3"),
    `video_rs_2` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_stim_2` enum("","1","6"),
    `mri_rs_video_2` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_aqu_error_2` varchar(255),
    `mri_rs_artifact_2` enum("","1","3"),
    `mri_rs_3_complete` enum("","1","3"),
    `video_rs_3` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_stim_3` enum("","1","6"),
    `mri_rs_video_3` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_aqu_error_3` varchar(255),
    `mri_rs_artifact_3` enum("","1","3"),
    `mri_rs_4_complete` enum("","1","3"),
    `mri_rs_stim_4` enum("","1","6"),
    `mri_rs_video_4` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `video_rs_4` enum("","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"),
    `mri_rs_aqu_error_4` varchar(255),
    `mri_rs_artifact_4` enum("","1","3"),
    `mri_firmm_total` int,
    `firmm_unfilt_total` int,
    `mri_anatom_review_complete` enum("","0","1"),
    `mri_review_need` enum("","0","1"),
    `data_sent_to_radiology_rev` enum("","0","1"),
    `mri_abnorm_confirm` enum("","0","1"),
    `physio_data_sent_to` enum("","0","1"),
    `dicoms_sent_to` enum("","0","1"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8