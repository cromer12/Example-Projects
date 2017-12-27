<?php
require_once('partials/login_check.php');
?>

<html>

<meta name="viewport" content="width=device-width, initial-scale=1">

<head>
	<link rel="stylesheet" href="fhp_test.css">
	<title>CIFC Admin</title>
</head>

<body>	

	<div id="banner-top">
    	<img id="title-img" src="images/fhp_logo.png"></img>
    	<ul>
    		<?php 
    			if($_SESSION['account'] != null){
    				echo "<a href=\"dashboard.php\"><li class=\"dashboard\">Dashboard</li></a>"; 
    				echo "<a href=\"logout.php\"><li>Logout</li></a>"; 
    			}
    		?> 									
    	</ul>
    </div>
	
	<div id="div-section-holder-admin">
		<h1 id="section-name-admin">Create a User</h1>
	</div>
	

	<div id="add-user-form-div">
		<form id="add-form" action="add_user.php" method="post">
		    <?php 
		    if($_GET['error'] == "password") echo "<center>The passwords do not match!</center>"; 
		    else if ($_GET['error'] == "account") echo "<center>Please enter an account type!</center>"; 
		    ?>
			<br>
			<h3 id="input-user-label">First Name</h3>
			<input type="text" tabindex="1" id="add-form-input" name="first" placeholder ="Enter First Name"required></input>
			<br>
			
			<h3 id="input-label">Last Name</h3>
			<input type="text" tabindex="2" id="add-form-input" name="last" placeholder ="Enter Last Name"required>
			<br>
			
			<h3 id="input-user-label">Email</h3>
			<input type="email" tabindex="3" id="add-form-input" name="email" placeholder ="Enter Email"required>
			<br>
			
			<h3 id="input-user-label">Username</h3>
			<input type="text" tabindex="4" id="add-form-input" name="username" placeholder ="Enter Username" required>
			<br>
			
			<h3 id="input-user-label">Password</h3>
			<input type="password" tabindex="5" id="add-form-input" name="password" placeholder ="Enter Password" required>
			<br>
			
			<h3 id="input-user-label">Re-Password</h3>
			<input type="password" tabindex="5" id="add-form-input" name="repassword" placeholder ="Re-Enter Password" required>
			<br>
			
			<!--Option Menu-->
			<h3 id="input-user-label">Account Type</h3>
			<!--Replace with Option Menu-->
			<select tabindex="7" name="account" required>		
				<option value="" selected disabled>Select Account Type</option>
				<option value="ADMIN">Admin</option>
				<option value="EDITOR">Editor</option>
				<option value="AUTHOR">Author</option>
			</select>
					
			<br><br>
			<button tabindex="8" id="add-form-submit-btn" type="submit" name="submit-btn">Submit</button>	
		
		</form>
		</div>
	
	<br><br>

</body>
</html>