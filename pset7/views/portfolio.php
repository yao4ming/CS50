<table class="table table-striped">
    <thead>
        <tr>
            <th style="text-align : center">Stock</th>
            <th style="text-align : center">Name</th>
            <th style="text-align : center">Price</th>
            <th style="text-align : center">Shares</th>
            <th style="text-align : center">Total</th>
        </tr>
    </thead>
    <tbody>
    <?php foreach ($positions as $position): ?>
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= $position["price"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td><?= $position["total"] ?></td>
        </tr>
    <?php endforeach ?>
    </tbody>
</table>
<div>
    <b>Cash Balance</b> : <?= $positions[0]["cashBalance"] ?>
</div>
    
