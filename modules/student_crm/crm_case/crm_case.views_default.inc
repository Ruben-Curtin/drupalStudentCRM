<?php
/**
 * @file
 * crm_case.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_case_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_contact_cases';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_case';
  $view->human_name = 'CRM Contact Cases';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cases';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No cases found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: CRM Case: Relation: CRM Contact Case (crm_case <-> crm_contact) */
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_contact']['id'] = 'relation_crm_contact_case_crm_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_contact']['table'] = 'crm_case';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_contact']['field'] = 'relation_crm_contact_case_crm_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_contact']['required'] = 0;
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_contact']['r_index'] = '-1';
  /* Field: CRM Case: Crm case ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'crm_case';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = 'Case ID';
  $handler->display->display_options['fields']['cid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['cid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['cid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['cid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['cid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['cid']['format_plural'] = 0;
  /* Field: CRM Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
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
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: CRM Case: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_case';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Case type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'relation_crm_contact_case_crm_contact';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['contact_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contact_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['contact_id']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/contact/%/cases';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Cases';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Open Cases';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'type' => 'type',
  );
  $handler->display->display_options['row_options']['separator'] = ' - ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Case: Crm case ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'crm_case';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['cid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['cid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['cid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['cid']['format_plural'] = 0;
  /* Field: CRM Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'crm/case/[case_id]';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: CRM Case: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_case';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'relation_crm_contact_case_crm_contact';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['contact_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['contact_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contact_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['contact_id']['not'] = 0;
  $translatables['crm_contact_cases'] = array(
    t('Master'),
    t('Cases'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No cases found.'),
    t('CRM Contact Case'),
    t('Case ID'),
    t('.'),
    t(','),
    t('Name'),
    t('Case type'),
    t('All'),
    t('Page'),
    t('Block'),
    t('Open Cases'),
    t('crm/case/[case_id]'),
  );
  $export['crm_contact_cases'] = $view;

  return $export;
}
