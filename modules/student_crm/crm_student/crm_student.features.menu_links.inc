<?php
/**
 * @file
 * crm_student.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_student_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:search
  $menu_links['menu-crm-navigation:search'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Students',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Students');


  return $menu_links;
}
