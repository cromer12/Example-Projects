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

  echo '<script>window.location="'.$location.'"</script>';
	//header("Location: $location");
  exit();

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

function get_dashboard(){

  if($_SESSION['permission'] == 1){
    $title = "Professor";
  }else{
    $title = "Student";
  }

  echo $title . " " . $_SESSION['username'];
}

//lists students on teacher's admin page
function get_students(){

  $id = $_SESSION['id'];
  $query = query("SELECT * FROM student WHERE teacherid='$id'");
  confirm($query);
  $row = fetch_array($query);


  //weird fix to grab first student.
  $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$row['fname']}</h3>
      </div>
      <div class="col-md-6">
      <a class="btn btn-danger float-left" style="margin-left: 20%" href="assign.php?id={$row['studentid']}">Assign Test</a> 
        <a class="btn btn-primary float-right" href="grades.php?id={$row['studentid']}">View Grades</a>  
      </div>
        </div>
      <hr>


DELIMETER;

echo $string;


//outputs all students
while ($row = fetch_array($query)) {

  //heredoc
$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$row['fname']}</h3>
      </div>
      <div class="col-md-6">
      <a class="btn btn-danger float-left" style="margin-left: 20%" href="assign.php?id={$row['studentid']}">Assign Test</a> 
        <a class="btn btn-primary float-right" href="grades.php?id={$row['studentid']}">View Grades</a>  
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
}

}

//prints quizes for students
function get_quizes(){

  $id = $_SESSION['id'];
  $query = query("SELECT * FROM take WHERE studentid='$id'");
  confirm($query);
  $row = fetch_array($query);
  
  //pulls test name from test table
  $testid = $row['testid'];

  $testq = query("SELECT * FROM test WHERE testid='$testid'");
  confirm($testq);
  $test = fetch_array($testq);

  if ($row == NULL && $test == NULL) {
    return 0;
  }


  // checks if the test has been taken
  if($row['taken'] == 0){

  //weird fix to grab first student.
  $string = <<<DELIMETER

      <div class="row">
      <div class="container">
      <div class="col-md-12">
      <h2 class="my-4" style="text-align: center"><b>Assignments:</b></h2>
      </div>
      </div>
      </div>
      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$test['testname']}</h3>
      </div>
      <div class="col-md-6">
      <a class="btn btn-danger float-right" style="margin-left: 20%" href="take.php?id={$row['testid']}">Take Test</a> 
      </div>
        </div>
      <hr>


DELIMETER;

echo $string;

}else{

  $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$test['testname']}</h3>
      </div>
      <div class="col-md-6">
      <a class="btn btn-success float-right" style="margin-left: 20%">Completed</a> 
      </div>
        </div>
      <hr>


DELIMETER;

echo $string;

}

//outputs all students
while ($row = fetch_array($query)) {

  $testid = $row['testid'];

  $testq = query("SELECT * FROM test WHERE testid='$testid'");
  confirm($testq);
  $test = fetch_array($testq);

  // checks if the test has been taken
  if($row['taken'] == 0){
  //heredoc
$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$test['testname']}</h3>
      </div>
      <div class="col-md-6">
      <a class="btn btn-danger float-right" style="margin-left: 20%" href="take.php?id={$row['testid']}">Take Test</a> 
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
  }else{

$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$test['testname']}</h3>
      </div>
      <div class="col-md-6">
      <a class="btn btn-success float-right" style="margin-left: 20%" >Completed</a> 
      </div>
        </div>
      <hr>


DELIMETER;

echo $string;
  }
}


}

