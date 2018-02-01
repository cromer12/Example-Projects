<!DOCTYPE html>
<html lang="en">
<?php require_once("./resources/config.php"); ?>
<?php login_check(); ?>
<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

<body>
	<?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>
	<?php include(TEMPLATE_BACK . DS . "sport_check.php") ?>

	<div class="container">
		<div class="row text-center">
			<div class="col-lg-12">
				<h1>Create a Sport: <?php echo $row['teamname']?> </h1>
				<hr>
				<form action="add_sport.php" method="post" enctype="multipart/form-data">
					<br>
					<h3>Sport Name:</h3>
					<input type="text" name="sportname" placeholder ="Enter Team Name" required></input>
					<br><br>
					<h3>Sport Type:</h3>
					<select name="gender" required>
						<option value="Male">Male</option>
						<option value="Female">Female</option>
						<option value="CoED">CoED</option>
					</select>
					<br><br>
					<input type="submit" value = "Upload">
						
				
				</form>
			</div>
		</div>
	</div>
	<?php
		if ($_SERVER['REQUEST_METHOD'] == "POST"){
		
				$sportname = escape_string($_POST['sportname']);
				$teamid = $_SESSION['sportid'];
				$gender = $_POST['gender'];
				var_dump($_SESSION);
				
				if($gender == "Male"){
					$query = query("INSERT INTO sportsmen (sportname, teamid) VALUES ('$sportname', '$teamid' )");
				}elseif($gender == "Female"){
					$query = query("INSERT INTO sportswomen (sportname, teamid) VALUES ('$sportname', '$teamid' )");
				}else{
					$query = query("INSERT INTO sportsco (sportname, teamid) VALUES ('$sportname', '$teamid' )");
				}

				confirm($query);
				$_SESSION['sportid'] = NULL;
				header("Location:sport_list.php");    
		}


	?>
	<br><br>

</body>
</html>