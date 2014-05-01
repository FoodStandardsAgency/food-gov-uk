#!/bin/bash

DATE=$(date | tr ' ' '-' | tr ':' '-')

echo "${DATE}"

cd ../../docroot/sites/default

drush -v -y si --site-name='Food Standards Agency' --account-name='admin' --account-pass='fsa' base

# @TODO add vocabulary terms.

# Open the ssh tunnel.
setup-ssh-tunnel.sh &

# Sleep for 30 seconds to allow for the tunnel to be built.
sleep 30

# Enable the FSA migration module.
drush en fsa_migrate -y

# Migrate all users.

# Migrate content.

drush dis pathauto -y

# Get all the media assets into the new system
# - Redirects may also need to be migrated here so that aliases are assigned to media
drush mi FSAMedia
drush en pathauto -y

drush cc all

drush -y vset "bbcgf_migration_date" "${DATE}"

# FAQ
# - Faq questions are all primary attached children - migrated into field collections

# Multibranch migration
# - First level (primary attached)children for each multibranch page are not imported, they instead become sections on the general page
#

# Migrate related media
# - related media appears in it's own field collection
# - the related media field collection has no title

# Migrate more in this section
# - Child pages are added as their own field collection
# - section title is "More in this section"


