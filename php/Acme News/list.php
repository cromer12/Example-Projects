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
            <h1 class="my-4"><em>Edit Articles</em></h1>
        </div>
      
      <div class="col-md-6">
          <a class="btn btn-warning btn-lg float-right my-4" href="add.php">Add New Article</a>
      </div>
</div>
      <?php // calls functions to display home
            get_list(); 

            if(isset($_GET['active']))//checks for active change
            {
                if($_GET['active'] == 2) //deletes the article
                {
                  $active = $_GET['active'];
                  $id = $_GET['id'];
                  $query = query("DELETE FROM articles where artid=$id");
                  confirm($query);
                  redirect("list.php");
                }else
                {
                  $active = $_GET['active'];  //changes from active to inactive
                  $id = $_GET['id'];
                  $query = query("UPDATE articles set artactive = '$active' where artid=$id");
                  confirm($query);
                  redirect("list.php");
                }
            }
            
      ?>


    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>