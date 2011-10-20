<?php

/**
 * This field handler aggregates operations that can be done on a crm_note
 * under a single field providing a more flexible way to present them in a view
 */
class crm_note_handler_crm_note_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['crm_note_id'] = 'crm_note_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('crm_note', 'admin/content/crm_notes/crm_note', array($this->get_value($values, 'crm_note_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
