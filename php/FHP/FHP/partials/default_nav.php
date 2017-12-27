<?php 
session_start(); 
$page = "";
// check what page is using the nav bar
if (basename($_SERVER['REQUEST_URI']) == "fhp_home.php") {
    $page = "home";
} else if (basename($_SERVER['REQUEST_URI']) == "fhp_institute.php") {
    $page = "institute";
} else if (basename($_SERVER['REQUEST_URI']) == "fhp_contact.php") {
    $page = "contact";
} else {
    $page = "about";
}
?>

<div <?php if ($page == "home") echo 'id="banner-top-home"'; else echo 'id="banner-top"'?>>
	<img id="title-img" src="images/fhp_logo.png"></img>
	<ul>
		<a href="fhp_home.php"><li <?php if ($page == "home") echo "class='home'";?>>Home</li></a>
		<a href="fhp_institute.php"><li <?php if ($page == "institute") echo "class='home'";?>>Institute</li></a>
		<a href="fhp_contact.php"><li <?php if ($page == "contact") echo "class='home'";?>>Contact</li></a>
					
		<div class="dropdown">
			<li <?php if ($page == "about") echo "class='home'";?>>About &#x25BC</li>
				<div class="dropdown-content">
					<a href="fhp_about.php">Freedom's Hill Primer</a>
					<a href="fhp_about_institute.php">Institute</a>
				</div>
		</div> 

		<?php 
			if($_SESSION != null){

				echo "<a href=\"dashboard.php\"><li>Dashboard</li></a>"; 

				echo "<a href=\"logout.php\"><li>Logout</li></a>"; 
			} else {

				echo "<a href=\"fhp_login.php\"><li>login</li></a>"; 
			}
		?>								
		<a href="logoutmain.php"><li>Main Site</li></a>
		<a href="http://freedomshillprimer.com/"><li>Active Site</li></a>
	</ul>
</div>