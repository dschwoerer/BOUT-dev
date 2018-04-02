
#pragma once
#include "aiolosmesh.hxx"

/********************************************************
 * BOUT++ Library - Write fluid simulations in curviilinear geometry
 * Copyright (C) 2016, 2017, 2018 David Schwörer
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
 *****************************************************************/

const BoutReal WENO_SMALL = 1.0e-8;

static void DDX_C2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_x_norm(const Field3D &in);
static void DDX_C2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_y_norm(const Field3D &in);
static void DDX_C2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_z_norm(const Field3D &in);
static void DDX_C2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C2_x_norm(const Field2D &in);
static void DDX_C2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C2_y_norm(const Field2D &in);
static void DDX_C4_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_x_norm(const Field3D &in);
static void DDX_C4_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_y_norm(const Field3D &in);
static void DDX_C4_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_z_norm(const Field3D &in);
static void DDX_C4_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C4_x_norm(const Field2D &in);
static void DDX_C4_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C4_y_norm(const Field2D &in);
static void DDX_CWENO2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_CWENO2_x_norm(const Field3D &in);
static void DDX_CWENO2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_CWENO2_y_norm(const Field3D &in);
static void DDX_CWENO2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_CWENO2_z_norm(const Field3D &in);
static void DDX_CWENO2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_CWENO2_x_norm(const Field2D &in);
static void DDX_CWENO2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_CWENO2_y_norm(const Field2D &in);
static void DDX_S2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_S2_x_norm(const Field3D &in);
static void DDX_S2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_S2_y_norm(const Field3D &in);
static void DDX_S2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_S2_z_norm(const Field3D &in);
static void DDX_S2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_S2_x_norm(const Field2D &in);
static void DDX_S2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                  const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_S2_y_norm(const Field2D &in);
static void D2DX2_C2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_x_norm(const Field3D &in);
static void D2DX2_C2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_y_norm(const Field3D &in);
static void D2DX2_C2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_z_norm(const Field3D &in);
static void D2DX2_C2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C2_x_norm(const Field2D &in);
static void D2DX2_C2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C2_y_norm(const Field2D &in);
static void D2DX2_C4_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C4_x_norm(const Field3D &in);
static void D2DX2_C4_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C4_y_norm(const Field3D &in);
static void D2DX2_C4_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C4_z_norm(const Field3D &in);
static void D2DX2_C4_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C4_x_norm(const Field2D &in);
static void D2DX2_C4_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                    const BoutReal *__restrict__ in_ptr, Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C4_y_norm(const Field2D &in);
static void VDDX_C2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_x_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_y_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_z_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C2_x_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C2_y_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C4_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_x_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_y_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_z_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C4_x_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C4_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C4_y_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U1_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_x_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_y_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_z_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U1_x_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U1_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U1_y_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_x_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_y_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_z_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U2_x_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U2_y_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U3_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U3_x_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U3_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U3_y_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U3_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U3_z_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U3_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U3_x_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U3_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U3_y_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_WENO3_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_WENO3_x_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_WENO3_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_WENO3_y_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_WENO3_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_WENO3_z_norm(const Field3D &v_in, const Field3D &f_in);
static void VDDX_WENO3_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_WENO3_x_norm(const Field2D &v_in, const Field2D &f_in);
static void VDDX_WENO3_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_WENO3_y_norm(const Field2D &v_in, const Field2D &f_in);
static void FDDX_U1_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_x_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_y_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_z_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_U1_x_norm(const Field2D &v_in, const Field2D &f_in);
static void FDDX_U1_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_U1_y_norm(const Field2D &v_in, const Field2D &f_in);
static void FDDX_C2_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_C2_x_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_C2_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_C2_y_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_C2_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_C2_z_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_C2_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_C2_x_norm(const Field2D &v_in, const Field2D &f_in);
static void FDDX_C2_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_C2_y_norm(const Field2D &v_in, const Field2D &f_in);
static void FDDX_C4_x_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_C4_x_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_C4_y_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_C4_y_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_C4_z_Field3D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_C4_z_norm(const Field3D &v_in, const Field3D &f_in);
static void FDDX_C4_x_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_C4_x_norm(const Field2D &v_in, const Field2D &f_in);
static void FDDX_C4_y_Field2D_norm(BoutReal *__restrict__ result_ptr,
                                   const BoutReal *__restrict__ v_in_ptr,
                                   const BoutReal *__restrict__ f_in_ptr,
                                   Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_C4_y_norm(const Field2D &v_in, const Field2D &f_in);
static void DDX_C2_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_stag_x_on(const Field3D &in);
static void DDX_C2_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_stag_y_on(const Field3D &in);
static void DDX_C2_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_stag_z_on(const Field3D &in);
static void DDX_C2_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C2_stag_x_on(const Field2D &in);
static void DDX_C2_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C2_stag_y_on(const Field2D &in);
static void DDX_C2_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_stag_x_off(const Field3D &in);
static void DDX_C2_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_stag_y_off(const Field3D &in);
static void DDX_C2_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C2_stag_z_off(const Field3D &in);
static void DDX_C2_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C2_stag_x_off(const Field2D &in);
static void DDX_C2_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C2_stag_y_off(const Field2D &in);
static void DDX_C4_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_stag_x_on(const Field3D &in);
static void DDX_C4_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_stag_y_on(const Field3D &in);
static void DDX_C4_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_stag_z_on(const Field3D &in);
static void DDX_C4_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C4_stag_x_on(const Field2D &in);
static void DDX_C4_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                     const BoutReal *__restrict__ in_ptr,
                                     Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C4_stag_y_on(const Field2D &in);
static void DDX_C4_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_stag_x_off(const Field3D &in);
static void DDX_C4_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_stag_y_off(const Field3D &in);
static void DDX_C4_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D DDX_C4_stag_z_off(const Field3D &in);
static void DDX_C4_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C4_stag_x_off(const Field2D &in);
static void DDX_C4_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D DDX_C4_stag_y_off(const Field2D &in);
static void D2DX2_C2_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_stag_x_on(const Field3D &in);
static void D2DX2_C2_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_stag_y_on(const Field3D &in);
static void D2DX2_C2_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_stag_z_on(const Field3D &in);
static void D2DX2_C2_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C2_stag_x_on(const Field2D &in);
static void D2DX2_C2_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C2_stag_y_on(const Field2D &in);
static void D2DX2_C2_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                        const BoutReal *__restrict__ in_ptr,
                                        Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_stag_x_off(const Field3D &in);
static void D2DX2_C2_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                        const BoutReal *__restrict__ in_ptr,
                                        Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_stag_y_off(const Field3D &in);
static void D2DX2_C2_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                        const BoutReal *__restrict__ in_ptr,
                                        Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D D2DX2_C2_stag_z_off(const Field3D &in);
static void D2DX2_C2_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                        const BoutReal *__restrict__ in_ptr,
                                        Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C2_stag_x_off(const Field2D &in);
static void D2DX2_C2_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                        const BoutReal *__restrict__ in_ptr,
                                        Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D D2DX2_C2_stag_y_off(const Field2D &in);
static void VDDX_U1_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_stag_x_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_stag_y_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_stag_z_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U1_stag_x_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U1_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U1_stag_y_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U1_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_stag_x_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_stag_y_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U1_stag_z_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U1_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U1_stag_x_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U1_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U1_stag_y_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U2_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_stag_x_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_stag_y_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_stag_z_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U2_stag_x_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U2_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U2_stag_y_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U2_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_stag_x_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_stag_y_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_U2_stag_z_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_U2_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U2_stag_x_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_U2_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_U2_stag_y_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C2_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_stag_x_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_stag_y_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_stag_z_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C2_stag_x_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C2_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C2_stag_y_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C2_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_stag_x_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_stag_y_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C2_stag_z_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C2_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C2_stag_x_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C2_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C2_stag_y_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C4_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_stag_x_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_stag_y_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_stag_z_on(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C4_stag_x_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C4_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C4_stag_y_on(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C4_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_stag_x_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_stag_y_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D VDDX_C4_stag_z_off(const Field3D &v_in, const Field3D &f_in);
static void VDDX_C4_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C4_stag_x_off(const Field2D &v_in, const Field2D &f_in);
static void VDDX_C4_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D VDDX_C4_stag_y_off(const Field2D &v_in, const Field2D &f_in);
static void FDDX_U1_stag_x_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_stag_x_on(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_stag_y_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_stag_y_on(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_stag_z_Field3D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_stag_z_on(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_stag_x_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_U1_stag_x_on(const Field2D &v_in, const Field2D &f_in);
static void FDDX_U1_stag_y_Field2D_on(BoutReal *__restrict__ result_ptr,
                                      const BoutReal *__restrict__ v_in_ptr,
                                      const BoutReal *__restrict__ f_in_ptr,
                                      Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_U1_stag_y_on(const Field2D &v_in, const Field2D &f_in);
static void FDDX_U1_stag_x_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_stag_x_off(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_stag_y_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_stag_y_off(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_stag_z_Field3D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field3D FDDX_U1_stag_z_off(const Field3D &v_in, const Field3D &f_in);
static void FDDX_U1_stag_x_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_U1_stag_x_off(const Field2D &v_in, const Field2D &f_in);
static void FDDX_U1_stag_y_Field2D_off(BoutReal *__restrict__ result_ptr,
                                       const BoutReal *__restrict__ v_in_ptr,
                                       const BoutReal *__restrict__ f_in_ptr,
                                       Mesh *localmesh);

// This file is auto-generated - do not edit!
Field2D FDDX_U1_stag_y_off(const Field2D &v_in, const Field2D &f_in);