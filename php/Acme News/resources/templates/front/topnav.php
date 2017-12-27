<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<!-- Navigation -->
<nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
  <div class="container">
        <?php

        if (isset($_SESSION['logged_in']))
        {
        $adminnav = <<< DELIMETER
        <ul class="nav navbar-right top-nav">
          <li class="dropdown">
                <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-user" style="color:white;">$_SESSION[username]</i><b class="caret"></b></a>
                <ul class="dropdown-menu">
                   
                    <li class="divider"></li>
                    <li>
                        <a href="logout.php"><i class="fa fa-fw fa-power-off"></i> Log Out</a>
                    </li>
                </ul>
            </li>
        </ul>
DELIMETER;
          echo $adminnav;
          }
        ?>
    <a class="navbar-brand" href="index.php">Acme News&reg</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarResponsive">
      <ul class="navbar-nav ml-auto">
        <li class="nav-item active">
          <a class="nav-link" href="index.php">Home</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="login.php">Admin</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="logoutmain.php">Main Site</a>
        </li>
        <?php

        if (isset($_SESSION['logged_in']))
        {
          echo "<li class=\"nav-item\">
          <a class=\"nav-link\" href=\"list.php\">Article Manager</a>";
        }
        ?>
      </ul>
    </div>
  </div>
</nav>
