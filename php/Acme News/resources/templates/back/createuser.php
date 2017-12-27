<?php

	$username = escape_string($_POST['username']);

	$password = $connection->escape_string(password_hash($_POST['password'], PASSWORD_BCRYPT));

	$hash = $connection->escape_string( md5( rand(0,1000) ) );

	$sql = "INSERT INTO users (username, userpass, userhash) " 
            . "VALUES ('$username','$password', '$hash')";

    $connection->query($sql);
	
?>