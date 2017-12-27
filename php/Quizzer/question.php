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
      <h1 class="my-4"><em>Test Maker: Multiple Choice</em></h1>

    <form action="" method="post">
      <?php // calls functions to display Question Inputs
            create_mc($_SESSION['numbermc']);

      ?>
      <button class="btn btn-primary" type="submit" name="submit" style="color:white">Submit Questions</button>
    </form>


      <?php
            //uploads questions to DB
          if ($_SERVER['REQUEST_METHOD'] == "POST"){
            $i=0;
            while($i < $_SESSION['numbermc']){

              $testid   = $_SESSION['testid'];
              $question = $_POST['question' . $i];
              $choice1  = $_POST['choice1'. $i];
              $choice2  = $_POST['choice2'. $i];
              $choice3  = $_POST['choice3'. $i];
              $choice4  = $_POST['choice4'. $i];
              $answer   = $_POST['answermc'. $i];
              $i++;

              echo $question;
              echo $choice1;
              echo $choice2;
              echo $choice3;
              echo $choice4;
              echo $answer;

              $query = query("INSERT INTO questionmc (testid, questionmc, choice1, choice2, choice3, choice4, answer) VALUES ('$testid', '$question', '$choice1', '$choice2', '$choice3', '$choice4', '$answer' )");
              confirm($query);
              
            }
            redirect('questiontf.php');
          }
  
      ?>


    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>