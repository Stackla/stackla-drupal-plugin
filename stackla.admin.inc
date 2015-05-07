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
    '#description' => t('You will need this to set up your client app in Stackla'),
  );

  $form['from-stackla'] = array(
    '#type' => 'fieldset',
    '#title' => t('Information from Stackla'),
  );

  $form['from-stackla']['stackla_host_name'] = array(
    '#title' => t('Your Stackla Host Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_host_name'),
    '#description' => t('eg https://my.stackla.com/api/ note trailing slash'),
  );

  $form['from-stackla']['stackla_stack_oauth_host'] = array(
    '#title' => t('Your Stackla Oauth Host'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_stack_oauth_host'),
    '#description' => t('eg https://api.stackla.com/api/ note trailing slash'),
  );

  $form['from-stackla']['stackla_stack_name'] = array(
    '#title' => t('Your Stackla Stack Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_stack_name'),
    '#description' => t('eg my-stack'),
  );

  $form['from-stackla']['stackla_client_id'] = array(
    '#title' => t('Stackla Client ID'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_id'),
    '#description' => t('eg 87c9334cc822d43bc1874c . You can find this in the Stackla "manage clients" interface'),
  );

  $form['from-stackla']['stackla_client_secret'] = array(
    '#title' => t('Stackla Client Secret'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_secret'),
    '#description' => t('You can find this in the Stackla "manage clients" interface'),
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
        '#value' => t('Authenticate with Stackla'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_authenticate'),
      );
    }
    else {
      // Add message 'Access token set'!
      $form['auth']['authenticate'] = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Access token set!') . '</p>',
      );

      $form['auth']['reauthenticate'] = array(
        '#type' => 'submit',
        '#value' => t('Reuthenticate with Stackla'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_admin_authenticate'),
      );
    }
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
