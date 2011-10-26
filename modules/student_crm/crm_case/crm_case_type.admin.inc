<?php

/**
 * @file
 * Model type editing UI.
 */

/**
 * Generates the crm_case type editing form.
 */
function crm_case_type_form($form, &$form_state, $crm_case_type, $op = 'edit') {

  if ($op == 'clone') {
    $crm_case_type->label .= ' (cloned)';
    $crm_case_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $crm_case_type->label,
    '#description' => t('The human-readable name of this crm_case type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($crm_case_type->type) ? $crm_case_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $crm_case_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'crm_case_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this crm_case type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save case type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$crm_case_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete crm_case type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('crm_case_type_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function crm_case_type_form_submit(&$form, &$form_state) {
  $crm_case_type = entity_ui_form_submit_build_entity($form, $form_state);
  $crm_case_type->save();
  $form_state['redirect'] = 'crm/admin/case-types';
}

/**
 * Form API submit callback for the delete button.
 */
function crm_case_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'crm/admin/case-types/manage/' . $form_state['crm_case_type']->type . '/delete';
}
