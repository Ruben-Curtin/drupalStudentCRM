<?php
/**
 * @file
 * crm_advisor.relation_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function crm_advisor_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'advisor';
  $relation_type->label = 'Advisor';
  $relation_type->reverse_label = 'Advisee';
  $relation_type->directional = 0;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 1;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $export['advisor'] = $relation_type;

  return $export;
}
