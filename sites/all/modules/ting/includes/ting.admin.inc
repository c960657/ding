<?php
// $Id$

/**
 * Ting search settings form.
 */
function ting_admin_settings_form($form_state) {
  $form = array();

  $form['ting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ting service settings'),
    '#tree' => FALSE,
  );
  $form['ting']['ting_agency'] = array(
    '#type' => 'textfield',
    '#title' => t('Library code'),
    '#description' => t('The 6-digit code representing the library organization'),
    '#default_value' => variable_get('ting_agency', ''),
  );
  $form['ting']['ting_search_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Search service URL'),
    '#description' => t('URL to the Ting search webservice, e.g. http://didicas.dbc.dk/opensearch/'),
    '#required' => TRUE,
    '#default_value' => variable_get('ting_search_url', ''),
  );
  $form['ting']['ting_scan_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Scan service URL'),
    '#description' => t('URL to the Ting scan webservice, e.g. http://didicas.dbc.dk/openscan/'),
    '#required' => TRUE,
    '#default_value' => variable_get('ting_scan_url', ''),
  );
  $form['ting']['ting_spell_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Spell service URL'),
    '#description' => t('URL to the Ting spell webservice, e.g. http://didicas.dbc.dk/openspell/'),
    '#required' => TRUE,
    '#default_value' => variable_get('ting_spell_url', ''),
  );
  $form['ting']['ting_recommendation_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Recommendation service URL'),
    '#description' => t('URL to the Ting recommendation webservice (Andre der har lånt...) , e.g. http://didicas.dbc.dk/openadhl/'),
    '#required' => TRUE,
    '#default_value' => variable_get('ting_recommendation_server', ''),
  );

  $form['addi'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Information settings'),
  	'#description' => t('The Additional Information service is used to retrieve cover images and other information about objects. <a href="http://www.danbib.dk/index.php?doc=forsideservice">More information about the service (in Danish)</a>'),
    '#tree' => FALSE,
  );
  $form['addi']['addi_wdsl_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Service URL'),
    '#description' => t('URL to the Additional Information webservice, e.g. http://forside.addi.dk/addi.wsdl'),
    '#required' => TRUE,
    '#default_value' => variable_get('addi_wdsl_url', ''),
  );
  $form['addi']['addi_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('Username for the Additional information webservice'),
    '#required' => TRUE,
    '#default_value' => variable_get('addi_username', ''),
  );
  $form['addi']['addi_group'] = array(
    '#type' => 'textfield',
    '#title' => t('Group'),
    '#description' => t('User group for the Additional information webservice'),
    '#required' => TRUE,
    '#default_value' => variable_get('addi_group', ''),
  );
  $form['addi']['addi_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('Password for the Additional information webservice'),
    '#required' => TRUE,
    '#default_value' => variable_get('addi_password', ''),
  );

  $form['proxy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Proxy service'),
  	'#description' => t('Restricted-access resources referenced by Ting may be accessed through the library\'s proxy server'),
    '#tree' => FALSE,
  );
  $form['proxy']['restricted_access_proxy_prefix'] = array(
    '#type' => 'textfield',
    '#title' => 'Proxy server URL prefix',
    '#default_value' => variable_get('restricted_access_proxy_prefix', ''),
    '#description' => t('E.g. <em>http://proxy.example.com/?url=</em>.'),
  );
  $form['proxy']['restricted_access_proxy_hostnames'] = array(
    '#type' => 'textarea',
    '#title' => 'Hostnames',
    '#rows' => 15,
    '#default_value' => implode("\n", variable_get('restricted_access_proxy_hostnames', array())),
    '#value_callback' => 'ting_admin_settings_hostnames_value',
    '#description' => t('Enter one hostname per line, e.g. <em>magazine.example.com</em>. Do not include the <em>http://</em> prefix.'),
  );

  return system_settings_form($form);
}

/**
 * Value callback for restricted_access_proxy_hostnames field defined in
 * ting_admin_settings_form().
 */
function ting_admin_settings_hostnames_value($form, $edit = FALSE) {
  if ($edit !== FALSE) {
    return array_filter(array_map('trim', explode("\n", $edit)));
  }
}

