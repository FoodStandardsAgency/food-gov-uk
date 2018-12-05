<?php

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site foodsciencecommittee, environment dev.
$aliases['dev'] = array(
  'root' => '/var/www/html/foodsciencecommittee.dev/docroot',
  'ac-site' => 'foodsciencecommittee',
  'ac-env' => 'dev',
  'ac-realm' => 'prod',
  'uri' => 'foodsciencecommitteedev.prod.acquia-sites.com',
  'remote-host' => 'foodsciencecommitteedev.ssh.prod.acquia-sites.com',
  'remote-user' => 'foodsciencecommittee.dev',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  ),
);
$aliases['dev.livedev'] = array(
  'parent' => '@foodsciencecommittee.dev',
  'root' => '/mnt/gfs/foodsciencecommittee.dev/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site foodsciencecommittee, environment prod.
$aliases['prod'] = array(
  'root' => '/var/www/html/foodsciencecommittee.prod/docroot',
  'ac-site' => 'foodsciencecommittee',
  'ac-env' => 'prod',
  'ac-realm' => 'prod',
  'uri' => 'foodsciencecommittee.prod.acquia-sites.com',
  'remote-host' => 'foodsciencecommittee.ssh.prod.acquia-sites.com',
  'remote-user' => 'foodsciencecommittee.prod',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  ),
);
$aliases['prod.livedev'] = array(
  'parent' => '@foodsciencecommittee.prod',
  'root' => '/mnt/gfs/foodsciencecommittee.prod/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site foodsciencecommittee, environment ra.
$aliases['ra'] = array(
  'root' => '/var/www/html/foodsciencecommittee.ra/docroot',
  'ac-site' => 'foodsciencecommittee',
  'ac-env' => 'ra',
  'ac-realm' => 'prod',
  'uri' => 'foodsciencecommitteera.prod.acquia-sites.com',
  'remote-host' => 'foodsciencecommitteera.ssh.prod.acquia-sites.com',
  'remote-user' => 'foodsciencecommittee.ra',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  ),
);
$aliases['ra.livedev'] = array(
  'parent' => '@foodsciencecommittee.ra',
  'root' => '/mnt/gfs/foodsciencecommittee.ra/livedev/docroot',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site foodsciencecommittee, environment test.
$aliases['test'] = array(
  'root' => '/var/www/html/foodsciencecommittee.test/docroot',
  'ac-site' => 'foodsciencecommittee',
  'ac-env' => 'test',
  'ac-realm' => 'prod',
  'uri' => 'foodsciencecommitteestg.prod.acquia-sites.com',
  'remote-host' => 'foodsciencecommitteestg.ssh.prod.acquia-sites.com',
  'remote-user' => 'foodsciencecommittee.test',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  ),
);
$aliases['test.livedev'] = array(
  'parent' => '@foodsciencecommittee.test',
  'root' => '/mnt/gfs/foodsciencecommittee.test/livedev/docroot',
);
