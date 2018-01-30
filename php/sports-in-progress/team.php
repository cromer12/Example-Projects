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
                <h1 class="display-3">$getTeamName</h1>
            </div>
        </header>

      <!-- Page Features -->
      <div class="row text-center">
        <div class="col-lg-4 col-md-6 mb-4">
            <h2>Men's Athletics</h2>
        </div>        
        <div class="col-lg-4 col-md-6 mb-4">
            <h2>Women's Athletics</h2>
        </div>
        <div class="col-lg-4 col-md-6 mb-4">
            <h2>Co-ED Athletics</h2>
        </div>
      </div>

      <div class="row text-center">
        <div class="col-lg-4 col-md-6 mb-4">
            <div class="card">
                <ul class="list-group list-group-flush">
                    <a href="schedule.php">
                        <li class="list-group-item">Function here</li>
                    </a>
                </ul>
            </div>
          </a>
        </div>

        <div class="col-lg-4 col-md-6 mb-4">
          <div class="card">
                <ul class="list-group list-group-flush">
                    <a href="schedule.php">
                        <li class="list-group-item">Function here</li>
                    </a>
                </ul>
          </div>
        </div>
        <div class="col-lg-4 col-md-6 mb-4">
          <div class="card">
                <ul class="list-group list-group-flush">
                    <a href="schedule.php">
                        <li class="list-group-item">Function here</li>
                    </a>
                </ul>
          </div>
        </div>

      </div>
      <!-- /.row -->

    </div>
    <!-- /.container -->
    
  <?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
  </body>


</html>
