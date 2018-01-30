<!DOCTYPE html>
<html lang="en">
  <?php require_once("./resources/config.php"); ?>
  <?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

  <body>
    <?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>

    <!-- Page Content -->
    <div class="container">

      <!-- Jumbotron Header -->
        <header class="jumbotron my-4">
            <div style="text-align:center">
                <h1 class="display-3">$getTeamName $getSport</h1>
            </div>
        </header>

      <!-- Page Features -->
      <div class="row text-center">
        <div class="col-lg-4">
            <h3>Team vs Team</h3>
        </div>

        <div class="col-lg-4">
            <h3>Date</h3>
        </div>

        <div class="col-lg-4">
            <h3>Score</h3>
        </div>
      </div>
      <!-- /.row -->

    </div>
    <!-- /.container -->
    
  <?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
  </body>


</html>
