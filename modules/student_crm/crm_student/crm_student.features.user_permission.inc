<?php
/**
 * @file
 * crm_student.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crm_student_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'comment',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'user',
  );

  // Exported permission: add contacts
  $permissions['add contacts'] = array(
    'name' => 'add contacts',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm',
  );

  // Exported permission: administer contact types
  $permissions['administer contact types'] = array(
    'name' => 'administer contact types',
    'roles' => array(),
  );

  // Exported permission: administer crm_case types
  $permissions['administer crm_case types'] = array(
    'name' => 'administer crm_case types',
    'roles' => array(),
  );

  // Exported permission: administer crm_cases
  $permissions['administer crm_cases'] = array(
    'name' => 'administer crm_cases',
    'roles' => array(),
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
  );

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(),
  );

  // Exported permission: administer relation types
  $permissions['administer relation types'] = array(
    'name' => 'administer relation types',
    'roles' => array(),
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
  );

  // Exported permission: advise students
  $permissions['advise students'] = array(
    'name' => 'advise students',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_advisor',
  );

  // Exported permission: bypass node access
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
  );

  // Exported permission: clear crm_demo_degrees feeds
  $permissions['clear crm_demo_degrees feeds'] = array(
    'name' => 'clear crm_demo_degrees feeds',
    'roles' => array(),
  );

  // Exported permission: clear crm_demo_students feeds
  $permissions['clear crm_demo_students feeds'] = array(
    'name' => 'clear crm_demo_students feeds',
    'roles' => array(),
  );

  // Exported permission: clear students feeds
  $permissions['clear students feeds'] = array(
    'name' => 'clear students feeds',
    'roles' => array(),
  );

  // Exported permission: create relations
  $permissions['create relations'] = array(
    'name' => 'create relations',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'relation',
  );

  // Exported permission: create webform content
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any webform content
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
  );

  // Exported permission: delete own webform content
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
  );

  // Exported permission: delete relations
  $permissions['delete relations'] = array(
    'name' => 'delete relations',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'relation',
  );

  // Exported permission: edit any css_student crm_case
  $permissions['edit any css_student crm_case'] = array(
    'name' => 'edit any css_student crm_case',
    'roles' => array(),
  );

  // Exported permission: edit any webform content
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(),
  );

  // Exported permission: edit contacts
  $permissions['edit contacts'] = array(
    'name' => 'edit contacts',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm',
  );

  // Exported permission: edit own webform content
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
  );

  // Exported permission: edit relations
  $permissions['edit relations'] = array(
    'name' => 'edit relations',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'relation',
  );

  // Exported permission: export relation types
  $permissions['export relation types'] = array(
    'name' => 'export relation types',
    'roles' => array(),
  );

  // Exported permission: import crm_demo_degrees feeds
  $permissions['import crm_demo_degrees feeds'] = array(
    'name' => 'import crm_demo_degrees feeds',
    'roles' => array(),
  );

  // Exported permission: import crm_demo_students feeds
  $permissions['import crm_demo_students feeds'] = array(
    'name' => 'import crm_demo_students feeds',
    'roles' => array(),
  );

  // Exported permission: import students feeds
  $permissions['import students feeds'] = array(
    'name' => 'import students feeds',
    'roles' => array(),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
  );

  // Exported permission: post comments
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'comment',
  );

  // Exported permission: show format selection for comment
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(),
  );

  // Exported permission: show format tips
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
  );

  // Exported permission: show more format tips link
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
  );

  // Exported permission: skip comment approval
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'comment',
  );

  // Exported permission: track user history
  $permissions['track user history'] = array(
    'name' => 'track user history',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_history',
  );

  // Exported permission: view any css_student crm_case
  $permissions['view any css_student crm_case'] = array(
    'name' => 'view any css_student crm_case',
    'roles' => array(),
  );

  return $permissions;
}
