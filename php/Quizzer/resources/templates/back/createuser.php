<?php

	$username = escape_string($_POST['username']);

	$password = $connection->escape_string(password_hash($_POST['password'], PASSWORD_BCRYPT));

	$hash = $connection->escape_string( md5( rand(0,1000) ) );

	$sql = "INSERT INTO users (username, userpass, userhash, userpermission) " 
            . "VALUES ('$username','$password', '$hash', 2)";

    $connection->query($sql);

    $last_id = mysqli_insert_id($connection);

    $teachid = $_SESSION['id'];

    $query = query("INSERT INTO student (teacherid, userid, fname) VALUES ('$teachid','$last_id', '$username' )");
  	confirm($query);
	
	redirect('dashboard.php');
?>