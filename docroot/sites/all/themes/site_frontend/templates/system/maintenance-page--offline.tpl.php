<?php
if (file_exists('public://site_maintenance_static.html')) {
  include('public://site_maintenance_static.html');
}
else {
  print 'Oh no, it\'s all gone wrong!';
}