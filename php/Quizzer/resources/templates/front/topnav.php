<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
?>
<!-- Navigation -->
<nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
  <div class="container">
    <a class="navbar-brand" href="index.php">Quizzer&reg</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarResponsive">
      <ul class="navbar-nav ml-auto">
        <?php
          if (isset($_SESSION['logged_in'])){
            echo "<li class=\"nav-item active\">
              <a class=\"nav-link\" href=\"dashboard.php\">Dashboard</a>
            </li>";
          }else{
            echo "<li class=\"nav-item active\">
              <a class=\"nav-link\" href=\"index.php\">Home</a>
            </li>";
          }
        ?>
        <?php

        if (isset($_SESSION['logged_in']))
        {
          echo "<li class=\"nav-item\">
          <a class=\"nav-link\" href=\"logout.php\">Logout</a>
          </li>";
        }
        ?>

        <li class="nav-item">
          <a class="nav-link" href="../index.php">Main Site</a>
        </li>
      </ul>
    </div>
  </div>
</nav>
