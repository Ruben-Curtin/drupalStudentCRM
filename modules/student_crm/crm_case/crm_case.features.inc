<?php
/**
 * @file
 * crm_case.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_case_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function crm_case_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
