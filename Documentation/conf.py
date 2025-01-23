# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#

import logging
import os
import sys

sys.path.insert(0, '../Raspi/src')

# -- Project information -----------------------------------------------------
project = 'Crazy Car NG, Running Linux'
copyright = '2024 (GPLv3)'
html_title = project
html_baseurl = 'https://www.fh-joanneum.at'
release = version = ''

# -- General configuration ---------------------------------------------------
master_doc = 'index'
templates_path = []

html_theme = 'sphinx_rtd_theme'

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx_rtd_theme',

    'sphinx.ext.todo',
    'sphinx.ext.viewcode',
    'sphinx.ext.autodoc',
    'sphinx.ext.doctest',
    'sphinx.ext.graphviz',
    'sphinx.ext.intersphinx',

    'sphinxemoji.sphinxemoji',
    'opentraining',
    'breathe',
]

todo_include_todos = True

# readthedocs.io sets the READTHEDOCS environment variable if they
# build the project. invoke doxygen if this is the case. I told them
# (via ../.readthedocs.yaml) to build in Documentation/; verify that.
if os.environ.get('READTHEDOCS') == 'True':
    import subprocess, os
    assert os.path.basename(os.getcwd()) == 'Documentation'
    subprocess.call('doxygen', shell=True)

breathe_projects = {"crazycar": "./xml"}   # "." is Documentation/
breathe_default_project = "crazycar"

intersphinx_mapping = {
    'jfasch': ('https://www.faschingbauer.me/', None),
}

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = [
    '_build',
    '**.ipynb_checkpoints',
]

def rstjinja(app, docname, source):
    """Render our pages as a jinja template for fancy templating goodness.

    Eric Holscher mentions this somewhere in his blog.

    """
    # Make sure we're outputting HTML
    if app.builder.format != 'html':
        return
    src = source[0]
    rendered = app.builder.templates.render_string(
        src, app.config.html_context
    )
    source[0] = rendered

def setup(app):
    app.connect("source-read", rstjinja)

    # html_sidebars has two matches, and both match any /blog/
    # docname. the first match is more specific than the second, which
    # I consider a common case. nevertheless sphinx generates a
    # warning. filter that out.

    # (rant) I have no idea what's the benefit of wrapping loggers
    # into LoggerAdapter's. Or what SphinxLoggerAdapter's purpose
    # is. Fortunately the LoggerAdapter (victim.logger) is friendly
    # enough to have a 'logger' member. gosh; I only want to silence a
    # warning.
    class NoWarnMultipleMatches(logging.Filter):
        def filter(self, record):
            return 'matches two patterns in html_sidebars' not in record.getMessage()
    import sphinx.builders.html as victim
    victim.logger.logger.addFilter(NoWarnMultipleMatches())
