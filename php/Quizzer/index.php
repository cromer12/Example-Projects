<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<?php ob_start();?>
<?php session_start();?>
<?php require_once("./resources/config.php"); ?>

<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>
<?php
  if(isset($_SESSION['logged_in'])){
    redirect("dashboard.php");
  }
?>
<?php
//add new user
/*
if ($_SERVER['REQUEST_METHOD'] == 'POST') 
{
    if (isset($_POST['submit'])) { //user logging in

        require TEMPLATE_BACK . DS . "createuser.php";
        
    }
}*/
?>

<div style="height: 100px"></div>

    <!-- Page Content -->
    <div class="container">

      <header>
            <h1 class="text-center">Login</h1>
            <h2 class="text-center bg-warning"><?php display_message(); ?></h2>
            <br>
            <?php login_user();  ?> 
        <div class="col-sm-12 text-center">         
            <form class="" action="" method="post" enctype="multipart/form-data">

                <div class="form-group"><label for="">
                    username<input type="text" name="username" class="form-control"></label>
                </div>
                 <div class="form-group"><label for="password">
                    Password<input type="password" name="password" required autocomplete="off" class="form-control"></label>
                </div>

                <div class="form-group">
                  <input type="submit" name="submit" class="btn btn-primary" style="color: black" value="submit">
                </div>
            </form>
        </div>  


    </header>


        </div>