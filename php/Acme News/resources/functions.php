<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<?php

// helper functions


function set_message($msg){

	if(!empty($msg)){

		$_SESSION['message'] = $msg;

	} else{
		$msg = "";
	}


}


function display_message(){

	if(isset($_SESSION['message'])){

		echo $_SESSION['message'];
		unset($_SESSION['message']);

	}

}



function redirect($location){

	header("Location: $location");


}

function query($sql){

	global $connection;

	return mysqli_query($connection, $sql);

}


function confirm($result){

	global $connection;

	if(!$result){

		die("QUERY FAILED " . mysqli_error($connection));
	}

}


function escape_string($string){

	global $connection;

	return mysqli_real_escape_string($connection, $string);
}

function fetch_array($result){

	return mysqli_fetch_array($result);
}


//FRONT END FUNCTIONS START HERE

//summary function
function character_limiter($str, $n = 500, $end_char = '&#8230;')
{
    if (strlen($str) < $n)
    {
        return $str;
    }

    $str = preg_replace("/\s+/", ' ', str_replace(array("\r\n", "\r", "\n"), ' ', $str));

    if (strlen($str) <= $n)
    {
        return $str;
    }

    $out = "";
    foreach (explode(' ', trim($str)) as $val)
    {
        $out .= $val.' ';

        if (strlen($out) >= $n)
        {
            $out = trim($out);
            return (strlen($out) == strlen($str)) ? $out : $out.$end_char;
        }
    }
 }

//display home
function get_home(){

	$query = query("SELECT * FROM articles ORDER BY arttimestamp DESC");
	confirm($query);

	while ($row = fetch_array($query)) {

		if($row['artactive'] == 1)
		{
			$summary = character_limiter($row['artcontent'], 200);

	//heredoc
$home = <<<DELIMETER

      	<div class="row">
        <div class="col-md-7">
          <a href="{$row['artimage']}">
            <img class="img-fluid rounded mb-3 mb-md-0" src="{$row['artimage']}" alt="">
          </a>
          <br>
          <br>
            <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['artcontact']}</em>, {$row['arttimestamp']}</div>
        </div>
    	<div class="col-md-5">
          <h3>{$row['arttitle']}</h3>
          <p><em>SUMMARY</em>: {$summary}</p>
          <a class="btn btn-primary" href="article.php?id={$row['artid']}">View Full Article</a>
        </div>
      	</div>

	    <hr>


DELIMETER;
	
	echo $home;
}

	}
}

//dislpay full article
function get_article(){

	$id = escape_string($_GET['id']);
	$query = query("SELECT * FROM articles WHERE artid='$id'");
	confirm($query);
	$row = fetch_array($query);

		if($row['artactive'] == 1)
		{

	//heredoc
$art = <<<DELIMETER
		
		<hr>
      	<div class="row">
        <div class="col-md-7">
          <a href="{$row['artimage']}">
            <img class="img-fluid rounded mb-3 mb-md-0" src="{$row['artimage']}" alt="">
          </a>
          <br>
          <br>
            <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['artcontact']}</em>, {$row['arttimestamp']}</div>
        </div>
    	<div class="col-md-5">
          <h2>{$row['arttitle']}</h3>
          <p style="font-size: 20px">{$row['artcontent']}</p>
        </div>
      	</div>

	    <hr>


DELIMETER;
	
	echo $art;


	}
}

