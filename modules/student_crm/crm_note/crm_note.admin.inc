<?php

/**
 * @file
 * crm_note editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class crm_noteUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'crm_notes',
      'description' => 'Add edit and update crm_notes.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list of crm_notes.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a crm_note',
      'description' => 'Add a new crm_note',
      'page callback'  => 'crm_note_add_page',
      'access callback'  => 'crm_note_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'crm_note.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
    
    // Add menu items to add each different type of entity.
    foreach (crm_note_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'crm_note_form_wrapper',
        'page arguments' => array(crm_note_create(array('type' => $type->type))),
        'access callback' => 'crm_note_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'crm_note.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing crm_note entities
    $items[$this->path . '/crm_note/' . $wildcard] = array(
      'page callback' => 'crm_note_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'crm_note_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'crm_note.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/crm_note/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/crm_note/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'crm_note_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'crm_note_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'crm_note.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing crm_notes
    $items['crm_note/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'crm_note_page_title',
      'title arguments' => array(1),
      'page callback' => 'crm_note_page_view',
      'page arguments' => array(1),
      'access callback' => 'crm_note_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add crm_note Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('crm_note_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a crm_note.
 *
 * @param $crm_note
 *   The crm_note object being edited by this form.
 *
 * @see crm_note_edit_form()
 */
function crm_note_form_wrapper($crm_note) {
  // Add the breadcrumb for the form's location.
  crm_note_set_breadcrumb();
  return drupal_get_form('crm_note_edit_form', $crm_note);
}


/**
 * Form callback wrapper: delete a crm_note.
 *
 * @param $crm_note
 *   The crm_note object being edited by this form.
 *
 * @see crm_note_edit_form()
 */
function crm_note_delete_form_wrapper($crm_note) {
  // Add the breadcrumb for the form's location.
  //crm_note_set_breadcrumb();
  return drupal_get_form('crm_note_delete_form', $crm_note);
}


/**
 * Form callback: create or edit a crm_note.
 *
 * @param $crm_note
 *   The crm_note object to edit or for a create form an empty crm_note object
 *     with only a crm_note type defined.
 */
function crm_note_edit_form($form, &$form_state, $crm_note) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('crm_note Name'),
    '#default_value' => isset($crm_note->name) ? $crm_note->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting crm_note switch'),
    '#default_value' => isset($crm_note->data['sample_data']) ? $crm_note->data['sample_data'] : 1,
  );

  // Add the field related form elements.
  $form_state['crm_note'] = $crm_note;
  field_attach_form('crm_note', $crm_note, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save crm_note'),
    '#submit' => $submit + array('crm_note_edit_form_submit'),
  );
  
  if (!empty($crm_note->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete crm_note'),
      '#suffix' => l(t('Cancel'), 'admin/content/crm_notes'),
      '#submit' => $submit + array('crm_note_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'crm_note_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the crm_note form
 */
function crm_note_edit_form_validate(&$form, &$form_state) {
  $crm_note = $form_state['crm_note'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('crm_note', $crm_note, $form, $form_state);
}


/**
 * Form API submit callback for the crm_note form.
 * 
 * @todo remove hard-coded link
 */
function crm_note_edit_form_submit(&$form, &$form_state) {
  
  $crm_note = entity_ui_controller('crm_note')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the crm_note and go back to the list of crm_notes
  
  // Add in created and changed times.
  if ($crm_note->is_new = isset($crm_note->is_new) ? $crm_note->is_new : 0){
    $crm_note->created = time();
  }

  $crm_note->changed = time();
  
  $crm_note->save();
  $form_state['redirect'] = 'admin/content/crm_notes';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function crm_note_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/crm_notes/crm_note/' . $form_state['crm_note']->crm_note_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a crm_note.
 *
 * @param $crm_note
 *   The crm_note to delete
 *
 * @see confirm_form()
 */
function crm_note_delete_form($form, &$form_state, $crm_note) {
  $form_state['crm_note'] = $crm_note;

  $form['#submit'][] = 'crm_note_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete crm_note %name?', array('%name' => $crm_note->name)),
    'admin/content/crm_notes/crm_note',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for crm_note_delete_form
 */
function crm_note_delete_form_submit($form, &$form_state) {
  $crm_note = $form_state['crm_note'];

  crm_note_delete($crm_note);

  drupal_set_message(t('The crm_note %name has been deleted.', array('%name' => $crm_note->name)));
  watchdog('crm_note', 'Deleted crm_note %name.', array('%name' => $crm_note->name));

  $form_state['redirect'] = 'admin/content/crm_notes';
}



/**
 * Page to add crm_note Entities.
 *
 * @todo Pass this through a proper theme function
 */
function crm_note_add_page() {
  $controller = entity_ui_controller('crm_note');
  return $controller->addPage();
}


/**
 * Displays the list of available crm_note types for crm_note creation.
 *
 * @ingroup themeable
 */
function theme_crm_note_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="crm_note-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer crm_note types')) {
      $output = '<p>' . t('crm_note Entities cannot be added because you have not created any crm_note types yet. Go to the <a href="@create-crm_note-type">crm_note type creation page</a> to add a new crm_note type.', array('@create-crm_note-type' => url('admin/structure/crm_note_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No crm_note types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative crm_note pages.
 */
function crm_note_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('crm_notes'), 'admin/content/crm_notes'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



