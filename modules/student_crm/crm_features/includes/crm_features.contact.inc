<?php

/**
 * Implements hook_features_export_options().
 */
function crm_contact_features_export_options() {
  $names = array();
  foreach(crm_contact_types() as $type) {
  	$names[$type->type] = $type->name;
  }
  return $names;
}

/**
 * Implements hook_features_export.
 */
function crm_contact_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  $map = features_get_default_map('crm_contact');

  foreach ($data as $type) {
    if ($info = crm_contact_type_load($type)) {
      $export['features']['crm_contact'][$type] = $type;
      $export['dependencies']['crm'] = 'crm';
      $export['dependencies']['features'] = 'features';
      
      $fields = field_info_instances('crm_contact', $type);
      foreach ($fields as $name => $field) {
        $pipe['field'][] = "crm_contact-{$field['bundle']}-{$field['field_name']}";
      }
    }
  }
  
  return $pipe;
}

/**
 * Implements hook_features_export_render().
 */
function crm_contact_features_export_render($module, $data, $export = NULL) {
  $elements = array(
    'type' => TRUE,
    'name' => FALSE,
    'description' => TRUE,
    'custom' => FALSE,
  );
  $output = array();
  $output[] = '  $items = array(';
  foreach ($data as $type) {
    if ($info = crm_contact_type_load($type)) {
      $output[] = "    '{$type}' => array(";
      foreach ($elements as $key => $t) {
        if ($t) {
          $text = str_replace("'", "\'", $info->$key);
          $text = !empty($text) ? "t('{$text}')" : "''";
          $output[] = "      '{$key}' => {$text},";
        }
        else {
          $output[] = "      '{$key}' => '{$info->$key}',";
        }
      }
      $output[] = "    ),";
    }
  }
  $output[] = '  );';
  $output[] = '  return $items;';
  $output = implode("\n", $output);
  return array('crm_features_contact_defaults' => $output);
}

/**
 * Implements hook_features_revert().
 *
 * @param $module
 * name of module to revert content for
 */
function crm_contact_features_revert($module = NULL) {
  if ($default_types = features_get_default('crm_features_contact_defaults', $module)) {
    foreach ($default_types as $type_name => $type_info) {
      db_delete('crm_contact_type')
        ->condition('type', $type_name)
        ->execute();
    }
    cache_clear_all();
    menu_rebuild();
  }
}

/**
 * Implements hook_features_disable().
 *
 * @param $module
 *   Name of module that has been disabled.
 */
function crm_contact_features_disable($module) {
  if ($default_types = features_get_default('crm_contact', $module)) {
    foreach ($default_types as $type_name => $type_info) {
      $type_info = crm_contact_type_load($type_name);
      $type_info->custom = 1;
      crm_contact_type_save($type_info);
    }
  }
}

/**
 * Implements hook_features_enable().
 *
 * @param $module
 *   Name of module that has been enabled.
 */
function crm_contact_features_enable($module) {
  if ($default_types = features_get_default('crm_contact', $module)) {
    foreach ($default_types as $type_name => $type_info) {
      $type_info = (object)$type_info;
      // Ensure the type exists.
      if ($existing_type = crm_contact_type_load($type_name)) {
        $existing_type = (object)$existing_type;
        $existing_type->custom = 0;
        crm_contact_type_save($type_info);
      }
      else {
        $type_info->is_new = TRUE;
        crm_contact_type_save($type_info);
      }
    }
  }
}
