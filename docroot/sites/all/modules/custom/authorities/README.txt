********************************************************************
D R U P A L    M O D U L E
********************************************************************
Name: Food Standards Authorities search
Author: Michael Raasch
Drupal: 7.x
********************************************************************
DESCRIPTION:

    Local module to display the closest authorities on a map and
    as a list

********************************************************************
INSTALLATION:

    Note: It is assumed that you have Drupal up and running.  Be sure to
    check the Drupal web site if you need assistance.  If you run into
    problems, you should always read the INSTALL.txt that comes with the
    Drupal package and read the online documentation.

	1. Place the entire module directory into your Drupal
        modules/directory.

	2. Enable the module by navigating to:

	   Administer > Site building > Modules

	Click the 'Save configuration' button at the bottom to commit your
    changes.
    
********************************************************************
POST-INSTALLATION:

Variables:
    The module exposes configuration data through the Variables module.
    The variables are set during installation with default values.
    See admin/config/system/variable/module -> Authorities

Blocks:
    The module exposes a couple of blocks
    1. Authorities search:Form
    2. Authorities search result:Map
    3. Authorities search result:List

    The search form performs a redirect to a particular page,
    which allows the form to be placed on multiple pages throughout the site.
    The redirect URL can be configured using the Authorities Variables (see above).

Permissions:
    Each blocks comes with their own permissions,
    which should be enabled so the blocks are indeed visible.
