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
        <div class="col-md-12">
            
        </div>
      </div>

    <form action="score.php" method="post">
    <?php // calls functions to display students
        takes();
    ?>
      <div class="text-center">
        <button class="btn btn-lg btn-success" type="submit" name="submit" style="color:white; text-align: center">Submit</button>
      </div>
    </form>
    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>