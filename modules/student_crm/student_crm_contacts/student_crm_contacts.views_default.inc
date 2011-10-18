<?php
/**
 * @file
 * student_crm_contacts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function student_crm_contacts_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'search_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_contact';
  $view->human_name = 'Search Contacts';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  /* Filter criterion: Contact: Name (contact_name) */
  $handler->display->display_options['filters']['contact_name_value']['id'] = 'contact_name_value';
  $handler->display->display_options['filters']['contact_name_value']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_value']['field'] = 'contact_name_value';
  $handler->display->display_options['filters']['contact_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['contact_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_value']['expose']['operator_id'] = 'contact_name_value_op';
  $handler->display->display_options['filters']['contact_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['contact_name_value']['expose']['operator'] = 'contact_name_value_op';
  $handler->display->display_options['filters']['contact_name_value']['expose']['identifier'] = 'contact_name_value';
  $handler->display->display_options['filters']['contact_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_value']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'search';
  $translatables['search_contacts'] = array(
    t('Master'),
    t('Search'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Contact ID'),
    t('Name'),
    t('Page'),
  );
  $export['search_contacts'] = $view;

  return $export;
}
