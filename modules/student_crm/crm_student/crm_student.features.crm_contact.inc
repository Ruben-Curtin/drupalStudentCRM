<?php
/**
 * @file
 * crm_student.features.crm_contact.inc
 */

/**
 * Implements hook_crm_features_contact_defaults().
 */
function crm_student_crm_features_contact_defaults() {
  $items = array(
    'student' => array(
      'type' => t('student'),
      'name' => 'Student',
      'description' => t('A student attending the university.'),
      'custom' => '0',
    ),
  );
  return $items;
}
