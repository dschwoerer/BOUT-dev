.. _sec-equations:

BOUT++ physics models
=====================

Once you have tried some example codes, and generally got the hang of
running BOUT++ and analysing the results, there will probably come a
time when you want to change the equations being solved. This section
demonstrates how a BOUT++ physics model is put together. It assumes you have a working knowledge
of C or C++, but you don’t need to be an expert - most of the messy code
is hidden away from the physics model. There are several good books on
C and C++, but I’d recommend online tutorials over books because there
are a lot more of them, they’re quicker to scan through, and they’re
cheaper.


Heat conduction
---------------

The ``conduction`` example solves 1D heat conduction

 .. math::

   \frac{\partial T}{\partial t} = \nabla_{||}(\chi\partial_{||} T)

The source code to solve this is in ``conduction.cxx`` which defines a class
Conduction:

::

    class Conduction : public PhysicsModel {
     private:
     protected:
      int init(bool restarting) override {
      }
      int rhs(BoutReal t) override {
      }
    };

and then defines a standard main() function using a macro:

::

    BOUTMAIN(Conduction);

You can define your own main() function, but for most cases this is enough.
The two methods defined in Conduction, ``init`` and ``rhs``, are both needed to define
a BOUT++ physics model. The ``init`` function is run once at the start,
and should set up the simulation and specify which variables are evolving in time. 
The ``rhs`` function should calculate the time derivative, and is called at least once
per output timestep, depending on the time integration method used.

Initialisation
~~~~~~~~~~~~~~

During initialisation (the ``init`` function), the conduction example first reads an 
option from the input settings file (BOUT.inp):

::

    Options *options = Options::getRoot()->getSection("conduction");
    OPTION(options, chi, 1.0); // Read from BOUT.inp, setting default to 1.0

This first gets a section called "conduction", then requests an option called "chi" inside
this section. If this setting is not found, then the default value of 1.0 will be used.
To set this value the BOUT.inp file contains:

.. code-block:: bash

    [conduction]
    chi = 1.0

which defines a section called "conduction", and within that section a variable called "chi". 
This value can be overridden by specifying the setting on the command line:


.. code-block:: bash

    $ ./conduction conduction:chi=2

where "conduction:chi" means the variable "chi" in the section "conduction". When this option is
read, a message is printed to the BOUT.log files, giving the value used and the source of that value:

.. code-block:: bash

    Option conduction:chi = 1 (data/BOUT.inp)

After reading the chi option, the ``init`` method then specifies which variables to evolve
using a macro:

::

    // Tell BOUT++ to solve T
    SOLVE_FOR(T);

This tells the BOUT++ time integration solver to set the variable T using values from the input settings. 
It looks in a section with the same name as the variable ("T" here) for variables "scale" and "function":

.. code-block:: bash

    [T] # Settings for the T variable

    scale = 1.0  # Size of the initial perturbation
    function = gauss(y-pi, 0.2)  # The form of the initial perturbation. y from 0 to 2*pi

The function is evaluated using expressions which can involve x,y and z coordinates. More details
are given in section :ref:`sec-init-time-evolved-vars`.

Finally an error code is returned, here 0 indicates no error. If init returns non-zero then 
the simulation will stop.

Time evolution
~~~~~~~~~~~~~~

During time evolution, the time integration method (ODE integrator) calculates the system state
(here "T") at a give time. It then calls the ``rhs`` function, which should calculate the
time derivative of all the evolving variables. In this case the job of the ``rhs`` function
is to calculate "ddt(T)", the **partial derivative** of the variable "T" with respect to time, given
the value of "T": 

 .. math::

   \frac{\partial T}{\partial t} = \nabla_{||}(\chi\partial_{||} T)

The first thing the ``rhs`` function function does is communicate the guard (halo) cells:

::

    mesh->communicate(T);

