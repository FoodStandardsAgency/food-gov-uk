#!/bin/bash

export DRUSH_SOURCE="@food.development"; export DRUSH_DEST="@food.migration"

DATE=$(date | tr ' ' '-' | tr ':' '-')

echo "${DATE}"

# go to main docroot
cd `drush $DRUSH_DEST dd`

# Optional considering we have the tunnel in another tab.
# setup-ssh-tunnel.sh &
# sleep 30

# Sync db and files

#drush sql-sync -y $DRUSH_SOURCE $DRUSH_DEST; drush -y rsync $DRUSH_SOURCE:%files $DRUSH_DEST:%files

drush cc all;

# Optional. Enable the FSA migration module.
drush en fsa_migrate FSA_menu_build -y;
drush mar;

# disable pathauto for Document page updates
drush vset fsa_migrate_pathauto_restrict 1;
# set production mode
drush vset fsa_migrate_production 1;

# Roll back the existing migration.
drush mr --force FSAChildpageCollection;
drush mr --force FSARelatedContentCollection;
drush mr --force FSAResearchProject;
drush mr --force FSAResearchProgramme;
drush mr --force FSAResearchProjectList;
drush mr --force FSAMultibranchCollectionChild;
drush mr --force FSANewsDocumentCollection;
drush mr --force FSAAuditReportCollection;
drush mr --force FSAAlertDocumentCollection;
drush mr --force FSAFAQpageCollection;
drush mr --force FSADocumentpageCollection;
drush mr --force FSAMultibranchCollection;
drush mr --force FSAMultibranchDocument;
drush mr --force FSANewsDocument;
drush mr --force FSAAlertDocument;
drush mr --force FSAFAQpage;
drush mr --force FSAAuditReport;
drush mr --force FSAConsultationpage;
drush mr --force FSADocumentpage;
drush mr --force FSAMediaDocument;
drush mr --force FSAMediaImages;

# Migrate all users.

# Get all the media assets into the new system
# - Redirects may also need to be migrated here so that aliases are assigned to media
drush mi FSAMediaImages --feedback="50 items";
drush mi FSAMediaDocument --feedback="50 items";

# Migrate nodes.
drush mi --feedback="50 items" FSAExternalsite;
drush mi --feedback="50 items" FSADocumentpage;
drush mi --feedback="50 items" FSAFAQpage;
drush mi --feedback="50 items" FSAAuditReport;
drush mi --feedback="50 items" FSAConsultationpage;
drush mi --feedback="50 items" FSANewsDocument;
drush mi --feedback="50 items" FSAAlertDocument;
drush mi --feedback="50 items" FSAMultibranchDocument;
drush mi --force --feedback="50 items" FSATreebranchDocument;


# Research
drush mi --force --feedback="50 items" FSAResearchProjectList;
drush mi --force --feedback="50 items" FSAResearchProject;
drush mi --force --feedback="50 items" FSAResearchProgramme;

# Migrate fc.
drush mi --force --feedback="50 items" FSADocumentpageCollection;
drush mi --force --feedback="50 items" FSAFAQpageCollection;
drush mi --force --feedback="50 items" FSAAuditReportCollection;
drush mi --force --feedback="50 items" FSANewsDocumentCollection;
drush mi --force --feedback="50 items" FSAAlertDocumentCollection;
drush mi --force --feedback="50 items" FSAConsultationpageCollection;


# Multibranch
drush mi --force --feedback="50 items" FSAMultibranchCollection;
drush mi --force --feedback="50 items" FSAMultibranchCollectionChild;

# Treebranch
drush mi --force --feedback="50 items" FSATreebranchCollection;
drush mi --force --feedback="50 items" FSATreebranchCollectionChild;
drush mi --force --feedback="50 items" FSATreebranchRelatedContentCollection;


# Migrate related media
# - related media appears in it's own field collection
# - the related media field collection has no title
drush mi --force --feedback="50 items" FSARelatedContentCollection;

# Migrate more in this section
# - Child pages are added as their own field collection
# - section title is "More in this section"
drush mi --force --feedback="50 items" FSAChildpageCollection;


# do menus
# break into sections to make a little easier to see progress - may also be more reliable
drush vset fsa_migrate_pathauto_restrict 0;
drush FSA-menu-build --filter="/news-updates";
drush FSA-menu-build --filter="/business-industry";
drush FSA-menu-build --filter="/enforcement";
drush FSA-menu-build --filter="/science/ouradvisors/cot";
drush FSA-menu-build --filter="/science/ouradvisors";
drush FSA-menu-build --filter="/science";
drush FSA-menu-build --filter="/about-us";
drush FSA-menu-build --filter="/wales";
drush FSA-menu-build --filter="/scotland";
drush FSA-menu-build --filter="/northern-ireland";


# Get solr indexed up
drush cc all
drush solr-mark-all
drush solr-index

drush -y vset "fsa_migration_date" "${DATE}"
# reenable document page pathauto




