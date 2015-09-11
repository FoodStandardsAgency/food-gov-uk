FSA Review date module
======================


Introduction
------------
This module provides review date functionality for nodes on the food.org.uk
website.

Functionality provided includes:

* A daily email is generated and sent to a specified email address containing
  details of content items due for review today, as well as items that have
  passed their review date and those whose review date is coming up within a
  pre-defined number of days from today.

* If no items are due for review today, no email is sent.

* A report is available through the Drupal administrative interface listing
  content items due for review today, content items that have passed their
  review dates, and content that is coming up for review.

* A new vertical tab is added to the edit form for nodes, enabling a review date
  to be set, together with an optional review comment.

* It is possible, via the admin interface, to determine which content types
  feature the review date and or review comment functionality. This can be set
  via a new configuration page or via each individual content type edit form.

* Three new permissions are added to control access to review date functionality


Limitations
-----------
At present, the functionality provided by this module is available only to
nodes. Other page types, such as views pages, cannot currently make use of this
functionality. If necessary, this could be added in the future, but it would
require a rethink of the way the review date information is stored. Currently,
it exists in a separate table, keyed on node ID and revision ID.


Requirements
------------
This module requires the following modules:

* Date (https://www.drupal.org/project/date)

The dependency on Date is for the date picker used to set the review dates.


Installation
------------
* Install as you would normally install a contributed Drupal module. See:
  https://drupal.org/documentation/install/modules-themes/modules-7
  for further information.


Permissions
-----------
This module defines the following permissions:

* Set review dates for content: allows users to set and amend review dates

* Administer review date settings: allows users to administer review date 
  settings via the Drupal admin interface and to clear review dates from items.
  
* View review date reports: allows users to view review date reports


Configuration
-------------
* Permissions can be configured at: Admin > People > Permissions

* Module settings can be configured at:

  Admin > Configuration > Content authoring > Review date settings
  
  These settings include:
  
  - Email 'to' address - the recipient of the review reminder emails

  - Email 'from' address - the address from which the emails appear to be sent

  - Email subject - the subject line of the reminder emails

  - Test email - you can send a test reminder email to see what it looks like

  - Number of days to include in upcoming review - this is where you determine
    the number of days from today to include items for review. Default is 30.
    
  - Content type settings - allows you to determine which content types include
    review date functionality and also review comment functionality. If a
    content type is selected for review comment functionality, it will 
    automatically be activated for review date functionality as the one will not
    work without the other.
    
* Content type settings

  In addition to being set via the administrative interface mentioned above,
  content type-specific review date settings can be configured on the individual
  content type Edit screen. A new vertical tab is added, with checkboxes to
  determine the status of review dates and review comments.


Usage
-----
* Users who have permission to set review dates can enter a review date via a
  date picker on enabled content types.
  
* The new review date field can be found at the bottom of the node edit form
  in a new vertical tab.

* An optional review comment can be added for those content types for which this
  is enabled.
  
* Users who do not have the permission to set review dates will still see the
  tab and the review date/comment, but will not be able to edit them.


Technical details
-----------------
* Review date information is stored in a new database table `fsa_review_date`.

* Review date information is related to the specific revision of a node, so a
  history is maintained.
  
* Per-content-type settings are stored in individual variables based on the
  content type name.
  
* All variables are prefixed with `fsa_review_date_`

* All variables are deleted when the module is uninstalled

* To prevent accidental data loss, the data table is not current dropped when
  the module is uninstalled
  

Maintainers
-----------
* Matt Farrow (mattfarrow) - https://www.drupal.org/u/mattfarrow

This module was created for the UK Food Standards Agency (FSA) - www.food.gov.uk
by Sirius Open Source - www.siriusopensource.com.
