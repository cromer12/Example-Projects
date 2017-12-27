<?php 
/*
  Name: Cameron Cromer
  Date: 10/6/2017
*/
  error_reporting(0);

?>

<?php  

ob_start();

session_start();


defined("DS") ? null : define("DS", DIRECTORY_SEPARATOR);

defined("TEMPLATE_FRONT") ? null : define("TEMPLATE_FRONT", __DIR__ . DS . "templates/front");  //may need to change that to \

defined("TEMPLATE_BACK") ? null : define("TEMPLATE_BACK", __DIR__ . DS . "templates/back");  //may need to change that to \

defined("DB_HOST") ? null : define("DB_HOST", "localhost");  //may need to change that to \

defined("DB_USER") ? null : define("DB_USER", "id2681202_user");  //may need to change that to \

defined("DB_PASS") ? null : define("DB_PASS", "cromer12");  //may need to change that to \

defined("DB_NAME") ? null : define("DB_NAME", "id2681202_article");  //may need to change that to \

$connection = mysqli_connect(DB_HOST,DB_USER,DB_PASS,DB_NAME);



if(!$connection){

echo "NO CONNECTION<br>";

}


require_once("functions.php");


?>