Getting started
===============

.. _sec-getting-started:

This section goes through the process of getting, installing, and
starting to run BOUT++. Only the basic functionality needed to use
BOUT++ is described here; the next section ([sec-advancedinstall]) goes
through more advanced options, and how to fix some common problems.

This section will go through the following steps:

#. :ref:`Obtaining a copy of BOUT++ <sec-obtainbout>`

#. :ref:`Installing dependencies <sec-dependencies>`

#. :ref:`Configuring BOUT++ <sec-config-bout>`
   
#. :ref:`Configuring BOUT++ analysis codes <sec-configanalysis>`

   #. :ref:`Python <sec-config-python>`

   #. :ref:`IDL <sec-config-idl>`
   
#. :ref:`Compiling BOUT++ <sec-compile-bout>`

#. :ref:`Running the test suite <sec-runtestsuite>`

#. :ref:`Installing BOUT++ (experimental) <sec-install-bout>`
   
**Note**: In this manual commands to run in a BASH shell will begin with
’$’, and commands specific to CSH with a ’%’.

.. _sec-obtainbout:

Obtaining BOUT++
----------------

BOUT++ is hosted publicly on github at
https://github.com/boutproject/BOUT-dev. You can the latest stable
version from https://github.com/boutproject/BOUT-dev/releases. If you
want to develop BOUT++, you should use git to clone the repository. To
obtain a copy of the latest version, run

.. code-block:: bash

    $ git clone git://github.com/boutproject/BOUT-dev.git

which will create a directory ``BOUT-dev`` containing the code. To get
the latest changes later, go into the ``BOUT-dev`` directory and run

.. code-block:: bash

    $ git pull

Development is done on the “next” branch, which you can checkout with

.. code-block:: bash

    $ git checkout next

.. _sec-installmpi:

Installing dependencies
-----------------------

.. _sec-dependencies:

To compile and run BOUT++ needs:

#. An MPI compiler such as OpenMPI (`www.open-mpi.org/ <www.open-mpi.org/>`__),
   MPICH ( `https://www.mpich.org/ <https://www.mpich.org/>`__) or
   LAM (`www.lam-mpi.org/ <www.lam-mpi.org/>`__)
   
#. The FFTW-3 library ( `http://www.fftw.org/ <http://www.fftw.org/>`__ )
   
#. The NetCDF library ( `https://www.unidata.ucar.edu/downloads/netcdf <https://www.unidata.ucar.edu/downloads/netcdf>`__ )


On a cluster or supercomputer
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

If you are installing on a cluster or supercomputer then the MPI C++ compilers will
already be installed, and on Cray or IBM machines will probably be
called ’CC’ and ’xlC’ respectively. 

On large facilities (e.g NERSC or Archer), the compilers and libraries
needed should already be installed, but you may need to load them to use them.
It is common to organise libraries using the ``modules`` system, so try typing

.. code-block:: bash

   modules avail

to get a list of available modules. Some instructions for specific machines can
be found in :ref:`sec-machine-specific`. See your system’s
documentation on modules and which ones to load. If you don’t know, or
modules don’t work, you can still install libraries in your home
directory by following the instructions below for :ref:`FFTW <sec-fftw-from-source>`
and :ref:`NetCDF <sec-netcdf-from-source>`.


Ubuntu / Debian
~~~~~~~~~~~~~~~   

On Ubuntu or Debian distributions if you have administrator rights then you can install
MPICH2 and the needed libraries by running:

.. code-block:: bash

    $ sudo apt-get install mpich2 libmpich2-dev
    $ sudo apt-get install libfftw3-dev libnetcdf-dev
   
If you do not have administrator rights, so can't install packages, then
you need to install these libraries from source into your home directory.
See sections on :ref:`installing MPI <sec-mpi-from-source>`, :ref:`installing FFTW <sec-fftw-from-source>`
and :ref:`installing NetCDF <sec-netcdf-from-source>`.

Arch Linux
~~~~~~~~~~

.. code-block:: bash

   $ pacman -S openmpi fftw netcdf-cxx 

.. _sec-config-bout:

Configuring  BOUT++
-------------------

To compile BOUT++, you first need to configure it. 
Go into the ``BOUT-dev`` directory and run

.. code-block:: bash

    $ ./configure


If this finishes by printing a summary, and paths for IDL, Python, and
Octave, then the libraries are set up and you can skip to the next
section. If you see a message
“``ERROR: FFTW not found. Required by BOUT++``” then make sure 
FFTW-3 is installed (See the previous section on :ref:`installing dependencies <sec-dependencies>` ).

