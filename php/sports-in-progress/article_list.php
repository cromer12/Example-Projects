<?php 
	require_once('partials/dashboard_nav.php'); 
	if($_SESSION['account'] == ""){
		header("Location: fhp_home.php");
		exit();
	}
?>

<html>
<head>
	<?php
		/*
		* Name: Cameron Cromer
		* Date: Nov. 19, 2017
		* Purpose: to add display all articles from db that are relevent to user. (AUTHOR only sees thier posts, EDITORS and ADMIN see all posts)

		ADMIN and EDITOR can delete here
		*/
	    require_once('connect.php');
	?>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="fhp_test.css">
	<link rel="stylesheet" href="bootstrap.min.css">
	<title>FHP Article List</title>
</head>
<body>

<main>
	<div id="div-section-holder-admin">
		<h1 id="section-name-admin">Articles</h1>
	</div>

	<div class="container">
		<div class="row">
			<div class="col-lg-12">
				<?php
					if($_SESSION['account'] != "author")
					{
						if(isset($_GET['active']))//checks for active change
			            {
			                if($_GET['active'] == 2) //deletes the article
			                {
			                  $active = $_GET['active'];
			                  $id = $_GET['id'];
			                  $query = query("DELETE FROM Post where id=$id");
			                  confirm($query);
			                
			                } else
			                {
			                  $active = $_GET['active'];  //changes from active to inactive
			                  $id = $_GET['id'];
			                  $query = query("UPDATE Post set is_live = '$active' where id=$id");
			                  confirm($query);
			                }
			            }
		        	}
					get_article();           
				?>
			</div>
		</div>
	</div>
	<?php 
		require_once('partials/tinymc_footer.php'); 
	?>
</main>
</html>