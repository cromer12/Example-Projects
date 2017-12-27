<?php
	/* Log out process, unsets and destroys session variables */
	/*
	* Name: Cameron Cromer
	* Date: Nov. 19, 2017
	* Purpose: to kill everything
	*/
	session_start();
	session_unset();
	session_destroy(); 
	
	header("Location: fhp_home.php");
?>