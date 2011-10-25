<?php
/**
 * @file
 * crm_student.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_student_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'search_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_contact';
  $view->human_name = 'Search students';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'contact_id' => 'contact_id',
    'field_first_name' => 'field_first_name',
    'contact_image' => 'contact_image',
    'field_last_name' => 'field_last_name',
    'field_student_status' => 'field_student_status',
    'field_student_id' => 'field_student_id',
    'field_student_degrees' => 'field_student_degrees',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'contact_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'contact_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_degrees' => array(
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
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No students found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['relation_advisor_user']['id'] = 'relation_advisor_user';
  $handler->display->display_options['relationships']['relation_advisor_user']['table'] = 'crm_contact';
  $handler->display->display_options['relationships']['relation_advisor_user']['field'] = 'relation_advisor_user';
  $handler->display->display_options['relationships']['relation_advisor_user']['label'] = 'Advisor';
  $handler->display->display_options['relationships']['relation_advisor_user']['required'] = 0;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: Contact: Image */
  $handler->display->display_options['fields']['contact_image']['id'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['table'] = 'field_data_contact_image';
  $handler->display->display_options['fields']['contact_image']['field'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['label'] = '';
  $handler->display->display_options['fields']['contact_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['contact_image']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['contact_image']['settings'] = array(
    'image_style' => 'contact_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['contact_image']['field_api_classes'] = 0;
  /* Field: Contact: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Contact: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: Contact: Student ID */
  $handler->display->display_options['fields']['field_student_id']['id'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['fields']['field_student_id']['field'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['field_api_classes'] = 0;
  /* Field: Contact: Status */
  $handler->display->display_options['fields']['field_student_status']['id'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['table'] = 'field_data_field_student_status';
  $handler->display->display_options['fields']['field_student_status']['field'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['field_api_classes'] = 0;
  /* Field: Contact: Degrees */
  $handler->display->display_options['fields']['field_student_degrees']['id'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['table'] = 'field_data_field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['field'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_student_degrees']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['field_api_classes'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'relation_advisor_user';
  $handler->display->display_options['fields']['name']['label'] = 'Advisor(s)';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 1;
  $handler->display->display_options['fields']['name']['empty_zero'] = 1;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
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
  /* Filter criterion: CRM Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'Student';

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
    t('No students found.'),
    t('Advisor'),
    t('crm/contact/[contact_id]'),
    t('First Name'),
    t('Last name'),
    t('Student ID'),
    t('Status'),
    t('Degrees'),
    t('Advisor(s)'),
    t('Name'),
    t('Page'),
  );
  $export['search_contacts'] = $view;

  return $export;
}
