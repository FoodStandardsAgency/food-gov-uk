<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

  $wrap_title = (strpos($title, '<h1 ') === NULL || strpos($title, '<h2 ') === NULL || strpos($title, '<p ') === NULL) ? TRUE: FALSE;
?>
<?php if (!empty($title)): ?>
  <?php if ($wrap_title): ?><h3><?php endif; ?><?php print $title; ?><?php if ($wrap_title): ?></h3><?php endif; ?>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
