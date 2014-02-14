<?php

/**
 * @file

 * Command line utlity to check that you can connect to and query the Oracle 10g database.
 *
 * @note Requires the oci8 PHP module: @see https://help.ubuntu.com/community/PHPOracle
 */

// Configuration.
$SQL = "SELECT *
FROM FIELDVALUE, OBJ, OBJTYPE, FIELDNAME
WHERE FIELDVALUE.OBJECTID = OBJ.OBJECTID
AND OBJ.OBJECTTYPEID = OBJTYPE.OBJECTTYPEID
AND FIELDVALUE.FIELDID = FIELDNAME.FIELDID
AND OBJ.PATH LIKE '/multimedia/webpage/uber-page/'";

$conf['oracle_db'] = array(
  'username' => 'cmauth',
  'password' => 'mediasurface',
  'connection_string' => '//localhost/msdev',
);

// Check the oci8 PHP module is enabled.
if (!extension_loaded('oci8')) {
  echo "oci8 PHP module not detected. Is it installed and enabled? Please see the inline documentation\n";
  exit(-1);
}

echo "oci8 PHP module : OK\n";

// Connect to the db.
$connection = oci_connect(
  $conf['oracle_db']['username'],
  $conf['oracle_db']['password'],
  $conf['oracle_db']['connection_string'],
  'UTF8'
);

if (!$connection) {
  $e = oci_error();
  throw new Exception($e['message']);
}
else {
  echo "Oracle connexion : OK\n";
}

$statement = oci_parse($connection, $SQL);

if (!$statement) {
  $e = oci_error($connection);
  var_dump($e);
}

// Execute the query.
$result = oci_execute($statement);

if (!$result) {
  $e = oci_error($statement);
  var_dump($e);
}

print 'Results: ';
// Print out results.
while ($row = oci_fetch_object($statement)) {
  var_dump($row->OBJECTID);
  echo "\n";
}
