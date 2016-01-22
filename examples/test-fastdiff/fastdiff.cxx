#include <bout.hxx>
#include <boutmain.hxx>

Field3D f1,f2;
int physics_init(bool restarting)
{
  SOLVE_FOR2(f1,f2);
  f2.setLocation(CELL_YLOW);
    
  //a=1;
  // a.allocate();
  // BoutReal *data=a[0][0];
  
  // for (int x=0;x<mesh->ngx*mesh->ngy*mesh->ngz;x++){
  //   BoutReal tmp=(2.0*std::rand())/RAND_MAX;
  //   printf("%g\t",tmp);
  //   data[x]=tmp;
  // }

  // calling laplace to check derivatives
  //Field3D b=Laplace(a);

  
  return 0;
}

int physics_run(BoutReal t)
{
  ddt(f1)=Laplace(f1);//+DDZ(f1);
  ddt(f2)=0;
  //ddt(f2)=DDZ(f2)
  return 0;
}
