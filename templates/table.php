<?php if (is_array($value) || is_object($value)) {

    // Empty data set
    if (empty($value)) { ?>
        <span class="debug-type unknown">(empty)</span>
        <?php return;
    } ?>

    <table class="debug-table">
        <?php foreach ($value as $key => $var) { ?>

            <tr>
                <td><span class="debug-type object"><?php echo $key; ?></span></td>
                <td><?php echo static::parseType($var); ?></td>
                <td><?php echo static::_renderTemplate('table', array('value' => $var)); ?></td>
            </tr>

        <?php }

        // Display class methods for non-augment classes
        if (is_object($value) && strpos(get_class($value), 'Augment') === false) {
            $methods = get_class_methods($value);
            sort($methods);

            foreach ($methods as $method) { ?>

            <tr>
                <td><span class="debug-type function"><?php echo $method; ?></span></td>
                <td>method</td>
                <td></td>
            </tr>

        <?php } } ?>
    </table>

<?php } else {
    echo static::parseValue($value, true);
} ?>