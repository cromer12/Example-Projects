<?php
	//Post Info
	$name = $_POST["name"];
	$email = $_POST["email"];
	$msg = $_POST["message"];

	// use wordwrap() if lines are longer than 70 characters
	$msg = wordwrap($msg,70);

	$mail = $name . "\n\n" . $email . "\n\n" . $msg;

	//Headers
	$to = "cchisholm@swu.edu";  
	$subject = "Contact Request";
	$from = "contactmail@web.com";

	// send email
	mail($to,$subject,$mail, $from);
?>

<html>
<style>
	h2 {
		font-family: arial;
		color: #12beed;
	}
</style>

<h2>Message sent! You will be redirected</h2>

<meta http-equiv="refresh" content="2;url=fhp/contact.php" />
</html>