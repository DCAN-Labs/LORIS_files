CREATE TABLE `medical_history_questionnaire` (
    `CommentID` varchar(255) NOT NULL DEFAULT '',
    `UserID` varchar(255) DEFAULT NULL,
    `medhx_1a_l` enum("","1","0","6"),
    `medhx_2a_l` enum("","1","0"),
    `medhx_2b_l` enum("","1","0"),
    `medhx_2c_l` enum("","1","0"),
    `medhx_2d_l` enum("","1","0"),
    `medhx_2e_l` enum("","1","0"),
    `medhx_2f_l` enum("","1","0"),
    `medhx_2g_l` enum("","1","0"),
    `medhx_2h_l` enum("","1","0"),
    `medhx_2i_l` enum("","1","0"),
    `medhx_2j_l` enum("","1","0"),
    `medhx_2k_l` enum("","1","0"),
    `medhx_2l_l` enum("","1","0"),
    `medhx_2m_l` enum("","1","0"),
    `medhx_2n_l` enum("","1","0"),
    `medhx_2o_l` enum("","1","0"),
    `medhx_2p_l` enum("","1","0"),
    `medhx_2q_l` enum("","1","0"),
    `medhx_2r_l` enum("","1","0"),
    `medhx_2t_l` enum("","1","0"),
    `medhx_2_notes2_l` enum("","1","0"),
    `medhx_4a_l` enum("","1","0","6","7"),
    `medhx_4b_l` enum("","1","2","3","4","5"),
    `medhx_6a_l` enum("","1","0"),
    `medhx_6a_notes_l` varchar(255),
    `medhx_6b_l` enum("","1","0"),
    `medhx_6b_notes_l` varchar(255),
    `medhx_6c_l` enum("","1","0"),
    `medhx_6c_times_l` varchar(255),
    `medhx_6d_l` enum("","1","0"),
    `medhx_6d_notes_l` varchar(255),
    `medhx_6e_l` enum("","1","0"),
    `medhx_6e_times_l` varchar(255),
    `medhx_6f_l` enum("","1","0"),
    `medhx_6f_notes_l` varchar(255),
    `medhx_6g_l` enum("","1","0"),
    `medhx_6g_times_l` varchar(255),
    `medhx_6h_l` enum("","1","0"),
    `medhx_6h_times_l` varchar(255),
    `medhx_6i_l` enum("","1","0"),
    `medhx_6i_times_l` varchar(255),
    `medhx_6j_l` enum("","1","0"),
    `medhx_6j_times_l` varchar(255),
    `medhx_6k_l` enum("","1","0"),
    `medhx_6k_times_l` varchar(255),
    `medhx_6l_l` enum("","1","0"),
    `medhx_6l_notes_l` varchar(255),
    `medhx_6m_l` enum("","1","0"),
    `medhx_6m_times_l` varchar(255),
    `medhx_6n_l` enum("","1","0"),
    `medhx_6n_notes_l` varchar(255),
    `medhx_6o_l` enum("","1","0"),
    `medhx_6o_notes_l` varchar(255),
    `medhx_6p_l` enum("","1","0"),
    `medhx_6p_notes_l` varchar(255),
    `medhx_6q_l` enum("","1","0"),
    `medhx_6q_notes_l` varchar(255),
    `medhx_6r_l` enum("","1","0"),
    `medhx_6r_notes_l` varchar(255),
    `medhx_6s_l` enum("","1","0"),
    `medhx_6s_times_l` varchar(255),
    `medhx_6t_l` enum("","1","0"),
    `medhx_6t_times_l` int,
    `medhx_8a_l` enum("","1","0","6"),
    `medhx_9a_l` enum("","1","0","6"),
    `medhx_9b_l` varchar(255),
    `medhx_9c_l` varchar(255),
    `medhx_11_l` enum("","1","0"),
    `medhx_12_l` enum("","1","0"),
    PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8