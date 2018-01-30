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
				<h1>Create a Team</h1>
				<hr>
				<form action="add_team.php" method="post" enctype="multipart/form-data">
					<br>
					<h3>Team Name:</h3>
					<input type="text" name="teamname" placeholder ="Enter Team Name"required></input>
					<br><br>
					<label for="file"> Pick a file :  </label>
					<input type="file" name ="file"> 
					<br><br>
					<input type="submit" value = "Upload">
						
				
				</form>
			</div>
		</div>
	</div>
	<?php
		if ($_SERVER['REQUEST_METHOD'] == "POST"){
		    
			
				//Check if the file is well uploaded
			if($_FILES['file']['error'] > 0) { echo 'Error during uploading, try again'; }
			
			//We won't use $_FILES['file']['type'] to check the file extension for security purpose
			
			//Set up valid image extensions
			$extsAllowed = array( 'jpg', 'jpeg', 'png', 'gif' );
			var_dump($_FILES);
			
			//Extract extention from uploaded file
				//substr return ".jpg"
				//Strrchr return "jpg"
				
			$extUpload = strtolower( substr( strrchr($_FILES['file']['name'], '.') ,1) ) ;
			//Check if the uploaded file extension is allowed

			var_dump($extUpload);
			if (in_array($extUpload, $extsAllowed) ) { 
			
			//Upload the file on the server
			
			$name = "img/{$_FILES['file']['name']}";
			$result = move_uploaded_file($_FILES['file']['tmp_name'], $name);
		
			if($result){
				$teamname = escape_string($_POST['teamname']);	
				$query = query("INSERT INTO team (teamname, teamimg) VALUES ('$teamname', '$name')");
		   		confirm($query);
				header("Location:dashboard.php");
			}
				
			} else { echo 'File is not valid. Please try again'; }	    
		}


	?>
	<br><br>

</body>
</html>