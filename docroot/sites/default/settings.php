<?php
/**
 * CODE POSITIVE STANDARD SETTINGS.PHP
 * Place any configuration changes for your local environment in: settings.local.php
 *
 * This config requires a few modules by path, if you get a WSOD, check that the modules exist
 *
**/

$databases = array (
  'default' =>
    array (
      'default' =>
        array (
          'database' => 'food',
          'username' => 'drupal',
          'password' => 'F8q9WCZJtp',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
    ),
);

$update_free_access = FALSE;

$drupal_hash_salt = 'Lqn-efzYTXp7qrA-R9bFPO1Sju8WRI72spTAo61xW0A';

ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);

# $conf['maintenance_theme'] = 'bartik';

$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';

/**
 * Allow DB configuration to be overridden by environment variables.
 */
if ($mysql_host = getenv('MYSQL_HOST')) {
  $databases['default']['default']['host'] = $mysql_host;
}

/**
 * Allow RABBITMQ configuration to be overridden by environment variables.
 */
if ($rabbitmq_host = getenv('RABBITMQ_HOST')) {
  $conf['message_broker_amqp_host'] = $rabbitmq_host;
}

/**
 * Memcache settings.
 */
$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache/memcache.inc';
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

/**
 * Allow memcache configuration to be overridden by environment variables.
 */
$conf['memcache_key_prefix'] = getenv('MEMCACHE_PREFIX') ?: 'drupal';
if ($memcache_hosts = getenv('MEMCACHE_HOSTS')) {
  $memcache_hosts = explode(' ', trim($memcache_hosts));
  foreach ($memcache_hosts as $memcache_host) {
    $conf['memcache_servers'][$memcache_host . ':11211'] = 'default';
  }

  $conf['memcache_bins'] = array(
    'cache' => 'default',
  );
}


/**
 * Allow Varnish configuration to be overridden by environment variables.
 */
if ($varnish_hosts = getenv('VARNISH_HOSTS')) {
  $conf['varnish_control_terminal'] = str_replace(' ', ':6082 ', $varnish_hosts) . ':6082';

  // Configure page cache to use Varnish.
  $conf['cache_backends'][] = 'sites/all/modules/contrib/varnish/varnish.cache.inc';
  $conf['cache_class_cache_page'] = 'VarnishCache';
  $conf['page_cache_invoke_hooks'] = FALSE;
  $conf['varnish_control_key'] = '0dab0075-ecbb-4f0c-8cc0-839f16501ffe';
}

/**
 * Allow Solr configuration to be overridden by environment variables.
 */
if (($solr_host = getenv('SOLR_HOST')) && ($solr_core = getenv('SOLR_CORE'))) {
  list($solr_ip, $solr_port) = explode(':', $solr_host);

  $conf['search_api_solr_overrides'] = array(
    'search' => array(
      'options' => array(
        'host' => $solr_ip,
        'port' => $solr_port,
        'path' => $solr_core,
      ),
    ),
  );
}

/**
 * Ensure we know when we are running on HTTPS.
 */
if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
  $_SERVER['HTTPS'] = 'on';
}

/**
 * Determine environment.
 */
