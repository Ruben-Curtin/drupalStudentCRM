<?php
/**
 * @file
 * crm_history.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_history_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_history';
  $context->description = 'CRM History blcok';
  $context->tag = 'crm';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_history-crm_history' => array(
          'module' => 'crm_history',
          'delta' => 'crm_history',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CRM History blcok');
  t('crm');
  $export['crm_history'] = $context;

  return $export;
}
