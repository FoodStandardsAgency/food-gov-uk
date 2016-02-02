<?php
/**
 * @file
 * Default theme implementation for search spelling suggestions
 */
?>

<div class="search-spelling-suggestions">
<?php if ($ch > $hits): ?>
    <?php if ($hits > 0): ?>
      <p>Showing results for <strong><?php print render($keyword); ?></strong>. Search instead for
        <?php if ($cs): ?>
          <a href="<?php print $suggested_query_link; ?>"><?php print render($suggestion); ?></a>.
        <?php else: ?>
          <a href="<?php print $original_query_link; ?>"><?php print render($original_query); ?></a>.
        <?php endif; ?>
      </p>

    <?php else: ?>
      <p>A search for <em><?php print render($original_query); ?></em> returned no results. Found <?php print render($ch); ?> results by searching for <strong><?php print render($keyword); ?></strong> instead.</p>
    <?php endif; ?>

<?php elseif ($ch > 0 && !empty($suggestion)): ?>
    <p>Showing results for <strong><?php print render($keyword); ?></strong>. You may alternatively want to try a search for <a href="<?php print $suggested_query_link; ?>"><?php print render($suggestion); ?></a>.</p>

<?php elseif ($hits == 0 && empty($suggestions) && empty($ch)): ?>

  <p>Sorry, we couldn't find any results searching for <?php print render($keyword); ?>, and we couldn't come up with an alternative query. You could try searching for these individual terms instead</p>
  <ul><?php if (!empty($suggested_keyword_links)): ?>
    <?php foreach ($suggested_keyword_links as $link): ?>
      <li><?php print render($link); ?></li>
    <?php endforeach; ?>
  <?php endif; ?></ul>

<?php endif; ?>
</div>






<!--
<hr>

OLD STUFF BELOW

<hr>


<?php if ($show_original): ?>
  <div class="search-spelling-suggestions">
    <p>Showing results for <strong><?php print render($keyword); ?></strong>.
    <?php if (!empty($original_query)): ?>
      Search instead for <a href="<?php print $original_query_link; ?>"><?php print render($original_query); ?></a>.</p>
    <?php endif; ?>
  </div>
<?php endif; ?>

<?php if ($show_suggestions): ?>
  <div class="search-spelling-suggestions">
    <p>Did you mean <a href="<?php print $suggested_query_link; ?>"><?php print render($suggestion); ?></a>?</p>
  </div>
<?php endif; ?>

-->
