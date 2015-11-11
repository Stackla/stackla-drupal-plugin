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
    '#title' => t('Information for Stackla'),
  );

  $form['for-stackla']['stackla_oauth_callback'] = array(
    '#title' => t('Oauth Callback URL for Stackla'),
    '#type' => 'textfield',
    '#value' => $base_url . '/admin/config/services/stackla/accesscallback',
    '#disabled' => TRUE,
    '#description' => t('Configure the following in the Drupal Plugin instance in your Stack.'),
  );

  $form['from-stackla'] = array(
    '#type' => 'fieldset',
    '#title' => t('Information from Stackla'),
    '#description' => t('Please find the information for the following fields in the Drupal Plugin instance in your Stack.'),
  );

  $form['from-stackla']['stackla_stack_name'] = array(
    '#title' => t('Stack Short Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_stack_name'),
  );

  $form['from-stackla']['stackla_client_id'] = array(
    '#title' => t('Stackla Client ID'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_id'),
  );

  $form['from-stackla']['stackla_client_secret'] = array(
    '#title' => t('Stackla Client Secret'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_secret'),
  );

  $form['auth'] = array(
    '#type' => 'fieldset',
    '#title' => t('Authentication'),
  );

  if (stackla_check_requirements()) {
    if (!stackla_is_authenticated()) {
      // Add authentication link.
      $form['auth']['authenticate'] = array(
        '#type' => 'submit',
        '#value' => t('Sign in as a Stackla user'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_authenticate'),
      );
    }
    else {
      // Add message 'Access token set'!
      $form['auth']['authenticate'] = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Signed in successfully') . '</p>',
      );

      $form['auth']['revoke_authentication'] = array(
        '#type' => 'submit',
        '#value' => t('Revoke current authentication'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_admin_revoke_authentication'),
      );

      $form['auth']['reauthenticate'] = array(
        '#type' => 'submit',
        '#value' => t('Sign in as a different user'),
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
  return(system_settings_form($form));
}

function stackla_admin_authenticate($form, &$form_state) {
  stackla_authenticate();
}

function stackla_admin_revoke_authentication($form, &$form_state) {
  stackla_revoke_authentication();
}
