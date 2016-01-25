#include <bout.hxx>
#include <boutmain.hxx>
#include "derivs.hxx"
//#include <fenv.h>
#include <field_factory.hxx>


Field3D f1,f2;
int physics_init(bool restarting)
{
  f2.setLocation(CELL_YLOW); // needs to be set BEFORE SOLVE_FOR is called
  f2=FieldFactory::get()->create3D("f2:function", Options::getRoot(), mesh, CELL_YLOW, 0);
  
  SOLVE_FOR2(f1,f2);
  
  //output.write("Mesh is %d x %d x %d\n",mesh->ngx,mesh->ngy,mesh->ngz);
  
  return 0;
}

int physics_run(BoutReal t)
{
  //feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);
  ddt(f1)=Laplace(f1)+DDZ(f1) + DDY(f2,CELL_CENTER) + DDY(f1);
  Field3D tmp1  = DDY(f2,CELL_YLOW);
  Field3D tmp2=DDY(f1,CELL_YLOW);
  tmp2 += tmp1;
  ddt(f2) = tmp2;
  //ddt(f2).checkData(true);
  
  return 0;
}
