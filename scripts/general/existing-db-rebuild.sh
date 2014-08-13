#!/bin/bash

export DRUSH_SOURCE="@food.development"; export DRUSH_DEST="@food.migration"
#drush sql-sync -y $DRUSH_SOURCE $DRUSH_DEST; drush -y rsync $DRUSH_SOURCE:%files $DRUSH_DEST:%files

DATE=$(date | tr ' ' '-' | tr ':' '-')

setup(){
  drush cc all;

  # Optional. Enable the FSA migration module.
  drush en fsa_migrate FSA_menu_build -y;
  drush mar;

  # disable pathauto for Document page updates
  drush vset fsa_migrate_pathauto_restrict 1;
  # set production mode
  drush vset fsa_migrate_production 1;
}

rollback(){
  # Roll back the existing migration.
  drush mr --all
}

media(){
  # Get all the media assets into the new system
  # - Redirects may also need to be migrated here so that aliases are assigned to media
  drush mi FSAMediaImages --feedback="50 items";
  drush mi FSAMediaDocument --feedback="50 items";
}

nodes(){
  # Migrate nodes.
  drush mi --feedback="50 items" FSAExternalsite;
  drush mi --feedback="50 items" FSADocumentpage;
  drush mi --feedback="50 items" FSAFAQpage;
  drush mi --feedback="50 items" FSAAuditReport;
  drush mi --feedback="50 items" FSAConsultationpage;
  drush mi --feedback="50 items" FSANewsDocument;
  drush mi --feedback="50 items" FSAAlertDocument;
  drush mi --feedback="50 items" FSAMultibranchDocument;
  drush mi --feedback="50 items" FSATreebranchDocument;
}

research(){
  # Research
  drush mi --force --feedback="50 items" FSAResearchProjectList;
  drush mi --force --feedback="50 items" FSAResearchProject;
  drush mi --force --feedback="50 items" FSAResearchProgramme;
}
field_collections(){
  # Migrate fc.
  drush mi --force --feedback="50 items" FSADocumentpageCollection;
  drush mi --force --feedback="50 items" FSAFAQpageCollection;
  drush mi --force --feedback="50 items" FSAAuditReportCollection;
  drush mi --force --feedback="50 items" FSANewsDocumentCollection;
  drush mi --force --feedback="50 items" FSAAlertDocumentCollection;
  drush mi --force --feedback="50 items" FSAConsultationpageCollection;
}

multibranch(){
  # Multibranch
  drush mi --force --feedback="50 items" FSAMultibranchCollection;
  drush mi --force --feedback="50 items" FSAMultibranchCollectionChild;
}
treebranch(){
  # Treebranch
  drush mi --force --feedback="50 items" FSATreebranchCollection;
  drush mi --force --feedback="50 items" FSATreebranchCollectionChild;
  drush mi --force --feedback="50 items" FSATreebranchRelatedContentCollection;
}

committees(){
  drush mi --force --feedback="50 items" FSACommitteepage;
  drush mi --force --feedback="50 items" FSACommitteeCollection;
  drush mi --force --feedback="50 items" FSACommitteeChildpageCollection;
}

meetings(){
  drush mi FSAMeetinglist;
  drush mi FSAMeeting;
}


related_items(){
  # Migrate related media
  # - related media appears in it's own field collection
  # - the related media field collection has no title
  drush mi --force --feedback="50 items" FSARelatedContentCollection;
}

child_pages(){
  # Migrate more in this section
  # - Child pages are added as their own field collection
  # - section title is "More in this section"
  drush mi --force --feedback="50 items" FSAChildpageCollection;
}

menus(){
  # do menus
  # break into sections to make a little easier to see progress - may also be more reliable
  drush vset fsa_migrate_pathauto_restrict 0;
  drush FSA-menu-build --reset --filter="news-updates";
  drush FSA-menu-build --filter="business-industry";
  drush FSA-menu-build --filter="enforcement";
  drush FSA-menu-build --filter="science/ouradvisors/cot";
  drush FSA-menu-build --filter="science/ouradvisors";
  drush FSA-menu-build --filter="science";
  drush FSA-menu-build --filter="about-us";
  drush FSA-menu-build --filter="wales";
  drush FSA-menu-build --filter="scotland";
  drush FSA-menu-build --filter="northern-ireland";
}

cleanup(){
  # Get solr indexed up
  drush cc all
  drush solr-mark-all
  drush solr-index
}

backup(){
  STAGE=$1
  DATE=`date +%Y%m%d-%s`
  drush sql-dump > /tmp/migrate.$STAGE.$DATE.sql
}

echo "${DATE}"

# go to main docroot
cd `drush $DRUSH_DEST dd`

drush use $DRUSH_DEST

# Optional considering we have the tunnel in another tab.
# setup-ssh-tunnel.sh &
# sleep 30






#========================================

setup
rollback
media
  backup "media"
nodes
  backup "nodes"
research
  backup "research"
meetings
  backup "meetings"
field_collections
  backup "field_collectons"
multibranch
treebranch
  backup "treebranch"
related_items
  backup "related"
child_pages
  backup "child_pages"
committees
  backup "committees"
menus
cleanup

#=======================================

drush -y vset "fsa_migration_date" "${DATE}"
# reenable document page pathauto




