<?php

/**
 * Determines whether to check the file system status.
 *
 * Since we're caching files in CloudFlare, it's unlikely that we'll need to
 * check file system status here, so this should be set to FALSE by default. An
 * implication of setting this to TRUE is that a problem with Drupal's files
 * directory could make Varnish think that Drupal is down. Since all the Drupal
 * instances currently share a single NFS file server, this could mean a
 * complete outage.
 */
define('STATUS_CHECK_FILESYSTEM', FALSE);

// Register our shutdown function so that no other shutdown functions run before this one.
// This shutdown function calls exit(), immediately short-circuiting any other shutdown functions,
// such as those registered by the devel.module for statistics.
register_shutdown_function('status_shutdown');
function status_shutdown() {
  exit();
}

define('DRUPAL_ROOT', getcwd());

// Drupal bootstrap.
require_once './includes/bootstrap.inc';

/**
 * Sets the bootstrap level to use, based on whether we're checking files.
 *
 * If we're checking file system status, then we need the public files
 * directory, which is stored in the Drupal variable `file_public_path`. This is
 * available only once `_drupal_bootsrap_variables()` has run. If we're not
 * checking files, then we can bootstrap to `DRUPAL_BOOTSTRAP_DATABASE` instead,
 * thereby making the check less resource-intensive.
 */
define('STATUS_BOOTSTRAP_LEVEL', STATUS_CHECK_FILESYSTEM ? DRUPAL_BOOTSTRAP_VARIABLES : DRUPAL_BOOTSTRAP_DATABASE);

drupal_page_is_cacheable(FALSE);
drupal_bootstrap(STATUS_BOOTSTRAP_LEVEL);

// Build up our list of errors.
$errors = array();

// Check that the main database is active.
$result = db_query('SELECT * FROM {users} WHERE uid = 1');
$account = $result->fetch();
if (!$account->uid == 1) {
  $errors[] = 'Master database not responding.';
}

// Check that the slave database is active.
if (function_exists('db_query_slave')) {
  $result = db_query_slave('SELECT * FROM {users} WHERE uid = 1');
  $account = $result->fetch();
  if (!$account->uid == 1) {
    $errors[] = 'Slave database not responding.';
  }
}

// Check that all memcache instances are running on this server.
if (isset($conf['cache_inc'])) {
  foreach ($conf['memcache_servers'] as $address => $bin) {
    list($ip, $port) = explode(':', $address);
    if (!memcache_connect($ip, $port)) {
      $errors[] = 'Memcache bin <em>' . $bin . '</em> at address ' . $address . ' is not available.';
    }
  }
}

// Check that the files directory is operating properly - if this is enabled.
if (STATUS_CHECK_FILESYSTEM) {
  // Get the public file path
  $public_file_path = variable_get('file_public_path');

  // If we have a public file path, let's check the file system operation.
  if (!empty($public_file_path)) {

    // Try creating a temporary file in the public files directory. If this is
    // not writable for any reason, it'll default to /tmp
    if ($test = tempnam($public_file_path, 'status_check_')) {
      // Check to see whether the file was saved in the public files directory.
      // If not, we set an error.
      if (strpos($test, DRUPAL_ROOT . '/' . $public_file_path) !== 0) {
        $errors[] = 'Files are not being saved in ' . DRUPAL_ROOT . '/' . $public_file_path . '.';
      }
      // Try to delete the temporary file. If this fails, log an error as
      // something must be wrong.
      if (!unlink($test)) {
        $errors[] = 'Could not delete newly created files in the files directory.';
      }
    }
    // If a temporary file couldn't be created, log an error.
    else {
      $errors[] = 'Could not create temporary file in the files directory.';
    }
  }
}

// Print all errors.
if ($errors) {
  $errors[] = 'Errors on this server will cause it to be removed from the load balancer.';
  header('HTTP/1.1 500 Internal Server Error');
  print implode("<br />\n", $errors);
}
else {
  // Split up this message, to prevent the remote chance of monitoring software
  // reading the source code if mod_php fails and then matching the string.
  print 'CONGRATULATIONS' . ' 200';
}

// Exit immediately, note the shutdown function registered at the top of the file.
exit();
