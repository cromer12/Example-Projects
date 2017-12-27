<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<?php require_once("./resources/config.php"); ?>

<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>
<?php
  if(!isset($_SESSION['logged_in'])){
    redirect("index.php");
  }
  if($_SESSION['permission'] != 1){
    redirect("index.php");
  }
?>
    <!-- Page Content -->
    <div class="container">

      <!-- Page Heading -->
      <h1 class="my-4"><em>Test Maker</em></h1>
      
      <?php // calls functions to display home
              get_create(); 

            //after post, create test in test database
            if ($_SERVER['REQUEST_METHOD'] == "POST"){

              $teacherid = escape_string($_SESSION['id']);
              $_SESSION['testname'] = escape_string($_POST['testname']);
              $testname = escape_string($_POST['testname']);

              //for question.php
              $_SESSION['numbermc'] = escape_string($_POST['numbermc']);
              $_SESSION['numbertf'] = escape_string($_POST['numbertf']);

              //inserts new test in table 'test'
              $query = query("INSERT INTO test (teacherid, testname) VALUES ('$teacherid', '$testname')");
              confirm($query);

              $_SESSION['testid'] = mysqli_insert_id($connection);
              //echo $_SESSION['testid'];

              redirect('question.php');
              }
      ?>


    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>