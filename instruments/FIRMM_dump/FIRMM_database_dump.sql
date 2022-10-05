CREATE TABLE `FIRMM_database_dump` (
                `CommentID` varchar(255) NOT NULL default '',
                `UserID` varchar(255) default NULL,
                `Examiner` varchar(255) default NULL,
                `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
`Date_taken` date default NULL,
`file_name` varchar(255) default NULL,
`file_path` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
