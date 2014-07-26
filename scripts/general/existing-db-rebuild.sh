#!/bin/bash

DRUSH_SOURCE="@food.development"
DRUSH_DEST="@food.migration"

DATE=$(date | tr ' ' '-' | tr ':' '-')

echo "${DATE}"

# go to main docroot
cd `drush $DRUSH_DEST dd`

# Optional considering we have the tunnel in another tab.
# setup-ssh-tunnel.sh &
# sleep 30

# Sync db and files
drush sql-sync -y $DRUSH_SOURCE $DRUSH_DEST
drush rsync -y $DRUSH_SOURCE $DRUSH_DEST

# Optional. Enable the FSA migration module.
drush en fsa_migrate -y

# disable pathauto for Document page updates
drush vset fsa_migrate_pathauto_restrict 1
# set production mode
drush vset fsa_migrate_production 1

# Roll back the existing migration.
drush mr FSAChildpageCollection
drush mr FSARelatedContentCollection
drush mr FSAMultibranchCollectionChild
drush mr FSANewsDocumentCollection
drush mr FSAAuditReportCollection
drush mr FSAAlertDocumentCollection
drush mr FSAFAQpageCollection
drush mr FSADocumentpageCollection
drush mr FSAMultibranchCollection
drush mr FSAMultibranchDocument
drush mr FSANewsDocument
drush mr FSAAlertDocument
drush mr FSAFAQpage
drush mr FSAAuditReport
drush mr FSAConsultationpage
drush mr FSADocumentpage
drush mr FSAMediaDocument
drush mr FSAMediaImages

# Migrate all users.

# Get all the media assets into the new system
# - Redirects may also need to be migrated here so that aliases are assigned to media
drush mi FSAMediaImages --feedback="50 items"
drush mi FSAMediaDocument --feedback="50 items"

# Migrate nodes.
drush mi --feedback="50 items" FSADocumentpage
drush mi --feedback="50 items" FSAFAQpage
drush mi --feedback="50 items" FSAAuditReport
drush mi --feedback="50 items" FSAConsultationpage
drush mi --feedback="50 items" FSANewsDocument
drush mi --feedback="50 items" FSAAlertDocument
drush mi --feedback="50 items" FSAMultibranchDocument

# Migrate fc.
drush mi --force --feedback="50 items" FSADocumentpageCollection
drush mi --force --feedback="50 items" FSAFAQpageCollection
drush mi --force --feedback="50 items" FSAAuditReportCollection
drush mi --force --feedback="50 items" FSANewsDocumentCollection
drush mi --force --feedback="50 items" FSAAlertDocumentCollection

# Multibranch
drush mi --force --feedback="50 items" FSAMultibranchDocument
drush mi --force --feedback="50 items" FSAMultibranchCollection
drush mi --force --feedback="50 items" FSAMultibranchCollectionChild

# Treebranch
drush mi --force --feedback="50 items" FSATreebranchDocument
drush mi --force --feedback="50 items" FSATreebranchCollection
drush mi --force --feedback="50 items" FSATreebranchCollectionChild


# Migrate related media
# - related media appears in it's own field collection
# - the related media field collection has no title
drush mi --force --feedback="50 items" FSARelatedContentCollection

# Migrate more in this section
# - Child pages are added as their own field collection
# - section title is "More in this section"
drush mi --force --feedback="50 items" FSAChildpageCollection

drush cc all
drush solr-mark-all

drush -y vset "fsa_migration_date" "${DATE}"
# reenable document page pathauto
drush vset fsa_migrate_pathauto_restrict 0


