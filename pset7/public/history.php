<?php
    require("../includes/config.php"); 

    //try to retrieve histories from database
    $histories = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    if (!$histories) {
        apologize("Wasn't able to retrieve history from database");
        return;
    }
    //render history
    render("history_display.php", ["histories" => $histories]);
?>