//displays all grades for a student
function get_grades(){

  //comes from link in get_students()
  $id = escape_string($_GET['id']);
  $query = query("SELECT * FROM grade g, test t, student s, take WHERE g.studentid='$id' AND g.testid=t.testid AND s.studentid='$id' AND take.studentid = '$id' AND take.testid = g.testid");
  confirm($query);
  $row = fetch_array($query);

  //checks to see if the student has any quiz assigned
  if(!$row){

  $query = query("SELECT * FROM student WHERE studentid='$id'");
  confirm($query);
  $row = fetch_array($query);

  $string = <<<DELIMETER
          <div class="row">
        <div class="col-md-12">
          <h2 class="my-4" style="text-align: center">{$row['fname']} Has No Quiz Assigned</h2>
        </div>
      </div>
DELIMETER;
    echo $string;
    return 0;
  }

  //if the quiz is taken, it outputs this
  if($row['taken'] == 1){

  $string = <<<DELIMETER

      <div class="row">
        <div class="col-md-12">
          <h2 class="my-4" style="text-align: center">{$row['fname']}</h2>
        </div>
      </div>
      <div class="row">
       <div class="col-md-6">
          <h2 class="my-4" style="padding-bottom:">Assignment</h2>
        </div>
       <div class="col-md-6">
          <h2 class="my-4 float-right">Grade</h2>
        </div>
      </div>


      <hr>
      <div class="row">
        <div class="col-md-6">
          <h4>{$row['testname']}</h4>
        </div>
        <div class="col-md-6">
          <h4 class="float-right" style="padding-right: 10px;">{$row['grade']}%</h4>
        </div>
      </div>
      <hr>

DELIMETER;

echo $string;
}else{  //otherwise it outputs this

  $string = <<<DELIMETER

      <div class="row">
        <div class="col-md-12">
          <h2 class="my-4" style="text-align: center">{$row['fname']}</h2>
        </div>
      </div>
      <div class="row">
       <div class="col-md-6">
          <h2 class="my-4" style="padding-bottom:">Assignment</h2>
        </div>
       <div class="col-md-6">
          <h2 class="my-4 float-right">Grade</h2>
        </div>
      </div>


      <hr>
      <div class="row">
        <div class="col-md-4">
          <h4>{$row['testname']}</h4>
        </div>
        <div class="col-md-4">
          <h4 class="float-right" style="color: red">Test Not Taken</h4>
        </div>
        <div class="col-md-4">
          <h4 class="float-right" style="padding-right: 10px;">{$row['grade']}%</h4>
        </div>
      </div>
      <hr>

DELIMETER;

echo $string;
}

//outputs all grades of studentid
while ($row = fetch_array($query)) {

  if($row['taken'] == 1){   //has taken

  $string = <<<DELIMETER

      <hr>
      <div class="row">
        <div class="col-md-6">
          <h4>{$row['testname']}</h4>
        </div>
        <div class="col-md-6">
          <h4 class="float-right" style="padding-right: 10px;">{$row['grade']}%</h4>
        </div>
      </div>
      <hr>

DELIMETER;

echo $string;
}else{    //has not taken.

  $string = <<<DELIMETER

      <hr>
      <div class="row">
        <div class="col-md-4">
          <h4>{$row['testname']}</h4>
        </div>
        <div class="col-md-4">
          <h4 class="float-right" style="color: red">Test Not Taken</h4>
        </div>
        <div class="col-md-4">
          <h4 class="float-right" style="padding-right: 10px;">{$row['grade']}%</h4>
        </div>
      </div>
      <hr>

DELIMETER;

echo $string;
}
}

}


//adds new mc question template
function get_create(){

	//heredoc
$create = <<<DELIMETER
		
		<hr>
		<form action="" method="post">
      	<div class="row">
        <div class="col-md-12">
        <h3>Test Name:</h3>
        <textarea name="testname" rows="1" cols="100" required></textarea>
      <br>
	    <h3>How Many Mutiple Choice Questions: </h3>
      <input type="number" name="numbermc" id="numbermc" min="0" required/>
	    <br>
      <h3>How Many True False Questions: </h3>
      <input type="number" name="numbertf" id="numbertf" min="0" required/>
	    <br>
	    <br>
	    <button class="btn btn-primary" type="submit" name="submit" style="color:white">Create Test</button>
	    </div>
      	</div>
      	</form>
      	<hr>

DELIMETER;
	
	echo $create;

}

