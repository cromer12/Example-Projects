<?php

/*
*Name: Cameron Cromer
*Date: Nov. 19, 2017
*Purpose: all functions for the site
*/

//BEGIN helper functions
function set_message($msg){
	if(!empty($msg)){
		$_SESSION['message'] = $msg;
	} else{
		$msg = "";
	}
}

function display_message(){
	if (isset($_SESSION['message'])) {
		echo $_SESSION['message'];
		unset($_SESSION['message']);
	}
}

function redirect($location){
	header("Location: $location");
}

function query($sql){
	global $conn;
	return mysqli_query($conn, $sql);
}

function confirm($result){

	global $conn;

	if (!$result) {
		die("QUERY FAILED " . mysqli_error($conn));
	}
}


function escape_string($string){

	global $conn;

	return mysqli_real_escape_string($conn, $string);
}

function fetch_array($result){

	return mysqli_fetch_array($result);
}
//END helper functions


//BEGIN LIST FUNCTIONS
//BEGIN fhp_article_list.php
function get_article(){
	
	//only shows authors articles
	if($_SESSION['account'] == "author") 
	{
		$fname = $_SESSION['firstname'];
		$lname = $_SESSION['lastname'];
		$name  = $fname . ' ' . $lname;
		$query = query("SELECT * FROM Post WHERE author = '$name'");
	  	confirm($query);	
	}else{
		$query = query("SELECT * FROM Post ORDER BY timestamp DESC");
	  	confirm($query);
	}
  	//checks to see if admin or editor is logged in
if($_SESSION['account'] == "editor" || $_SESSION['account'] == "admin"){
	  	while($row = fetch_array($query)) {
	  		//if it is not live it shows inactive, and if is live shows active
	  		if($row['is_live'] == 0){
		
$category = <<< DELIMETER

		<hr>
      	<div class="row">
    	<div class="col-md-8">
          <h2>{$row['title']}</h2>
          <!--<p style="font-size: 20px">{$row['content']}</p>-->
          <br>
          <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['author']}</em>, {$row['timestamp']}
          </div>
        </div>
		<div class="col-lg-2">
			<h3><em>Category:</em></h3> {$row['category']}
			<br>
			<br>
			<a class="btn btn-danger" href="fhp_article_list.php?id={$row['id']}&active=2">Delete</a>
		</div>
		<div class="col-lg-2">
			<a class="btn btn-success btn-lg  my-4" href="fhp_article_list.php?id={$row['id']}&active=1">Click to Publish</a>
			<a class="btn btn-primary btn-lg  my-4" href="fhp_edit_article.php?id={$row['id']}">Edit / View Article</a>
		</div>
      	</div>

	    <hr>

						
DELIMETER;
}else{
$category = <<< DELIMETER

		<hr>
      	<div class="row">
    	<div class="col-md-8">
          <h2>{$row['title']}</h2>
          <!--<p style="font-size: 20px">{$row['content']}</p>-->
          <br>
          <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['author']}</em>, {$row['timestamp']}
          </div>
        </div>
		<div class="col-lg-2">
			<h3><em>Category:</em></h3> {$row['category']}
		</div>
		<div class="col-lg-2">
			<a class="btn btn-danger btn-lg  my-4" href="fhp_article_list.php?id={$row['id']}&active=0">Click to Unpublish</a>
			<a class="btn btn-primary btn-lg  my-4" href="fhp_edit_article.php?id={$row['id']}">Edit / View Article</a>
		</div>
      	</div>

	    <hr>

						
DELIMETER;
}
	echo $category;

	}
}else{
	//this is author display, which does not show the active/inactive button
  	while($row = fetch_array($query)) {

		
$category = <<< DELIMETER

		<hr>
      	<div class="row">
    	<div class="col-md-8">
          <h2>{$row['title']}</h2>
          <p style="font-size: 20px">{$row['content']}</p>
          <br>
          <div style="position: absolute; bottom: 0; left: 10;"><em>{$row['author']}</em>, {$row['timestamp']}
          </div>
        </div>
		<div class="col-lg-4">
			<h3><em>Category:</em></h3> {$row['category']}
			<a class="btn btn-primary btn-lg float-right my-4" href="fhp_edit_article.php?id={$row['id']}">Edit Article</a>
		</div>
      	</div>

	    <hr>

						
DELIMETER;
	
	echo $category;

	}
}
}
//END fhp_article_list.php

//BEGIN fhp_category_list.php
function get_category_list(){
		//outputs categories to be deleted
		$query = query("SELECT * FROM Categories");
	  	confirm($query);

  	//checks to see if admin or editor is logged in
	  	while($row = fetch_array($query)) {
		
$category = <<< DELIMETER

		<hr>
      	<div class="row">
    	<div class="col-md-6">
			<h3>Category: <em>{$row['name']}</em></h3> 
			<br>
			<br>
			
        </div>
		<div class="col-md-2 offset-md-4">
		<a class="btn btn-danger btn-block float-right" href="fhp_category_list.php?id={$row['id']}&active=2">Delete</a>
		</div>
      	</div>

	    <hr>

						
DELIMETER;
	echo $category;

	}
}
//END fhp_category_list.php

//BEGIN fhp_add_article.php
function get_category(){

	//gets list of categories to select on article creation

	$query = query("SELECT * FROM Categories");
  	confirm($query);

  	while($row = fetch_array($query)) {

//submitbutton is given the value of the row. do ifs on page to check
		
$category = <<< DELIMETER

<option value="{$row['name']}">{$row['name']}</option>
						
DELIMETER;
	
	echo $category;

	}
}
//END fhp_add_article.php


