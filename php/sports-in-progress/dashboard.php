<!DOCTYPE html>
<html lang="en">
  <?php require_once("./resources/config.php"); ?>
  <?php login_check(); ?>
  <?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

  <body>
	<?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>
	
	<?php 
		//var_dump($_SESSION);
		if($_SESSION['permission'] == "2"){
			get_admin();
		}
		if($_SESSION['permission'] == "1"){
			get_coach();
		}
		if($_SESSION['permission'] == "0"){
			get_assist();
		}
	?>

	<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
</body>
</html>