This is because BOUT++ does not (generally) do communications, but leaves it up to the user to decide
when the most efficient or convenient time to do them is. Before we can take derivatives of a variable (here T),
the values of the function must be known in the boundaries and guard cells, which requires communication between
processors. By default the values in the guard cells are set to NaN, so if they are accidentally used without
first communicating then the code should crash fairly quickly with a non-finite number error.

Once the guard cells have been communicated, we calculate the right hand side (RHS) of the equation
above:

::

    ddt(T) = Div_par_K_Grad_par(chi, T);


The function "Div_par_K_Grad_par" is a function in the BOUT++ library which calculates the divergence
in the parallel (y) direction of a constant multiplied by the gradient of a function in the parallel direction.

As with the init code, a non-zero return value indicates an error and will stop the simulation.

Magnetohydrodynamics (MHD)
--------------------------

When going through this section, it may help to refer to the finished
code, which is given in the file ``mhd.cxx`` in the BOUT++ examples
directory. The equations to be solved are:

.. math::

   {{\frac{\partial \rho}{\partial t}}} =& -\mathbf{v}\cdot\nabla\rho - \rho\nabla\cdot\mathbf{v} \\
       {{\frac{\partial p}{\partial t}}} =& -\mathbf{v}\cdot\nabla p - \gamma p\nabla\cdot\mathbf{v} \\
       {{\frac{\partial \mathbf{v}}{\partial t}}} =& -\mathbf{v}\cdot\nabla\mathbf{v} +
       \frac{1}{\rho}(-\nabla p +
       (\nabla\times\mathbf{B})\times\mathbf{B}) \\ {{\frac{\partial \mathbf{B}}{\partial t}}} =&
       \nabla\times(\mathbf{v}\times\mathbf{B})

There are two ways to specify a set of equations to solve in BOUT++.
For advanced users, an object-oriented interface is available and
described in :ref:`sec-newapi`. The simplest way to start is to use a
C-like interface and define two functions:

::

    int physics_init(bool restarting) {
      return 0;
    }

    int physics_run(BoutReal t) {
      return 0;
    }

The first of these is called once at the start of the simulation, and
should set up the problem, specifying which variables are to be evolved.
The argument ``restarting`` is false the first time a problem is run,
and true if loading the state from a restart file.

The second function ``physics_run`` is called every time-step, and
should calculate the time-derivatives for a given state. In both cases
returning non-zero tells BOUT++ that an error occurred.

Variables
---------

