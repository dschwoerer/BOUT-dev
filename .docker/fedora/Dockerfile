FROM registry.fedoraproject.org/fedora:latest

RUN echo "install_weak_deps=False" >> /etc/dnf/dnf.conf && rm /etc/yum.repos.d/*modular*

ARG MPI=mpich

# Some convinient tools
# RUN dnf -y install dnf-plugins-core python3-pip emacs vim nano sudo diffutils git && dnf clean all

# BOUT++ deps
RUN dnf -y install netcdf-devel netcdf-cxx4-devel hdf5-devel fftw-devel cmake python3-numpy python3-Cython python3-netcdf4 python3-scipy python3-boututils python3-boutdata flexiblas-devel gcc-c++ mpark-variant-devel python3-jinja2 petsc-$MPI-devel hdf5-$MPI-devel sundials-$MPI-devel sundials-devel git-core && dnf clean all

ARG PETSC_VERSION=3.16.4

# PETSc
RUN dnf install -y bison flex diffutils && dnf clean all \
 && VER=$PETSC_VERSION && curl https://ftp.mcs.anl.gov/pub/petsc/release-snapshots/petsc-lite-$VER.tar.gz > petsc-lite-$VER.tar.gz \
 && tar -xf petsc-lite-$VER.tar.gz \
 && cd petsc-$VER/ \
 && /usr/bin/python3 ./configure --with-clanguage=cxx --with-mpi=yes --with-shared-libraries --with-precision=double --with-scalar-type=real \
    --download-mumps=1 --download-scalapack=1 --download-blacs=1 --download-fblas-lapack=1 \
    --download-parmetis=1 --download-ptscotch=1 --download-metis=1 --with-openmp=1 --with-debugging=0 --prefix=/opt/petsc \
    --with-python-exec=/usr/bin/python3 --with-mpi-dir=/usr/lib64/$MPI --with-blas-lib=flexiblas --with-lapack-lib=flexiblas\
 && make all \
 && make install \
 && make check \
 && rm -r /petsc-$VER/
# Check is really slow
# && make test \


# ----------------------------------------------------------------
# Build and install BOUT++
# ----------------------------------------------------------------
RUN useradd boutuser -p boutforever -G wheel
RUN mkdir /opt/bout++ && chown boutuser /opt/bout++

USER boutuser
WORKDIR /home/boutuser

ARG COMMIT=next

# Checkout submodules now so configure later is fast, and iterating on
# it less painful
RUN git clone https://github.com/dschwoerer/BOUT-dev.git \
 && chown -R boutuser /home/boutuser/BOUT-dev \
 && cd BOUT-dev \
 && git checkout $COMMIT \
 && git -c submodule.recurse=false submodule update --init --recursive


WORKDIR /home/boutuser/BOUT-dev

ARG CMAKE_OPTIONS

ENV MPI_BIN=/usr/lib64/$MPI/bin
ENV MPI_SYSCONFIG=/etc/$MPI-x86_64
ENV MPI_FORTRAN_MOD_DIR=/usr/lib64/gfortran/modules/$MPI
ENV MPI_INCLUDE=/usr/include/$MPI-x86_64
ENV MPI_LIB=/usr/lib64/$MPI/lib
ENV MPI_MAN=/usr/share/man/$MPI-x86_64
ENV MPI_PYTHON_SITEARCH=/usr/lib64/python3.9/site-packages/$MPI
ENV MPI_PYTHON3_SITEARCH=/usr/lib64/python3.9/site-packages/$MPI
ENV MPI_COMPILER=$MPI-x86_64
ENV MPI_SUFFIX=_$MPI
ENV MPI_HOME=/usr/lib64/$MPI


RUN export PATH=$MPI_BIN:$PATH LD_LIBRARY_PATH=$MPI_LIB:$LD_LIBRARY_PATH \
 && export PKG_CONFIG_PATH=$MPI_LIB/pkgconfig:$PKG_CONFIG_PATH MANPATH=$MPI_MAN:$MANPATH \
 && cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/opt/bout++/ \
          -DBOUT_GENERATE_FIELDOPS=OFF \
          -DBOUT_USE_PETSC=ON -DPETSc_ROOT=/opt/petsc \
          -DBOUT_ENABLE_METRIC_3D=ON -DBOUT_ENABLE_OPENMP=ON -DBOUT_ENABLE_PYTHON=ON \
          -DBOUT_USE_SUNDIALS=ON -DSUNDIALS_ROOT=/usr/lib64/$MPI/ -DSUNDIALS_INCLUDE_DIR=/usr/include/$MPI-x86_64/sundials/ \
	  $CMAKE_OPTIONS || (cat /home/boutuser/BOUT-dev/build/CMakeFiles/CMake{Output,Error}.log  ; exit 1)

#

RUN make -C build -j 2
RUN make -C build install

RUN find /opt/bout++