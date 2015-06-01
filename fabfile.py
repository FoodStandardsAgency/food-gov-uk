from __future__ import print_function

import os.path

from fabric.api import *
from fabric.contrib.project import rsync_project

env.roledefs = {
    'vagrant': ['localhost'],
    'dev': ['fsaenaa20.miniserver.com'],
    'staging': ['fsaenaa8.miniserver.com'],
    'production': [
        'fsaenaa2.miniserver.com',
        'fsaenaa3.miniserver.com',
        'fsaenaa5.miniserver.com',
        'fsaenaa10.miniserver.com',
    ],
}

env.user = 'root'

env.docroot = env.get('docroot', '/var/www/food.gov.uk')


@task
def full_deploy():
    """Nuke the current docroot and replace with local code."""
    check_docroot()
    clean()
    copy_files()
    fix_perms()
    post_deploy()


@task
def deploy():
    """Upload local code over current docroot contents.

    Doesn't clean out old files from docroot.
    """
    check_docroot()
    copy_files()
    fix_perms()
    post_deploy()


def check_docroot():
    """Ensure the given docroot is sane or abort."""
    if env.docroot in ('', '/'):
        abort('docroot empty or fs root')


@task
def clean():
    """Delete and re-create the docroot directory structure."""
    with warn_only():
        run('umount {docroot}/sites/default/files'.format(**env))
    run('rm -rf {docroot}'.format(**env))
    run('mkdir {docroot}'.format(**env))
    run('mkdir -p {docroot}/sites/default/files'.format(**env))
    run('mount {docroot}/sites/default/files'.format(**env))


@task
def fix_perms():
    """Ensure permissions on the docroot contents are sane."""
    with cd(env.docroot):
        # would use chown -R but can't exclude sites/default/files
        run('find . -path ./sites/default/files -prune -o '
            '-exec chown root:dev {} +')
        run('chmod -R g+w .')
        run('find . -type d -exec chmod g+s {} +')
        run('find . -type f -exec chmod -sx {} +')
        run('chown www-data:dev sites/default/settings.php')
        run('chmod 440 sites/default/settings.php')


@task
def copy_files(delete=False):
    """Use rsync to copy local code to docroot.

    The delete argument corresponds to rsync's --delete option.
    """
    rsync_project(env.docroot, 'docroot/',
                  extra_opts='--no-times --no-perms --chmod=ugo=rwX',
                  exclude=['.gitignore'],
                  delete=delete)


def post_deploy():
    """Perform post-deployment tasks.

    Runs "updatedb" and "cc all" via drush from the docroot.
    Deletes installation files.
    """
    with cd(env.docroot):
	run('rm CHANGELOG.txt')
        run('rm INSTALL.mysql.txt')
	run('rm INSTALL.pgsql.txt')
	run('rm INSTALL.sqlite.txt')
	run('rm INSTALL.txt')
	run('rm LICENSE.txt')
	run('rm MAINTAINERS.txt')
	run('rm UPGRADE.txt')
	run('rm update.php')
	run('rm install.php')
	run('rm COPYRIGHT.txt')
	run('rm README.txt')
        run('drush updatedb --y')
        run('drush cc all')

@task
@hosts('fsaenaa14.miniserver.com')
def sync_drupal_files():
     """Copy the contents of the files directory from prod to staging/dev."""
     run('rsync -av --delete /srv/drupal_data/ /srv/drupal_data_dev/')
     run('rsync -av --delete /srv/drupal_data/ /srv/drupal_data_fsadev/')


@task
def copy_latest_db():
    """Copy the live db from the mirror into another environment"""
    with cd(env.docroot):
        datedfile = 'food.' + datetime.date.today.strftime('%Y%m%d%H%M%S') + '.sql'
        run('mysqldump -h 10.247.17.22 -u replication -pwjYSa5JM9hUD food > /srv/' + datedfile)
        # don't want the dump to include the contents of the caches...
        run('drush cc')
        # backup then drop the current db
        run('drush sql-dump > /srv/old.' + datedfile)
        run('drush sql-drop')
        # import the one we just took from live
        run('drush sql-cli < /srv/' + datedfile)
        post_deploy()


@task
def backup_db():
    """Backup the database of the current environment to a file"""
    with cd(env.docroot):
        datedfile = 'food.' + datetime.date.today.strftime('%Y%m%d%H%M%S') + '.sql'
        # clear the cache so it isn't written to the backup, then take a backup
        run('drush cc')
        run('drush sql-dump > /srv/' + datedfile)
