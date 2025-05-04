from setuptools import find_packages
from setuptools import setup

setup(
    name='multi_map_nav_interfaces',
    version='0.0.1',
    packages=find_packages(
        include=('multi_map_nav_interfaces', 'multi_map_nav_interfaces.*')),
)
