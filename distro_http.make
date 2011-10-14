; Use this file to build a full distribution including Drupal core and the
; Student CRM profile using the following command:
;
; drush make distro.make <target directory>

api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = "7"

; Add Student CRM to the full distribution build.
projects[student_crm][type] = profile
projects[student_crm][version] = 1.x-dev
projects[student_crm][download][type] = git
projects[student_crm][download][url] = http://github.com/kevee/drupalStudentCRM.git
projects[student_crm][download][branch] = master