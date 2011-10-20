<?php

/**
 * @file
 * Providing extra functionality for the crm_note UI via views.
 */


/**
 * Implements hook_views_data()
 */
function crm_note_views_data_alter(&$data) { 
  $data['crm_note']['link_crm_note'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the crm_note.'),
      'handler' => 'crm_note_handler_link_field',
    ),
  );
  $data['crm_note']['edit_crm_note'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the crm_note.'),
      'handler' => 'crm_note_handler_edit_link_field',
    ),
  );
  $data['crm_note']['delete_crm_note'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the crm_note.'),
      'handler' => 'crm_note_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows crm_notes/crm_note/%crm_note_id/op
  $data['crm_note']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this crm_note.'),
      'handler' => 'crm_note_handler_crm_note_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function crm_note_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'crm_notes';
  $view->description = 'A list of all crm_notes';
  $view->tag = 'crm_notes';
  $view->base_table = 'crm_note';
  $view->human_name = 'crm_notes';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'crm_notes';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any crm_note type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'crm_note_id' => 'crm_note_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'crm_note_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No crm_notes have been created yet';
  /* Field: crm_note: crm_note ID */
  $handler->display->display_options['fields']['crm_note_id']['id'] = 'crm_note_id';
  $handler->display->display_options['fields']['crm_note_id']['table'] = 'crm_note';
  $handler->display->display_options['fields']['crm_note_id']['field'] = 'crm_note_id';
  $handler->display->display_options['fields']['crm_note_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['crm_note_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['crm_note_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['crm_note_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['crm_note_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['crm_note_id']['empty_zero'] = 0;
  /* Field: crm_note: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_note';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: crm_note: Link */
  $handler->display->display_options['fields']['link_crm_note']['id'] = 'link_crm_note';
  $handler->display->display_options['fields']['link_crm_note']['table'] = 'crm_note';
  $handler->display->display_options['fields']['link_crm_note']['field'] = 'link_crm_note';
  $handler->display->display_options['fields']['link_crm_note']['label'] = 'View';
  $handler->display->display_options['fields']['link_crm_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_crm_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_crm_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_crm_note']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_crm_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_crm_note']['empty_zero'] = 0;
  /* Field: crm_note: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'crm_note';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'crm_notes_admin_page');
  $handler->display->display_options['path'] = 'admin/content/crm_notes/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'crm_notes';
  $handler->display->display_options['tab_options']['description'] = 'Manage crm_notes';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['crm_notes'] = array(
    t('Master'),
    t('crm_notes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No crm_notes have been created yet'),
    t('crm_note ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
