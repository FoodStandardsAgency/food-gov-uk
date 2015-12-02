<?php
/**
 * @file
 * Default theme implementation for a problem feport.
 *
 * @see template_preprocess_problem_report().
 */
?>
<div class="<?php print $classes; ?>" <?php print $attributes; ?>>

  <?php if (!empty($unsent_warning)): ?>
    <div class="messages warning">
      <p class="problem-report-unsent-warning"><?php print render($unsent_warning); ?></p>
    </div>
  <?php endif; ?>
  
  <h2><?php print $business_name; ?></h2>
  
  <p><?php print $business_location; ?><?php if (!empty($business_postcode)) : ?>, <?php print $business_postcode; ?><?php endif; ?></p>

  <div class="problem-report-detail">
    <?php print render($local_authority); ?>
    <?php print render($reporter_name); ?>
    <?php print render($problem_date); ?>
  </div>
  
  <?php print render($problem_details); ?>

</div>
