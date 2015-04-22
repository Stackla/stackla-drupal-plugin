<?php

/**
 * @file: Stackla Base admin functions.
 */

/**
 * Stackla Base admin configuration form.
 */
function stackla_settings_form($form,&$form_state) {
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

  if(stackla_admin_check_requirements()) {
    if(!stackla_is_authenticated()) {
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
      $form['authenticate']  = array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Access token set!') . '</p>',
      );

      $form['reauthenticate'] = array(
         '#type' => 'submit',
         '#value' => t('Reuthenticate with Stackla'),
         '#op' => 'authenticate',
         '#submit' => array('stackla_authenticate'),
       );

    }
  }

  return(system_settings_form($form));
}

function stackla_admin_check_requirements() {
  if(variable_get('stackla_stack_id') &&
     variable_get('stackla_stack_oauth_host') &&
     variable_get('stackla_stack_name') &&
     variable_get('stackla_client_id') &&
     variable_get('stackla_client_secret')
         ) {
    return TRUE;
  }
  return FALSE;
}

function stackla_authenticate($form,&$form_state) {
  libraries_load('stackla');
  dpm('authenticate called');
  if(!stackla_admin_check_requirements()) {
    return FALSE;
  }
  $client_id = variable_get('stackla_host_name');
  $host = variable_get('stackla_stack_oauth_host');
  $stack = variable_get('stackla_stack_name');
  $client_secret = variable_get('stackla_client_secret');
  $protocol = (!empty($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off' || $_SERVER['SERVER_PORT'] == 443) ? "https://" : "http://";
  $callback = $protocol . $_SERVER['HTTP_HOST'] . '/admin/config/services/stackla/accesscallback';
  $credentials = new Stackla\Core\Credentials($host, null, $stack);
  $access_uri = $credentials->getAccessUri($client_id, $client_secret, $callback);

  drupal_goto($access_uri);
}
