<?php 
session_start();

require_once('connect.php');

//Set up query to add data to table
$query = "SELECT name
		  FROM Categories";

//Run query//Run query
$result = $conn->query($query);
?>
<div id="banner-top">
	<img id="title-img" src="images/fhp_logo.png"></img>

<!--Nav Bar and Dropdown menus-->
	<ul>
		<a href="fhp_home.php"><li>Home</li></a>
		<a href="fhp_institute.php"><li class="institute">Institute</li></a>
		<div class="dropdown">
			<li>Categories &#x25BC</li>
				<div class="dropdown-content">
				
				<?php 
				while($row = $result->fetch_assoc())
				{
				?>
					<a href="fhp_category.php?id=<?php echo $row['name'];?>"><?php echo $row['name'];?></a>
				<?php 
				}
				?>
				</div>
		</div>					
		
		<a href="fhp_contact.php"><li>Contact</li></a>	

		<div class="dropdown">
			<li>About &#x25BC</li>
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
	</ul>
<!--End Nav Bar-->
</div>