<?php
/**
 * @file
 * Default theme implementation for a GovDelivery category.
 */
?>

<dl class="category-details">
  <dt>Category name</dt>
  <dd><?php print render($name); ?></dd>
  
  <dt>Short name</dt>
  <dd><?php print render($short_name); ?></dd>
  
  <dt>Description</dt>
  <dd><?php print render($description); ?></dd>

  <dt>Category code</dt>
  <dd><?php print render($category_code); ?></dd>
  
  <?php if (!empty($parent_category)): ?>
    <dt>Parent category</dt>
    <dd><?php print render($parent_category); ?></dd>
  <?php endif; ?>
    
  <dt>Allow subscriptions</dt>
  <dd><?php print render($allow_subscriptions); ?></dd>
    
  <dt>Default open</dt>
  <dd><?php print render($default_open); ?></dd>
  
  <?php if (!empty($quick_subscribe_page)): ?>
    <dt>Quick subscribe page</dt>
    <dd><?php print render($quick_subscribe_page); ?></dd>
  <?php endif; ?>
  
  <?php if (!empty($topics)): ?>
    <dt>Topics</dt>
    <dd>
      <ul>
        <?php foreach ($topics as $topic): ?>
          <li><?php print render($topic); ?></li>
        <?php endforeach; ?>
      </ul>
    </dd>
  <?php endif; ?>  
  
</dl>
