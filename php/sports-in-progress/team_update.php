<!DOCTYPE html>
<html lang="en">
<?php require_once("./resources/config.php"); ?>
<?php login_check_admin(); ?>
<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

<body>
	<?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>
	<?php
		$id = $_GET['id'];
		if ($_SERVER['REQUEST_METHOD'] == "POST"){
				//Check if the file is well uploaded
			if($_FILES['file']['error'] > 0) {
				$teamname = escape_string($_POST['teamname']);	
				$query = query("UPDATE team SET teamname = '$teamname' WHERE teamid = '$id'");
				confirm($query);
				header("Location:dashboard.php"); 
			}
			
			//We won't use $_FILES['file']['type'] to check the file extension for security purpose
			
			//Set up valid image extensions
			$extsAllowed = array( 'jpg', 'jpeg', 'png', 'gif' );
			
			//Extract extention from uploaded file
				//substr return ".jpg"
				//Strrchr return "jpg"
				
			$extUpload = strtolower( substr( strrchr($_FILES['file']['name'], '.') ,1) ) ;
			//Check if the uploaded file extension is allowed

			if (in_array($extUpload, $extsAllowed) ) { 
			
			//Upload the file on the server
			
			$name = "img/{$_FILES['file']['name']}";
			$result = move_uploaded_file($_FILES['file']['tmp_name'], $name);
			
		
			if($result){
				$teamname = escape_string($_POST['teamname']);	
				
				$query = query("SELECT * FROM team WHERE teamid = '$id'");
				confirm($query);
				$row = fetch_array($query);
				$oldimg = $row['teamimg'];
				$query = query("UPDATE team SET teamname = '$teamname', teamimg = '$name' WHERE teamid = '$id'");
				confirm($query);
				unlink($oldimg);
				header("Location:dashboard.php");
			}
				
			} else { echo 'File is not valid. Please try again'; }	    
		}
		$query = query("SELECT * FROM team WHERE teamid = $id");
		confirm($query);
		
		$row = fetch_array($query);
	
		$team = <<< DELIMETER
		<div class="container">
			<div class="row text-center">
				<div class="col-lg-12">
					<h1>Create a Team</h1>
					<hr>
					<form action="team_update.php?id={$id}" method="post" enctype="multipart/form-data">
						<br>
						<h3>Team Name:</h3>
						<input type="text" name="teamname" placeholder ="Current: {$row['teamname']}"required></input>
						<br><br>
						<label for="file"> Pick a file :  </label>
						<input type="file" name ="file"> 
						<br><br>
						<input type="submit" value = "Upload">
					</form>
					<br>
					Current Image:
					<img src="{$row['teamimg']}">
				</div>
			</div>
		</div>
DELIMETER;
		echo $team;


	?>
	<br><br>

</body>
</html>