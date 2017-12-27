<?php 
	require_once('partials/login_check.php'); 
?>

<html>
<head>

	<title>FHP Dashboard</title>
</head>
<body>
	<?php 
		require_once('partials/dashboard_nav.php');
	?>

	<?php 
		//var_dump($_SESSION);
		if($_SESSION['account'] == "admin"){
			get_admin();
		}
		if($_SESSION['account'] == "editor"){
			get_editor();
		}
		if($_SESSION['account'] == "author"){
			get_author();
		}
	?>

	<?php 
		require_once('partials/tinymc_footer.php'); 
	?>
</body>
</html>