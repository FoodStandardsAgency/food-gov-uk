# FSA cache clearing module #

## Introduction ##
This module provides additional cache clearing functionality for the FSA website to enhance that already provided by the Expire and Varnish modules.

### The problem ###

#### 1. Varnish ####
FSA carry out updates to the website via the URL [admin.food.gov.uk](https://admin.food.gov.uk). When nodes, files and other objects are updated, created or deleted, the Expire module invokes the Varnish module to clear its cache for the given URL and various dependent URLs specified via the Expire module's configuration page.

This works perfectly for the site's current domain, eg `admin.food.gov.uk`, but not for the site's main domain `www.food.gov.uk` as the Varnish module clears only paths from the current domain.

This means that changes to pages and files are not always visible on the live website.

#### 2. CloudFlare ####
The FSA website uses [CloudFlare](https://www.cloudflare.com) to provide caching and various other functions in front of their Varnish servers.

Amongst other things, CloudFlare stores a cached version of pages and files. At present, updates to the FSA site don't automatically trigger a purge of the CloudFlare cache for the relevant URLs, which means that changes are not always visible for some time afterwards.

### The solution ###
This module builds upon the existing functionality provided by the Varnish and Expire modules to address the two problems outlined above. Wherever possible, it makes use of existing functionality to avoid re-inventing the wheel. This means that there is a tight dependency on both Expire and Varnish modules, which needs to be taken into account when upgrading these modules.

#### 1. The Varnish problem ####
This module provides site administrators with the ability to specify additional domains to be cleared from the Varnish cache. This is achieved via an administration interface.

Using `hook_expire_cache()`, which is provided by the Expire module, we call `varnish_purge()` for the additional domains specified, first checking that we're not performing a repeat of the purge for the current domain.

This is just a simple wrapper for functionality already provided by the Expire and Varnish modules, and it inherits their configuration settings.

#### 2. The CloudFlare problem ####
CloudFlare provide an API, which is documented on the the [CloudFlare website](https://www.cloudflare.com/docs/client-api.html). This module calls a specific function provided by the CloudFlare API in order to purge specific files/URLs from their cache.

It was decided not to use the existing [CloudFlare contrib module](https://www.drupal.org/project/cloudflare) as it had previously been tried and found to create memory leaks.

Instead, we provide a simple HTTP interface to the CloudFlare API and purge the required files.

Because CloudFlare has a rate limit of 100 requests per minute, the module has the ability to fix the number of requests sent to the CloudFlare API endpoint.

The module also provides the ability to determine which types of object will trigger a CloudFlare purge, eg node/user/file/menu link.

When expiring or modifying a page that contains a menu link, typically a large number of other pages can be purged, so it may be desirable not to enable this object type.

This is all configurable from the administration interface.

## Requirements ##
* [Expire](https://www.drupal.org/project/expire)
* [Varnish](https://www.drupal.org/project/varnish)

This module calls functions from the Varnish module directly. It checks for their existence first, and will not cause exceptions if they do not exist, but neither will it function properly.

The functionality of this module is triggered by an implementation of `hook_expire_cache()`, which is called by the Expire module, so without this module, the functionality will not be called.

## Permissions ##
This module does not define any new permissions. Access to the administration interface is available to all users with the `administer site configuration`  permission.

## Installation ##
Install as you would normally install a contributed Drupal module. See: https://drupal.org/documentation/install/modules-themes/modules-7 for further information.

## Configuration ##
The administration interface can be found at:

> Administration > Configuration > Development > FSA Cache Clearing

The administration interface exposes the following configuration options:

### Varnish cache settings ###

#### Domains to clear from the Varnish cache ####
Use this text area to include a list of **additional** domains to be cleared from the Varnish cache.

The Varnish module will automatically clear pages from the current domain, so there's no need to include it here. Don't worry if you do though, the module will automatically remove them so we don't duplicate effort.

Each entry should be on a new line.

For the purposes of the FSA website, it should be necessary only to include:

> www.food.gov.uk

### CloudFlare settings ###
There are a number of CloudFlare settings to configure. These are described below.

#### Clear the CloudFlare cache ####
Use this checkbox to turn CloudFlare cache purging on and off.

#### CloudFlare API endpoint ####
This is the URL of the CloudFlare API. It is available from the [API documentation](https://www.cloudflare.com/docs/client-api.html).

#### CloudFlare API key ####
This is the key for the CloudFlare API, which can be found on the [CloudFlare account page](https://www.cloudflare.com/my-account.html).

#### CloudFlare email address ####
This is the email address associated with the CloudFlare account. It can be found on the [CloudFlare account page](https://www.cloudflare.com/my-account.html).

#### Domains to clear from the CloudFlare cache ####
This is a list of domains - one per line - to use when clearing URLs from the CloudFlare cache. This should typically just be the main URL of the site.

#### CloudFlare request limit ####
The CloudFlare API has a rate limit for file purges of 100 per minute. Use this field to set the maximum number of requests per operation. Bear in mind that the cache needs to be cleared for both HTTP and HTTPS versions of a page.

#### Set the object types for which the CloudFlare cache is to be cleared ####
Clearing the CloudFlare cache can be triggered by updates and changes to a number of different object types. These include:

* Nodes
* Files
* Users
* Menu links

Use this field to determine which of these will be used to trigger a cache clear.
