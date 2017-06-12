<?php
/**
 * @file
 * This file contains the forms and functions for the onboarding.
 */

/**
 * The form constructor for the onboarding form.
 *
 * @param bool $js
 *   Whether js was enabled.
 * @param int $step
 *   Which step where at.
 *
 * @ingroup forms
 *
 * @link http://internetdevels.com/blog/ctools-multistep-wizard-example
 *
 * @return array
 *   Returns the form array.
 */
function openlucius_onboarding_form($js = FALSE, $step = 0) {
  // Check if this is called as a modal.
  if ($js) {
    ctools_include('modal');
    ctools_include('ajax');
  }

  // Define array for ctools multistep wizard.
  $form_info = array(
    'id'              => 'openlucius_onboarding',
    'path'            => "onboarding/" . ($js ? 'ajax' : 'nojs') . "/form/%step",
    'show trail'      => FALSE,
    'show back'       => FALSE,
    'show cancel'     => FALSE,
    'show return'     => FALSE,
    'next callback'   => 'openlucius_onboarding_form_next',
    'finish callback' => 'openlucius_onboarding_form_finish',
    'finish text'     => t('Continue'),
    'current_step'    => $step,
    'divider'         => '',
    // Define forms order.
    'order'           => array(
      'start'  => t('Welcome in OpenLucius'),
      'second' => t('Please start by completing your profile'),
      'third'  => t("Who's on your team?"),
      'fourth' => t('What should we call your first workgroup?'),
    ),

    // Define forms.
    'forms'           => array(
      'start'  => array(
        'form id' => 'openlucius_onboarding_form_welcome',
      ),
      'second' => array(
        'form id' => 'openlucius_onboarding_form_profile',
      ),
      'third'  => array(
        'form id' => 'openlucius_onboarding_form_team',
      ),
      'fourth' => array(
        'form id' => 'openlucius_onboarding_form_name',
      ),
    ),
  );

  // If someone has finished the onboarding process unset the optional
  // third and fourth form.
  if (variable_get('openlucius_onboarding_initial', 0) == 1) {
    unset($form_info['order']['third']);
    unset($form_info['forms']['third']);
    unset($form_info['order']['fourth']);
    unset($form_info['forms']['fourth']);
  }

  // We're not using any real storage here, so we're going to set our
  // object_id to 1. When using wizard forms, id management turns
  // out to be one of the hardest parts. Editing an object with an id
  // is easy, but new objects don't usually have ids until somewhere
  // in creation.
  //
  // We skip all this here by just using an id of 1.
  $object_id = 1;

  // Load any requirements.
  module_load_include('inc', 'openlucius_onboarding', 'includes/cache');

  // Check if we have a step.
  if (empty($step)) {

    // We reset the form when $step is NULL because that means they have
    // for whatever reason started over.
    openlucius_onboarding_cache_clear($object_id);
    $step = 'start';
  }

  // This automatically gets defaults if there wasn't anything saved.
  $object = openlucius_onboarding_cache_get($object_id);

  // Live $form_state changes.
  $form_state = array(
    'ajax'      => $js,

    // Put our object and ID into the form state cache so we can easily find it.
    'object_id' => $object_id,
    'object'    => &$object,
  );

  // Send this all off to our form.
  // This is like drupal_get_form only wizardly.
  ctools_include('wizard');

  // Initiate multistep form.
  $form = ctools_wizard_multistep_form($form_info, $step, $form_state);

  // Render the form.
  $output = drupal_render($form);

  // If javascript is active, we have to use a render array.
  if ($js) {
    $commands = array();

    // Check if we have output and the user has not yet completed the form.
    if ($output === FALSE || !empty($form_state['complete'])) {
      ctools_add_js('ajax-responder');

      // Dismiss the modal.
      $commands[] = ctools_modal_command_dismiss();
      $commands[] = ctools_ajax_command_redirect('<front>', 0, array('query' => array('tour' => 'frontpage_nl')));

      // Allow other modules to add commands to the list.
      $extra_commands = openlucius_onboarding_after($commands);

      // If we have a redirect.
      if (!empty($extra_commands['redirect'])) {
        $commands[] = ctools_ajax_command_redirect('<front>', 0, $extra_commands['redirect']);
      }
      else {
        $commands[] = ctools_ajax_command_redirect('<front>');
      }

      // TODO improve the above so other modules may handle it directly.
      // For now sending ctools_ajax_command_redirect via hook is missing
      // the query.
    }
    else {
      $commands = ctools_modal_form_render($form_state, $output);

      // Hide close button.
      $commands[] = ajax_command_invoke('.modal-header .close', 'addClass', array('hidden'));

      // Make overlay plain white without transparency.
      $commands[] = ajax_command_invoke('#modalBackdrop', 'addClass', array('opaque'));

      // Remove escape behaviour.
      $commands[] = array(
        'command' => 'modalRemoveEscapeBehaviour',
        'data'    => TRUE,
      );
    }
    print ajax_render($commands);
  }

  // No js so lets render it and return the output.
  else {

    if ($output === FALSE || !empty($form_state['complete'])) {
      drupal_goto('<front>');
    }
    else {
      return $output;
    }
  }
}

