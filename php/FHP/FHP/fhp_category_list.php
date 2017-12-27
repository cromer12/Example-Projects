<?php 
	require_once('partials/dashboard_nav.php'); 
	if($_SESSION['account'] == "" || $_SESSION['account'] == "author"){
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
		* Purpose: to list all categories. EDITOR AND ADMIN ONLY, can delete categories here
		*/
    	require_once('connect.php');
	?>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="fhp_test.css">
	<link rel="stylesheet" href="bootstrap.min.css">
	<title>FHP Category</title>
</head>
<body>
    
<main>
	<div id="div-section-holder-admin">
		<h1 id="section-name-admin">Categories</h1>
	</div>

	<div class="container">
		<div class="row">
			<div class="col-lg-12">
				<?php
					if(isset($_GET['active']))//checks for active change
		            {
		                if($_GET['active'] == 2) //deletes the article
		                {
		                  $active = $_GET['active'];
		                  $id = $_GET['id'];
		                  $query = query("DELETE FROM Categories where id=$id");
		                  confirm($query);
		                }
		            }
					get_category_list();           
				?>
			</div>
		</div>
	</div>
	<?php 
		require_once('partials/tinymc_footer.php'); 
	?>
</main>
</html>