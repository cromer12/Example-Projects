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

function login_user(){

if(isset($_POST['submit'])){
/* User login process, checks if user exists and password is correct */

// Escape email to protect against SQL injections
$username = escape_string($_POST['username']);
$result = query("SELECT * FROM users WHERE username='$username'");

if ( $result->num_rows == 0 ){ // User doesn't exist
    $_SESSION['message'] = "User doesn't exist!";
} else { 
		// User exists
		$user = $result->fetch_assoc();

		if ( password_verify($_POST['password'], $user['userpass']) ) {
			
			$_SESSION['username'] = $user['username'];
			// This is how we'll know the user is logged in
			$_SESSION['logged_in'] = true;
			$_SESSION['permission'] = $user['userpermission'];
			$_SESSION['teamid'] = $user['userteamid'];
			redirect("dashboard.php");
		}
		else {
			echo "wrong username and pass";
		}
	}
}
}

function login_check(){
	if(!$_SESSION['logged_in']){
		redirect('index.php');
	}
}

function login_check_admin(){
	if(!$_SESSION['logged_in'] && $_SESSION['permission'] == 2){
		redirect('index.php');
	}
	return true;
}

//BACKEND FUNCTIONS START HERE

function admin_nav(){

	if($_SESSION[logged_in] == true)
	{

	$adminnav = <<< DELIMETER
        <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
            <!-- Brand and toggle get grouped for better mobile display -->
            <!-- Top Menu Items -->
            <ul class="nav navbar-right top-nav">
              <li class="dropdown">
                    <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-user" style="color:white;">$_SESSION[username]</i><b class="caret"></b></a>
                    <ul class="dropdown-menu">
                       
                        <li class="divider"></li>
                        <li>
                            <a href="logout.php"><i class="fa fa-fw fa-power-off"></i> Log Out</a>
                        </li>
                    </ul>
                </li>
            </ul>
        </nav>
DELIMETER;
		echo $adminnav;
	}
}

function get_admin(){

	$admin = <<< DELIMETER
	<div style="height: 5%"></div>
	<div class="container">
		<div class="row">
			<div class="col-md-12">
				<h2>Hello, {$_SESSION['username']}</h2>
			</div>
		</div>
		<hr>
		<div class="row">
			<div class="col-md-6">					
				<a class="btn btn-warning btn-large btn-block" href="user_list.php">User List</a>
				<a class="btn btn-warning btn-large btn-block mb-2" href="add_user.php">Create User</a>
				<a class="btn btn-warning btn-large btn-block mb-2" href="team_list.php">Team List</a>
				<a class="btn btn-warning btn-large btn-block mb-2" href="add_team.php">Create Team</a>
			</div>
			<div class="col-md-6">
				<a class="btn btn-success btn-large btn-block" href="team_select.php">Sports List & Create Sport</a>
				<a class="btn btn-success btn-large btn-block" href="game_list.php">Game List & Create Game</a>
			</div>
		</div>
	</div>
DELIMETER;

echo $admin;
}

function get_coach(){

	$editor = <<< DELIMETER
	<div style="height: 5%"></div>
	<div class="container">
		<div class="row">
			<div class="col-md-12">
				<h2>Hello, {$_SESSION['username']}</h2>
			</div>
		</div>
		<hr>
		<div class="row">
			<div class="col-md-12">
			<a class="btn btn-success btn-large btn-block" href="team_select.php">Sports List & Create Sport</a>
			<a class="btn btn-success btn-large btn-block" href="game_list.php">Game List & Create Game</a>
			</div>
		</div>
	</div>
DELIMETER;

echo $editor;
}

function get_assist(){
	redirect('games.php');
}

function get_users(){
	
	$query = query("SELECT * FROM users");
	  confirm($query);
	  while($row = fetch_array($query)) {

		if($row['userpermission'] == 2){
			$account = 'Admin';
		}elseif($row['userpermission'] == 1){
			$account =	'Coach';
		}elseif($row['userpermission'] == 0){
			$account =	'Assistant';
		}

$users = <<< DELIMETER

	<hr>
	  <div class="row">
	<div class="col-md-6">
		<h3>User: <em>{$row['username']}</em></h3> 
		<br>
		<br>
		<h4>Account Type: <em>{$account}</em></h4>
	</div>
	<div class="col-md-3 offset-md-3">
	<a class="btn btn-danger btn-block float-right" href="user_list.php?id={$row['userid']}">Delete User</a>
	</div>
	  </div>

	<hr>

					
DELIMETER;
echo $users;
	}
}

