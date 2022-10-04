CREATE TABLE `masc2_self_lookup` (
  `sex` enum('m','f') NOT NULL,
  `age` tinyint NOT NULL,
  `attribute` varchar(45) NOT NULL,
  `score` smallint NOT NULL,
  `t_score` tinyint DEFAULT NULL,
  PRIMARY KEY (`sex`,`age`,`attribute`,`score`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
