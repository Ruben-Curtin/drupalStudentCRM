; Make file for student_crm profile.

projects[drupal][type] = core
core = 7.x
api = 2

;Adding the profiler module
;Profiler is in dev and we can't patch libraries, so including it in the repository for now
;libraries[profiler][download][type] = "get"
;libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz"
;libraries[profiler][destination] = "libraries/profiler"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.0-rc1"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-beta10"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta4"

projects[Guiders-JS][subdir] = "contrib"
projects[Guiders-JS][version] = "1.0"

projects[views][subdir] = "contrib"
projects[views][version] = "3.0-rc1"

; Modules in development

; Trellon CRM

projects[crm][type] = module
projects[crm][subdir] = "contrib"
projects[crm][version] = "1.x-dev"
projects[crm][download][type] = "git"
projects[crm][download][url] = "http://git.drupal.org/sandbox/citizenkane/1260982.git"
projects[crm][download][branch] = "master"

; Formalize module
projects[formalize][type] = module
projects[formalize][subdir] = "contrib"
projects[formalize][version] = "1.x-dev"
projects[formalize][download][type] = "git"
projects[formalize][download][url] = "http://git.drupal.org/project/formalize.git"
projects[formalize][download][branch] = "7.x-1.x"

; Libraries

; Download the Formalize library
libraries[guiders][download][type] = "get"
libraries[guiders][download][url] = "https://github.com/nathansmith/formalize/tarball/master"
libraries[guiders][directory_name] = "formalize"
libraries[guiders][destination] = "libraries"


; Download the guidersJS library
libraries[guiders][download][type] = "get"
libraries[guiders][download][url] = "https://github.com/jeff-optimizely/Guiders-JS/tarball/master"
libraries[guiders][directory_name] = "guiders"
libraries[guiders][destination] = "libraries"