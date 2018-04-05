********************************************************************
                     D R U P A L    M O D U L E
********************************************************************
Name: Preserve Filter Module
Author: Robert Castelo <www.codepositive.com>
Drupal: 7.x
********************************************************************
DESCRIPTION:

Provides an input filter that can be added to an input format.

This input filter preserves any content that is placed between <preserve>…</preserve> tags from
modification by other input filters.


********************************************************************
PREREQUISITES:

  This does not deal with nested preserve tags.

  This input filter should be the last to run, the only exception is the Tidy Up HTML filter which
  can be run after this filter to clean up the output.

  If another filter uses a hook_filter_info() prepare callback to change the content it may alter the
  content that is to be preserved.


********************************************************************
INSTALLATION:

Note: It is assumed that you have Drupal up and running.  Be sure to
check the Drupal web site if you need assistance.

1. Place the entire module directory into your Drupal directory:
   sites/all/modules/


2. Enable the module by navigating to:

   administer > modules

  Click the 'Save configuration' button at the bottom to commit your
  changes.



********************************************************************
CONFIGURATION:

Add Preserve input filter to input formats of your choice.




********************************************************************
AUTHOR CONTACT

- Commission New Features:
   http://drupal.org/user/3555/contact



********************************************************************
ACKNOWLEDGEMENT

This is a custom module developed for the FSA (www.fsa.gov.uk)

