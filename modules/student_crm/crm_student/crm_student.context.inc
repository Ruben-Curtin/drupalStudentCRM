<?php
/**
 * @file
 * crm_student.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_student_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_search';
  $context->description = 'Search context';
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
        'views--exp-search_contacts-page' => array(
          'module' => 'views',
          'delta' => '-exp-search_contacts-page',
          'region' => 'header_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search context');
  t('crm');
  $export['crm_search'] = $context;

  return $export;
}
