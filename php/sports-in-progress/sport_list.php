<!DOCTYPE html>
<html lang="en">
<?php require_once("./resources/config.php"); ?>
<?php login_check(); ?>
<?php include(TEMPLATE_FRONT . DS . "header.php"); ?>
<?php include(TEMPLATE_BACK . DS . "sport_check.php") ?>
<?php
	$id = $_SESSION['teamid'];
	if (isset($_GET['id'])){
		login_check_admin();
		$id = $_GET['id'];
	}
	if($id == 0){
		header('location:team_select.php');
	}
?>

<body>
	<?php include(TEMPLATE_FRONT . DS . "topnav.php"); ?>
	<div class="container">
		<div class="row">
			<div class="col-lg-12">
				<h1>Sports: <?php echo $row['teamname']?></h1>
				<br>
			</div>
		</div>
	</div>
	<div class="container">
		<div class="row">
			<div class="col-lg-4">
				<a class="btn btn-warning btn-lg btn-block" href="add_sport.php?id=<?php echo $id ?>">Add New Sport</a>
				<br>
			</div>
		</div>
	</div>
	<div class="container">
		<div class="row">
			<div class="col-lg-4">
				<button class="btn btn-primary btn-lg btn-block co">CoED</button>
				<div class="colist">
					<?php get_sports_co($id) ?>
				</div>
				<br>
				
			</div>
			<div class="col-lg-4">
				<button class="btn btn-primary btn-lg btn-block men">Men</button>
				<div class="menlist">
					<?php get_sports_men($id) ?>
				</div>
				<br>
			</div>
			<div class="col-lg-4">
				<button class="btn btn-primary btn-lg btn-block women">Women</button>
				<div class="womenlist">
					<?php get_sports_women($id) ?>
				</div>
				<br>
			</div>
		</div>
	<?php include(TEMPLATE_FRONT . DS . "footer.php"); ?>
	<script>
		setUpEventListeners = function(){
			var co = document.querySelector('.co');
			var men = document.querySelector('.men');
			var women = document.querySelector('.women');
			

			co.addEventListener('click', function(){
				document.querySelector('.colist').classList.toggle('displayMe');
			});
        	men.addEventListener('click', function(){
				document.querySelector('.menlist').classList.toggle('displayMe');
			});
        	women.addEventListener('click', function(){
				document.querySelector('.womenlist').classList.toggle('displayMe');
			});
		}

		setUpEventListeners();
	</script>
</body>
</html>