function create_mc($number){

$i = 0;
$question = 1;
if($number == 0)
{
  redirect('questiontf.php');
}
while($i < $number)
{
$createmc = <<<DELIMETER

    <hr>
        <div class="row">
        <div class="col-md-12">
        <h3>Multiple Choice Question {$question}:</h3>
        <textarea name="question{$i}" rows="1" cols="100" required></textarea>
      <br>
        <h3>Choice 1:</h3>
        <textarea name="choice1{$i}" rows="1" cols="100" required></textarea>
      <br>

     <h3>Choice 2:</h3>
        <textarea name="choice2{$i}" rows="1" cols="100" required></textarea>
      <br>

      <h3>Choice 3:</h3>
        <textarea name="choice3{$i}" rows="1" cols="100" required></textarea>
      <br>

        <h3>Choice 4:</h3>
        <textarea name="choice4{$i}" rows="1" cols="100" required></textarea>
      <br>

      <h3>Answer(Input Number): </h3>
      <input type="number" name="answermc{$i}" id="answermc{$i}" min="1" max="4" required/>
      <br>
      <br>
      
      </div>
        </div>
        <hr>

DELIMETER;
  
  echo $createmc;
  $i++;
  $question++;
}
}

function create_tf($number){

$i = 0;
$question = 1;
while($i < $number)
{
$createtf = <<<DELIMETER
    
    <hr>
        <div class="row">
        <div class="col-md-12">
        <h3>True/False Question {$question}:</h3>
        <textarea name="question{$i}" id="question{$i}" rows="1" cols="100" required></textarea>
      <br>

      <h3>Answer: </h3>
      <input type="radio" name="answer{$i}" id="answer{$i}" value="1" required/> True<br>
      <input type="radio" name="answer{$i}" id="answer{$i}" value="0"/> False<br>
      <br>
      <br>
      </div>
        </div>
        <hr>

DELIMETER;
  
  echo $createtf;
  $i++;
  $question++;
}

}

//lists all test to assgin them to students
function get_assign(){

  $id = $_SESSION['id'];
  $query = query("SELECT * FROM test WHERE teacherid='$id'");
  confirm($query);
  $row = fetch_array($query);


  //weird fix to grab first student.
  $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$row['testname']}</h3>
      </div>
      <div class="col-md-6">
        <button class="btn btn-primary float-right" name="submit" type="submit" value="{$row['testid']}" >Assign</button>  
      </div>
        </div>
      <hr>


DELIMETER;

echo $string;


//outputs all students
while ($row = fetch_array($query)) {

  //heredoc
$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>{$row['testname']}</h3>
      </div>
      <div class="col-md-6">
        <button class="btn btn-primary float-right" name="submit" type="submit" value="{$row['testid']}">Assign</button>  
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
}

}


function takes(){

  $id = $_GET['id'];
  //gets mcquestions
  $qmc = query("SELECT * FROM questionmc WHERE testid='$id'");
  confirm($qmc);

  //gets tf questions
  $qtf = query("SELECT * FROM questiontf WHERE testid='$id'");
  confirm($qtf);

  $i = 1;
//output mc first
 while ($mc = fetch_array($qmc)) {

  //heredoc
$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>Question {$i}:</h3>
        <p>{$mc['questionmc']}</p>
      </div>
      <div class="col-md-6">
          <input type="radio" name="mc{$i}" value="1" required> {$mc['choice1']}<br>
          <input type="radio" name="mc{$i}" value="2" required> {$mc['choice2']}<br>
          <input type="radio" name="mc{$i}" value="3" required> {$mc['choice3']}<br>
          <input type="radio" name="mc{$i}" value="4" required> {$mc['choice4']}
      </div>
        </div>
      <hr>


DELIMETER;
  $i++;
  echo $string;
}

//then output tf
while ($tf = fetch_array($qtf)) {

  //heredoc
$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>Question {$i}:</h3>
        <p>{$tf['questiontf']}</p>
      </div>
      <div class="col-md-6">
          <input type="radio" name="tf{$i}" value="1" required>True<br>
          <input type="radio" name="tf{$i}" value="0" required>False<br>
      </div>
        </div>
      <hr>


DELIMETER;
  
  $i++;
  echo $string;
}

$_SESSION['testid'] = $id;
}


