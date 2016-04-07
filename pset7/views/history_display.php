<table class="table table-striped">
    <thead>
        <tr>
            <th style="text-align : center">Stock</th>
            <th style="text-align : center">Transaction</th>
            <th style="text-align : center">Shares</th>
            <th style="text-align : center">Price</th>
            <th style="text-align : center">TimeStamp</th>
        </tr>
    </thead>
    <tbody>
    <?php foreach ($histories as $history): ?>
        <tr>
            <td><?= $history["symbol"] ?></td>
            <td><?= $history["transaction"] ?></td>
            <td><?= $history["shares"] ?></td>
            <td><?= $history["price"] ?></td>
            <td><?= $history["time"] ?></td>
        </tr>
    <?php endforeach ?>
    </tbody>
</table>