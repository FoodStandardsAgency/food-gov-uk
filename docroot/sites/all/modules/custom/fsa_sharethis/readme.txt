# FSA ShareThis module

## Overview
The FSA ShareThis module provides some accessibility enhancements to the [contrib ShareThis module](https://www.drupal.org/project/sharethis), which enables the ShareThis widget to be added to pages in Drupal.

The primary enhancement provided by this custom module is to enable the ShareThis icons to be activated using the keyboard. In its standard form, it is not possible to focus the buttons using the tab key, so a mouse or touch action is required. This does not meet the FSA's accessibility requirements.

To address this issue, a theme override function has been implemented that uses `<button>` elements, rather than `<span>` elements. A JavaScript function has also been included to trigger the standard ShareThis functionality when the buttons are activated.

This has been tested across all major browsers and devices.

## Requirements
* [ShareThsis](https://www.drupal.org/project/sharethis)

## Permissions
This module does not define any new permissions, but the permission **Administer ShareThis** is defined by the contrib ShareThis module.

## Installation
Install as you would normally install a contributed Drupal module. See: https://drupal.org/documentation/install/modules-themes/modules-7 for further information.

Since the ShareThis contrib module is a dependency, it will also be enabled when this module is enabled.

## Configuration
This module does not provide any configuration options. The contrib ShareThis module's configuration interface can be found at:

> Admin > Configuration > Web services > ShareThis

## Operation
The ShareThis widget is applied to pages on the FSA website using a block. This has been set using the contrib module's configuration page.

The ShareThis block is added to the pages using a context called **share\_this\_widget**.

This context applies the block based on two conditions: content type and path.

Content type determines the node types on which the block will appear; path can be used to exclude certain pages. The conditions work together, and both must be fulfilled for the block to appear.

### Modifying the context
In order to change the content types on which the widget appears or to exclude certain pages, the context will need to be modified. The process is as follows.

1. Log into Drupal with administrative privileges
2. Go to Admin > Structure > Context
3. Search for `share_this_widget`
4. Click the **Edit** link

#### Changing the content types
To change the content types on which the widget appears:

1. Under **Conditions**, click **Node type**
2. Tick or untick the content types according to your requirements
3. Scroll down and click the **Save** button

#### Excluding pages
To exclude a page that would otherwise be included:

1. Make sure you know the path of the page(s) you want to exclude. The path starts after (not including) the first forward slash in the URL, eg `about-us/contactus`
2. Under **Conditions**, click **Path**
3. In the **Path** field, enter the path from 1 above, preceded by a tilde '~', eg `~about-us/contactus`. If you want to exclude an entire section, you can include a wildcard '*' after the path.
4. Scroll down and click the **Save** button

Note that it is not possible to include a page by path if it is not one of the types included in the node type condition.

## Limitations and future enhancements
### Excluding committee sites
Because the committee sites use their own subdomains, it is not currently possible to exclude their page using context. In order to enable this, a new context plugin would be required. This would be fairly straightforward to write.

### Positioning beneath the date
The ShareThis widget currently appears beneath the page title, but above the last updated date (where this is present). If it is required to display the widget beneath the date, then a modification to views will be required, together with an adjustment to the context.

### Including on non-node pages
The current context does not allow for the inclusion of the ShareThis widget on non-node pages. Should this become a requirement in future, then we will need to revise the context. This may involve writing further context plugins.


## Maintainers ##
* [Matt Farrow](https://www.drupal.org/user/3054707) - https://www.drupal.org/user/3054707

This project has been created at [Sirius - stress free technology](http://www.siriusopensource.com) - http://www.siriusopensource.com