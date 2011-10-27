<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function crm_case_views_data_alter(&$data) { 
  $data['crm_case']['link_crm_case'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the case.'),
      'handler' => 'crm_case_handler_link_field',
    ),
  );
  $data['crm_case']['edit_crm_case'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the case.'),
      'handler' => 'crm_case_handler_edit_link_field',
    ),
  );
  $data['crm_case']['delete_crm_case'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the case.'),
      'handler' => 'crm_case_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows crm_cases/crm_case/%crm_case_id/op
  $data['crm_case']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this case.'),
      'handler' => 'crm_case_handler_crm_case_operations_field',
    ),
  );
}

