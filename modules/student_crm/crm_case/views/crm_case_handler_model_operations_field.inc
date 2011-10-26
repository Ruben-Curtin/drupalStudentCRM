<?php

/**
 * This field handler aggregates operations that can be done on a crm_case
 * under a single field providing a more flexible way to present them in a view
 */
class crm_case_handler_crm_case_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['cid'] = 'cid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('crm_case', 'crm/cases/crm_case', array($this->get_value($values, 'cid')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
