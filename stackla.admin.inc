<?php

/**
 * @file: Stackla Base admin functions.
 */

/**
 * Stackla Base admin configuration form.
 */
function stackla_settings_form($form,&$form_state) {
  $form = array();

  $form['stackla_api_key'] = array(
    '#title' => t('Stackla API key'),
    '#type' => 'textfield',
    '#default_value' => variable_get('stackla_api_key'),
  );

  return(system_settings_form($form));
}
