from __future__ import print_function
from common import *
import sys
from collections import OrderedDict

# read tables
func_tables = OrderedDict()


class FuncTableEntry:
    """Contains the enum-name and the appropiate stencil"""

    def __init__(self, name, normal, upwind, flux):
        self.name = name
        self.isNormal = False
        self.isUpwind = False
        self.isFlux = False
        self.func_name = None
        if normal != 'NULL':
            self.isNormal = True
            self.func_name = normal
        if upwind != 'NULL':
            self.isUpwind = True
            ASSERT(self.func_name == None)
            self.func_name = upwind
        if flux != 'NULL':
            self.isFlux = True
            ASSERT(self.func_name == None)
            self.func_name = flux

    def isStag(self):
        return self.func_name[-4:] == "stag"

    def isFlow(self):
        return self.isFlux or self.isUpwind

    def __repr__(self):
        return str([self.name, self.func_name, self.isNormal,
                    self.isUpwind, self.isFlux, self.parent])


class FuncTable:
    """Contains all entries for a given type, e.g. UpwindStagTable

    funcname is the template for the C++ function, e.g. indexVDD%s
    """

    def __init__(self, name, table):
        self.name = name
        self.entries = []
        self.funcname = None
        inBlock = 0
        for cchar in table:
            # debug(cchar,inBlock)
            if cchar == '}':
                inBlock -= 1
            if inBlock == 2:
                current_entry += cchar
            if cchar == '{':
                inBlock += 1
                current_entry = ""
            if cchar == '}' and inBlock == 1:
                current_entry = current_entry.split(',')
                current_entry_cleaned = []
                for diff in current_entry:
                    current_entry_cleaned.append(diff.strip())
                # debug("current_entry_cleaned:",current_entry_cleaned)
                current_entry_name = current_entry_cleaned[0]
                # NI not implemented :
                to_skip = {
                    'DIFF_W3': "WENO3 - to hard",
                    'DIFF_SPLIT': "SPLIT - to different",
                    'DIFF_NND': "NND - probably broken",
                    'DIFF_DEFAULT': "DEFAULT - just a limiter"}
                if current_entry_name in to_skip:
                    debug("Skipping %s - %s" %
                          (current_entry_name, to_skip[current_entry_name]))
                    continue
                if current_entry_cleaned[1:4] == ['NULL'] * 3:
                    continue
                # debug(name,current_entry_name)
                self.entries.append(FuncTableEntry(*current_entry_cleaned))
        for entry in self.entries:
            # entry.setStag(self.isStag())
            entry.parent = self.name

    def setFuncName(self, funcname):
        self.funcname = funcname

    def getFullName(self, direction):
        fullname = self.funcname % direction.upper()
        if self.isStag():
            fullname += "_stag"
        else:
            fullname += "_non_stag"
        return fullname

    def isFlux(self):
        return self.entries[0].isFlux

    def isUpwind(self):
        return self.entries[0].isUpwind

    def isFlow(self):
        return self.isFlux() or self.isUpwind()

    def isStag(self):
        return self.entries[0].isStag()


def parse_descriptions(text):
    inBlock = 0
    descriptions = []
    entry = [""]
    for c in text:
        if c == '{':
            inBlock += 1
        elif c == '}':
            inBlock -= 1
            if inBlock == 1:
                descriptions.append([i.strip() for i in entry])
                entry = [""]
        elif inBlock == 2:
            if c == ',':
                entry.append("")
            elif c == '"':
                pass
            else:
                entry[-1] += c
    return descriptions

########################################################################
#  Parse the table that contains the list of what function belongs to
#  what type of differentiation
########################################################################
with open("tables_cleaned.cxx", "r") as f:
    inBlock = 0
    current_table = ""
    for line in f:
        inBlock += line.count('{')
        if inBlock:
            current_table += line
        inBlock -= line.count('}')
        if inBlock == 0:
            if not current_table == "":
                # debug(current_table)
                name = current_table.split(" ")[2].split("[")[0]
                # debug("a,",current_table,name,"b")
                if len(name) > 2:
                    # print name
                    if name == "DiffNameTable":
                        descriptions = parse_descriptions(current_table)
                    else:
                        func_tables[name] = FuncTable(name, current_table)
                current_table = ""


func_tables['FirstDerivTable'].setFuncName('indexDD%s')
func_tables['FirstStagDerivTable'].setFuncName('indexDD%s')
func_tables['SecondDerivTable'].setFuncName('indexD2D%s2')
func_tables['SecondStagDerivTable'].setFuncName('indexD2D%s2')
func_tables['UpwindTable'].setFuncName('indexVDD%s')
func_tables['UpwindStagTable'].setFuncName('indexVDD%s')
func_tables['FluxTable'].setFuncName('indexFDD%s')
func_tables['FluxStagTable'].setFuncName('indexFDD%s')

funcs_to_gen = []


