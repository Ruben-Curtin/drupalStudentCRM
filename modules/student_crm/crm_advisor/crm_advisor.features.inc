<?php
/**
 * @file
 * crm_advisor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_advisor_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_default") {
    return array("version" => "1");
  }
}
