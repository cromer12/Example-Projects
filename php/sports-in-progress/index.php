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
        <h1 class="display-3">Sports Zone</h1>
        <p class="lead">A Place For All The Teams and Games</p>
      </header>

      <!-- Page Features -->
      <div class="row text-center">

        <div class="col-lg-4 col-md-6 mb-4">
          <a href="team.php">
            <div class="card">
              <img class="card-img-top my-auto img-fluid" src="http://walhallafootball.org/wp-content/uploads/2016/04/Shield-NewColor.png" alt="">
            </div>
          </a>
        </div>

        <div class="col-lg-4 col-md-6 mb-4">
          <div class="card">
            <img class="card-img-top my-auto img-fluid" src="https://static.hudl.com/users/prod/4742410_5fbf0214948141f184d7a01b3d072ad5.jpg" alt="">
          </div>
        </div>

        <div class="col-lg-4 col-md-6 mb-4">
          <div class="card">
            <img class="card-img-top my-auto img-fluid" src="https://static.hudl.com/users/prod/4742410_5fbf0214948141f184d7a01b3d072ad5.jpg" alt="">
          </div>
        </div>
      </div>
      <!-- /.row -->

    </div>
    <!-- /.container -->
    <?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
  </body>
</html>
