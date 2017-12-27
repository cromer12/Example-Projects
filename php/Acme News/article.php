<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<?php require_once("./resources/config.php"); ?>

<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

    <!-- Page Content -->
    <div class="container">


      <?php // calls functions to display article
            get_article(); 
      ?>


    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>