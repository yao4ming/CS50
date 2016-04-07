<?php
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $stock = lookup($_POST['symbol']);
        if (!$stock) {
            apologize("Stock symbol was not found");
        } else {
            $stock['price'] = number_format($stock['price'], 2, ".", ",");
            render("quote_display.php", ["symbol" => $stock['symbol'], 
                                        "name" => $stock['name'], "price" => $stock['price']]);
        }
    } else {
        render("quote_form.php");
    }
    
?>