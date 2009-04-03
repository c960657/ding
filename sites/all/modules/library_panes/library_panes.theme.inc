<?php
// $Id$

/**
 * @file library_panes.theme.inc
 * Theming implementation for library panes.
 */

/**
 * Preprocess hook for the library title and navigation pane.
 */
function library_panes_preprocess_title(&$variables) {
  $node = $variables['node'];
  $variables['library_links'] = _library_panes_theme_title_navigation($node);
  $variables['library_navigation'] = theme('item_list', $variables['library_links']);
}

function _library_panes_theme_title_navigation($node) {
  $links = array();
  if (isset($node->library_slug) && !empty($node->library_slug)) {
    $base_path = 'bibliotek/' . $node->library_slug;

    $links['front'] = l(t('Front page'), $base_path);
    $links['events'] = l(t('Events'), $base_path . '/arrangementer');
    $links['facilities'] = l(t('Facilities'), $base_path . '/faciliteter');
    $links['about'] = l(t('About'), $base_path . '/os');
    $links['locally'] = l(t('Locally'), $base_path . '/lokalt');
  }
  return $links;
}
