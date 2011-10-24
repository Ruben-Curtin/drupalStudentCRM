<?php
/**
 * @file
 * crm_advisor.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function crm_advisor_user_default_roles() {
  $roles = array();

  // Exported role: advisor
  $roles['advisor'] = array(
    'name' => 'advisor',
    'weight' => '2',
  );

  return $roles;
}
