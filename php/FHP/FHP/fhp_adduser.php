<?php
    // Author:      Dylan Porter
    // Date:        11/16/2017
    // Purpose:     Add a user to the database

    // TODO: change POST variables to match the form
    // TODO: redirect page to the correct place
    // TODO: add error catching for matching passwords and valid inputs

    // open connection to database
    require_once('connect.php');
    
    // grab all posted variables
    $firstname = trim($_POST['first']);
    $lastname = trim($_POST['last']);
    $email = trim($_POST['email']);
    $username = trim($_POST['username']);
    $password = trim($_POST['password']);
    $repassword = trim($_POST['repassword']);
    $account = trim($_POST['account']);
    
    $firstname = mysqli_real_escape_string($conn, $firstname);
    $lastname = mysqli_real_escape_string($conn, $lastname);
    $email = mysqli_real_escape_string($conn, $email);
    $username = mysqli_real_escape_string($conn, $username);
    $password = mysqli_real_escape_string($conn, $password);
    $repassword = mysqli_real_escape_string($conn, $repassword);
    $account = mysqli_real_escape_string($conn, $account);
    $salt = strtoupper(bin2hex(random_bytes(20)));
    
    // update database with the new user information
    $sql = 'INSERT INTO Users (Id, first_name, last_name, email, username, account_type)
        VALUES (NULL, "' . $firstname . '", "' . $lastname . '", "' . $email . '", "' . $username . '", "' . strtoupper($account) . '")';
    
    $result = $conn->query($sql);
    
    $sql = 'INSERT INTO Logins (id, username, password_hash, password_salt)
        VALUES (NULL, "' . $username . '", PASSWORD("' . $password . '"), "' . $salt . '" )';
    
    $result = $conn->query($sql);
    
    mysqli_close($conn);
    
    //header("Location: REDIRECT");
?>