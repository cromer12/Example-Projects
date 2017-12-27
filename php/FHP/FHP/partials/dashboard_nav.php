<?php session_start(); ?>

<div id="banner-top">
	<img id="title-img" src="images/fhp_logo.png"></img>
	<ul>
		<?php 
			if($_SESSION['account'] != null){
				echo "<a href=\"dashboard.php\"><li class=\"dashboard\">Dashboard</li></a>"; 
				echo "<a href=\"fhp_institute.php\"><li>Institute</li></a>";
				echo "<a href=\"logout.php\"><li>Logout</li></a>"; 
			}
		?> 									
	</ul>
</div>