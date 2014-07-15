<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 *
 * Notes: changed grouped heading from an h3 to a div and added a class: "custom-views-grouped-heading"
 */
?>
<?php if (!empty($title)): ?>
  <div class="custom-views-grouped-heading"><?php print $title; ?></div>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>