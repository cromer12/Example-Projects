<!DOCTYPE html>
<html lang="en">
<?php require_once("./resources/config.php"); ?>
<?php login_check_admin(); ?>
<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>

<body>
	<?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>
	<div class="container">
		<div class="row">
			<div class="col-lg-12">
				<h1>Sports: Select Team</h1>
			</div>
		</div>
	</div>
	<div class="container">
		<div class="row">
			<div class="col-lg-12">
				<?php		
					get_team_select();           
				?>
			</div>
		</div>
		<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
	</body>
</html>