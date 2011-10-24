<?php
/**
 * @file
 * crm_advisor.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function crm_advisor_taxonomy_default_vocabularies() {
  return array(
    'advisor_type' => array(
      'name' => 'Advisor type',
      'machine_name' => 'advisor_type',
      'description' => 'Types of advisors',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
