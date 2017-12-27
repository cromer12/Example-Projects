<?php require_once('partials/login_check.php'); ?>
<html>
<head>
	<?php
		//checks for get set and kicks if not set
		if(isset($_GET['id'])){
		    $id = $_GET['id'];

		    //checks to see if account level is author
		    if ($_SESSION['account'] == "author")
		    {
			    $query = query("SELECT * FROM Post WHERE id = '$id'");
			  	confirm($query);
			  	$post = fetch_array($query);
			  	$fname = $_SESSION['firstname'];
				$lname = $_SESSION['lastname'];
				$name  = $fname . ' ' . $lname;

				//checks account name to the articles author's name to ensure they are allowed (ONLY FOR ACCOUNT LEVLE: AUTHOR)
			  	if($post['author'] != $name)
			  	{
			  		header("Location: fhp_article_list.php");
			  	}
		 	}
		} else {
			header("Location: fhp_article_list.php");
		}

	    $query = query("SELECT * FROM Post WHERE id = '$id'");
	    confirm($query);
	    $results = fetch_array($query);
	?>
	<title>FHP Edit Article</title>
</head>

<body>
	<?php 
		require_once('partials/dashboard_nav.php'); 
	?>
<main>
	<div id="div-section-holder">
		<h1 id="section-name">Edit Article</h1>
	</div>

	<div id="div-section-holder">
		<form action="" method="post">
	      	<div class="row">
		        <div class="col-md-12">
		        	<?php get_article_edit($id); ?>
				    <br><br>
				    <h3 style="font-weight: normal">Category:</h3>
				    <select id="artcategory" name="artcategory">
					  <?php get_category_edit($results['category']); ?>
					</select>
					<br><br><br>
					
					<!--Get author-->
					<?php get_author_edit($id)?>
		      	    <br>
					
				    <button id="contact-form-submit" type="submit" name="submit">Submit</button>
			    </div>
	      	</div>
	  	</form>
	</div>

	<?php
		if ($_SERVER['REQUEST_METHOD'] == "POST"){

		              $title = escape_string($_POST['arttitle']);
		              $content = escape_string($_POST['artcontent']);
		              $author = $_POST['artauthor'];
		              $date = date("Y-m-d h:i:sH");
		              $date = substr($date, 0, -2);
		              $category = escape_string($_POST['artcategory']);
		              $id = $results['id'];

		              $query = query("UPDATE Post SET title='$title', content='$content', timestamp='$date', category = '$category', author='$author' WHERE id=$id");
		              confirm($query);

		             echo "<script type=\"text/javascript\">window.location.replace(\"fhp_article_list.php\")</script>";
		}

		require_once('partials/tinymc_footer.php'); 
	?>
</main>
</html>