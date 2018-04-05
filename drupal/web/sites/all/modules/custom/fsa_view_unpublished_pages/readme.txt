# FSA View unpublished pages module

## Introduction

This module provides permissions and access checking to enable selected users to
view pages that are unpublished.

The functionality it provides is fairly basic in that it will allow users to
view nodes in full page format, but may not enable them to view the same nodes
when they appear in views or node listings.

However, the intention of the module is to allow users to view nodes in full-page
mode, so it should be fit for purpose.

If more sophisticated access control is required, the contributed
[View unpublished](https://www.drupal.org/project/view_unpublished) module may be
appropriate.

This module uses the same permissions, so it should be a drop-in fit.

However, it's worth reading the notes in that module's README.txt file about
block caching before doing so.

You may also want to have a look at this page for further reference:
[https://www.drupal.org/node/1106606](https://www.drupal.org/node/1106606)


## Requirements
This module does not have any special requirements.

## Installation
* Install as you would normally install a contributed Drupal module. See: [https://drupal.org/documentation/install/modules-themes/modules-7](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration
The module itself has no menu or modifiable settings.

However, once installed, permissions will need to be assigned to roles via the
Admin > People > Permissions menu.

You may need to clear your site's caches for the new permissions to appear.

## Permissions
This module provides a new permission for every active content type on the given
site.

Permissions are of the form "Content type: View any unpublished content", eg
"News: View any unpublished content".

## Maintainers
* Matt Farrow (mattfarrow) - https://www.drupal.org/u/mattfarrow

Created at Sirius Open Source - stress free technology - www.siriusopensource.com
