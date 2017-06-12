; Specify the version of Drupal being used.
core = 7.x
; Specify the api version of Drush Make.
api = 2

projects[drupal][patch][] = http://www.drupal.org/files/issues/2380361-missing-file-reset.patch

; Include modules, libraries, themes, including patches used:
includes[] = drupal-org.make
