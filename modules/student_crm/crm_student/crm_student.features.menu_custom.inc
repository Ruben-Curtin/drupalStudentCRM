<?php
/**
 * @file
 * crm_student.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function crm_student_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-crm-navigation
  $menus['menu-crm-navigation'] = array(
    'menu_name' => 'menu-crm-navigation',
    'title' => 'CRM Navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CRM Navigation');


  return $menus;
}