/**
 * Initial intro item contains no fields only a movie.
 *
 * @ingroup forms
 */
function openlucius_onboarding_form_welcome($form, &$form_state) {

  $form['video'] = array(
    '#markup' => sprintf('<iframe id="onboarding-video" src="%s" frameborder="0" allowfullscreen></iframe>', variable_get('openlucius_onboarding_video', '')),
  );

  // Add form theming.
  $form['#theme'] = array('openlucius_onboarding_start');
  $form_state['form_info']['current_step'] = 'start';

  return $form;
}

/**
 * The form constructor for the profile form.
 *
 * @ingroup forms
 */
function openlucius_onboarding_form_profile($form, &$form_state) {
  global $user;

  // Load account for settings.
  $account = user_load($user->uid);

  $form['name'] = array(
    '#title'      => t('FULL NAME'),
    '#type'       => 'textfield',
    '#attributes' => array(
      'placeholder' => t('First & Last Name.'),
    ),
    '#required'   => TRUE,
  );

  $form['email'] = array(
    '#title'         => t('EMAIL'),
    '#type'          => 'textfield',
    '#attributes'    => array(
      'placeholder' => t('Your mail address.'),
    ),
    '#required'      => TRUE,
    '#default_value' => $account->mail,
  );

  $form['password'] = array(
    '#title'      => t('PASSWORD'),
    '#type'       => 'password',
    '#attributes' => array(
      'placeholder' => t('Your password.'),
    ),
    '#required'   => TRUE,
  );

  // Holder for the image.
  $form['picture'] = array(
    '#prefix' => '<div class="profile-image">',
    '#suffix' => '</div>',
  );

  $form['picture']['preview'] = array(
    '#markup' => openlucius_core_fetch_user_image(NULL),
  );

  $form['picture']['picture_upload'] = array(
    '#type'        => 'file',
    '#title'       => t('Upload picture'),
    '#size'        => 48,
    '#description' => t('Your virtual face or picture. Pictures larger than @dimensions pixels will be scaled down.', array('@dimensions' => variable_get('user_picture_dimensions', '85x85'))) . ' ' . filter_xss_admin(variable_get('user_picture_guidelines', '')),
    '#attributes'  => array(
      'class' => array(
        'openlucius-onboarding-upload',
      ),
    ),
  );

  // Add form theming.
  $form['#theme'] = array('openlucius_onboarding_profile');

  // Use Drupal default validate.
  $form['#validate'][] = 'user_validate_picture';

  // Attach javascript for image preview.
  $form['#attached'] = array(
    'js' => array(drupal_get_path('module', 'openlucius_onboarding') . '/js/openlucius_onboarding.js'),
  );

  $form_state['form_info']['current_step'] = 'second';

  return $form;
}

/**
 * Handles submit for the profile form.
 */