switch (getenv('AH_SITE_ENVIRONMENT')) {
  case 'development':

    // Disable google experiments on every page of the site (so we don't get annoying redirects ALL the time)
    $conf['content_experiments_visibility'] = 0;
    $conf['content_experiments_pages'] = '*';

    // Disable aggregation
    $conf['preprocess_css'] = 0;
    $conf['preprocess_js'] = 0;
    $conf['less_devel'] = TRUE;


    // Enable some handy module
    $conf['environment_modules'] = array(
     // 'devel' => 'sites/all/modules/development/devel/devel.module',
     // 'shield' => 'sites/all/modules/development/shield/shield.module',
      //'stage_file_proxy' => 'sites/all/modules/contrib/contrib/stage_file_proxy/stage_file_proxy.module',
    );

    break;

  case 'qa':

    // Disable google experiments on every page of the site (so we don't get annoying redirects ALL the time)
    $conf['content_experiments_visibility'] = 0;
    $conf['content_experiments_pages'] = '*';

    $conf['less_devel'] = 0;
    $conf['less_watch'] = 0;

    // No additional settings!
    break;

  case 'staging':
    // Enable production performance settings.
    $conf['less_devel'] = 0;
    $conf['less_watch'] = 0;
    $conf['preprocess_css'] = 1;
    $conf['preprocess_js'] = 1;
    $conf['error_level'] = 0;
    $conf['cache'] = 1;
    $conf['block_cache'] = 0;
    $conf['cache_lifetime'] = 300;
    $conf['page_cache_maximum_age'] = 600;

    // Disable google experiments on every page of the site (so we don't get annoying redirects ALL the time)
    $conf['content_experiments_visibility'] = 0;
    $conf['content_experiments_pages'] = '*';

    // Enable some handy module
    $conf['environment_modules'] = array(
      //'shield' => 'sites/all/modules/development/shield/shield.module',
      //'stage_file_proxy' => 'sites/all/modules/contrib/contrib/stage_file_proxy/stage_file_proxy.module',
    );
    break;

 case 'production':
    $conf['less_devel'] = 0;
    $conf['less_watch'] = 0;
    $conf['preprocess_css'] = 1;
    $conf['preprocess_js'] = 1;
    $conf['user_register'] = 0;
    $conf['error_level'] = 0;
    $conf['cache'] = 1;
    $conf['block_cache'] = 0;
    $conf['cache_lifetime'] = 300;
    $conf['page_cache_maximum_age'] = 600;
    break;

  case 'local':
  default:

    // Disable google experiments on every page of the site (so we don't get annoying redirects ALL the time)
    $conf['content_experiments_visibility'] = 0;
    $conf['content_experiments_pages'] = '*';

    // Disable aggregation
    $conf['preprocess_css'] = 1;
    $conf['preprocess_js'] = 1;
    $conf['less_devel'] = TRUE;

    // Enable some handy module
    $conf['environment_modules'] = array(
      'devel' => 'sites/all/modules/development/devel/devel.module',
      //'stage_file_proxy' => 'sites/all/modules/contrib/contrib/stage_file_proxy/stage_file_proxy.module',
    );
    // Disable memcache.
    // Commenting out the below as it's causing problems when using Drush
    // @see Ticket#2015022410000048
    // The AH_SITE_ENVIRONMENT variable is not getting set when using Drush, so
    // Drush was trying to use database caching, not memcache. Since we always
    // have memcache in place, it should be fine to leave the below out.
    // $conf['cache_default_class'] = 'DrupalDatabaseCache';
    // Set stage file proxy source
    //$conf['stage_file_proxy_origin'] = 'http://' . urlencode('username') . ':password@http://developmentdomain.com/';
    //$conf['stage_file_proxy_use_imagecache_root'] = TRUE;

    break;

}

// AH_SITE_ENVIRONMENT is also used as a constant.
define('AH_SITE_ENVIRONMENT', getenv('AH_SITE_ENVIRONMENT'));

// Ensure APPLICATION_ENV is set in the environment and as a constant.
if (!defined('APPLICATION_ENV')) define('APPLICATION_ENV', AH_SITE_ENVIRONMENT);
putenv('APPLICATION_ENV=' . APPLICATION_ENV);

// CDN settings.
if ($cdn_domains = getenv('CLOUDFRONT_URLS')) {
  $cdn_domains = explode(' ', trim($cdn_domains));
  $conf['cdn_status'] = 2; // CDN_ENABLED
  $conf['cdn_basic_mapping'] = '//' . implode("\n//", $cdn_domains);
  $conf['cdn_basic_mapping_https'] = '//' . implode("\n//", $cdn_domains);
  $conf['cdn_https_support'] = TRUE;
}
else {
  $conf['cdn_status'] = 0; // CDN_DISABLED
}

/**
 * Implementation of cdn_pick_server().
 */
function cdn_pick_server($servers_for_file) {
  $filename = basename($servers_for_file[0]['url']);
  $unique_file_id = hexdec(substr(md5($filename), 0, 5));
  return $servers_for_file[$unique_file_id % count($servers_for_file)];
}


/**
 * Fast 404 settings:
 *
 * Fast 404 will do two separate types of 404 checking.
 *
 * The first is to check for URLs which appear to be files or images. If Drupal
 * is handling these items, then they were not found in the file system and are
 * a 404.
 *
 * The second is to check whether or not the URL exists in Drupal by checking
 * with the menu router, aliases and redirects. If the page does not exist, we
 * will server a fast 404 error and exit.
 */

# Load the fast_404.inc file. This is needed if you wish to do extension
# checking in settings.php.
include_once( DRUPAL_ROOT . '/sites/all/modules/contrib/fast_404/fast_404.inc');

# Disallowed extensions. Any extension in here will not be served by Drupal and
# will get a fast 404.
# Default extension list, this is considered safe and is even in queue for
# Drupal 8 (see: http://drupal.org/node/76824).
$conf['fast_404_exts'] = '/[^robots]\.(txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['fast_404_exts'] = '';
# Allow anonymous users to hit URLs containing 'imagecache' even if the file
# does not exist. TRUE is default behavior. If you know all imagecache
# variations are already made set this to FALSE.
$conf['fast_404_allow_anon_imagecache'] = TRUE;

