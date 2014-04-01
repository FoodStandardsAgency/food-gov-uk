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

# Migrate all users.

# Migrate content.

drush dis pathauto -y
drush mi FSAMedia
drush en pathauto -y

drush cc all

drush -y vset "bbcgf_migration_date" "${DATE}"