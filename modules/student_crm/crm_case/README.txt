Introduction
------------
The CRMCase Entities module provides a fully working yet generic example
about what is good practice in creating and administering entities and integrating
entities with the rest of Drupal Core and the Drupal ecosystem.

It is also a way to quickstart your entities development as the code can directly
be used in your own project.

As mentioned the code tries to remain as generic as possible so as to not to distract
away from the main issue and allow you to literally copy and paste into your own project.

This module does not provide any functionality to non-developers.

Installation
-------------
Once you activate the module it sets up an entity administration interface under
Admnistration > Structure > CRMCase Types

You can add crm_case entities via

Administration > Content > CRMCases

Keep in mind that you need to create some CRMCase Types before you can add entities.


Using the code in your projects
-------------------------------
The way I envision using the module in my own projects is, for the time being,
searching and replacing the word "crm_case" with the actual name I want to give my
entity and the base entity table and then adding the domain specific functionality.

It would be nice if this could eventually develop in something that is automated
so via a drush script we can get all the code ready to go.

Customising your entities in 3 simple steps.
--------------------------------------------
1. The first step is to customize your table in module.install by adding any column
tables specific to your entity.

Your would only every really need to change the CRMCase entity and CRMCase type as CRMCaseType
is simply there to provide a means to represent your different entity bundles.

Also keep in mind that if you can get away with adding data only in serialized form in
the data column you can avoid doing anything to the tables.

2. You would then want to customize the edit form for your entity - which you will find in
crm_case.admin.inc and customize the behaviour of your entity on save, delete which you
do via the CRMCaseController class in crm_case.module.

Currently, I am overwriting the create function to add some extra info. If you stick to
the $data variable and save extra data in serialized form (and not adding new columns
to your table)  - just like the crm_case entity does with the checkbox - there is nothing
else you need to do. If you have added new columns you need to add support for them
in $crm_case->create but not necessarily $crm_case->save unless you are doing something specific.

3. Finally you can play around within the theming for your entity by looking into crm_case.tpl.php and
crm_case-sample-data.tpl.php



