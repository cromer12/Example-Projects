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

    <?php // calls functions to display students
        grade();
        $id = $_SESSION['testid'];

        $query = query("UPDATE take SET taken=1 WHERE testid='$id'");
        confirm($query);
    ?>

      <div class="row">
        <div class="col-md-2">
        </div>
        <div class="col-md-8">
            <div class="text-center">
              <a class="btn btn-block btn-primary" href="dashboard.php">Dashboard</a>
            </div>
        </div>
      </div>

    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>