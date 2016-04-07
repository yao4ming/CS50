<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("register_form.php", ["title" => "Register"]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //validate post data
        if ($_POST['username'] === "") {
            apologize("Cannot have blank username");
        } else if ($_POST['password'] === "") {
            apologize("Cannot have blank password");
        } else if ($_POST['password'] !== $_POST['confirmation']) {
            apologize("Passwords do not match");
        } else {
            //insert user data into database
            $result = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST['username'], password_hash($_POST['password'], PASSWORD_DEFAULT));
            if ($result === 0) {
                apologize("Username is taken");
                return;
            }
            
            //get inserted user's id and save in session
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            $_SESSION["id"] = $id;
            redirect("/");
        }
        
        
    }

?>