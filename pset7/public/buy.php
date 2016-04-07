<?php
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        //check if shares was a whole number
        if (!preg_match("/^\d+$/", $_POST["shares"])) {
            apologize("Shares to buy must be whole numbers");
            return;
        }
        //check if database returned cash
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        if (!$cash) {
            apologize("Wasn't able to retrieve cash from database");
            return;
        }
        //check if lookup function returned stock info
        $stock = lookup($_POST["symbol"]);
        if (!$stock) {
            apologize("Wasn't able to lookup stock symbol");
            return;
        }
        //check if user has enough cash to buy
        if ($cash[0]["cash"] < $stock["price"] * $_POST["shares"]) {
            apologize("Don't have enough money to buy");
            return;
        }
        //passed all conditions, buy stocks
        $bought = CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) 
                        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
                        $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
        //check if database was updated from purchase                
        if (!$bought) {
            apologize("Wasn't able to update database with purchase");
            return;
        }
        //subtract purchase amount from cash balance
        $subtracted = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", 
                        $stock["price"] * $_POST["shares"], $_SESSION["id"]);
        if (!$subtracted) {
            apologize("Wasn't able to deduce stock purchase from cash balance");
            return;
        }
        //insert this transaction into history
        $updatedHistory = CS50::query("INSERT INTO history (user_id, symbol, transaction, shares, price, time) 
                        VALUES(?, ?, 'buy',?, ?, NOW())",
                        $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"]);
        if (!$updatedHistory) {
            apologize("Wasn't able to update history will sell transaction");
            return;
        }
        redirect("/");
        
    } else {
        render("buy_form.php");
    }

?>