function openlucius_onboarding_form_profile_submit($form, &$form_state) {
  global $user;

  // Get values.
  $values = $form_state['values'];

  // Store form values.
  $form_state['object']->name = $values['name'];
  $form_state['object']->email = $values['email'];
  $form_state['object']->password = $values['password'];

  // Check if we have an upload :).
  if (!empty($values['picture_upload'])) {
    $picture = $values['picture_upload'];

    // If the picture is a temporary file move it to its final location and
    // make it permanent.
    if (!$picture->status) {
      $info = image_get_info($picture->uri);
      $picture_directory = file_default_scheme() . '://' . variable_get('user_picture_path', 'pictures');

      // Prepare the pictures directory.
      file_prepare_directory($picture_directory, FILE_CREATE_DIRECTORY);
      $destination = file_stream_wrapper_uri_normalize($picture_directory . '/picture-' . $user->uid . '-' . REQUEST_TIME . '.' . $info['extension']);

      // Move the temporary file into the final location.
      if ($picture = file_move($picture, $destination, FILE_EXISTS_RENAME)) {
        $picture->status = FILE_STATUS_PERMANENT;
        $user->picture = file_save($picture);
        file_usage_add($picture, 'user', 'user', $user->uid);
      }
    }

    // Delete the previous picture if it was deleted or replaced.
    if (!empty($user->original->picture->fid)) {
      file_usage_delete($user->original->picture, 'user', 'user', $user->uid);
      file_delete($user->original->picture);
    }

    // Set / override picture.
    $form_state['object']->picture = $picture->fid;
  }
}

/**
 * Form constructor for the onboarding team invite form.
 *
 * @see openlucius_onboarding_form_team_submit()
 *
 * @ingroup forms
 */
function openlucius_onboarding_form_team($form, &$form_state) {
  // Add the placeholder image.
  $form['#default_image'] = openlucius_core_fetch_user_image(NULL);

  // Add 4 user fields.
  for ($i = 0; $i < OPENLUCIUS_ONBOARDING_INVITE_LIMIT; $i++) {

    $form['user_invite_' . $i] = array(
      '#type'       => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Teammates email'),
      ),
    );
  }

  $form_state['form_info']['current_step'] = 'third';

  // Add form theming.
  $form['#theme'] = array('openlucius_onboarding_team');

  return $form;
}

/**
 * Submit handler for the team invite form.
 *
 * @see openlucius_onboarding_form_team()
 */
function openlucius_onboarding_form_team_submit($form, &$form_state) {
  // Get values.
  $values = $form_state['values'];

  // Add 4 user fields.
  for ($i = 0; $i < OPENLUCIUS_ONBOARDING_INVITE_LIMIT; $i++) {

    if (!empty($values['user_invite_' . $i])) {
      $form_state['object']->invites[] = check_plain($values['user_invite_' . $i]);
    }
  }
}

/**
 * Form constructor for the initial group name.
 *
 * @see openlucius_onboarding_form_name_submit()
 */
function openlucius_onboarding_form_name($form, &$form_state) {
  $users = array();

  // Fetch default image.
  $default = openlucius_core_fetch_user_image(NULL);

  // Check if we have a picture.
  if (!empty($form_state['object']->picture)) {
    $picture = file_load($form_state['object']->picture);
    $user_image = theme('image_style', array(
      'style_name' => 'ol_50x50',
      'path'       => $picture->uri,
    ));

    // Add user and image.
    $users[t('You')] = $user_image;
  }
  else {
    // Add user and image.
    $users[$form_state['object']->name] = $default;
  }

  // Add invited users to the list.
  if (!empty($form_state['object']->invites)) {
    foreach ($form_state['object']->invites as $invited_email) {
      $users[$invited_email] = $default;
    }
  }

  // Add users to the form.
  $form['#heading_users'] = $users;

  // Add group element.
  $form['group'] = array(
    '#description' => t('Your teammates will be added to this workgroup'),
    '#attributes'  => array(
      'placeholder' => t('ex. Marketing, Design, Executive...'),
    ),
    '#type'        => 'textfield',
    '#required'    => TRUE,
  );

  $form_state['form_info']['current_step'] = 'fourth';

  // Add form theming.
  $form['#theme'] = array('openlucius_onboarding_name');

  return $form;
}

/**
 * Submission handler for the onboarding name form.
 *
 * @see openlucius_onboarding_form_name()
 */
function openlucius_onboarding_form_name_submit($form, &$form_state) {
  $form_state['object']->group = $form_state['values']['group'];
}

/**
 * Handles the 'next' click on the onboarding form.
 */
