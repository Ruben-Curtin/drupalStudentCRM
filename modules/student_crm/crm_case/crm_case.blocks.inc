<?php

function crm_case_blocks_crm_create_case() {
  foreach (crm_case_get_types() as $type) {
  	$type_name = check_plain($type->type);
  	if(user_access("edit any $type_name crm_case")) {
  	  return array('subject' => 'Open new case',
  	  			   'content' => drupal_get_form('_crm_case_blocks_crm_create_case_form'));
    }
  }
}

function _crm_case_blocks_crm_create_case_form() {
	$form = array();
	
	$types = array();
	
	foreach (crm_case_get_types() as $type) {
  		$type_name = check_plain($type->type);
  		if(user_access("edit any $type_name crm_case")) {
  			$types[$type->type] = $type->label;
  		}
  	}
	
	$form['case_type'] = array(
		'#type' => 'select',
		'#title' => 'Select case type',
		'#options' => $types,
	);
	
	$item = menu_get_item();
    if(isset($item['load_functions'][2]) && $item['load_functions'][2] == 'crm_contact_load') {
	    if($item['page_callback'] == 'crm_contact_view') {
	    	$form['contact'] = array(
	    		'#type' => 'hidden',
	    		'#value' => $item['page_arguments'][0]->contact_id
	    		);
	    }
	}
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'Open case',
	);
	
	return $form;
}

function _crm_case_blocks_crm_create_case_form_submit($form, $form_state) {
	drupal_goto('crm/cases/add/'. 
				$form_state['values']['case_type'] .'/'. 
				$form_state['values']['contact']);
}