class FuncToGen(object):

    def __init__(self, name, field, d, mode, ftype, ftg):
        self.name = name
        self.field = field
        self.stag_mode = mode
        self.fromsten = ftype
        self.d = d
        self.stag = ftype.isStag()
        self.flux = ftype.isFlow()
        self.old = [name, field, d, mstag, ftype.func_name, self.flux]
        self.sten = None
        for old in ftg:
            if old[0] == self[0]:
                if old[1] == self[1]:
                    debug(self, enable=True)
                    debug(old)
                    raise RuntimeError(
                        "Trying to add FuncToGen which already exists!")

    def __getitem__(self, ind):
        return self.old[ind]

    def __repr__(self):
        return str(self.old)

    def setSten(self, sten):
        try:
            assert(sten.flux == self.flux)
            assert(sten.stag == self.stag)
        except:
            debug(self.name, sten.name, enable=True)
            debug(self.flux, sten.flux)
            raise
        self.sten = sten

default_methods = dict()

# Having a duplicate in the list means something is wrong
duplicates(list(func_tables.keys()))

debug(func_tables, enable=True)
for name in func_tables:
    debug(name)
for name in func_tables:
    table = func_tables[name]
    #debug("Func_table:", t, func_tables[t], func_tables[t].values())
    debug()
    #fu = next(iter(func_tables[t].values()))
    if True:
        duplicates(fields)
        for field in fields:
            duplicates(dirs[field])
            for d in dirs[field]:
                warn()
                myname = table.getFullName(d)
                inp = "("
                if table.isFlow():
                    inp += "const " + field + " &v, "
                inp += "const " + field + " &f, "
                print("const", field, myname, inp,
                      "CELL_LOC outloc, DIFF_METHOD method) {")
                print("  if (method == DIFF_DEFAULT){")
                print("    method = default_%s_%s;" %
                      # drop 'Table' at end of string
                      (d, name[:-5] + ("Deriv" if table.isFlow() else "")))
                print("  }")
                print("  if (outloc == CELL_DEFAULT){")
                print("    outloc = f.getLocation();")
                print("  }")
                print("  switch (method) {")
                default_methods["default_%s_%s" %
                                (d, name[:-5])] = table.entries[0]
                duplicates(list(table.entries))
                for method_full in table.entries:
                    method = method_full.name
                    # debug(method)
                    print("  case", method + ":")
                    if table.isFlow():
                        f = "v,f"
                    else:
                        f = "f"
                    if table.isFlow():
                        # f.getLocation() == outloc guaranteed
                        if table.isStag():
                            print(
                                "    if (outloc == CELL_%sLOW) {" % d.upper())
                            print("      return %s_on_%s(interp_to(v,CELL_CENTRE),f);" %
                                  (table.funcname % d.upper(), method))
                            print("    } else {")  # inloc must be CELL_%sLOW
                            print("      return interp_to(%s_off_%s(v,interp_to(f,CELL_CENTRE)),outloc);" %
                                  (table.funcname % d.upper(), method))
                            print("    }")
                            stags = ['on', 'off']
                        else:
                            print(
                                "    if (v.getLocation() == f.getLocation()) {")
                            print("      return interp_to(%s_norm_%s(v,f),outloc);" % (
                                table.funcname % d.upper(), method))
                            print("    } else {")
                            print("      return interp_to(%s_norm_%s(interp_to(v,CELL_CENTRE),interp_to(f,CELL_CENTRE)),outloc);" % (
                                table.funcname % d.upper(), method))
                            print("    }")
                            stags = ['norm']
                    else:  # not Flow
                        if table.isStag():
                            print("    if (outloc == CELL_%sLOW){" % d.upper())
                            print("      return %s_on_%s(interp_to(%s,CELL_CENTRE));" % (
                                table.funcname % d.upper(), method, f))
                            print("    } else {")  # inloc must be CELL_%sLOW
                            print("      return interp_to(%s_off_%s(%s),outloc);" %
                                  (table.funcname % d.upper(), method, f))
                            print("    }")
                            stags = ['on', 'off']
                        else:
                            print("    return interp_to(%s_norm_%s(%s),outloc);" % (
                                table.funcname % d.upper(), method, f))
                            stags = ['norm']
                    for mstag in stags:
                        funcs_to_gen.append(FuncToGen("%s_%s_%s" % (
                            table.funcname % d.upper(), mstag, method),
                            field, d, mstag, method_full, funcs_to_gen))
                    print("    break;")
                print("  default:")
                print("    throw BoutException(\"%s AiolosMesh::" %
                      field + myname, 'unknown method %d.\\n"')
                print('      "Supported methods are"')
                for method in table.entries:
                    print('      " * ' + method.name + '"')
                print('      "\\nNote FFTs are not (yet) supported.",method);')
                print("  }; // end switch")
                print("}")
                print()


