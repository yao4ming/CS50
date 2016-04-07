<?php
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $deposited = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", 
                                        $_POST["deposit"], $_SESSION["id"]);
        if (!$deposited) {
            apologize("Wasn't able to deposit money");
            return;
        }
        
        redirect("/");
    } else {
        render("deposit_form.php");
    }
?>