<?php

function crm_advisor_advisor_autocomplete_list($string = '') {
  $matches = array();
  if ($string) {
    $result = db_select('users', 'u')
    		  ->fields('u', array('name'))
    		  ->leftJoin('users_roles', 'r', 'r.uid = u.uid')
    		  ->leftJoin('role_permission', 'p', 'p.rid = r.rid')
    		  ->condition('u.name', db_like($string) . '%', 'LIKE')
    		  ->condition('p.permission', 'advise students')
    		  ->range(0, 10)
    		  ->execute();
    foreach ($result as $user) {
      $user = user_load($user->uid);
      $matches[$user->name] = check_plain(theme('username', array('account' => $user->name)));
    }
  }

  drupal_json_output($matches);
}