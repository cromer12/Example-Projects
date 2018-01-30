<!DOCTYPE html>
<html lang="en">
<?php require_once("./resources/config.php"); ?>
<?php login_check_admin(); ?>
<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

<body>
	<?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>
	<div class="container">
		<div class="row text-center">
			<div class="col-lg-12">
				<h1>Create a User</h1>
				<hr>
				<form action="add_user.php" method="post">
					<br>
					<h3>Username:</h3>
					<input type="text" name="username" placeholder ="Enter Username"required></input>
					
					<h3>Password</h3>
					<input type="password" name="userpass" placeholder ="Enter Password" required>
					<br>

					<!--Option Menu-->
					<h3>Team</h3>
					<!--Replace with Option Menu-->
					<select name="userteamid" required>		
						<option value="" selected disabled>Select Team</option>
						<?php get_teams_list();?>
					</select>
					
					<!--Option Menu-->
					<h3>Account Type</h3>
					<!--Replace with Option Menu-->
					<select name="userpermission" required>		
						<option value="" selected disabled>Select Account Type</option>
						<option value="2">Admin</option>
						<option value="1">Coach</option>
						<option value="0">Assistant</option>
					</select>
							
					<br><br>
					<button id="add-form-submit-btn" type="submit" name="submit-btn">Submit</button>	
				
				</form>
			</div>
		</div>
	</div>
	<?php
		if ($_SERVER['REQUEST_METHOD'] == "POST"){
		    $username = escape_string($_POST['username']);		    
		    $userteamid = escape_string($_POST['userteamid']);
			$userpermission = escape_string($_POST['userpermission']);
			$userpass = $connection->escape_string(password_hash($_POST['userpass'], PASSWORD_BCRYPT));
			$userhash = $connection->escape_string( md5( rand(0,1000) ) );

		    $query = query("INSERT INTO users (username, userpass, userhash, userpermission, userteamid) VALUES ('$username', '$userpass', '$userhash', '$userpermission', '$userteamid')");
		    confirm($query);
		    header("Location:dashboard.php");
		}
	?>
	<br><br>

</body>
</html>