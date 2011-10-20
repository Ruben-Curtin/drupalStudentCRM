<?php

/**
 * @file
 * Example tpl file for theming a single crm_note-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 * 
 * Helper variables:
 * - $crm_note: The crm_note object this status is derived from
 */
?>

<div class="crm_note-status">
  <?php print '<strong>crm_note Sample Data:</strong> ' . $crm_note_sample_data = ($crm_note_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>