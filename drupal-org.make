; Specify the version of Drupal being used.
core = 7.x
; Specify the api version of Drush Make.
api = 2

; Modules
projects[admin_menu][subdir] = contrib
projects[admin_menu][version] = "3.0-rc5"

projects[avatar_selection][subdir] = contrib
projects[avatar_selection][version] = "1.1"

projects[better_formats][subdir] = contrib
projects[better_formats][version] = "1.0-beta2"

projects[calendar][subdir] = contrib
projects[calendar][version] = "3.5"

projects[comment_alter][subdir] = contrib
projects[comment_alter][version] = "1.0-rc4"

projects[context][subdir] = contrib
projects[context][version] = "3.7"

projects[context_var][subdir] = contrib

projects[ctools][subdir] = contrib
projects[ctools][version] = "1.12"

projects[date][subdir] = contrib
projects[date][version] = "2.10"

projects[date_ical][subdir] = contrib
projects[date_ical][version] = "3.9"

projects[diff][subdir] = contrib
projects[diff][version] = "3.3"

projects[distro_update][subdir] = contrib

projects[draggableviews][subdir] = contrib

projects[dragndrop_upload][subdir] = contrib
projects[dragndrop_upload][version] = "1.0-alpha2"

projects[entity][subdir] = contrib
projects[entity][version] = "1.8"

projects[entitycache][subdir] = contrib
projects[entity_modified][subdir] = contrib

projects[facetapi][subdir] = contrib
projects[facetapi][version] = "1.5"

projects[features][subdir] = contrib

projects[features_date_formats][subdir] = contrib
projects[features_date_formats][download][type] = "git"
projects[features_date_formats][download][url] = "http://git.drupal.org/sandbox/rballou/1699026.git"
projects[features_date_formats][type] = "module"

projects[fieldblock][subdir] = contrib
projects[fieldblock][version] = "1.4"

projects[field_group][subdir] = contrib

projects[flag][subdir] = contrib

projects[form_placeholder][subdir] = contrib
projects[form_placeholder][version] = "1.6"

projects[heartbeat][subdir] = contrib
projects[heartbeat][version] = "1.1"

projects[i18n][subdir] = contrib

projects[imagecache_actions][subdir] = contrib
projects[imagecache_actions][version] = "1.7"

projects[itweak_upload][subdir] = contrib
projects[itweak_upload][version] = "3.x-dev"

projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = "2.7"

projects[libraries][subdir] = contrib
projects[libraries][version] = "2.3"

projects[lightbox2][subdir] = contrib
projects[lightbox2][version] = "1.0-beta1"

projects[logintoboggan][subdir] = contrib
projects[logintoboggan][version] = "1.5"

projects[mailsystem][subdir] = contrib

projects[memcache][subdir] = contrib
projects[memcache][version] = "1.5"

projects[mimemail][subdir] = contrib

projects[multiupload_filefield_widget][subdir] = contrib
projects[multiupload_filefield_widget][version] = "1.13"

projects[publish_button][subdir] = contrib
projects[publish_button][version] = "1.1"

projects[realname][subdir] = contrib
projects[realname][version] = "1.2"

projects[references][subdir] = contrib
projects[references][version] = "2.2"

projects[render_cache][subdir] = contrib

projects[rules][subdir] = contrib
projects[rules][version] = "2.10"

projects[search_autocomplete][subdir] = contrib
projects[search_autocomplete][version] = "4.7"

projects[search_facetapi][subdir] = contrib
projects[search_facetapi][version] = "1.0-beta2"

projects[stringoverrides][subdir] = contrib
projects[stringoverrides][version] = "1.8"

projects[strongarm][subdir] = contrib
projects[strongarm][version] = "2.0"

projects[themekey][subdir] = contrib

projects[token][subdir] = contrib
projects[token][version] = "1.7"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.2"

projects[userone][subdir] = contrib
projects[userone][version] = "1.0-beta1"

projects[variable][subdir] = contrib

projects[views][subdir] = contrib

projects[views_autocomplete_filters][subdir] = contrib
projects[views_autocomplete_filters][version] = "1.2"

projects[views_block_filter_block][subdir] = contrib

projects[views_fluid_grid][subdir] = contrib
projects[views_fluid_grid][version] = "3.0"

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][version] = "2.4"

projects[wysiwyg_filter][subdir] = contrib

; Openlucius modules, which can be enabled by an admin.
projects[openlucius_inline_images][subdir] = contrib
projects[openlucius_timetracker][subdir] = contrib
projects[openlucius_events_extras][subdir] = contrib
projects[openlucius_news][subdir] = contrib
projects[openlucius_ldap][subdir] = contrib
projects[openlucius_services][subdir] = contrib
projects[openlucius_board][subdir] = contrib

; Themes
projects[bootstrap][version] = "3.14"
projects[rubik][version] = "4.4"
projects[tao][version] = "3.1"

; Libraries
libraries[backbone][download][type] = "get"
libraries[backbone][download][url] = "https://github.com/jashkenas/backbone/archive/master.zip"
libraries[backbone][directory_name] = "backbone"
libraries[backbone][type] = "library"

libraries[iCalcreator][download][type] = "git"
libraries[iCalcreator][download][url] = "https://github.com/iCalcreator/iCalcreator.git"
libraries[iCalcreator][download][revision] = "e3dbec2cb3bb91a8bde989e467567ae8831a4026"
libraries[iCalcreator][directory_name] = "iCalcreator"
libraries[iCalcreator][type] = "library"

libraries[tinymce][download][type] = "file"
libraries[tinymce][download][url] = "https://github.com/downloads/tinymce/tinymce/tinymce_3.5.8.zip"
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][type] = "library"

libraries[underscore][download][type] = "get"
libraries[underscore][download][url] = "https://github.com/jashkenas/underscore/archive/master.zip"
libraries[underscore][directory_name] = "underscore"
libraries[underscore][type] = "library"

libraries[fancytree][download][type] = "git"
libraries[fancytree][download][url] = "https://github.com/mar10/fancytree.git"
libraries[fancytree][directory_name] = "fancytree"
libraries[fancytree][type] = "library"
