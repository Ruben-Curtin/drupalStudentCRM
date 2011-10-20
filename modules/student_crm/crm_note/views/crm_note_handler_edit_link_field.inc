<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class crm_note_handler_edit_link_field extends crm_note_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy crm_note to check access against
    $dummy_crm_note = (object) array('type' => $type);
    if (!crm_note_access('edit', $dummy_crm_note)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $crm_note_id = $values->{$this->aliases['crm_note_id']};
    
    return l($text, 'admin/content/crm_notes/crm_note/' . $crm_note_id . '/edit');
  }
}
