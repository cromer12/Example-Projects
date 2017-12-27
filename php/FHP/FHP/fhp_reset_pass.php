<html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="fhp_test.css">
	<title>CIFC Reset Password</title>
</head>
    <div id="banner-top">
    	<img id="title-img" src="images/fhp_logo.png"></img>	
		<ul>
			<h2 id="admin-subtitle-login">Enter New Password</h2>		
		</ul>
    </div>
<body>	
	<?php 
	   $user = $_GET['key'];
	?> 

    <div id="login-holder">
    	<form action="fhp_update_pass.php" method="post">
    		<input type="hidden" name="user" value="<?php echo $user ?>">
    		<!--password input-->
    		<input type="password" id="login-input" placeholder="New Password" name="password" required>
    		<br>
    		<!--re-password input-->
    		<input type="password" id="login-input" placeholder="Re-Enter Password" name="repassword" required>
    		<br><br>
    		<!--Submit Button-->
    		<button type="submit" id="contact-form-submit" name="submit">Submit</button>
    	</form>	
    </div>
</body>
</html>