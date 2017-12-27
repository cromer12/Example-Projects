<?php 
	require_once('partials/login_check.php'); 
?>

<html>
<head>

	<title>FHP About</title>
</head>
<body>
	<?php 
		require_once('partials/dashboard_nav.php'); 
	?>
<main>
	
		<div id="div-section-holder-admin">
		    <h1 id="section-name-admin">Create a Category</h1>
    	</div>
        <br>
	
		<form action="" method="post">
	      	<div class="row">
		        <div class="col-md-12">
			       	<input style="display: block; margin: auto; width: 50%" name="artcategory" id="add-form-input"></input>
					<br><br>
				    <button id="contact-form-submit" type="submit" name="submit">Submit</button>
			    </div>
	      	</div>
	  	</form>
	<?php
		if ($_SERVER['REQUEST_METHOD'] == "POST"){
		  $category = escape_string($_POST['artcategory']);
		  $query = query("INSERT INTO Categories (name) VALUES ('$category')");
		  confirm($query);
		  header("Location: dashboard.php");
		}
	?>
	<?php 
		require_once('partials/tinymc_footer.php'); 
	?>
</main>
</html>