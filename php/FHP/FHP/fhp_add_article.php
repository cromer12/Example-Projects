<?php 
		require_once('partials/login_check.php'); 
?>
<html>
<head>
	
	<title>FHP Add Article</title>
</head>
<body>
	<?php 
		require_once('partials/dashboard_nav.php'); 
	?>
<main>
	<div id="div-section-holder-admin">
		<h1 id="section-name-admin">Create an Article</h1>
	</div>

	<div id="div-section-holder">
		<form action="" method="post">
	      	<div class="row">
		        <div class="col-md-12">
			        <h3 style="font-weight: normal">Article Title:</h3>
			        	<input name="arttitle" id="add-form-input"></input>
			      		<br>
				    <h3  style="font-weight: normal">Content:</h3>
			      		<textarea name="artcontent" class="tinymce-300"></textarea>
				    	<br><br>
				    	
				    <h3 style="font-weight: normal">Category:</h3>
					    <select id="artcategory" name="artcategory">
						  <?php get_category(); ?>
						</select>
						<br><br>
						
						<h3 style="font-weight: normal">Author: <i style="font-size: .65em;">(only if different from user)</i></h3>
			        	<input type="text" name="artauthor" id="add-form-input"></input>
			      		<br>
			      		
			      		<!--
			      		<h3 style="font-weight: normal">Date: <i style="font-size: .65em;">(only if different from current date)</i></h3>
			        	<input type="date" name="artdate id="add-form-date"></input>
			      		<br>-->
			      		
				   		<button id="add-form-submit-btn" type="submit" name="submit">Submit</button>
			    </div>
	      	</div>
	  	</form>
	</div>
	<?php
		if ($_SERVER['REQUEST_METHOD'] == "POST"){
		    $title = escape_string($_POST['arttitle']);
		    $content = escape_string($_POST['artcontent']);
		    
		    //If input field is blank, do this
		    if(empty($_POST['artauthor'])) {
		        $author = $_SESSION['firstname'] . " " . $_SESSION['lastname'];
		    }
		    //Otherwise pull author from input field
		    else {
		        $author = $_POST['artauthor'];
		    }
	
		    
		    $date = date("Y-m-d h:i:sH");
		    $date = substr($date, 0, -2);
		    $category = escape_string($_POST['artcategory']);

		    $query = query("INSERT INTO Post (title, content, author, timestamp, category, is_live) VALUES ('$title', '$content', '$author', '$date', '$category', 0)");
		    confirm($query);
		    header("Location:dashboard.php");
		}
	?>
	<?php 
		require_once('partials/tinymc_footer.php'); 
	?>
</main>
</html>