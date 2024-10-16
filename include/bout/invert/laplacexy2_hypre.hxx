/**************************************************************************
 * Laplacian solver in 2D (X-Y)
 *
 * Equation solved is:
 *
 * Div( A * Grad_perp(x) ) + B*x = b
 *
 * Intended for use in solving n = 0 component of potential
 * from inversion of vorticity equation
 *
 **************************************************************************
 * Copyright 2015 B.Dudson
 *
 * Contact: Ben Dudson, bd512@york.ac.uk
 *
 * This file is part of BOUT++.
 *
 * BOUT++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BOUT++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with BOUT++.  If not, see <http://www.gnu.org/licenses/>.
 *
 **************************************************************************/

#ifndef LAPLACE_XY2_HYPRE_H
#define LAPLACE_XY2_HYPRE_H

#include <bout/build_defines.hxx>

#if not BOUT_HAS_HYPRE
// If no Hypre

#warning LaplaceXY requires Hypre. No LaplaceXY available

#include "bout/globalindexer.hxx"
#include <bout/mesh.hxx>
#include <boutexception.hxx>
#include <options.hxx>

/*!
 * Create a dummy class so that code will compile
 * without Hypre, but will throw an exception if
 * LaplaceXY is used.
 */
class LaplaceXY2Hypre {
public:
  LaplaceXY2Hypre(Mesh* UNUSED(m) = nullptr, Options* UNUSED(opt) = nullptr,
                  const CELL_LOC UNUSED(loc) = CELL_CENTRE) {
    throw BoutException("LaplaceXY requires Hypre. No LaplaceXY available");
  }
  void setCoefs(const Field2D& UNUSED(A), const Field2D& UNUSED(B)) {}
  Field2D solve(const Field2D& UNUSED(rhs), const Field2D& UNUSED(x0)) {
    throw BoutException("LaplaceXY requires Hypre. No LaplaceXY available");
  }
};

#else // BOUT_HAS_HYPRE

class Mesh;

#include "utils.hxx"
#include <bout/hypre_interface.hxx>

class LaplaceXY2Hypre {
public:
  LaplaceXY2Hypre(Mesh* m = nullptr, Options* opt = nullptr,
                  const CELL_LOC loc = CELL_CENTRE);
  ~LaplaceXY2Hypre() = default;

  /*!
   * Set coefficients (A, B) in equation:
   * Div( A * Grad_perp(x) ) + B*x = b
   */
  void setCoefs(const Field2D& A, const Field2D& B);

  /*!
   * Solve Laplacian in X-Y
   *
   * Inputs
   * ======
   *
   * rhs  - The field to be inverted. This must be allocated
   *        and contain valid data.
   * x0   - Initial guess at the solution. If this is unallocated
   *        then an initial guess of zero will be used.
   *
   * Returns
   * =======
   *
   * The solution as a Field2D. On failure an exception will be raised
   *
   */
  Field2D solve(Field2D& rhs, Field2D& x0);

  /*!
   * Preconditioner function
   * This is called by Hypre via a static function.
   * and should not be called by external users
   */
  // int precon(HYPRE_IJVector x, HYPRE_IJVector y);

private:
  Mesh* localmesh; ///< The mesh this operates on, provides metrics and communication
  IndexerPtr<Field2D> indexConverter;
  bout::HypreMatrix<Field2D> M;
  bout::HypreVector<Field2D> x;
  bout::HypreVector<Field2D> b;
  bout::HypreSystem<Field2D> linearSystem;

  // Y derivatives
  bool include_y_derivs; // Include Y derivative terms?

  // Boundary conditions
  bool x_inner_dirichlet; // Dirichlet on inner X boundary?
  bool x_outer_dirichlet; // Dirichlet on outer X boundary?
  bool y_bndry_dirichlet; // Dirichlet on Y boundary?

  bool print_timing;

  // Location of the rhs and solution
  CELL_LOC location;

  /*!
   * Return the communicator for XY
   */
  MPI_Comm communicator();
};

#endif // BOUT_HAS_HYPRE
#endif // LAPLACE_XY_HYPRE_H
