-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.6.11-log


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema hackathon
--

CREATE DATABASE IF NOT EXISTS hackathon;
USE hackathon;

--
-- Definition of table `anemometru`
--

DROP TABLE IF EXISTS `anemometru`;
CREATE TABLE `anemometru` (
  `UTC` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `speed` float NOT NULL,
  `location_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`UTC`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `anemometru`
--

/*!40000 ALTER TABLE `anemometru` DISABLE KEYS */;
/*!40000 ALTER TABLE `anemometru` ENABLE KEYS */;


--
-- Definition of table `dez`
--

DROP TABLE IF EXISTS `dez`;
CREATE TABLE `dez` (
  `UTC` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `dez` int(10) unsigned NOT NULL,
  `resolution` int(10) unsigned NOT NULL,
  `location_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`UTC`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `dez`
--

/*!40000 ALTER TABLE `dez` DISABLE KEYS */;
/*!40000 ALTER TABLE `dez` ENABLE KEYS */;


--
-- Definition of table `location`
--

DROP TABLE IF EXISTS `location`;
CREATE TABLE `location` (
  `id` int(10) unsigned NOT NULL,
  `lat` float NOT NULL,
  `lon` float NOT NULL,
  `UTC` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `index_2` (`UTC`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `location`
--

/*!40000 ALTER TABLE `location` DISABLE KEYS */;
INSERT INTO `location` VALUES  (1,44.425,26.0833,'2013-04-20 21:27:22');
/*!40000 ALTER TABLE `location` ENABLE KEYS */;




/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
