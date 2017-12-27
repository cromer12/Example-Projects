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
      <h1 class="my-4"><em>Local News</em>
        <small>Stories Important to You</small>
      </h1>

      <?php // calls functions to display home
            get_add(); 
           if ($_SERVER['REQUEST_METHOD'] == "POST"){

              //creates new article
              $image = escape_string($_POST['editimage']);
              $contact = escape_string($_POST['editcontact']);
              $title = escape_string($_POST['edittitle']);
              $content = escape_string($_POST['editcontent']);
              $date = date("Y-m-d h:i:sH");
              $date = substr($date, 0, -2);

              $query = query("INSERT INTO articles (artimage, arttitle, artcontent, artcontact, arttimestamp, artactive) VALUES ('$image', '$title', '$content', '$contact', '$date', 1)");
              confirm($query);
              redirect("list.php");
           }
      ?>


    </div>
    <!-- /.container -->
    <br>
<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>