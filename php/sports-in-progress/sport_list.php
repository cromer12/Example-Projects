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
				<h1>Sports</h1>
				<br>
			</div>
		</div>
	</div>
	<div class="container">
		<div class="row">
			<div class="col-lg-4">
				<button class="btn btn-primary btn-lg btn-block">CoED</button>
				<br>
			</div>
			<div class="col-lg-4">
				<button class="btn btn-primary btn-lg btn-block">Men</button>
				<br>
			</div>
			<div class="col-lg-4">
				<button class="btn btn-primary btn-lg btn-block">Women</button>
				<br>
			</div>
		</div>
		<div class="row">
			<div class="col-lg-12">				
				<?php		
					/*if (isset($_GET['id'])){			
						$id = $_GET['id'];
						$query = query("SELECT * FROM team WHERE teamid=$id");
						confrim($query);
						$row = fetch_array($query);
						unlink($row['teamimg']);
						$query = query("DELETE FROM team where teamid=$id");
						confirm($query);
					}*/
					      
				?>
			</div>
		</div>
	<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
	<script>
			
	</script>
</body>
</html>