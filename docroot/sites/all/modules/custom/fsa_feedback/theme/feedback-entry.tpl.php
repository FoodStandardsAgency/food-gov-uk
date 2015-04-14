<?php
/**
 * @file
 * FSA-specific theme implementation to present a feedback entry.
 *
 * @see template_preprocess_feedback_entry()
 */
?>
<div class="feedback-entry"<?php print $attributes; ?>>
  
  <div class="feedback-entry-detail">
  
    <div class="field field-label-inline">
      <div class="field-label"><?php print t('Location'); ?>:&nbsp;</div>
      <?php print $location; ?>
    </div>
    <div class="field field-label-inline">
      <div class="field-label"><?php print t('Date'); ?>:&nbsp;</div>
      <?php print $date; ?>
    </div>

    <div class="field field-label-inline">
      <div class="field-label"><?php print t('User'); ?>:&nbsp;</div>
      <?php print $account; ?>
    </div>

    <div class="field field-label-inline">
      <div class="field-label">Browser:&nbsp;</div>
      <?php print render($browser); ?>
    </div>
    
  </div>
  
  <h2>Message</h2>
  <?php print render($content); ?>
  
</div>