# Extension list requiring whitelisting to be activated **If you use this
# without whitelisting enabled your site will not load!
//$conf['fast_404_exts'] = '/\.(txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp|php|html?|xml)$/i';
# Default fast 404 error message.

# Default fast 404 error message.
$ga_account="";
$ga_js = "<script type=\"text/javascript\">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', '". $ga_account ."']);
  _gaq.push(['_setCustomVar', 1, 'Page type', 'Fast 404 Page Default']);
  _gaq.push(['_setDomainName','none']);
  _gaq.push(['_trackPageview']);
  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script>";

# Check paths during bootstrap and see if they are legitimate.
$conf['fast_404_path_check'] = FALSE;

# If enabled, you may add extensions such as xml and php to the
# $conf['fast_404_exts'] above. BE CAREFUL with this setting as some modules
# use their own php files and you need to be certain they do not bootstrap
# Drupal. If they do, you will need to whitelist them too.
$conf['fast_404_url_whitelisting'] = FALSE;

# Array of whitelisted files/urls. Used if whitelisting is set to TRUE.
$conf['fast_404_whitelist'] = array('index.php', 'rss.xml', 'install.php', 'cron.php', 'update.php', 'xmlrpc.php');

# Array of whitelisted URL fragment strings that conflict with fast_404.
$conf['fast_404_string_whitelisting'] = array('cdn/farfuture', '/advagg_');

# By default we will show a super plain 404, because usually errors like this are shown to browsers who only look at the headers.
# However, some cases (usually when checking paths for Drupal pages) you may want to show a regular 404 error. In this case you can
# specify a URL to another page and it will be read and displayed (it can't be redirected to because we have to give a 30x header to
# do that. This page needs to be in your docroot.

# sr14 addition - checks for 404.html in multisite folder first.
$path_to_path = './404.html';

if (file_exists(DRUPAL_ROOT . '/' . conf_path() . '/404/404.html')) {
  $path_to_path = DRUPAL_ROOT . '/' . conf_path() . '/404/404.html';
}

$conf['fast_404_HTML_error_page'] = $path_to_path;

# By default the custom 404 page is only loaded for path checking. Load it for all 404s with the below option set to TRUE
$conf['fast_404_HTML_error_all_paths'] = FALSE;

# Call the extension checking now. This will skip any logging of 404s.
# Extension checking is safe to do from settings.php. There are many
# examples of this on Drupal.org.
fast_404_ext_check();

# Path checking. USE AT YOUR OWN RISK (only works with MySQL).
# Path checking at this phase is more dangerous, but faster. Normally
# Fast_404 will check paths during Drupal boostrap via hook_boot. Checking
# paths here is faster, but trickier as the Drupal database connections have
# not yet been made and the module must make a separate DB connection. Under
# most configurations this DB connection will be reused by Drupal so there
# is no waste.
# While this setting finds 404s faster, it adds a bit more load time to
# regular pages, so only use if you are spending too much CPU/Memory/DB on
# 404s and the trade-off is worth it.
# This setting will deliver 404s with less than 2MB of RAM.
//fast_404_path_check();


# ========================= Memory boosting
# Some admin pages are resource heavy. Rather than boosting the memory for all pages,
# we can selectively increase memory for the pages that need it


if (strpos($_GET['q'], 'admin') === 0) {
  ini_set('memory_limit', '512M');
  ini_set('max_execution_time', 120);
}

// Boost cron runs.
if (isset($_GET['cron'])) { ini_set('memory_limit', '512M'); }


# ========================= General Variable Overrides
//shield settings
$conf['shield_user'] = 'shield';
$conf['shield_pass'] = 'down';
$conf['shield_allow_cli'] = 1;
$conf['shield_print'] =  'Authentication required';


#========================== Local File Overrides
/**
 * Load local development override configuration, if available.
 *
 * Use settings.local.php to override variables on secondary (staging,
 * development, etc) installations of this site. Typically used to disable
 * caching, JavaScript/CSS compression, re-routing of outgoing e-mails, and
 * other things that should not happen on development and testing sites.
 *
 * Keep this code block at the end of this file to take full effect.
 */

if (file_exists('/var/www/site-php/food-settings.inc')) {
  // server specific config
  require('/var/www/site-php/food-settings.inc');
}
if (file_exists(DRUPAL_ROOT . '/' . conf_path() . '/settings.local.php')) {
  include DRUPAL_ROOT . '/' . conf_path() . '/settings.local.php';
}