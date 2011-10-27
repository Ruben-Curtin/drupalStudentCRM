<?php
/**
 * @file
 * student_crm_demo.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function student_crm_demo_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_degrees';
  $feeds_importer->config = array(
    'name' => 'Demo Degrees',
    'description' => 'A demonstration taxonomy for degrees',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'degrees',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'type',
            'target' => 'field_degree_type',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_degrees'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_students';
  $feeds_importer->config = array(
    'name' => 'Demo Students',
    'description' => 'Demonstration import of students.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMFeedsContactProcessor',
      'config' => array(
        'contact_type' => 'student',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'first_name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'last_name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'full_name',
            'target' => 'contact_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'student_id',
            'target' => 'field_student_id',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'student_id',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_students'] = $feeds_importer;

  return $export;
}
