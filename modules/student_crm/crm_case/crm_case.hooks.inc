<?php
/**
 * @file
 * Hooks provided by this module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Acts on cases being loaded from the database.
 *
 * This hook is invoked during case loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $cases
 *   An array of case entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_crm_case_load(array $cases) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a case is inserted.
 *
 * This hook is invoked after the case is inserted into the database.
 *
 * @param CRMCase $case
 *   The case that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_crm_case_insert(CRMCase $case) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('crm_case', $case),
      'extra' => print_r($case, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a case being inserted or updated.
 *
 * This hook is invoked before the case is saved to the database.
 *
 * @param CRMCase $case
 *   The case that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_crm_case_presave(CRMCase $case) {
  $case->name = 'foo';
}

/**
 * Responds to a case being updated.
 *
 * This hook is invoked after the case has been updated in the database.
 *
 * @param CRMCase $case
 *   The case that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_crm_case_update(CRMCase $case) {
  db_update('mytable')
    ->fields(array('extra' => print_r($case, TRUE)))
    ->condition('id', entity_id('crm_case', $case))
    ->execute();
}

/**
 * Responds to case deletion.
 *
 * This hook is invoked after the case has been removed from the database.
 *
 * @param CRMCase $case
 *   The case that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_crm_case_delete(CRMCase $case) {
  db_delete('mytable')
    ->condition('pid', entity_id('crm_case', $case))
    ->execute();
}

/**
 * @}
 */