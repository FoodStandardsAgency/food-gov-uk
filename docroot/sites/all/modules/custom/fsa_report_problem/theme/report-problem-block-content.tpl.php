<?php
/**
 * @file
 * Main theme implementation for report a food problem block content
 */
?>
<div class="<?php print render($classes); ?> fsa-report-problem-form">
  <?php if ($service_status > FSA_REPORT_PROBLEM_STATUS_PRODUCTION && $service_status != FSA_REPORT_PROBLEM_STATUS_OFFLINE): ?>
    <!-- Phase banner: alpha, beta status -->
    <div class="phase-banner">
      <p>
        <strong class="phase-tag <?php print strtolower(_fsa_report_problem_status_description($service_status)); ?>">
          <?php print _fsa_report_problem_status_description($service_status); ?>
        </strong>
        <span>
          <?php print _fsa_report_problem_status_message($service_status); ?>
        </span>
      </p>
    </div>
  <?php endif; ?>

  <!-- Step indicator -->
  <div class="step-indicator">
    <h2><?php print $step_title; ?></h2>
    <p><?php print t('Step @current_step of @step_count', array('@current_step' => $current_step, '@step_count' => $step_count)); ?></p>
  </div>

  <!-- Main block content -->
  <?php print render($content); ?>

</div>
