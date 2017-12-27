<html>

<meta name="viewport" content="width=device-width, initial-scale=1">

<head>
<link rel="stylesheet" href="fhp_test.css">
<title>CIFC Admin Login</title>
</head>

	
<div id="banner-top">
	<img id="title-img" src="images/fhp_logo.png"></img>	
	
		<ul>
			<h2 id="admin-subtitle-login">Administration</h2>
			
		</ul>
</div>

<body>	

	<!--Logout Icon-->
	<a href="logout.php"><img id="public-icon" src="images/public_site.png"></img></a>

<div id="login-holder">
	<form action="fhp_verify_user.php" method="post">
		<!--Image-->
		<img id="login-img" src="images/loginImg.png"></img>
		
		<!--username input-->
		<input tabindex="1" type="text" id="login-input" placeholder="username" name="username" required>
		<br>
		<!--password input-->
		<input tabindex="2"type="password" id="login-input" placeholder="password" name="password" required>
		<br>
		
		<a style="color:#21367d; font-family:arial" href="fhp_email_form.php">Forgot your password?</a>
		
		<br><br>
		
		<!--Submit Button-->
		<button tabindex="3" type="submit" id="contact-form-submit">Submit</button>
	</form>	
</div>


</body>
</html>