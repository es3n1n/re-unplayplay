import os
import re
import shutil
import sys
import platform
import subprocess

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
from distutils.version import LooseVersion


class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=''):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)


class CMakeBuild(build_ext):
    def run(self):
        try:
            out = subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError(
                'CMake must be installed to build the following extensions: '
                + ', '.join(e.name for e in self.extensions)
            )

        if platform.system() == 'Windows':
            cmake_version = LooseVersion(
                re.search(r'version\s*([\d.]+)', out.decode()).group(1)
            )
            if cmake_version < '3.1.0':
                raise RuntimeError('CMake >= 3.1.0 is required on Windows')

        for ext in self.extensions:
            self.build_extension(ext)

    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        cmake_args = [
            '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + extdir,
            '-DPYTHON_EXECUTABLE=' + sys.executable,
            '-DRE_UNPP_BUILD_PYTHON=1',
        ]

        cfg = 'Debug' if self.debug else 'Release'
        build_args = [
            '--config',
            cfg,
        ]

        if platform.system() == 'Windows':
            cmake_args += [
                '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), extdir)
            ]
            if sys.maxsize > 2**32:
                cmake_args += ['-A', 'x64']
            build_args += ['--', '/m']
        else:
            cmake_args += ['-DCMAKE_BUILD_TYPE=' + cfg]
            build_args += ['--', '-j2']

        env = os.environ.copy()
        env['CXXFLAGS'] = "{} -DVERSION_INFO=\\'{}\\'".format(
            env.get('CXXFLAGS', ''), self.distribution.get_version()
        )
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)
        subprocess.check_call(
            ['cmake', ext.sourcedir] + cmake_args, cwd=self.build_temp, env=env
        )
        subprocess.check_call(
            ['cmake', '--build', '.'] + build_args, cwd=self.build_temp
        )

        # Rename re_unplayplay_python to re_unplayplay
        for filename in os.listdir(extdir):
            if ext.name not in filename:
                continue

            old_path = os.path.join(extdir, filename)
            new_filename = filename.replace(ext.name, 're_unplayplay')
            new_path = os.path.join(extdir, new_filename)

            shutil.move(old_path, new_path)
            break

    def get_ext_filename(self, ext_name):
        filename = super().get_ext_filename(ext_name)
        return filename.replace('re_unplayplay_python', 're_unplayplay')


setup(
    name='re-unplayplay',
    version='1.1.4',
    author='es3n1n',
    description='A rewritten version of unplayplay',
    long_description='https://github.com/es3n1n/re-unplayplay',
    ext_modules=[CMakeExtension('re_unplayplay_python')],
    extras_require={'test': ['pytest>=6.0']},
    cmdclass=dict(build_ext=CMakeBuild),
    zip_safe=False,
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',  # License type
        'Operating System :: OS Independent',
    ],
    include_package_data=True,
)