If FFTW-3 is installed in a non-standard location, you can specify  the
directory with the ``–with-fftw=`` option e.g:

.. code-block:: bash

    $ ./configure --with-fftw=$HOME/local

Configure should now find FFTW, and search for the NetCDF library. If
configure finishes successfully, then skip to the next section, but if
you see a message ``NetCDF support disabled`` then configure couldn’t
find the NetCDF library. Unless you have another file format (like HDF5) installed, this
will be followed by a message
``ERROR: At least one file format must be supported``. Check that you have
NetCDF installed (See the previous section on :ref:`installing dependencies <sec-dependencies>` ).

Like the FFTW-3 library, if NetCDF is installed in a non-standard location then
you can specify the directory with the ``--with-netcdf=`` option e.g.:

.. code-block:: bash

    $ ./configure --with-fftw=$HOME/local --with-netcdf=$HOME/local

which should now finish successfully, printing a summary of the
configuration:

.. code-block:: bash

    Configuration summary
      PETSc support: no
      SLEPc support: no
      IDA support: yes
      CVODE support: yes
      ARKODE support: yes
      NetCDF support: yes
      Parallel-NetCDF support: no
      HDF5 support: yes (parallel: no)
      MUMPS support: no

If not, see :ref:`sec-advancedinstall` for some things you can try to
resolve common problems.

.. _sec-configanalysis:

Configuring analysis routines
-----------------------------

The BOUT++ installation comes with a set of useful routines which can be
used to prepare inputs and analyse outputs. Most of this code is now in Python,
though IDL was used for many years. Python is useful In particular because the test suite
scripts and examples use Python, so to run these you’ll need python configured.

When the configure script finishes, it prints out the paths you need to
get IDL, Python, and Octave analysis routines working. If you
just want to compile BOUT++ then you can skip to the next section, but
make a note of what configure printed out.

Python
~~~~~~

.. _sec-config-python:


To use Python, you will need the NumPy and SciPy libraries. On Debian or
Ubuntu these can be installed with

.. code-block:: bash

    $ sudo apt-get install python-scipy

which should then add all the other dependencies like NumPy. To test if
everything is installed, run

.. code-block:: bash

    $ python -c "import scipy"

If not, see the SciPy website https://www.scipy.org for instructions on
installing.

To do this, the path to ``tools/pylib`` should be added to the
``PYTHONPATH`` environment variable. Instructions for doing this are
printed at the end of the configure script, for example:

.. code-block:: bash

    Make sure that the tools/pylib directory is in your PYTHONPATH
    e.g. by adding to your ~/.bashrc file

       export PYTHONPATH=/home/ben/BOUT/tools/pylib/:$PYTHONPATH

To test if this command has worked, try running

.. code-block:: bash

    $ python -c "import boutdata"

If this doesn’t produce any error messages then Python is configured
correctly.

IDL
~~~

.. _sec-config-idl:

If you want to use `IDL <https://en.wikipedia.org/wiki/IDL_(programming_language)>`__ to analyse
BOUT++ outputs, then the ``IDL_PATH`` environment variable should include the
``tools/idllib/`` subdirectory included with BOUT++. 
The required command (for Bash) is printed at the end of the BOUT++ configuration:

.. code-block:: bash

    $ export IDL_PATH=...

After running that command, check that ``idl`` can find the analysis routines by running:

.. code-block:: bash

    $ idl
    IDL> .r collect
    IDL> help, /source

You should see the function ``COLLECT`` in the ``BOUT/tools/idllib``
directory. If not, something is wrong with your ``IDL_PATH`` variable.
On some machines, modifying ``IDL_PATH`` causes problems, in which case
you can try modifying the path inside IDL by running

.. code-block:: bash

    IDL> !path = !path + ":/path/to/BOUT-dev/tools/idllib"

where you should use the full path. You can get this by going to the
``tools/idllib`` directory and typing ``pwd``. Once this is done
you should be able to use ``collect`` and other routines.

.. _sec-compile-bout:

Compiling BOUT++
----------------

Once BOUT++ has been configured, you can compile the bulk of the code by
going to the ``BOUT-dev`` directory (same as ``configure``) and running

.. code-block:: bash

    $ make

(on OS-X, FreeBSD, and AIX this should be ``gmake``). This should print
something like:

