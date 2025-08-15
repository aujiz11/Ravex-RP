DROP TABLE IF EXISTS `houses`;
CREATE TABLE `houses`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `OwnerID` int NULL DEFAULT 0,
  `Price` int NOT NULL DEFAULT 0,
  `EntInterior` int NOT NULL DEFAULT 0,
  `EntWorld` int NOT NULL DEFAULT 0,
  `ExitInterior` int NOT NULL DEFAULT 0,
  `ExitWorld` int NOT NULL DEFAULT 0,
  `EntX` float NOT NULL DEFAULT 0,
  `EntY` float NOT NULL DEFAULT 0,
  `EntZ` float NOT NULL DEFAULT 0,
  `EntA` float NOT NULL DEFAULT 0,
  `ExitX` float NOT NULL DEFAULT 0,
  `ExitY` float NOT NULL DEFAULT 0,
  `ExitZ` float NOT NULL DEFAULT 0,
  `ExitA` float NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `OwnerID`(`OwnerID` ASC) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;