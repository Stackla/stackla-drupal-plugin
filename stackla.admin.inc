<?php

/**
 * @file: Stackla Base admin functions.
 */

/**
 * Stackla Base admin configuration form.
 */
function stackla_settings_form($form, &$form_state) {
  $form = array();

  $form['stackla_host_name'] = array(
    '#title' => t('Your Stackla Host Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_host_name'),
  );

  $form['stackla_stack_oauth_host'] = array(
    '#title' => t('Your Stackla Oauth Host'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_stack_oauth_host'),
  );

  $form['stackla_stack_name'] = array(
    '#title' => t('Your Stackla Stack Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_stack_name'),
  );

  $form['stackla_client_id'] = array(
    '#title' => t('Stackla Client ID'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_id'),
  );

  $form['stackla_client_secret'] = array(
    '#title' => t('Stackla Client Secret'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('stackla_client_secret'),
  );

  if (stackla_check_requirements()) {
    if (!stackla_is_authenticated()) {
      // Add authentication link.
      $form['authenticate'] = array(
        '#type' => 'submit',
        '#value' => t('Authenticate with Stackla'),
        '#op' => 'authenticate',
        '#submit' => array('stackla_authenticate'),
      );
    }
    else {
      // Add message 'Access token set'!
      $form['authenticate'] = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Access token set!') . '</p>',
      );

      $form['reauthenticate'] = array(
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
    '#description' => t('Will display and log verbose debug information'),
    '#default_value' => variable_get('stackla_debug_mode'),
  );

  $form['debug']['stackla_sim_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable simulation mode'),
    '#description' => t('When checked we don\'t send any data to stackla, just log what would have been sent'),
    '#default_value' => variable_get('stackla_sim_mode'),
  );

  return(system_settings_form($form));
}

function stackla_admin_authenticate($form, &$form_state) {
  stackla_authenticate();
}
