<?php 
	/*
	* Name: Cameron Cromer
	* Date: Nov. 19, 2017
	* Purpose: where ADMIN, EDITOR, and AUTHOR all land on login. this is the mainhub and nav for the backend
	*/

	session_start();
	//In case of second session start on nav includes
	error_reporting(0);

	//Kick the user out to home if not logged in
	if(!$_SESSION['account']){
		header("Location: fhp_home.php");
	}
	require_once('connect.php');
?>

<!-- Other Head includes -->
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="fhp_test.css">
<link rel="stylesheet" href="bootstrap.min.css">