We need to define the variables to evolve as global variables (so they
can be used in ``physics_init`` and ``physics_run``.

For ideal MHD, we need two 3D scalar fields density :math:`\rho` and
pressure :math:`p`, and two 3D vector fields velocity :math:`v`, and
magnetic field :math:`B`:

::

    Field3D rho, p; // 3D scalar fields
    Vector3D v, B;  // 3D vector fields

    int physics_init(bool restarting) {
    }

Scalar and vector fields behave much as you would expect: ``Field3D``
objects can be added, subtracted, multiplied, divided and exponentiated,
so the following examples are all valid operations:

::

    Field3D a, b, c;
    BoutReal r;

    a = b + c; a = b - c;
    a = b * c; a = r * b;
    a = b / c; a = b / r; a = r / b;
    a = b ^ c; a = b ^ r; a = r ^ b;

Similarly, vector objects can be added/subtracted from each other,
multiplied/divided by scalar fields and real numbers, for example:

::

    Vector3D a, b, c;
    Field3D f;
    BoutReal r;

    a = b + c; a = b - c;
    a = b * f; a = b * r;
    a = b / f; a = b / r;

In addition the dot and cross products are represented by ``*`` and
:math:`\wedge` \ symbols:

::

    Vector3D a, b, c;
    Field3D f;

    f = a * b // Dot-product
    a = b ^ c // Cross-product

For both scalar and vector field operations, so long as the result of an
operation is of the correct type, the usual C/C++ shorthand notation can
be used:

::

    Field3D a, b;
    Vector3D v, w;

    a += b; v *= a; v -= w; v ^= w; // valid
    v *= w; // NOT valid: result of dot-product is a scalar

Evolution equations
-------------------

At this point we can tell BOUT++ which variables to evolve, and where
the state and time-derivatives will be stored. This is done using the
``bout_solve(variable, name)`` function in ``physics_init``:

::

    int physics_init(bool restarting) {
      bout_solve(rho, "density");
      bout_solve(p,   "pressure");
      bout_solve(v,   "v");
      bout_solve(B,   "B");

      return 0;
    }

The name given to this function will be used in the output and restart
data files. These will be automatically read and written depending on
input options (see :ref:`sec-options`). Input options based on these
names are also used to initialise the variables.

If the name of the variable in the output file is the same as the
variable name, you can use a shorthand macro. In this case, we could use
this shorthand for ``v`` and ``B``:

::

    SOLVE_FOR(v);
    SOLVE_FOR(B);

To make this even shorter, we can use macros ``SOLVE_FOR2``,
``SOLVE_FOR3``, ..., ``SOLVE_FOR6`` to shorten our initialisation code
to

::

    int physics_init(bool restarting) {
      bout_solve(rho, "density");
      bout_solve(p,   "pressure");
      SOLVE_FOR2(v, B);

      return 0;
    }

The equations to be solved can now be written in the ``physics_run``
function. The value passed to the function (``BoutReal t``) is the
simulation time - only needed if your equations contain time-dependent
sources or similar terms. To refer to the time-derivative of a variable
``var``, use ``ddt(var)``. The ideal MHD equations can be written as:

::

    int physics_run(BoutReal t) {
      ddt(rho) = -V_dot_Grad(v, rho) - rho*Div(v);
      ddt(p) = -V_dot_Grad(v, p) - gamma*p*Div(v);
      ddt(v) = -V_dot_Grad(v, v) + ( (Curl(B)^B) - Grad(p) ) / rho;
      ddt(B) = Curl(v^B);
    }

Where the differential operators ``vector = Grad(scalar)``,
``scalar = Div(vector)``, and ``vector = Curl(vector)`` are used. For
the density and pressure equations, the
:math:`\mathbf{v}\cdot\nabla\rho` term could be written as
``v*Grad(rho)``, but this would then use central differencing in the
Grad operator. Instead, the function ``V_dot_Grad`` uses upwinding
methods for these advection terms. In addition, the ``Grad`` function
will not operate on vector objects (since result is neither scalar nor
vector), so the :math:`\mathbf{v}\cdot\nabla\mathbf{v}` term CANNOT be
written as ``v*Grad(v)``.

.. _sec-inputopts:

Input options
-------------

Note that in the above equations the extra parameter ``gamma`` has been
used. To enable this to be set in the input options file (see
:ref:`sec-options`), we use the ``options`` object in the
initialisation function:

::

    BoutReal gamma;

    int physics_init(bool restarting) {
      Options *globalOptions = Options::getRoot();
      Options *options = globalOptions->getSection("mhd");

      options->get("gamma", gamma, 5.0/3.0);

This specifies that an option called “gamma” in a section called “mhd”
should be put into the variable ``gamma``. If the option could not be
found, or was of the wrong type, the variable should be set to a default
value of :math:`5/3`. The value used will be printed to the output file,
so if gamma is not set in the input file the following line will appear:

::

          Option mhd / gamma = 1.66667 (default)

This function can be used to get integers and booleans. To get strings,
there is the function (``char* options.getString(section, name)``. To
separate options specific to the physics model, these options should be
put in a separate section, for example here the “mhd” section has been
specified. To save having to write the section name for every option,
there is the ``setSection`` function:

::

    BoutReal gamma;
    int someint;

    int physics_init(bool restarting) {
      Options *globalOptions = Options::getRoot();
      Options *options = globalOptions->getSection("mhd");

      options->get("gamma", gamma, 5.0/3.0);
      options->get("someint", someint, 0);

Most of the time, the name of the variable (e.g. ``gamma``) will be the
same as the identifier in the options file (“gamma”). In this case,
there is the macro

::

    OPTION(options, gamma, 5.0/3.0);

which is equivalent to

::

    options->get("gamma", gamma, 5.0/3.0);

See :ref:`sec-options` for more details of how to use the input
options.

Communication
-------------

If you plan to run BOUT++ on more than one processor, any operations
involving y derivatives will require knowledge of data stored on other
processors. To handle the necessary parallel communication, there is the
``mesh->communicate`` function. This takes care of where the data needs
to go to/from, and only needs to be told which variables to transfer.

If you only need to communicate a small number (up to 5 currently) of
variables then just call the ``mesh->communicate`` function directly.
For the MHD code, we need to communicate the variables ``rho,p,v,B`` at
the beginning of the ``physics_run`` function before any derivatives are
calculated:

::

    int physics_run(BoutReal t) {
      mesh->communicate(rho, p, v, B);

If you need to communicate lots of variables, or want to change at
run-time which variables are evolved (e.g. depending on input options),
then you can create a group of variables and communicate them later. To
do this, first create a ``FieldGroup`` object , in this case called
``comms`` , then use the add method. This method does no communication,
but records which variables to transfer when the communication is done
later.

::

    FieldGroup comms;

    int physics_init() {
      .
      .
      .
      comms.add(rho);
      comms.add(p);
      comms.add(v);
      comms.add(B);

      return 0;
    }

The ``comms.add()`` routine can be given up to 6 variables at once
(there’s no practical limit on the total number of variables which are
added to a ``FieldGroup`` ), so this can be shortened to

::

    FieldGroup comms;

    int physics_init() {
      .
      .
      .
      comms.add(rho, p, v, B);

      return 0;
    }

To perform the actual communication, call the ``mesh->communicate``
function with the group. In this case we need to communicate all these
variables before performing any calculations, so call this function at
the start of the ``physics_run`` routine:

::

    int physics_run(BoutReal t) {
      mesh->communicate(comms);
      .
      .
      .

In many situations there may be several groups of variables which can be
communicated at different times. The function ``mesh->communicate``
consists of a call to ``mesh->send`` followed by ``mesh->wait`` which
can be done separately to interleave calculations and communications.
This will speed up the code if parallel communication bandwidth is a
problem for your simulation.

In our MHD example, the calculation of ``ddt(rho)`` and ``ddt(p)`` does
not require ``B``, so we could first communicate ``rho``, ``p``, and
``v``, send ``B`` and do some calculations whilst communications are
performed:

::

    int physics_run(BoutReal t) {
      mesh->communicate(rho, p, v); // sends and receives rho, p and v
      comm_handle ch = mesh->send(B);// only send B

      ddt(rho) = ...
      ddt(p) = ...

      mesh->wait(ch); // now wait for B to arrive

      ddt(v) = ...
      ddt(B) = ...

      return 0;
    }

This scheme is not used in ``mhd.cxx``, partly for clarity, and partly
because currently communications are not a significant bottleneck (too
much inefficiency elsewhere!).

When a differential is calculated, points on neighbouring cells are
assumed to be in the guard cells. There is no way to calculate the
result of the differential in the guard cells, and so after every
differential operator the values in the guard cells are invalid.
Therefore, if you take the output of one differential operator and use
it as input to another differential operator, you must perform
communications (and set boundary conditions) first. See
:ref:`sec-diffops`.

Boundary conditions
-------------------

All evolving variables have boundary conditions applied automatically
after the ``physics_run`` has finished. Which condition is applied
depends on the options file settings (see :ref:`sec-bndryopts`). If
you want to disable this and apply your own boundary conditions then set
boundary condition to ``none`` in the ``BOUT.inp`` options file.

In addition to evolving variables, it’s sometimes necessary to impose
boundary conditions on other quantities which are not explicitly
evolved.

The simplest way to set a boundary condition is to specify it as text,
so to apply a Dirichlet boundary condition:

::

      Field3D var;
      ...
      var.applyBoundary("dirichlet");

The format is exactly the same as in the options file. Each time this is
called it must parse the text, create and destroy boundary objects. To
avoid this overhead and have different boundary conditions for each
region, it’s better to set the boundary conditions you want to use first
in ``physics_init``, then just apply them every time:

::

    Field3D var;

    int physics_init() {
      ...
      var.setBoundary("myVar");
      ...
    }

    int physics_run(BoutReal t) {
      ...
      var.applyBoundary();
      ...
    }

This will look in the options file for a section called ``[myvar]``
(upper or lower case doesn’t matter) in the same way that evolving
variables are handled. In fact this is precisely what is done: inside
``bout_solve`` (or ``SOLVE_FOR``) the ``setBoundary`` method is called,
and then after ``physics_run`` the applyBoundary() method is called on
each evolving variable. This method also gives you the flexibility to
apply different boundary conditions on different boundary regions (e.g.
radial boundaries and target plates); the first method just applies the
same boundary condition to all boundaries.

Another way to set the boundaries is to copy them from another variable:

::

    Field3D a, b;
      ...
      a.setBoundaryTo(b); // Copy b's boundaries into a
      ...

Custom boundary conditions
~~~~~~~~~~~~~~~~~~~~~~~~~~

The boundary conditions supplied with the BOUT++ library cover the most
common situations, but cannot cover all of them. If the boundary
condition you need isn’t available, then it’s quite straightforward to
write your own. First you need to make sure that your boundary condition
isn’t going to be overwritten. To do this, set the boundary condition to
“none” in the BOUT.inp options file, and BOUT++ will leave that boundary
alone. For example:

::

    [P]
    bndry_all = dirichlet
    bndry_xin = none
    bndry_xout = none

would set all boundaries for the variable “P” to zero value, except for
the X inner and outer boundaries which will be left alone for you to
modify.

To set an X boundary condition, it’s necessary to test if the processor
is at the left boundary (first in X), or right boundary (last in X).
Note that it might be both if ``NXPE = 1``, or neither if ``NXPE > 2``.

::

      Field3D f;
      ...
      if(mesh->firstX()) {
        // At the left of the X domain
        // set f[0:1][*][*] i.e. first two points in X, all Y and all Z
        for(int x=0; x < 2; x++)
          for(int y=0; y < mesh->LocalNy; y++)
            for(int z=0; z < mesh->LocalNz; z++) {
              f[x][y][z] = ...
            }
      }
      if(mesh->lastX()) {
        // At the right of the X domain
        // Set last two points in X
        for(int x=mesh->LocalNx-2; x < mesh->LocalNx; x++)
          for(int y=0; y < mesh->LocalNy; y++)
            for(int z=0; z < mesh->LocalNz; z++) {
              f[x][y][z] = ...
            }
      }

note the size of the local mesh including guard cells is given by
``mesh->LocalNx``, ``mesh->LocalNy``, and ``mesh->LocalNz``. The functions
``mesh->firstX()`` and ``mesh->lastX()`` return true only if the current
processor is on the left or right of the X domain respectively.

Setting custom Y boundaries is slightly more complicated than X
boundaries, because target or limiter plates could cover only part of
the domain. Rather than use a ``for`` loop to iterate over the points in
the boundary, we need to use a more general iterator:

::

      Field3D f;
      ...
      RangeIterator it = mesh->iterateBndryLowerY();
      for(it.first(); !it.isDone(); it++) {
        // it.ind contains the x index
        for(int y=2;y>=0;y--)  // Boundary width 3 points
          for(int z=0;z<mesh->LocalNz;z++) {
            ddt(f)[it.ind][y][z] = 0.;  // Set time-derivative to zero in boundary
          }
      }

This would set the time-derivative of f to zero in a boundary of width 3
in Y (from 0 to 2 inclusive). In the same way
``mesh->iterateBndryUpperY()`` can be used to iterate over the upper
boundary:

::

      RangeIterator it = mesh->iterateBndryUpperY();
      for(it.first(); !it.isDone(); it++) {
        // it.ind contains the x index
        for(int y=mesh->LocalNy-3;y<mesh->LocalNy;y--)  // Boundary width 3 points
          for(int z=0;z<mesh->LocalNz;z++) {
            ddt(f)[it.ind][y][z] = 0.;  // Set time-derivative to zero in boundary
          }
      }

Initial profiles
----------------

Up to this point the code is evolving total density, pressure etc. This
has advantages for clarity, but has problems numerically: For small
perturbations, rounding error and tolerances in the time-integration
mean that linear dispersion relations are not calculated correctly. The
solution to this is to write all equations in terms of an initial
“background” quantity and a time-evolving perturbation, for example
:math:`\rho(t) arrow \rho_0 +
\tilde{\rho}(t)`. For this reason, **the initialisation of all
variables passed to the ``bout_solve`` function is a combination of
small-amplitude gaussians and waves; the user is expected to have
performed this separation into background and perturbed quantities.**

To read in a quantity from a grid file, there is the ``grid.get``
function:

::

    Field2D Ni0; // Background density

    int physics_init(bool restarting) {
      ...
      mesh->get(Ni0, "Ni0");
      ...
    }

As with the input options, most of the time the name of the variable in
the physics code will be the same as the name in the grid file to avoid
confusion. In this case, you can just use

::

    GRID_LOAD(Ni0);

which is equivalent to

::

    mesh->get(Ni0, "Ni0");

Output variables
----------------

BOUT++ always writes the evolving variables to file, but often it’s
useful to add other variables to the output. For convenience you might
want to write the normalised starting profiles or other non-evolving
values to file. For example:

::

      Field2D Ni0;
      ...
      GRID_LOAD(Ni0);
      dump.add(Ni0, "Ni0", 0);

where the ’0’ at the end means the variable should only be written to
file once at the start of the simulation. For convenience there are some
macros e.g.

::

      SAVE_ONCE(Ni0);

is equivalent to

::

      dump.add(Ni0, "Ni0", 0);

In some situations you might also want to write some data to a different
file. To do this, create a Datafile object:

::

    Datafile mydata;

in physics\_init, you then:

#. (optional) Initialise the file, passing it the options to use. If you
   skip this step, default (sane) options will be used. This just allows
   you to enable/disable, use parallel I/O, set whether files are opened
   and closed every time etc.

   ::

       mydata = Datafile(Options::getRoot()->getSection("mydata"));

   which would use options in a section [mydata] in BOUT.inp

#. Open the file for writing

   ::

       mydata.openw("mydata.nc")

   By default this only specifies the file name; actual opening of the
   file happens later when the data is written. If you are not using
   parallel I/O, the processor number is also inserted into the file
   name before the last “.”, so mydata.nc” becomes “mydata.0.nc”,
   “mydata.1.nc” etc. The file format used depends on the extension, so
   “.nc” will open NetCDF, and “.hdf5” or “.h5” an HDF5 file.

   (see e.g. src/fileio/datafile.cxx line 139, which calls
   src/fileio/dataformat.cxx line 23, which then calls the file format
   interface e.g. src/fileio/impls/netcdf/nc\_format.cxx line 172).

#. Add variables to the file

   ::

       mydata.add(variable, "name") ;  // Not evolving. Every time the file is
       written, this will be overwritten
       mydata.add(variable2, "name2", 1); // Evolving. Will output a sequence of values

Whenever you want to write values to the file, for example in
physics\_run or a monitor, just call

::

    mydata.write();

To collect the data afterwards, you can specify the prefix to collect.
In Python:

::

    >>> var = collect("name", prefix="mydata")

or in IDL:

::

    IDL> var = collect(var="name", prefix="mydata")

By default the prefix is “BOUT.dmp”.