.. code-block:: bash

    ----- Compiling BOUT++ -----
    CXX      =  mpicxx
    CFLAGS   =  -O -DCHECK=2 -DSIGHANDLE \
     -DREVISION=13571f760cec446d907e1bbeb1d7a3b1c6e0212a \
     -DNCDF -DBOUT_HAS_PVODE
    CHECKSUM =  ff3fb702b13acc092613cfce3869b875
    INCLUDE  =  -I../include
      Compiling  field.cxx
      Compiling  field2d.cxx

At the end of this, you should see a file ``libbout++.a`` in the
``lib/`` subdirectory of the BOUT++ distribution. If you get an error,
please `create an issue on Github <https://github.com/boutproject/BOUT-dev/issues>`__
including:

-  Which machine you’re compiling on

-  The output from make, including full error message

-  The ``make.config`` file in the BOUT++ root directory

.. _sec-runtestsuite:

Running the test suite
----------------------

BOUT++ comes with three sets of test suites: unit tests, integrated
tests and method of manufactured solutions (MMS) tests. The easiest
way to run all of them is to simply do

.. code-block:: bash

    $ make check

from the top-level directory. Alternatively, if you just want to run
one them individually, you can do

.. code-block:: bash

    $ make check-unit-tests
    $ make check-integrated-tests
    $ make check-mms-tests

**Note:** The integrated test suite currently uses the ``mpirun``
command to launch the runs, so won’t work on machines which use a job
submission system like PBS or SGE.

These tests should all pass, but if not please `create an issue on Github <https://github.com/boutproject/BOUT-dev/issues>`__
containing:

-  Which machine you’re running on

-  The ``make.config`` file in the BOUT++ root directory

-  The ``run.log.*`` files in the directory of the test which failed

If the tests pass, congratulations! You have now got a working
installation of BOUT++. Unless you want to use some experimental
features of BOUT++, skip to section [sec-running] to start running the
code.

Installing BOUT++ (experimental)
--------------------------------

.. _sec-install-bout:

Most BOUT++ users install and develop their own copies in their home directory,
so do not need to install BOUT++ to a system directory.
As of version 4.1 (August 2017), it is possible to install BOUT++ but this is
not widely used and so should be considered experimental. 

After configuring and compiling BOUT++ as above, BOUT++ can be installed
to system directories by running as superuser or ``sudo``:

**NOTE:** Do not do this unless you know what you're doing!

.. code-block:: bash

   $ make install

This will install the following files under ``/usr/local/``:
   
* ``/usr/local/bin/bout-config``  A script which can be used to query BOUT++ configuration and compile codes with BOUT++.

* ``/usr/local/include/bout++/...`` header files for BOUT++
    
* ``/usr/local/lib/libbout++.a``  The main BOUT++ library

* ``/usr/local/lib/libpvode.a`` and ``/usr/local/lib/libpvpre.a``, the PVODE library

* ``/usr/local/share/bout++/pylib/...`` Python analysis routines

* ``/usr/local/share/bout++/idllib/...`` IDL analysis routines
  
* ``/usr/local/share/bout++/make.config`` A ``makefile`` configuration, used to compile many BOUT++ examples


To install BOUT++ under a different directory, use the ``--prefix=`` flag e.g. to install in your home directory:

  .. code-block:: bash

   $ make install prefix=$HOME/local/

You can also specify this prefix when configuring, in the usual way (see :ref:`sec-config-bout`):
   
  .. code-block:: bash

     $ ./configure --prefix=$HOME/local/
     $ make
     $ make install

More control over where files are installed is possible by passing options to
``configure``, following the GNU conventions:

* ``--bindir=``  sets where ``bout-config`` will be installed ( default ``/usr/local/bin``)

