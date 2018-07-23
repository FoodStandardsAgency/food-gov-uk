<?php

/**
 * @file
 * FSA-specific theme implementation to present the feedback form.
 *
 * @see template_preprocess_feedback_form_display()
 * @see fsa_feedback_preprocess_feedback_form_display()
 */
?>
<div id="block-feedback-form">
  <h2><span class="feedback-link"><?php print $title; ?></span></h2>
  <div class="content">
    <div class="grey-container-block">
      <?php print drupal_render($content); ?>
    </div>
  </div>
</div>
