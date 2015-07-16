<?php
/**
 * @file
 * Default theme implementation for a problem feport.
 *
 * @see template_preprocess_problem_report().
 */
?>
<div class="feedback-entry"<?php print $attributes; ?>>

  <div class="feedback-entry-detail">

    <div class="field field-label-inline">
      <div class="field-label"><?php print t('Business name'); ?>:&nbsp;</div>
      <?php print $business_name; ?>
    </div>

    <div class="field field-label-inline">
      <div class="field-label"><?php print t('Business FHRS ID'); ?>:&nbsp;</div>
      <?php print $fhrsid; ?>
    </div>

    <div class="field field-label-inline">
      <div class="field-label"><?php print t('Local authority'); ?>:&nbsp;</div>
      <?php print $local_authority_name; ?>,
      <?php print $local_authority_email; ?>
    </div>
    


  </div>

  <h2>Problem details</h2>
  <?php print render($problem_details); ?>

</div>
