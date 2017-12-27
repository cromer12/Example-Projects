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
      <h1 class="my-4"><em>Test Maker: True False</em></h1>
         <form action="" method="post">
      <?php // calls functions to display Question Inputs
            create_tf($_SESSION['numbertf']);

      ?>
      <button class="btn btn-primary" type="submit" name="submit" style="color:white">Submit Questions</button>
    </form>


      <?php
            //uploads questions to DB
          if ($_SERVER['REQUEST_METHOD'] == "POST"){

            $i=0;
            while($i < $_SESSION['numbertf']){

              $testid   = $_SESSION['testid'];
              $question = $_POST['question' . $i];
              $answer   = $_POST['answer'. $i];
              $i++;

              $query = query("INSERT INTO questiontf (testid, questiontf, answer) VALUES ('$testid', '$question', '$answer')");
              confirm($query);
            }
           redirect('dashboard.php');
          }
  
      ?>


    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>