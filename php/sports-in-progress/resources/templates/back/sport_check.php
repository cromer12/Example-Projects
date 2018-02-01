<?php
    if(login_check_admin()){
        if(isset($_GET['id'])){
            $_SESSION['sportid'] = $_GET['id'];
        }
        $id = $_SESSION['sportid'];
        $query = query("SELECT * FROM team WHERE teamid='$id'");
        confirm($query);
        $row = fetch_array($query);
    }else{
        $id = $_SESSION['teamid'];
        $query = query("SELECT * FROM team WHERE teamid='$id'");
        confirm($query);
    }
?>