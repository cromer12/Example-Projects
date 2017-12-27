<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<?php
/* Log out process, unsets and destroys session variables */
session_start();
session_unset();
session_destroy(); 
header("Location: ../index.php");
?>