function get_teams_list(){
	$query = query("SELECT * FROM team");
	confirm($query);
	
	while($row = fetch_array($query)) {
		$teams = <<< DELIMETER

		<option value="{$row['teamid']}">{$row['teamname']}</option>
					
DELIMETER;
echo $teams;
	}
}

function get_teams(){
	$query = query("SELECT * FROM team");
	confirm($query);
	
	while($row = fetch_array($query)) {
	$team = <<< DELIMETER

	<hr>
	  <div class="row text-center">
	  	<div class="col-lg-4">
			<h2>{$row['teamname']}</h2>
			<a class="btn btn-primary btn-block float-right" href="team_update.php?id={$row['teamid']}">Update Team</a>
		</div>
		<div class="col-lg-4">
			<a href="team.php">
				<div class="card">
					<img class="card-img-top my-auto img-fluid" src="{$row['teamimg']}" alt="Team Image">
				</div>
			</a>
	  	</div>
		<div class="col-lg-4">
			<br><br>
			<a class="btn btn-danger btn-block float-right" href="team_list.php?id={$row['teamid']}">Delete Team</a>
		</div>
	  </div>

	<hr>

					
DELIMETER;
echo $team;
	}
}

function get_team_select(){
	$query = query("SELECT * FROM team");
	confirm($query);
	
	while($row = fetch_array($query)) {
	$team = <<< DELIMETER

	<hr>
	  <div class="row text-center">
	  	<div class="col-lg-4">
			<h2>{$row['teamname']}</h2>
		</div>
		<div class="col-lg-4">
			<a href="team.php">
				<div class="card">
					<img class="card-img-top my-auto img-fluid" src="{$row['teamimg']}" alt="Team Image">
				</div>
			</a>
	  	</div>
		<div class="col-lg-4">
			<br><br>
			<a class="btn btn-primary btn-block float-right" href="sport_list.php?id={$row['teamid']}">Select Team</a>
		</div>
	  </div>

	<hr>

					
DELIMETER;
echo $team;
	}
}

function get_sports_co($id){
	$query = query("SELECT * FROM sportsco WHERE teamid = '$id'");
	confirm($query);
	$team = NULL;

	while($row = fetch_array($query)) {
	$team = <<< DELIMETER

	<hr>
	  <div class="row text-center">
	  	<div class="col-lg-6">
			<h2>CoEd</h2>
			<a class="btn btn-primary btn-block float-right" href="team_update.php?id={$row['teamid']}">Update Sport</a>
		</div>
		<div class="col-lg-6">
			<h2>{$row['sportname']}</h2>
			<a class="btn btn-danger btn-block float-right" href="team_list.php?id={$row['sportid']}">Delete Sport</a>
		</div>
	  </div>

	<hr>

					
DELIMETER;
echo $team;
	}
	if($team == NULL){
		echo "<div class=\"text-center\"><h2>No Sports Listed</h2></div>";
	}
}

function get_sports_women($id){
	$query = query("SELECT * FROM sportswomen WHERE teamid = '$id'");
	confirm($query);
	$team = NULL;

	while($row = fetch_array($query)) {
	$team = <<< DELIMETER

	<hr>
	  <div class="row text-center">
	  	<div class="col-lg-6">
			<h2>Women: </h2>
			<a class="btn btn-primary btn-block float-right" href="team_update.php?id={$row['teamid']}">Update Sport</a>
		</div>
		<div class="col-lg-6">
			<h2>{$row['sportname']}</h2>
			<a class="btn btn-danger btn-block float-right" href="team_list.php?id={$row['sportid']}">Delete Sport</a>
		</div>
	  </div>

	<hr>
					
DELIMETER;
echo $team;
	}
	if($team == NULL){
		echo "<div class=\"text-center\"><h2>No Sports Listed</h2></div>";
	}
	
}


function get_sports_men($id){
	$query = query("SELECT * FROM sportsmen WHERE teamid = '$id'");
	confirm($query);
	$team = NULL;

	while($row = fetch_array($query)) {
	$team = <<< DELIMETER

	<hr>
	  <div class="row text-center">
	  	<div class="col-lg-6">
			<h2>Men: </h2>
			<a class="btn btn-primary btn-block float-right" href="team_update.php?id={$row['teamid']}">Update Sport</a>
		</div>
		<div class="col-lg-6">
			<h2>{$row['sportname']}</h2>
			<a class="btn btn-danger btn-block float-right" href="team_list.php?id={$row['sportid']}">Delete Sport</a>
		</div>
	  </div>

	<hr>

					
DELIMETER;
echo $team;
	}
	if($team == NULL){
		echo "<div class=\"text-center\"><h2>No Sports Listed</h2></div>";
	}

}
?>