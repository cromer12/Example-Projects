<?php 
    require_once('partials/nav_with_dropdown.php');
?>

<head>

<meta name="viewport" content="width=device-width, initial-scale=1">

<link rel="stylesheet" href="fhp_test.css">
<title>CIFC</title>
</head>

<!--Connect to database-->
<?php
require_once('connect.php');
?>

<body>
	
	<!--Article Preview Holder-->
	<div id="all-article-view">
	
		<!--Get articles and sort by date added-->
	<?php
	    $cat_name = $_GET['id'];
	
    	//Set up query to add data to table
    	$query = "SELECT id, title, content, author, timestamp, category
    		      FROM Post
                  WHERE category = '" . $cat_name . "'
    		      ORDER BY TIMESTAMP(timestamp) DESC";
    	
    	//Run query//Run query
    	$result = $conn->query($query);
    	
    	$formatCnt = 0;
	
	    if (!$article = $result->fetch_assoc()) {
	        echo "<h2>No Articles Found</h2>";
	    }
	    else
	    {
	        //Run query//Run query
    	    $result = $conn->query($query);
	    }
	
		//Read results
		while($article = $result->fetch_assoc()) { 	
	?>	
	
	    
		<div id="article-preview-holder">
		    <a href="fhp_view_article.php?id=<?php echo $article['id']?>">	
    			<?php
    			    $image = $article['content'];
    			    $startPos = strpos($image, "<img");
    			    $endPos = strpos($image, "/>") + 2;
    			    $endPos = $endPos - $startPos;
    			    $image = substr($image, $startPos, $endPos);
    			    $newImage = substr_replace($image, "id='preview-img'", 5, 0);
    			    
    			    echo $newImage;
    			?>
			</a>
			<!--title and info-->
    			
			<!--Title-->
			<div id="title-div">
				<h2 id="art-title">
					<?php echo $article['title'];?>
				</h2>
			</div>
				
			<div id="info-div">
				<!--Info-->
				<img id="tiny-icon"src="images/author_icon.png"></img>
				<h4 id="info-text"> 
				<?php echo $article['author'];?>
				</h4>
					&nbsp
				<img id="tiny-icon"src="images/time_icon.png"></img>
				<h4 id="info-text">
					<?php echo $article['timestamp'];?>
				</h4>
			</div>
		</div>
			
		<?php } ?>			
	</div>	

</body>

</html>