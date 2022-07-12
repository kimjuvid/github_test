-- --------------------------------------------------------
-- 호스트:                          127.0.0.1
-- 서버 버전:                        10.8.3-MariaDB - mariadb.org binary distribution
-- 서버 OS:                        Win64
-- HeidiSQL 버전:                  11.3.0.6295
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- 7_11_team 데이터베이스 구조 내보내기
CREATE DATABASE IF NOT EXISTS `7_11_team` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `7_11_team`;

-- 테이블 7_11_team.ingredient 구조 내보내기
CREATE TABLE IF NOT EXISTS `ingredient` (
  `Name` varchar(20) CHARACTER SET utf8mb4 DEFAULT NULL,
  `Count` int(11) DEFAULT NULL,
  `Max_Count` int(11) DEFAULT NULL,
  `Min_Count` int(11) DEFAULT NULL,
  `Price` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- 테이블 데이터 7_11_team.ingredient:~16 rows (대략적) 내보내기
/*!40000 ALTER TABLE `ingredient` DISABLE KEYS */;
INSERT INTO `ingredient` (`Name`, `Count`, `Max_Count`, `Min_Count`, `Price`) VALUES
	('밀가루', 100, 2000, 50, 255),
	('설탕', 100, 2000, 50, 161),
	('팜유', 100, 2000, 50, 500),
	('계란', 100, 2000, 50, 800),
	('소금', 100, 2000, 50, 110),
	('버터', 100, 2000, 50, 1800),
	('유청분말', 100, 2000, 50, 1100),
	('코코아버터', 100, 2000, 50, 1950),
	('코코아매스', 100, 2000, 50, 1450),
	('액상과당', 100, 2000, 50, 105),
	('합성착향료', 100, 2000, 50, 5000),
	('유화제', 100, 2000, 50, 1600),
	('유크림', 100, 2000, 50, 5000),
	('산도조절제', 100, 2000, 50, 2000),
	('젤라틴', 100, 2000, 50, 1600),
	('옥수수전분', 100, 2000, 50, 450);
/*!40000 ALTER TABLE `ingredient` ENABLE KEYS */;

-- 테이블 7_11_team.purchase_record 구조 내보내기
CREATE TABLE IF NOT EXISTS `purchase_record` (
  `date` date DEFAULT NULL,
  `ingredient` varchar(200) DEFAULT NULL,
  `pur_amout` int(11) DEFAULT NULL,
  `cost` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 테이블 데이터 7_11_team.purchase_record:~1 rows (대략적) 내보내기
/*!40000 ALTER TABLE `purchase_record` DISABLE KEYS */;
INSERT INTO `purchase_record` (`date`, `ingredient`, `pur_amout`, `cost`) VALUES
	('2022-07-12', '케첩', 5, 500);
/*!40000 ALTER TABLE `purchase_record` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
