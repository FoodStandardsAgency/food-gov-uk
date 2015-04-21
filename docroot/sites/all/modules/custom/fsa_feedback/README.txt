# FSA feedback module

## Introduction
This custom module provides functionality to enhance the existing contributed [Feedback module](https://www.drupal.org/project/feedback).

## Enhancements to the contrib module
This module features the following enhancements to the contributed Feedback module.

* Splitting the feedback message field into two separate fields for what the user was doing and what the problem was
* Displaying the two user fields separately on the feedback messages report page
* Enabling the two user message 'fields' to be edited separately via the admin interface.
* Enabling feedback messages to be sent to an email address
* Bespoke templates, CSS and JavaScript
* Providing the ability for site administrators to forward feedback messages
* Enhancements to the display of individual feedback messages
* Adding additional operations links to the feedback messages list page
* Adding additional tabs to the feedback message display/edit pages
* Moving the feedback form to a different region

## Requirements
* [Feedback](https://www.drupal.org/project/feedback)

## Installation ##
Install as you would normally install a contributed Drupal module. See: https://drupal.org/documentation/install/modules-themes/modules-7 for further information.

## Permissions
The FSA feedback module does not itself define any new permissions, but access to the various functions is controlled by permissions defined by the contrib Feedback module:

### Access feedback form
This permission is required for users to access the feedback form. It should be given to the `anonymous` user.

### View feedback messages
This permission is required to view feedback messages in the admin interface.

### Administer feedback
This permission is required to administer the configuration settings for the feedback module.

## Configuration
This module has several configuration settings, all of which are available via:

> Admin > Configuration > User interface > Feedback

The settings are as follows.

### Email recipient address
This is the email address to which feedback responses will be sent. By default this will be the site's main configured email address.

You can add multiple email recipients, separated by commas.

### Email subject line
This is the subject line of the email that will be sent to the designated recipients when a user submits a feeback message. The default value will be `Feedback message from @site_name` where `@site_name` is the name of the site as defined in the main configuration settings.

### Feedback link
This is the text that will be displayed on the page as a link for the user to click when she wants to submit some feedback. By default, it will read `Is there anything wrong with this page?`.

### Feedback form heading
This is the heading that appears within the feedback form. By default it will be `Help us improve food.gov.uk`.

### Message label
This is the label for the first of the two text boxes that the user completes when providing feedback. By default it will be `What you were doing`.

### Second message label
This is the label for the second of the two text boxes that the user completes when providing feedback. By default it will be `What went wrong`.

### Intro text
This is some optional text that can be included at the top of the feedback form. It is blank by default.

## Operation
### Viewing feedback messages
Users with the permission `view feedback messages` can view feedback messages here:

> Admin > Reports > Feedback messages

This screen is provided either directly through a function or through a view, depending on configuration. It is recommended that the view is disabled as some additional functionality has been provided through the module.

To disable the view, go to:

> Admin > Structure > Views

and search for a view with the name `feedback_messages`. Under **Operations**, select **Disable**.

#### Feedback status
Feedback messages can have one of two statuses: **Open** and **Processed**.

Open feedback messages are displayed at the top of the listing page, whereas processed messages are displayed at the bottom, in a collapsed fieldset.

#### Feedback operations
Several operations are available for feedback messages:

* **Edit:** Enables the message to be edited and its status changed
* **Delete:** Enables the message to be deleted permanently
* **View:** Enables the message to be viewed in full
* **Mark as processed:** Enables the message to be marked as processed
* **Forward by email:** Enables the message to be forwarded by email


## Upgrading the contrib module
The contrib Feedback module has not been customised, so upgrading it should not cause problems for this custom module. However, testing should be undertaken to ensure that the API and preprocess functions exposed by the contrib module continue to function in the expected ways.

## Future development
Future development may include:

* Exposing the feedback form as a block that can be positioned using context or the standard Drupal blocks UI.
* Adding additional fields for data capture

## Maintainers ##
* Dr Roy Schestowitz - http://schestowitz.com
* Matt Farrow - https://www.drupal.org/user/3054707

This project has been created at Sirius - stress free technology - http://www.siriusopensource.com
