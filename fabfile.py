from __future__ import print_function

import os.path

from fabric.api import *
from fabric.contrib.project import rsync_project

env.roledefs = {
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

def full_deploy():
    check_docroot()
    clean()
    copy_files()
    fix_perms()
    post_deploy()


def deploy():
    check_docroot()
    copy_files()
    fix_perms()
    post_deploy()


def check_docroot():
    if env.docroot in ('', '/'):
        abort('docroot empty or fs root')


def clean():
    with warn_only():
        run('umount {docroot}/sites/default/files'.format(**env))
    run('rm -rf {docroot}'.format(**env))
    run('mkdir {docroot}'.format(**env))
    run('mkdir -p {docroot}/sites/default/files'.format(**env))
    run('mount {docroot}/sites/default/files'.format(**env))


def fix_perms():
    with cd(env.docroot):
        # would use chown -R but can't exclude sites/default/files
        run('find . -path ./sites/default/files -prune -o '
            '-exec chown root:dev {} + ')
        run('chmod -R g+w .')
        run('find . -type d -exec chmod g+s {} +')
        run('find . -type f -exec chmod -sx {} +')


def copy_files(delete=False):
    rsync_project(env.docroot, 'docroot/',
                  extra_opts='--no-times --no-perms',
                  exclude=['.gitignore'],
                  delete=delete)


def post_deploy():
    with cd(env.docroot):
        run('drush updatedb')
        run('drush cc all')
