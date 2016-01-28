<?php
/**
 * @file
 * Default theme implementation for search spelling suggestions
 */
?>

<?php if ($show_suggestions): ?>
  <div class="search-spelling-suggestions">
    <p>Showing results for <strong><?php print render($keyword); ?></strong>.
    <?php if (!empty($original_query)): ?>
      Search instead for <a href="<?php print $original_query_link; ?>"><?php print render($original_query); ?></a>.</p>
    <?php endif; ?>
  </div>
<?php endif; ?>