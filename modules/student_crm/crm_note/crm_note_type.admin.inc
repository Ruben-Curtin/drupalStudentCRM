<?php

/**
 * @file
 * crm_note type editing UI.
 */

/**
 * UI controller.
 */
class crm_noteTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage crm_note entity types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the crm_note type editing form.
 */
function crm_note_type_form($form, &$form_state, $crm_note_type, $op = 'edit') {

  if ($op == 'clone') {
    $crm_note_type->label .= ' (cloned)';
    $crm_note_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $crm_note_type->label,
    '#description' => t('The human-readable name of this crm_note type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($crm_note_type->type) ? $crm_note_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $crm_note_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'crm_note_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this crm_note type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting crm_note switch'),
    '#default_value' => !empty($crm_note_type->data['sample_data']),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save crm_note type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$crm_note_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete crm_note type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('crm_note_type_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function crm_note_type_form_submit(&$form, &$form_state) {
  $crm_note_type = entity_ui_form_submit_build_entity($form, $form_state);
  $crm_note_type->save();
  $form_state['redirect'] = 'admin/structure/crm_note_types';
}

/**
 * Form API submit callback for the delete button.
 */
function crm_note_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/crm_note_types/manage/' . $form_state['crm_note_type']->type . '/delete';
}