//grade function

function grade(){

  $id = $_SESSION['testid'];
  //gets mcquestions
  $qmc = query("SELECT * FROM questionmc WHERE testid='$id'");
  confirm($qmc);

  //gets tf questions
  $qtf = query("SELECT * FROM questiontf WHERE testid='$id'");
  confirm($qtf);

  $i = 1;
  $right = 0;
  $wrong = 0;


  //post mc out
 while ($mc = fetch_array($qmc)) {

  if($_POST['mc'.$i] == $mc['answer']){

  $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>Question {$i}:</h3>
        <p>{$mc['questionmc']}</p>
      </div>
      <div class="col-md-6">
          <a class="btn btn-lg btn-success float-right" disabled style="color: white">Correct</a>
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
  $right++;
  }else{

  $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>Question {$i}:</h3>
        <p>{$mc['questionmc']}</p>
      </div>
      <div class="col-md-6">
          <a class="btn btn-lg btn-danger float-right" disabled style="color: white">Incorrect</a>
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
  $wrong++;
  }
 
 $i++;
 }

  //may neeed to look back at this ////////////////////////////////////////
 while ($tf = fetch_array($qtf)) {

  if($_POST['tf'.$i] == $tf['answer']){

    $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>Question {$i}:</h3>
        <p>{$tf['questiontf']}</p>
      </div>
      <div class="col-md-6">
          <a class="btn btn-lg btn-success float-right" disabled style="color: white">Correct</a>
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
  $right++;

  }else{

      $string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-6">
        <h3>Question {$i}:</h3>
        <p>{$tf['questiontf']}</p>
      </div>
      <div class="col-md-6">
          <a class="btn btn-lg btn-danger float-right" disabled style="color: white">Incorrect</a>
      </div>
        </div>
      <hr>


DELIMETER;
  
  echo $string;
  $wrong++;
  }
 
 $i++;
 }

$total = $right + $wrong;
$grade = $right/$total;
$grade = $grade * 100;
$studid = $_SESSION['id'];

//update grades
  $updategrade = query("UPDATE grade SET grade='$grade' WHERE testid='$id' AND studentid='$studid'");
  confirm($updategrade);

$string = <<<DELIMETER

      <hr>
        <div class="row">
      <div class="col-md-12">
        <div class="text-center">
          <h4>Score: {$grade}/100</h4>
        </div>
      </div>
      </div>
      <hr>


DELIMETER;

echo $string;

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
        $_SESSION['permission'] = $user['userpermission'];

        //assigns id to teacherid if a teacher login
        if ($_SESSION['permission'] == 1)
        {
          $id = $user['userid'];
          $query = query("SELECT * FROM teacher WHERE userid=$id");
          confirm($query);
          $row = fetch_array($query);
          $_SESSION['id'] = $row['teacherid'];
        }

        //assign id to studentid if student login
        if ($_SESSION['permission'] == 2)
        {
          $id = $user['userid'];
          $query = query("SELECT * FROM student WHERE userid=$id");
          confirm($query);
          $row = fetch_array($query);
          $_SESSION['id'] = $row['studentid'];
        }
        //echo "i was called";
        //$_SESSION['id'] = $user['userid'];
        redirect("dashboard.php");
    }
    else {
        echo "wrong username and pass";
    }
	}
}
}


?>