* ``--includedir=`` sets where the ``bout++/*.hxx`` header files wil be installed (default ``/usr/local/include``)

* ``--libdir=`` sets where the ``libbout++.a``, ``libpvode.a`` and ``libpvpre.a`` libraries are installed (default ``/usr/local/lib``)
  
* ``--datadir=`` sets where ``idllib``, ``pylib`` and ``make.config`` are installed (default ``/usr/local/share/``)


After installing, that you can run ``bout-config`` e.g

.. code-block:: bash

    $ bout-config --all

which should print out the list of configuration settings which ``bout-config`` can provide.
If this doesn't work, check that the directory containing ``bout-config`` is in your ``PATH``.

The python and IDL analysis scripts can be configured using ``bout-config`` rather than manually
setting paths as in :ref:`sec-configanalysis`. Add this line to your startup file (e.g. ``$HOME/.bashrc``):

.. code-block:: bash
   
   export PYTHONPATH=`bout-config --python`:$PYTHONPATH

note the back ticks around ``bout-config --python`` not quotes. Similarly for IDL:

.. code-block:: bash
   
   export IDL_PATH=`bout-config --idl`:'<IDL_DEFAULT>':$IDL_PATH

More details on using bout-config are in the :ref:`section on makefiles <sec-bout-config>`.


.. _sec-mpi-from-source:

Installing MPICH from source
----------------------------

In your home directory, create
two subdirectories: One called “install” where we’ll put the source
code, and one called “local” where we’ll install the MPI compiler:

.. code-block:: bash

    $ cd
    $ mkdir install
    $ mkdir local

Download the latest stable version of MPICH from https://www.mpich.org/ and put the
file in the “install” subdirectory created above. At the time of writing
(June 2012), the file was called ``mpich2-1.4.1p1.tar.gz``. Untar the
file:

.. code-block:: bash

    $ tar -xzvf mpich2-1.4.1p1.tar.gz

which will create a directory containing the source code. ’cd’ into this
directory and run

.. code-block:: bash

    $ ./configure --prefix=$HOME/local
    $ make
    $ make install

Each of which might take a while. This is the standard way of installing
software from source, and will also be used for installing libraries
later. The ``–prefix=`` option specifies where the software should be
installed. Since we don’t have permission to write in the system
directories (e.g. ``/usr/bin``), we just use a subdirectory of our home
directory. The ``configure`` command configures the install, finding the
libraries and commands it needs. ``make`` compiles everything using the
options found by ``configure``. The final ``make install`` step copies
the compiled code into the correct places under ``$HOME/local``.

To be able to use the MPI compiler, you need to modify the ``PATH``
environment variable. To do this, run

.. code-block:: bash

    $ export PATH=$PATH:$HOME/local/bin

and add this to the end of your startup file ``$HOME/.bashrc``. If
you’re using CSH rather than BASH, the command is

.. code-block:: bash

    % setenv PATH ${PATH}:${HOME}/local/bin

and the startup file is ``$HOME/.cshrc``. You should now be able to run
``mpicc`` and so have a working MPI compiler.

.. _sec-fftw-from-source:

Installing FFTW from source
---------------------------

If you haven’t already, create directories “install” and “local”
in your home directory:

.. code-block:: bash

    $ cd
    $ mkdir install
    $ mkdir local

Download the latest stable version from
http://www.fftw.org/download.html into the “install” directory. At the
time of writing, this was called ``fftw-3.3.2.tar.gz``. Untar this file,
and ’cd’ into the resulting directory. As with the MPI compiler,
configure and install the FFTW library into ``$HOME/local`` by running:

.. code-block:: bash

    $ ./configure --prefix=$HOME/local
    $ make
    $ make install


.. _sec-netcdf-from-source:

Installing NetCDF from source
-----------------------------

The latest versions of NetCDF have separated out the C++ API from the
main C library. As a result, you will need to download and install both.
Download the latest versions of the NetCDF-C and NetCDF-4 C++ libraries
from https://www.unidata.ucar.edu/downloads/netcdf. As of
January 2017, these are versions 4.4.1.1 and 4.3.0 respectively.

Untar the file and ’cd’ into the resulting directory:

.. code-block:: bash

    $ tar -xzvf netcdf-4.4.1.1.tar.gz
    $ cd netcdf-4.4.1.1

As with MPI compilers and FFTW, configure, then make and make install:

.. code-block:: bash

    $ ./configure --prefix=$HOME/local
    $ make
    $ make install

Sometimes configure can fail, in which case try disabling Fortran:

.. code-block:: bash

    $ ./configure --prefix=$HOME/local --disable-fortran
    $ make
    $ make install

Similarly for the C++ API:

.. code-block:: bash

    $ tar -xzvf netcdf-cxx4-4.3.0.tar.gz
    $ cd netcdf-cxx4-4.3.0
    $ ./configure --prefix=$HOME/local
    $ make
    $ make install

You may need to set a couple of environment variables as well:

.. code-block:: bash

    $ export PATH=$HOME/local/bin:$PATH
    $ export LD_LIBRARY_PATH=$HOME/local/lib:$LD_LIBRARY_PATH

You should check where NetCDF actually installed its libraries. On some
systems this will be ``$HOME/local/lib``, but on others it may be, e.g.
``$HOME/local/lib64``. Check which it is, and set ``$LD_LIBRARY_PATH``
appropriately.
