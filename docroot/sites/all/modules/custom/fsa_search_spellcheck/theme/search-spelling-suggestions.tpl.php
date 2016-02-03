<?php
/**
 * @file
 * Default theme implementation for search spelling suggestions
 */
?>

<div class="search-spelling-suggestions">
<?php
// More hits for suggestion than original query
?>
<?php if ($ch > $hits): ?>
    <?php
    // We do have some hits for the original query
    ?>
    <?php if ($hits > 0): ?>
      <p>Showing results for <strong><?php print render($keyword); ?></strong>. Search instead for
        <?php
        // If the original search is considered correctly spelt
        ?>
        <?php if ($cs): ?>
          <a href="<?php print $suggested_query_link; ?>"><?php print render($suggestion); ?></a>.
        <?php else: ?>
          <a href="<?php print $original_query_link; ?>"><?php print render($original_query); ?></a>.
        <?php endif; ?>
      </p>

    <?php
    // We don't have any hits for the original query
    ?>
    <?php else: ?>
      <p>A search for <em><?php print render($original_query); ?></em> returned no results. Searched instead for <strong><?php print render($keyword); ?></strong>.</p>
    <?php endif; ?>

<?php elseif ($ch > 0 && !empty($suggestion)): ?>
    <p>Showing results for <strong><?php print render($keyword); ?></strong>. You may alternatively want to try a search for <a href="<?php print $suggested_query_link; ?>"><?php print render($suggestion); ?></a> (<?php print render($ch); ?> results).</p>

<?php elseif ($hits === 0 && empty($suggestions) && empty($ch)): ?>
  <p>Sorry, we couldn't find any results searching for <em><?php print render($keyword); ?></em>, and we couldn't come up with an alternative suggestion.</p>
  <?php if (!empty($suggested_keyword_links)): ?>
    <p>You could try searching for these terms instead:</p>
    <ul class="search-suggested-keywords">
      <?php foreach ($suggested_keyword_links as $link): ?>
        <li><?php print render($link); ?></li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
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
