<?php

/**
 * @file
 *   drush integration for Stackla Base.
 */

/**
 * The Stackla SDK URI.
 */
define('STACKLA_SDK_DOWNLOAD_URI', 'https://github.com/jackmoore/colorbox/archive/1.x.zip');
define('STACKLA_SDK_DOWNLOAD_PREFIX', 'stackla-');

/**
 * Implementation of hook_drush_command().
 */
function stackla_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['stackla-sdk'] = array(
    'callback' => 'drush_stackla_sdk',
    'description' => dt('Download and install the Stackla SDK.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Stackla SDK. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('st-sdk'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function stackla_drush_help($section) {
  switch ($section) {
    case 'drush:stackla-sdk':
      return dt('Download and install the Stackla SDK from Stackla, default location is sites/all/libraries.');
  }
}


/**
 * Command to download the Colorbox plugin.
 */
function drush_stackla_sdk() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive
  if ($filepath = drush_download_file(STACKLA_SDK_DOWNLOAD_URI)) {
    $filename = basename($filepath);
    $dirname = STACKLA_SDK_DOWNLOAD_PREFIX . basename($filepath, '.zip');

    // Remove any existing Colorbox plugin directory
    if (is_dir($dirname) || is_dir('stackla')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('stackla', TRUE);
      drush_log(dt('A existing Stackla SDK was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive
    drush_tarball_extract($filename);

    // Change the directory name to "colorbox" if needed.
    if ($dirname != 'stackla') {
      drush_move_dir($dirname, 'stackla', TRUE);
      $dirname = 'stackla';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('Stackla SDK has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Stackla SDK to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
