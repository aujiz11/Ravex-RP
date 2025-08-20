DROP TABLE IF EXISTS `accounts`;
CREATE TABLE `accounts`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `Registered` tinyint NOT NULL DEFAULT 0,
  `Username` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `Password` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `BirthDate` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT '00/00/0000',
  `Gender` tinyint NOT NULL DEFAULT 0,
  `Model` tinyint NOT NULL DEFAULT 0,
  `Referral` int NOT NULL DEFAULT 0,
  `PlayerPosX` float NOT NULL DEFAULT 0,
  `PlayerPosY` float NOT NULL DEFAULT 0,
  `PlayerPosZ` float NOT NULL DEFAULT 0,
  `PlayerAngle` float NOT NULL DEFAULT 0,
  `World` int NOT NULL DEFAULT 0,
  `Interior` tinyint NOT NULL DEFAULT 0,
  `Admin` tinyint NOT NULL DEFAULT 0,
  `AdminCode` varchar(128) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  PRIMARY KEY (`id`, `Username`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;
