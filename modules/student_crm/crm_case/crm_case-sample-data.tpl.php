<?php

/**
 * @file
 * Example tpl file for theming a single crm_case-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 * 
 * Helper variables:
 * - $crm_case: The Model object this status is derived from
 */
?>

<div class="crm_case-status">
  <?php print '<strong>Model Sample Data:</strong> ' . $crm_case_sample_data = ($crm_case_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>