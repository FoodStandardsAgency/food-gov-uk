<?php

/**
 * @file
 * Common functions
 */

// Modules have no id, but file_usage want's one.
define("FILE_LOCK_ID", 0);

/**
 * Add lock for the $file
 * This is done by adding an entry to the file_usage table.
 *
 * @param file $file
 *   file object (with at least 'fid' set)
 */
function file_lock_add_lock($file) {
  if (!file_lock_is_locked($file)) {
    // Only add one lock for every file.
    file_usage_add($file, 'file_lock', 'module', FILE_LOCK_ID);
  }
}

/**
 * Remove lock for the $file
 *
 * @param file $file
 *   file object (with at least 'fid' set)
 */
function file_lock_remove_lock($file) {
  file_usage_delete($file, 'file_lock', FILE_LOCK_ID);
}

/**
 * Remove lock for all locked files
 */
function file_lock_remove_all_lock() {
  $files = file_load_multiple(FALSE);
  foreach ($files as $file) {
    file_lock_remove_lock($file);
  }
}

/**
 * Check if a file has already an entry in file_usage for file_lock
 *
 * @param file $file
 *   the file to check
 *
 * @return bool
 *   TRUE if file is locked
 *   FALSE if file is not locked
 */
function file_lock_is_locked($file) {
  $file_usage_list = file_usage_list($file);
  return isset($file_usage_list['file_lock']);
}
