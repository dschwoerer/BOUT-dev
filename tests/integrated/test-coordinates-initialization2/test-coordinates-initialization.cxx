/*
 * Test of initialization of Coordinates objects in Mesh::coords_map
 */

#include "bout.hxx"
#include "optionsreader.hxx"

int main(int argc, char** argv) {

  // Initialize BOUT++
  BoutInitialise(argc,argv);

  // Test CELL_CENTRE
  Field3D f(0., mesh);
  f.applyBoundary("neumann");

  // Test CELL_YLOW
  Field3D f_ylow(0., mesh);
  f_ylow.setLocation(CELL_YLOW);
  f_ylow.applyBoundary("neumann");

  // Synchronise all processors
  MPI_Barrier(BoutComm::get());

  MPI_Finalize();

  return 0;
}
