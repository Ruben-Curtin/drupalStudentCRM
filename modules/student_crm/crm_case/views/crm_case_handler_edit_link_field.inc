<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class crm_case_handler_edit_link_field extends crm_case_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy crm_case to check access against
    $dummy_crm_case = (object) array('type' => $type);
    if (!crm_case_access('edit', $dummy_crm_case)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $cid = $values->{$this->aliases['cid']};
    
    return l($text, 'crm/cases/case/' . $cid . '/edit');
  }
}
