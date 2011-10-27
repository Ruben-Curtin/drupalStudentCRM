<?php
/**
 * @file
 * crm_case.relation_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function crm_case_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'crm_case_activity';
  $relation_type->label = 'CRM Case Activity';
  $relation_type->reverse_label = 'Referenced by';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $export['crm_case_activity'] = $relation_type;

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'crm_contact_case';
  $relation_type->label = 'CRM Contact Case';
  $relation_type->reverse_label = 'Referenced by';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 1;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $export['crm_contact_case'] = $relation_type;

  return $export;
}
