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
?>
    <!-- Page Content -->
    <div class="container">

      <!-- Page Heading -->
      <div class="row">
        <div class="col-md-6">
            <h1 class="my-4">Dashboard: <em><?php get_dashboard(); ?></em></h1>
        </div>
      
      <div class="col-md-6">
        <!--<a class="btn btn-danger btn-lg float-right my-4" href="assign.php">Assign Test</a>-->
        

        <?php if($_SESSION['permission'] == 1){  //allows the test button to appear for teachers ?>
        <a class="btn btn-warning btn-lg float-right my-4" href="addstudent.php">Add Student</a>
        <a class="btn btn-success btn-lg float-right my-4" href="create.php" style="margin-right: 20px">Create Test</a>
        <?php }?>

       <?php if($_SESSION['permission'] == 2){  //allows the test button to appear for teachers 
        
        echo "<a class=\"btn btn-primary float-right my-4\" href=\"grades.php?id=".$_SESSION['id']."\">View Grades</a>";
        }?>



      </div>
</div>
    <?php // calls functions to display students
      if($_SESSION['permission'] == 2){
            get_quizes();
          } 
      ?>

      <?php // calls functions to display students
      if($_SESSION['permission'] == 1){
            get_students();
          } 
      ?>

    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>