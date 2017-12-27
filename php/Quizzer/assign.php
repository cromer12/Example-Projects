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
    <div style="height: 20px"></div>
    <div class="container">
      <form action="assign.php" method="post">
      <?php // calls functions to display article
        if(isset($_GET['id'])){
            //this outputs all the tests with a link that sets $_GET['id'] to the test id.
            get_assign();
            $_SESSION['studentid'] = $_GET['id'];

          }elseif (isset($_POST['submit'])) //detects post from assign button
          {   
            //below checks to see if the entry already exists
              $studentid = $_SESSION['studentid'];   
              $testid = $_POST['submit'];
              $count = query("SELECT * FROM take WHERE studentid = '$studentid' AND testid = '$testid'");
              confirm($count);

              //if count==0, add to take table otherwise, report error
              if(mysqli_num_rows($count) == 0){
              $query = query("INSERT INTO take (studentid, testid, taken) VALUES ('$studentid', '$testid', 0)");
              confirm($query);

              $query = query("INSERT INTO grade (studentid, testid) VALUES ('$studentid', '$testid')");
              confirm($query);

              redirect('dashboard.php');
              }else{
                set_message('Student Already Has This Test Assigned');
                display_message();
                echo "<a class=\"btn btn-primary\" style=\"margin-left:50%\" href=\"assign.php?id=$studentid\">Back</a>";
              }

          }else
          {
            //this takes the id, lists the students, and allows the TAKE table to be updated with both the studentid and testid
            redirect('dashboard.php');
          }
      ?>
      </form>
    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>