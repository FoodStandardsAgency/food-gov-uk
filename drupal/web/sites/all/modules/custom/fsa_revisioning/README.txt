DESCRIPTION
===========
This module provides some enhancements to the contributed Revisioning and
Revisioning Scheduler modules as used on the FSA website.

www.drupal.org/project/revisioning


CURRENT ENHANCEMENTS
====================
Current enhancements include:

1. A fix for a bug whereby scheduled publication dates aren't always saved the
   first time they're added. This bug has been reported on Drupal.org:
   https://www.drupal.org/node/2445469. Although a patch has been provided, it
   was deemed easier for the upgrade path if we fixed it in this custom module.
   The fix involves adding an update hook that sets the weight of the
   revisioning_scheduler module as greater than the revisioning module.
2. Use a date popup field when setting publication dates. If the Date API
   module is available, we replace the standard text field for publication date
   with a more user-friendly calendar popup.
3. Better validation for publication dates. Drupal now checks to see whether
   the publication date entered by the user is valid before saving the node.
4. Enhanced JavaScript. Because publication dates are saved only if the option
   Create new revision and moderate is selected, we hide the publication date
   field otherwise.


FUTURE ENHANCEMENTS
===================
* Change the wording of the options in the Revision information field set on the
  node edit page to be a little more intuitive.


INSTALLATION & CONFIGURATION
============================
* Install as you would any other Drupal module.
* This module does not provide any configuration options
* Database schema updates must be run following installation. This should happen
  as part of the installation process, but it's worth making sure.


REQUIREMENTS
============
* This module requires the revisioning and revisioning_scheduler modules.
* For the date popup field to work, the Date API module must be installed and
  enabled, though this isn't a strict requirement.


AUTHOR
======
Matt Farrow, Sirius Open Source, Stress Free Technology
https://www.drupal.org/u/mattfarrow
http://www.siriusopensource.com
