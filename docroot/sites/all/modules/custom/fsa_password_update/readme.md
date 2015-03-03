# FSA password update module
## Introduction
This module provides a simple URL that can be included in password reset emails.

When a user follows the URL she will either be taken directly to the password update page provided by the Password Policy module (if logged in) or to the user login page, whence she will be redirected to the password update page upon successful login.

### The problem
This module solves a problem that password update reminder emails are sent from the main FSA Drupal server using a link that is based on http://www.food.gov.uk. However, when users click on this link, they do not arrive at the correct page as all admin functions are carried out via the domain https://admin.food.gov.uk.

The emails and their links are created by the [Password Policy module](https://www.drupal.org/project/password_policy), which provides some tokens to be included in email text.

However, because these emails are sent via Cron, the links contained in them are based on www.food.gov.uk.

### The solution
There is no easy way to modify the tokens used in the module, so an alternative approach is to include a hard-coded link instead.

However, this has the drawback that it can't include the user ID, which is required in order to get to the password update page.

To get around this issue, this module creates a single URL which, when accessed, first determines whether the user is already logged in, and if so, redirects her to the password update page.

If the user is not logged in, she is first taken to the standard user login page, and when she has successfully logged in, she is then redirected to the password update page.

The new fixed URL is https://admin.food.gov.uk/user/passwordupdate

## Requirements
* [Password Policy](https://www.drupal.org/project/password_policy)

## Installation
* Install as you would normally install a contributed Drupal module. See: https://drupal.org/documentation/install/modules-themes/modules-7 for further information.

## Configuration
The module has no menu or modifiable settings. There is no configuration. When enabled, the new URL can be used within the password update emails.

## Maintainers
* Matt Farrow (mattfarrow) - https://www.drupal.org/u/mattfarrow

Created at Sirius Open Source - stress free technology - www.siriusopensource.com
