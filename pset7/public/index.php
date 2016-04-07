<?php

    // configuration
    require("../includes/config.php"); 
    
    $positions = [];
    
    //query database for user portfolio
    $rows = CS50::query("SELECT symbol, shares FROM `portfolio` WHERE user_id = ?", $_SESSION["id"]);
    if (!$rows) {
        apologize("Wasn't able to get user portfolio");
    }
    //query database for user cash balance
    $cashBalance = CS50::query("SELECT cash FROM `users` WHERE id = ?", $_SESSION["id"])[0];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => number_format($row["shares"] * $stock["price"],2),
                "cashBalance" => $cashBalance["cash"]
            ];
        } else {
            apologize("Wasn't able to lookup stock");
        }
    }

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

?>
