<?php 
	require_once('partials/nav_with_dropdown.php');
?>

<html>

<meta name="viewport" content="width=device-width, initial-scale=1">

<link rel="stylesheet" href="fhp_test.css">
<title>CIFC</title>
</head>

<div id="top-banner">
		<h1 id="cifc-heading">Carolina Institute For Faith &amp Culture</h1>
</div>

<body>	

    <?php $author = $_GET['id'];?>

   
	<h2 style="font-family: 'Barlow Condensed'; margin-left: 1em; font-size: 2em;">Articles by <?php echo $author ?></h2>
	
	
	<!--Article Preview Holder-->
	<div id="all-article-view">
	
		<!--Get articles and sort by date added-->
	<?php
	
    	//Set up query to add data to table
    	$query = "SELECT id, title, content, author, DATE_FORMAT(timestamp, '%b %e, %Y %r') AS timestamp, category
        		  FROM Post
        		  WHERE is_live = 1 AND author = '$author'
        		  ORDER BY TIMESTAMP(timestamp) DESC";
    	
    	//Run query//Run query
    	$result = $conn->query($query);
	
		//Read results
		while($article = $result->fetch_assoc()) { 	
	?>	
	    <a href="fhp_view_article.php?id=<?php echo $article['id'];?>">
		<div id="article-preview-holder">	
			<!--image-->
			<!--<a href="fhp_view_article.php?id=<?php echo $article['id'];?>">-->
    			<?php
    			    $image = $article['content'];
    			    $startPos = strpos($image, "<img");
    			    $endPos = strpos($image, "/>") + 2;
    			    $endPos = $endPos - $startPos;
    			    $image = substr($image, $startPos, $endPos);
    			    $newImage = substr_replace($image, "id='preview-img'", 5, 0);
    			    
    			    echo $newImage;
    			?>
			<!--</a>-->
			<!--title and info-->
			
			<!--Title-->
			<div id="title-div">
				<h2 id="art-title">
					<?php echo $article['title'];?>
				</h2>
			</div>
				
			<div id="info-div">
				<!--Info-->
				<h4 id="info-text">Category: <?php echo $article['category'];?></h4><br>
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
		</a>

		<?php } ?>			
	</div>	


</body>

</html>