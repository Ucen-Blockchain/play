from setuptools import setup

setup( name='steemdebugnode',
       version='0.1',
       description='A wrapper for launching and interacting with a Steem Debug Node',
       url='http://github.com/ucenio/ucen',
       author='Steemit, Inc.',
       author_email='vandeberg@ucenio.com',
       license='See LICENSE.md',
       packages=['steemdebugnode'],
       #install_requires=['steemapi'],
       zip_safe=False )