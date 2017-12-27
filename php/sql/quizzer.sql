-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Oct 18, 2017 at 01:59 AM
-- Server version: 5.7.19
-- PHP Version: 5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `quizzer`
--

-- --------------------------------------------------------

--
-- Table structure for table `grade`
--

DROP TABLE IF EXISTS `grade`;
CREATE TABLE IF NOT EXISTS `grade` (
  `gradeid` int(11) NOT NULL AUTO_INCREMENT,
  `studentid` int(11) NOT NULL,
  `testid` int(11) NOT NULL,
  `grade` int(11) DEFAULT NULL,
  PRIMARY KEY (`gradeid`),
  KEY `Grade_fk0` (`studentid`),
  KEY `Grade_fk1` (`testid`)
) ENGINE=MyISAM AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `grade`
--

INSERT INTO `grade` (`gradeid`, `studentid`, `testid`, `grade`) VALUES
(14, 1, 29, 100),
(13, 1, 28, 75);

-- --------------------------------------------------------

--
-- Table structure for table `questionmc`
--

DROP TABLE IF EXISTS `questionmc`;
CREATE TABLE IF NOT EXISTS `questionmc` (
  `questionmcid` int(11) NOT NULL AUTO_INCREMENT,
  `testid` int(11) NOT NULL,
  `questionmc` text NOT NULL,
  `choice1` text NOT NULL,
  `choice2` text NOT NULL,
  `choice3` text NOT NULL,
  `choice4` text NOT NULL,
  `answer` int(11) NOT NULL,
  PRIMARY KEY (`questionmcid`),
  KEY `QuestionMC_fk0` (`testid`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `questionmc`
--

INSERT INTO `questionmc` (`questionmcid`, `testid`, `questionmc`, `choice1`, `choice2`, `choice3`, `choice4`, `answer`) VALUES
(9, 29, 'test', '1', '1', '1', '2', 4),
(8, 28, 'This is choice 2', 'no', 'this one', 'nope', 'not', 2),
(7, 28, 'This is choice 1', 'this one', 'no ', 'not ', 'nope', 1);

-- --------------------------------------------------------

--
-- Table structure for table `questiontf`
--

DROP TABLE IF EXISTS `questiontf`;
CREATE TABLE IF NOT EXISTS `questiontf` (
  `questiontfid` int(11) NOT NULL AUTO_INCREMENT,
  `testid` int(11) NOT NULL,
  `questiontf` text NOT NULL,
  `answer` tinyint(1) NOT NULL,
  PRIMARY KEY (`questiontfid`),
  KEY `QuestionTF_fk0` (`testid`)
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `questiontf`
--

INSERT INTO `questiontf` (`questiontfid`, `testid`, `questiontf`, `answer`) VALUES
(10, 29, 'tre', 1),
(9, 28, 'false', 0),
(8, 28, 'true', 1);

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
CREATE TABLE IF NOT EXISTS `student` (
  `studentid` int(11) NOT NULL AUTO_INCREMENT,
  `teacherid` int(11) NOT NULL,
  `userid` int(11) NOT NULL,
  `fname` text NOT NULL,
  PRIMARY KEY (`studentid`),
  KEY `Student_fk0` (`teacherid`),
  KEY `Student_fk1` (`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`studentid`, `teacherid`, `userid`, `fname`) VALUES
(1, 1, 5, 'pstudent'),
(2, 3, 4, 'bstudent'),
(3, 1, 6, 'pstudent2'),
(4, 1, 7, 'pstudent3'),
(5, 3, 8, 'bstudent2'),
(6, 3, 9, 'bstudent3');

-- --------------------------------------------------------

--
-- Table structure for table `take`
--

DROP TABLE IF EXISTS `take`;
CREATE TABLE IF NOT EXISTS `take` (
  `takeid` int(11) NOT NULL AUTO_INCREMENT,
  `studentid` int(11) NOT NULL,
  `testid` int(11) NOT NULL,
  `taken` tinyint(1) NOT NULL,
  PRIMARY KEY (`takeid`)
) ENGINE=MyISAM AUTO_INCREMENT=55 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `take`
--

INSERT INTO `take` (`takeid`, `studentid`, `testid`, `taken`) VALUES
(54, 1, 29, 1),
(53, 1, 28, 1);

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

DROP TABLE IF EXISTS `teacher`;
CREATE TABLE IF NOT EXISTS `teacher` (
  `teacherid` int(11) NOT NULL AUTO_INCREMENT,
  `userid` int(11) NOT NULL,
  PRIMARY KEY (`teacherid`),
  KEY `Teacher_fk0` (`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `teacher`
--

INSERT INTO `teacher` (`teacherid`, `userid`) VALUES
(1, 1),
(2, 3);

-- --------------------------------------------------------

--
-- Table structure for table `test`
--

DROP TABLE IF EXISTS `test`;
CREATE TABLE IF NOT EXISTS `test` (
  `testid` int(11) NOT NULL AUTO_INCREMENT,
  `teacherid` int(11) NOT NULL,
  `testname` text NOT NULL,
  PRIMARY KEY (`testid`),
  KEY `Test_fk0` (`teacherid`)
) ENGINE=MyISAM AUTO_INCREMENT=30 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `test`
--

INSERT INTO `test` (`testid`, `teacherid`, `testname`) VALUES
(29, 1, 'test2 '),
(28, 1, 'Test One');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `userid` int(11) NOT NULL AUTO_INCREMENT,
  `username` text NOT NULL,
  `userpass` text NOT NULL,
  `userhash` text NOT NULL,
  `userpermission` int(11) NOT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`userid`, `username`, `userpass`, `userhash`, `userpermission`) VALUES
(1, 'pjordan', '$2y$10$Ps2heLjKklH1FytdzqEoPOVZNpabzgHKRTLQrGishEfvBpH7voq76', '6a9aeddfc689c1d0e3b9ccc3ab651bc5', 1),
(3, 'bcromer', '$2y$10$ibzN73cN1HkiaIqCil55sOsLAf/5As39WKC9ncIDqavNYJ.zxIMTq', '8f85517967795eeef66c225f7883bdcb', 1),
(4, 'bstudent', '$2y$10$PqjvDWC6jJFY8VqDKwLv4.3jfvBWyMXF5TIKEVVfLhbd6.2zEeSN2', 'a5771bce93e200c36f7cd9dfd0e5deaa', 2),
(5, 'pstudent', '$2y$10$S6TP6kOXbvW4r3vroP7nieDCwNsTyFuwj6V4krO2lVL.En6m8Fw82', '6a9aeddfc689c1d0e3b9ccc3ab651bc5', 2),
(6, 'pstudent2', '$2y$10$NA7hqqwcpTiJP/IhhECzWeXIrBngnL7hv3K9envpECeenBMrB4B3e', '115f89503138416a242f40fb7d7f338e', 2),
(7, 'pstudent3', '$2y$10$bNcO3/KXbu.55Nbe.HbCY.CzeteV1dg3957a3v0IPAcV6icP3s1SO', '03c6b06952c750899bb03d998e631860', 2),
(8, 'bstudent2', '$2y$10$LPyAUFaoFM5XSvc1ZJheiOUvw35AfEVrbPRqVhaf6fTQcW1MIUHEW', '6c4b761a28b734fe93831e3fb400ce87', 2),
(9, 'bstudent3', '$2y$10$7/0s0e8uhHkXgtPHq2H4IeM96zipusi8H7ALmYG4Ja6jp24ylTqC6', '68053af2923e00204c3ca7c6a3150cf7', 2);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
