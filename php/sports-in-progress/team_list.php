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
				<h1>Teams</h1>
			</div>
		</div>
	</div>
	<div class="container">
		<div class="row">
			<div class="col-lg-12">
				<?php		
					if (isset($_GET['id'])){			
						$id = $_GET['id'];
						$query = query("SELECT * FROM team WHERE teamid=$id");
						confrim($query);
						$row = fetch_array($query);
						unlink($row['teamimg']);
						$query = query("DELETE FROM team where teamid=$id");
						confirm($query);
					}
					get_teams();           
				?>
			</div>
		</div>
		<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
	</body>
</html>