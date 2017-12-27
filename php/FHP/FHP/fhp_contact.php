<?php 
	require_once('partials/default_nav.php'); 
?>

<html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="fhp_test.css">
	<title>FHP Contact</title>
</head>
<body>	
	
	<div id="div-contact-section">
		<h1 id="section-name">Thank you for your interest!</h1>
		
		<p id="section-about">
			We are grateful for your input! Please visit and give us feedback often. It is only with your interest that we can have a successful platform for the exchange of ideas and creative content that is pleasing for us to create and relevant to you
		</p>
		<p id="section-about">
			Again, we are looking forward to a long relationship with you, our visitors, and hope to provide thought provoking material for a long time to come.
		</p>
		<p id="section-about">
				Editors:<br>
				David Stubblefield<br>
				Chad Chisholm, Ph.D.<br>
				Lewis C. Knight, Ph.D.<br>
		</p>
	</div>
	
		<!--Contact Form-->
	<form method="post" action="fhp_send_mail.php"id="contact-form">
		<h2 id="contact-heading">Send us a Message</h1>
		<!--<label id="contact-label" for="input1">Name:</label><br>-->
		<input tabindex="1" id="contact-form-input" type="text" name="name" placeholder="Enter Name" required><br>
		
		<!--<label id="contact-label" for="input1">Email:</label><br>-->
		<input tabindex="2" id="contact-form-input" type="email" name="email" placeholder="Enter Email"><br>
		
		<!--<label id="contact-label" for="input1">Message:</label><br>-->
		<textarea tabindex="3" id="contact-form-textarea" name="message" placeholder="Enter Message"></textarea><br>
		
		<button tabindex="4" id="contact-form-submit" type="submit">Submit</button>
	</form>
	<br><br>	
</body>
</html>