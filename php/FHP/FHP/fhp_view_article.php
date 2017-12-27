<?php 
	require_once('partials/nav_with_dropdown.php');
	require_once('connect.php');
?>

<html>

<meta name="viewport" content="width=device-width, initial-scale=1">

<link rel="stylesheet" href="fhp_test.css">
<link rel="stylesheet" href="bootstrap.min.css">
<title>CIFC</title>
</head>

<body>
    <?php
        $id = $_GET['id'];
        
        //Set up query
    	$query = "SELECT id, title, content, author,  DATE_FORMAT(timestamp, '%b %e, %Y') AS timestamp
        		  FROM Post
        		  WHERE id='" . $id . "'";
    	
    	//Run query
    	$result = $conn->query($query);
	
		//Read results
		$article = $result->fetch_assoc();
    ?>
    <br>
    <?php
        $image = $article['content'];
        $startPos = strpos($image, "<img");
        $endPos = strpos($image, "/>") + 2;
        $endPos = $endPos - $startPos;
        $image = substr($image, $startPos, $endPos);
        $article['content'] = str_replace($image, "",$article['content']);
     ?>
    
    <br>
    <div class="container">
        <!-- Title -->
        <div class="row">
            <div class="col-md-12">
                    <center><h2 style="font-family: 'Barlow Condensed', arial; font-size: 2.5em;"><?php echo $article['title']?></h2></center>
            </div>
        </div>
        <br>
         <!-- Author and Date -->
        <div class="row">
            <div class="col-md-12">
                <!--Info-->
                
                <!--Author-->
                <a id="author-link" href="fhp_institute_author.php? id=<?php echo $article['author'];?>">
    				<img id="tiny-icon"src="images/author_icon.png"></img>
    				<h4  style="font-size: .8em" id="info-text"> 
    				<?php echo $article['author'];?>
    				</h4>
				</a>
				
				
					&nbsp
				<!--Date-->
				<img id="tiny-icon"src="images/time_icon.png"></img>
				<h4 style="font-size: .8em" id="info-text">
					<?php echo $article['timestamp'];?>
				</h4>
            </div>
        </div>
        <hr>
        <br>
        <!-- Content -->
        <div class="row">
            <div style="text-align: center" class="col-md-12">
                <?php echo $article['content']?>
            </div>
        </div>
        <br>
    </div>
</body>

</html>