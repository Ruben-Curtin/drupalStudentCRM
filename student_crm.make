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

projects[views][subdir] = "contrib"
projects[views][version] = "3.0-rc1"