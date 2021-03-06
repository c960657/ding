<?php
// $Id$

/**
 * Admin settings form.
 */
function webtrends_admin_settings_form($form_state) {
  $form = array();

  $form['webtrends_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Hostname'),
    '#description' => t('The hostname of the WebTrends server (gDomain).'),
    '#default_value' => variable_get('webtrends_domain', FALSE),
  );

  $form['webtrends_dcs_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Site ID'),
    '#description' => t('The site identification key (gDcsId).'),
    '#default_value' => variable_get('webtrends_dcs_id', FALSE),
  );

  // Delete the generated file js/webtrends_include1.js.
  $form['#submit'][] = 'drupal_clear_js_cache';

  return system_settings_form($form);
}