headers = ""
for func in ["indexDD%s", "indexD2D%s2", "indexVDD%s", "indexFDD%s"]:
    flux = True
    if func.find("indexD") > -1:
        flux = False
    for field in fields:
        for d in dirs[field]:
            warn()
            sig = "("
            if flux:
                sig += "const " + field + " &v,"
            sig += "const " + field + " &f"
            sig += ", CELL_LOC outloc, DIFF_METHOD method"
            sig += ",REGION ignored"
            sig += ")"
            function_header = "  virtual const " + field + " " + func % d.upper()
            function_header += sig
            function_header += " override;\n"
            headers += function_header
            function_header = "const " + field + " AiolosMesh::" + func % d.upper()
            function_header += sig
            if flux:
                f = "v, f"
            else:
                f = "f"
            print(function_header, " {")
            print("  if (outloc == CELL_DEFAULT) {")
            print("    outloc=f.getLocation();")
            print("  }")
            if flux:
                print("  if (outloc != f.getLocation()) {")
                print('    throw BoutException("AiolosMesh::index?DDX: Unhandled case for shifting.\\n\
f.getLocation()==outloc is required!");')
                print("  }")
            print("  if (this->LocalN%s == 1) {" % d)
            print("    %s result{0.,this};" % field)
            print("    result.setLocation(outloc);")
            print("    return result;")
            print("  }")
            # print '  output.write("Using aiolos mesh for
            # %s\\n");'%(func%d.upper())
            if flux:
                print("  if ((outloc == CELL_%sLOW) != (v.getLocation() == CELL_%sLOW)){" %
                      (d.upper(), d.upper()))
            else:
                print("  if ((outloc == CELL_%sLOW) != (f.getLocation() == CELL_%sLOW)){" %
                      (d.upper(), d.upper()))
            print("    // we are going onto a staggered grid or coming from one")
            print("    return", func % d.upper() +
                  "_stag", "(" + f + ",outloc,method);")
            print("  } else {")
            print("    return", func % d.upper() +
                  "_non_stag", "(" + f + ",outloc,method);")
            print("  }")
            print("}")
            print()

with open("generated_header.hxx", "w") as f:
    f.write(headers)


tmp = []
for fu in funcs_to_gen:
    tmp.append(fu[0] + fu[1])
duplicates(tmp)
guards_ = []
sys.stdout = open("generated_stencils.cxx", "w")
from gen_stencils import gen_functions_normal
gen_functions_normal(funcs_to_gen)
sys.stdout.flush()
sys.stdout = open("generated_init.cxx", "w")

for d in dirs['Field3D']:
    warn()
    for i in ['First', 'Second', 'Upwind', 'Flux']:
        for stag in ['', 'Stag']:
            print('DIFF_METHOD default_%s_%s%sDeriv;' % (d, i, stag))

warn()
print("void AiolosMesh::derivs_init(Options * option) {")
print("  std::string name;")
print("  Options * dirOption;")
for d in dirs['Field3D']:
    print("  output.write(\"\\tSetting derivatives for direction %s:\\n\");" % d)
    print('  dirOption = option->getSection("dd%s");' % d)
    print()
    for i in ['First', 'Second', 'Upwind', 'Flux']:
        if i in ['First', 'Second']:
            table = "DerivTable"
        else:
            table = "Table"
        for stag in ['', 'Stag']:
            warn()
            print('  // Setting derivatives for dd%s and %s' % (d, i + stag))
            print(' ', end=' ')
            if i == 'Second' and stag == "Stag":
                print('    name="C2";')
            if i == 'Flux' or i == 'Upwind':
                default_diff = "U1"
            else:
                default_diff = "C2"
            for option in ['dirOption']:
                if stag == "Stag":
                    names = [i + stag, i, "all"]
                else:
                    names = [i, "all"]
                for name in names:
                    print('if (%s->isSet("%s")){' % (option, name))
                    print('    %s->get("%s",name,"%s");' %
                          (option, name, default_diff))
                    print('  } else', end=' ')
            print('  {')
            print('    name="%s";' % default_diff)
            print('  }')
            print(' ', end=' ')
            options = ""
            for method in func_tables[i + stag + table].entries:
                for method_, key, description in descriptions:
                    if method.name == method_:
                        print('if (strcasecmp(name.c_str(),"%s")==0) {' % key)
                        print('    default_%s_%s%sDeriv = %s;' %
                              (d, i, stag, method.name))
                        print('    output.write("\t%15s : %s\\n");' %
                              (i + stag, description))
                        print('  } else', end=' ')
                        options += "\\n * %s: %s" % (key, description)
            print('{')
            print('    throw BoutException("Dont\'t know what diff method to use for %s (direction %s, tried to use %s)!\\nOptions are:%s",name.c_str());' % (
                i + stag, d, '%s', options))
            print('  }')
print("}")
sys.stdout.flush()