//BEGIN fhp_edit_article.php
function get_category_edit($name){

	//gets list of categories with the active category selected first on edit page

	$query = query("SELECT * FROM Categories WHERE name = '$name'");
  	confirm($query);

	$row = fetch_array($query);
		
$category = <<< DELIMETER

<option value="{$row['name']}">{$row['name']}</option>
						
DELIMETER;
	
	echo $category;

//****************ABOVE IS TO OUTPUT ACTIVE ARTICLE FIRST*********************//

	//this removes the first output from the list on print
	$query = query("SELECT * FROM Categories");
  	confirm($query);

  	while($row = fetch_array($query)) {
		if($row['name'] != $name){
$category = <<< DELIMETER

<option value="{$row['name']}">{$row['name']}</option>
						
DELIMETER;
	
	echo $category;
}
	}
}

function get_article_edit($id){

	//receieves ID from page to select correct article from database

    $query = query("SELECT * FROM Post WHERE id = '$id'");
    confirm($query);
    $results = fetch_array($query);

    $article = <<< DELIMETER
	    <h3 style="font-weight: normal" >Article Title:</h3>
        <input name="arttitle" id="add-form-input" value="{$results['title']}"></input>
      <br>
	    <h3 style="font-weight: normal">Content:</h3>
      <textarea name="artcontent" class="tinymce-300">{$results['content']}</textarea>
DELIMETER;
	
	echo $article;
}

function get_author_edit($id) {
    
    //receieves ID from page to select correct author from database

    $query = query("SELECT author FROM Post WHERE id = '$id'");
    confirm($query);
    $results = fetch_array($query);
    
	echo "<h3 style='font-weight: normal'>Author:</h3>";
	echo "<input name='artauthor' id='add-form-input' value='" . $results['author'] . "'></input>";
  	echo "<br>";
    
}
//END fhp_edit_article.php


//BEGIN fhp_user_list.php
function get_users(){
	
		$query = query("SELECT * FROM Users");
	  	confirm($query);

  	//checks to see if admin or editor is logged in
	  	while($row = fetch_array($query)) {
		
$users = <<< DELIMETER

		<hr>
      	<div class="row">
    	<div class="col-md-6">
			<h3>User: <em>{$row['first_name']} {$row['last_name']}</em></h3> 
			<br>
			<br>
			<h4>Account Type: <em>{$row['account_type']}</em></h4>
        </div>
		<div class="col-md-3 offset-md-3">
		<a class="btn btn-danger btn-block float-right" href="fhp_user_list.php?id={$row['Id']}&active=2">Delete User</a>
		</div>
      	</div>

	    <hr>

						
DELIMETER;
	echo $users;

	}
}
//END fhp_user_list.php

//END LIST FUNCTIONS



//dashboard.php//
function get_admin(){

	    $admin = <<< DELIMETER
		<div style="height: 5%"></div>
		<div class="container">
			<div class="row">
				<div class="col-md-12">
					<h2>Hello, {$_SESSION['firstname']} ({$_SESSION['account']})</h2>
				</div>
			</div>
			<hr>
			<div class="row">
				<div class="col-md-4">					
					<a class="btn btn-warning btn-large btn-block" href="fhp_user_list.php">User List</a>
					<a class="btn btn-warning btn-large btn-block mb-2" href="fhp_add_user.php">Create User</a>
				</div>
				<div class="col-md-4">
					<a class="btn btn-success btn-large btn-block" href="fhp_article_list.php">Article List</a>
					<a class="btn btn-success btn-large btn-block mb-2" href="fhp_add_article.php">Create Article</a>
				</div>
				<div class="col-md-4">		
                    <a class="btn btn-primary btn-large btn-block" href="fhp_category_list.php">Category List</a>
					<a class="btn btn-primary btn-large btn-block mb-2" href="fhp_add_category.php">Create Category</a>
				</div>
			</div>
		</div>
DELIMETER;
	
	echo $admin;
}

function get_editor(){

	    $editor = <<< DELIMETER
		<div style="height: 5%"></div>
		<div class="container">
			<div class="row">
				<div class="col-md-12">
					<h2>Hello, {$_SESSION['firstname']} ({$_SESSION['account']})</h2>
				</div>
			</div>
			<hr>
			<div class="row">
				<div class="col-md-3 offset-md-2">
					<a class="btn btn-success btn-large btn-block" href="fhp_article_list.php">Article List</a>
					<a class="btn btn-success btn-large btn-block mb-2" href="fhp_category_list.php">Category List</a>
				</div>
				<div class="col-md-3 offset-md-2">
					<a class="btn btn-primary btn-large btn-block" href="fhp_add_article.php">Create Article</a>
					<a class="btn btn-primary btn-large btn-block mb-2" href="fhp_add_category.php">Create Category</a>
				</div>
			</div>
		</div>
DELIMETER;
	
	echo $editor;
}

function get_author(){

	    $admin = <<< DELIMETER
		<div style="height: 5%"></div>
		<div class="container">
			<div class="row">
				<div class="col-md-12">
					<h2>Hello, {$_SESSION['firstname']} ({$_SESSION['account']})</h2>
				</div>
			</div>
			<hr>
			<div class="row">
				<div class="col-md-3 offset-md-2">
					<a class="btn btn-success btn-large btn-block" href="fhp_article_list.php">Article List</a>
				</div>
				<div class="col-md-3 offset-md-2">
					<a class="btn btn-primary btn-large btn-block mb-2" href="fhp_add_article.php">Create Article</a>
				</div>
			</div>
		</div>
DELIMETER;
	
	echo $admin;
}
//dashboard.php//
?>