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

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_sitewide';
  $context->description = 'Site-wide settings for Student CRM';
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
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'menu-menu-crm-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-crm-navigation',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site-wide settings for Student CRM');
  t('crm');
  $export['crm_sitewide'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_student_view';
  $context->description = 'Viewing a student CRM contact';
  $context->tag = 'crm student';
  $context->conditions = array(
    'crm_context_condition_contact_type' => array(
      'values' => array(
        'student' => 'student',
      ),
      'options' => array(
        'contact_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_case-crm_create_case' => array(
          'module' => 'crm_case',
          'delta' => 'crm_create_case',
          'region' => 'sidebar_left',
          'weight' => '3',
        ),
        'views-crm_contact_fields-block_2' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block_2',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'views-crm_contact_fields-block_1' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block_1',
          'region' => 'sidebar_right',
          'weight' => '-9',
        ),
        'views-crm_student_advisors-block' => array(
          'module' => 'views',
          'delta' => 'crm_student_advisors-block',
          'region' => 'sidebar_right',
          'weight' => '-8',
        ),
        'views-crm_contact_cases-block' => array(
          'module' => 'views',
          'delta' => 'crm_contact_cases-block',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
        'views-crm_contact_fields-block' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block',
          'region' => 'content_top_wide',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'search',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Viewing a student CRM contact');
  t('crm student');
  $export['crm_student_view'] = $context;

  return $export;
}