//display list of articles and allows edits
function get_list(){

	$query = query("SELECT * FROM articles ORDER BY arttimestamp DESC");
	confirm($query);

	while ($row = fetch_array($query)) {

		if($row['artactive'] == 1) //check to see if the article is active
		{
			$summary = character_limiter($row['artcontent'], 200);

	//heredoc
$list = <<<DELIMETER

      	<div class="row">
        <div class="col-md-7">
          <a href="{$row['artimage']}">
            <img class="img-fluid rounded mb-3 mb-md-0" src="{$row['artimage']}" alt="">
          </a>
          <br>
          <br>
            <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['artcontact']}</em>, {$row['arttimestamp']}</div>
        </div>
    	<div class="col-md-5">
          <h3>{$row['arttitle']}</h3>
          <p><em>SUMMARY</em>: {$summary}</p>
          <a class="btn btn-primary" href="edit.php?id={$row['artid']}">Edit</a>
          <a class="btn btn-success" href="list.php?id={$row['artid']}&active=0">Active</a>
        </div>
      	</div>

	    <hr>


DELIMETER;
	
	echo $list;
}else{
		//heredoc
$list = <<<DELIMETER
		
		<div class="row">
      	<div class="col-md-12">
      	<h2 style="text-align: center; color: red">Not Active</h2>
      	</div>
		</div>
      	<div class="row">
        <div class="col-md-7">
          <a href="{$row['artimage']}">
            <img class="img-fluid rounded mb-3 mb-md-0" src="{$row['artimage']}" alt="">
          </a>
          <br>
          <br>
            <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['artcontact']}</em>, {$row['arttimestamp']}</div>
        </div>
    	<div class="col-md-5">
          <h3>{$row['arttitle']}</h3>
          <a class="btn btn-primary" href="edit.php?id={$row['artid']}">Edit</a>
          <a class="btn btn-warning" href="list.php?id={$row['artid']}&active=1">Active</a>
          <a class="btn btn-danger float-right" href="list.php?id={$row['artid']}&active=2">Delete</a>
        </div>
      	</div>

	    <hr>


DELIMETER;
	
	echo $list;
}

	}
}


//dislpay The editing area
function get_edit(){

	$id = escape_string($_GET['id']);
	$query = query("SELECT * FROM articles WHERE artid='$id'");
	confirm($query);
	$row = fetch_array($query);

	//heredoc
$edit = <<<DELIMETER
		
		<hr>
		<form action="" method="post">
      	<div class="row">
        <div class="col-md-7">
        <h3>Image Link</h3>
      	<textarea name="editimage" rows="3" cols="75">{$row['artimage']}</textarea>
            <img class="img-fluid rounded mb-3 mb-md-0" src="{$row['artimage']}" alt="">
          <br>
          <br>
          <br>
            <div style="position: absolute; bottom: 0; left: 10;"><em><textarea name="editcontact" rows="1" cols="35">{$row['artcontact']}</textarea></em></div>
        </div>
    	<div class="col-md-5">
          <h3>Title: <textarea name="edittitle" rows="1" cols="54">{$row['arttitle']}</textarea></h3>
          <h3>Body:</h3>
          <textarea name="editcontent" rows="6" cols="100">{$row['artcontent']}</textarea>
          <button class="btn btn-primary" type="submit" name="submit" style="color:white">Submit</button>
        </div>
      	</div>
      	</form>
      	<hr>

DELIMETER;
	
	echo $edit;

}


//adds new article
function get_add(){

	//heredoc
$add = <<<DELIMETER
		
		<hr>
		<form action="" method="post">
      	<div class="row">
        <div class="col-md-12">
	    <h3>Title: </h3>
	    <textarea name="edittitle" rows="1" cols="100"></textarea>
	    <br>
	    <h3>Body:</h3>
	    <textarea name="editcontent" rows="6" cols="100"></textarea>
        <h3>Image Link</h3>
      	<textarea name="editimage" rows="3" cols="100"></textarea>
	    <br>
	    <h3>Author:</h3>
	    <textarea name="editcontact" rows="1" cols="100"></textarea>
	    <br>
	    <br>
	    <button class="btn btn-primary" type="submit" name="submit" style="color:white">Add New</button>
	    </div>
      	</div>
      	</form>
      	<hr>

DELIMETER;
	
	echo $add;

}


function login_user(){

if(isset($_POST['submit'])){
/* User login process, checks if user exists and password is correct */

// Escape email to protect against SQL injections
$username = escape_string($_POST['username']);
$result = query("SELECT * FROM users WHERE username='$username'");

if ( $result->num_rows == 0 ){ // User doesn't exist
    $_SESSION['message'] = "User doesn't exist!";
	}
else { // User exists
    $user = $result->fetch_assoc();

    if ( password_verify($_POST['password'], $user['userpass']) ) {
        
        $_SESSION['username'] = $user['username'];
        // This is how we'll know the user is logged in
        $_SESSION['logged_in'] = true;
        echo "
        <script>
        window.location.href =\"https://cameroncromer.000webhostapp.com/project5/list.php\"
        </script>
        ";
    }
    else {
        echo "wrong username and pass";
    }
	}
}
}


?>

