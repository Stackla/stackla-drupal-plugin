<?php

/**
 * @file: Stackla Base admin functions.
 */

/**
 * Stackla Base admin configuration form.
 */
function stackla_settings_form($form, &$form_state) {
  global $base_url;
  $form = array();

  $form['for-stackla'] = array(
    '#type' => 'fieldset',
    '#title' => t('Step 1: Configure Stackla'),
    '#description' => t("<p>Before you can configure Drupal, you need to first configure Stackla.</p><p>Copy the 'Callback URL' below and paste it in the relevant field in the Drupal plugin configuration screen in Stackla.</p>"),
  );

  $form['for-stackla']['stackla_oauth_callback'] = array(
    '#title' => t('Callback URL'),
    '#type' => 'textfield',
    '#value' => $base_url . '/admin/config/services/stackla/accesscallback',
    '#disabled' => TRUE,
    '#description' => t("Please copy + paste this URL into the 'Callback URL' field in the Drupal plugin configuration screen in Stackla.")
  );

  $form['from-stackla'] = array(
    '#type' => 'fieldset',
    '#title' => t('Step 2: Configure Drupal'),
  );

  $form['from-stackla']['stackla_stack_name'] = array(
    '#title' => t('Stack Shortname'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_stack_name'),
    '#description' => t('You can retrieve your Stack shortname from the Drupal configuration settings page.'),
  );

  $form['from-stackla']['stackla_client_id'] = array(
    '#title' => t('Client ID'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_id'),
  );

  $form['from-stackla']['stackla_client_secret'] = array(
    '#title' => t('Client Secret'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_secret'),
  );

  $form['auth'] = array(
    '#type' => 'fieldset',
    '#title' => t('Setp 3: Authorize'),
    '#description' => t("You need to authorize Drupal to access your Stackla account. Click 'Authorize' below, you'll be prompted to log in to Stackla to provide authorization.")
  );

  if (stackla_check_requirements()) {
    if (!stackla_is_authenticated()) {
      // Add authentication link.
      $form['auth']['authenticate'] = array(
        '#type' => 'submit',
        '#value' => t('Authorize'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_authenticate'),
      );
    }
    else {
      $form['auth']['revoke_authentication'] = array(
        '#type' => 'submit',
        '#value' => t('Revoke authorization'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_admin_revoke_authentication'),
      );

      $form['auth']['reauthenticate'] = array(
        '#type' => 'submit',
        '#value' => t('Reautorize'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_admin_authenticate'),
      );
    }
  } else {
      // Add authentication link.
      $form['auth']['authenticate'] = array(
        '#type' => 'submit',
        '#disabled' => true,
        '#value' => t('Sign in as a Stackla user'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_authenticate'),
      );
  }

  $form['debug'] = array(
    '#type' => 'fieldset',
    '#title' => t('Debug'),
  );

  $form['debug']['stackla_debug_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable debug mode'),
    '#description' => t('Will display and log verbose debug information. This should be disabled in production.'),
    '#default_value' => variable_get('stackla_debug_mode'),
  );

  $form['powered_by_stackla'] = array(
    '#type' => 'markup',
    '#markup' => t('Powered by Stackla'),
    '#prefix' => '<div class="powered-by-stackla">',
    '#suffix' => '</div>',
  );

  //CSS
  $css = drupal_get_path('module','stackla') . '/css/stackla_powered.css';

  $form['#attached'] = array(
    'css' => array($css),
  );

  return(system_settings_form($form));
}

function stackla_admin_authenticate($form, &$form_state) {
  stackla_authenticate();
}

function stackla_admin_revoke_authentication($form, &$form_state) {
  stackla_revoke_authentication();
}
