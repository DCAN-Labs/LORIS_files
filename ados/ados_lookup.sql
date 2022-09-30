CREATE TABLE `ados_lookup` (
  `sevscore` int(11) NOT NULL,
  `module` varchar(255) DEFAULT NULL,
  `minagemos` int(11) DEFAULT NULL,
  `maxagemos` int(11) DEFAULT NULL,
  `minraw` int(11) DEFAULT NULL,
  `maxraw` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
