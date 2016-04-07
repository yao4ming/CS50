<?php
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        
        //select shares to sell from database
        $shares = CS50::query("SELECT shares FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
        if (!$shares) {
            apologize("Wasn't able to retreive shares to sell from database");
            return;
        }
        //delete sold stock from database
        $deleted = CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?", 
                                $_SESSION["id"], $_POST["symbol"]);
        if (!$deleted) {
            apologize("Wasn't able to delete shares from database");
            return;
        }
        
        //lookup symbol for current price
        $stock = lookup($_POST["symbol"]);
        if (!$stock) {
            apologize("Wasn't able to lookup symbol");
            return;
        }
        
        //update cash with profit from sold stock
        $updated = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", 
                                        $stock["price"] * $shares[0]["shares"], $_SESSION["id"]);
        if (!$updated)  {
            apologize("Wasn't able to update cash in database");
            return;
        }
        
        //insert this transaction into history
        $updatedHistory = CS50::query("INSERT INTO history (user_id, symbol, transaction, shares, price, time) 
                        VALUES(?, ?, 'sell', 0, ?, NOW())",
                        $_SESSION["id"], strtoupper($_POST["symbol"]), $stock["price"]);
        if (!$updatedHistory) {
            apologize("Wasn't able to update history will sell transaction");
            return;
        }
        
        redirect("/");
        
    } else {
        render("sell_form.php");
    }


?>