function openlucius_onboarding_form_next(&$form_state) {
  module_load_include('inc', 'openlucius_onboarding', 'includes/cache');
  openlucius_onboarding_cache_set($form_state['object_id'], $form_state['object']);
}

/**
 * Handles the final continue click on the onboarding form.
 */
function openlucius_onboarding_form_finish(&$form_state) {
  global $user, $language;

  // Load full user object.
  $account = user_load($user->uid);

  // Set form state so we can exit the modal or form.
  $form_state['complete'] = TRUE;

  // Process and store the data.
  if (!empty($form_state['object'])) {
    $object = $form_state['object'];

    // Replace settings.
    $edit = array(
      'name'                => $object->name,
      'mail'                => $account->mail,
      'pass'                => $object->password,
      'onboarding_complete' => array(LANGUAGE_NONE => array(array('value' => 1))),
    );

    // Check if we have a picture.
    if (!empty($object->picture)) {
      $edit['picture'] = file_load($object->picture);
    }

    // Store the changes.
    user_save($account, $edit);

    // Check if this is the first run of this form.
    if (variable_get('openlucius_onboarding_initial', 0) === 0) {

      // Create a new group.
      $node = new stdClass();
      $node->type = "ol_group";
      $node->title = $object->group;
      $node->uid = 1;
      $node->language = LANGUAGE_NONE;
      node_object_prepare($node);
      $node = node_submit($node);
      node_save($node);

      // Fetch default buttons for setting the enabled apps.
      $default_buttons = openlucius_core_default_group_header_buttons();

      $new_group_settings = array();
      foreach ($default_buttons as $button_key => $button_values) {
        $new_group_settings[$button_key] = variable_get('openlucius_core_' . $button_key . '_enabled', $button_key);
      }

      // Fetch all group settings.
      $group_settings = variable_get('openlucius_core_group_settings');

      // Store the settings.
      $group_settings[$node->nid] = $new_group_settings;
      variable_set('openlucius_core_group_settings', $group_settings);

      // Invite users to group.
      if (!empty($object->invites)) {

        // Loop through and create users.
        foreach ($object->invites as $invite_email) {

          // User settings.
          $new_user = array(
            'name'         => $invite_email,
            'mail'         => $invite_email,
            'pass'         => user_password(),
            'status'       => 1,
            'field_groups' => array(LANGUAGE_NONE => array(array('nid' => $node->nid))),
            'access'       => REQUEST_TIME,
            'roles'        => array(
              DRUPAL_AUTHENTICATED_RID                => 'authenticated user',
              OPENLUCIUS_CORE_OPENLUCIUS_DEFAULT_ROLE => OPENLUCIUS_CORE_OPENLUCIUS_DEFAULT_ROLE,
            ),
          );
          $new_account = user_save(NULL, $new_user);

          // Notify user of account.
          $params['account'] = $new_account;
          $language = $language ? $language : user_preferred_language($new_account);
          drupal_mail('user', 'register_admin_created', $new_account->mail, $language, $params);
        }
      }

      // Prevent others from being able to perform the full onboarding process.
      variable_set('openlucius_onboarding_initial', 1);
    }
  }
}

/**
 * Hook which is fired after onboarding.
 *
 * @param bool $js
 *   Whether this is an ajax triggered after.
 *
 * @return array
 *   Returns the commands array.
 */
function openlucius_onboarding_after($js = TRUE) {
  $commands = array();

  // Check if a module uses our function.
  if (count(module_implements('openlucius_onboarding_after')) > 0) {

    // Call modules that implement the hook.
    $commands = module_invoke_all('openlucius_onboarding_after', $commands, $js);
  }

  return $commands;
}

/**
 * Form constructor for the onboarding settings form.
 *
 * @return mixed
 *   Returns the onboarding settings form.
 *
 * @ingroup forms
 */
function openlucius_onboarding_settings_form($form, &$form_state) {
  $form = array();

  $form['openlucius_onboarding_video'] = array(
    '#title'         => t('The OpenLucius Onboarding video'),
    '#description'   => t('The video displayed in the first step of the onboarding'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('openlucius_onboarding_video', ''),
    '#attributes'    => array(
      'placeholder' => t('Please enter a youtube link.'),
    ),
  );

  return system_settings_form($form);
}
