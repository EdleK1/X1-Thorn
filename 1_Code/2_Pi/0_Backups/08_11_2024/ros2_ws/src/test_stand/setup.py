from setuptools import find_packages, setup

package_name = 'test_stand'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='marc',
    maintainer_email='marc@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "Load_Cell_Reader_node = test_stand.Load_Cell_Reader_node:main",
            "Test_Stand_Planner_node = test_stand.Test_Stand_Planner_node:main"
        ],
    },
)
