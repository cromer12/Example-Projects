<?php 
    // Author:      Dylan Porter
    // Date:        11/19/2017
    // Purpose:     Send a password reset link to the user
    
    //TODO: insert site domain into the email link
    //TODO: change the from email address

    // open connection to database
    require_once('connect.php');

    if (isset($_POST['email']))
    {
        // grab and santize user input
        $email = trim($_POST['email']);
        $email = mysqli_real_escape_string($conn, $email);
        
        // see if there is a user with that email in the database
        $sql = "SELECT email, U.username
                    FROM users U, logins L
                    WHERE email='" . $email . "' AND U.username = L.username";
        
        $result = $conn->query($sql);
        $row = $result->fetch_assoc();
        
        $user = $row['username'];
        
        if (isset($row['email']))
        {
            // hash username to be used in the URL
            $user = md5($user);
            
            // link to use in the email
            $link = "<a href='fhp_reset_pass.php?key=" . $user . "'>Click to reset password.</a>";
            
            // set the email headers
            $to = $email;
            $subject = "Reset Link";
            $from = "contactmail@web.com";
            
            // send the email
            mail($to, $subject, $link, $from);
            
            echo "A reset link has been successfully sent to your email address!";
        }
        else
        {
            // redirect back to the email form with an error that the email was not found
            header("Location: fhp_email_form.php?error=true");
        }
    }
?>