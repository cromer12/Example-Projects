<?php
	//Database configuration
	$db_name = 'id2681202_article';
	$db_pass = 'cromer12';
	$db_username = 'id2681202_user';
	$db_servername = 'localhost';

	//Create connection
	$conn = mysqli_connect($db_servername, $db_username, $db_pass, $db_name);

	//Check connection
	if ($conn->connect_error) {
	    die("Connection failed: " . $conn->connect_error);
	}
	require_once("functions.php");
?>