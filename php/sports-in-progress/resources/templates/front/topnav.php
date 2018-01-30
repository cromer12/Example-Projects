<!-- Navigation -->
    <!-- Navigation -->
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
      <div class="container">
        <a class="navbar-brand" href="index.php">Sports Manager</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarResponsive">
          <ul class="navbar-nav ml-auto">
            <li class="nav-item">
              <a class="nav-link" href="index.php">Home
              </a>
            </li>
            <?php 
              if (isset($_SESSION['logged_in']))
              {
                echo "<li class=\"nav-item\">
                <a class=\"nav-link\" href=\"dashboard.php\">Dashboard</a>";
                echo "<li class=\"nav-item\">
                <a class=\"nav-link\" href=\"logout.php\">Logout</a>";
                
              }else{
                echo "<li class=\"nav-item\">
                <a class=\"nav-link\" href=\"login.php\">Login</a>";
              }
              ?>
            
          </ul>
        </div>
      </div>
    </nav>
