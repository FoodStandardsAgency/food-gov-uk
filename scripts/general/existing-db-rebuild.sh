#!/bin/bash

DATE=$(date | tr ' ' '-' | tr ':' '-')

echo "${DATE}"

cd ../../docroot/sites/default

# Optional considering we have the tunnel in another tab.
# setup-ssh-tunnel.sh &
# sleep 30

# Optional. Enable the FSA migration module.
# drush en fsa_migrate -y

# Roll back the existing migration.
drush mr FSAChildpageCollection
drush mr FSARelatedContentCollection
drush mr FSADocumentpageCollection
drush mr FSADocumentpage
drush mr FSAMediaDocument
drush mr FSAMediaImages

# Migrate all users.

# Get all the media assets into the new system
# - Redirects may also need to be migrated here so that aliases are assigned to media
drush mi FSAMediaImages
drush mi FSAMediaDocument

# Migrate content.
drush mi FSADocumentpage
drush mi FSADocumentpageCollection

# Migrate related media
# - related media appears in it's own field collection
# - the related media field collection has no title
drush mi FSARelatedContentCollection

# Migrate more in this section
# - Child pages are added as their own field collection
# - section title is "More in this section"
drush mi FSAChildpageCollection

drush cc all

drush -y vset "fsa_migration_date" "${DATE}"

# FAQ
# - Faq questions are all primary attached children - migrated into field collections

# Multibranch migration
# - First level (primary attached)children for each multibranch page are not imported, they instead become sections on the general page
#

