import os
import re
import sys
import random
import string

import tqdm
import tqdm.contrib.itertools

from sympy import Symbol
from sympy.parsing.sympy_parser import parse_expr


def mylen(s):
    return len(purere.findall(s))


def tosympy(s):
    for k, v in forward:
        s = re.sub(k, v, s)
    pt = purere.findall(s)
    for x in xs:
        s = purere.sub(x, s, count=1)
    s = parse_expr(s)
    return s, pt


def fromsympy(s, pt):
    s = str(s)
    for k, v in forward:
        s = re.sub(re.escape(v), k, s)
    for x, t in zip(xs, pt):
        s = re.sub(x, t, s)
    return s


def clean(s):
    return fromsympy(*tosympy(s)).replace(" ", "")


maxlen = int(sys.argv[1]) if len(sys.argv) > 1 else 3

xs = [Symbol(f"x{i}") for i in range(maxlen)]
xs = [f"x{i}" for i in range(maxlen)]

# pure = ["F3D", "A3D", "BRL"]
puredict = {
    "F3D": "Field3D",
    "BRL": "BoutReal",
}
pure = list(puredict.keys())
pos = set(["F3D"])  # , "A3D"])

purere = re.compile("|".join(pure))
ops = "+-*/"

names = {k: v for k, v in zip("pdmf", ops)}
inames = {v: k for k, v in names.items()}
forward = list(names.items()) + ["l(", "r)"]


xire = re.compile("x(\\d+)")


def totype(s):
    if s in pure:
        return puredict[s]
    return f"Temporary{s}"


class Todo2:
    def __init__(self, a, ob, b):
        self.a = a
        self.op = op
        self.b = b

    def __hash__(self):
        return hash(repr(self))

    def __repr__(self):
        return str((self.a, self.op, self.b))

    def __lt__(self, rhs):
        return (self.a, self.op, self.b) < (rhs.a, rhs.op, rhs.b)

    def print(self):
        la = mylen(self.a)
        lb = mylen(self.b)
        ca = clean(self.a)
        cb = clean(self.b)
        op = names[self.op]
        iop = self.op
        operator = f"operator{op}(const {totype(ca)}& lhs, const {totype(cb)}& rhs)"
        if min(la, lb) + 1 <= maxlen:
            if mylen(self.a) >= mylen(self.b):
                return f"""inline {totype(clean('F3D' + iop + self.b))} {operator} {{
  return static_cast<Field3D>(lhs) {op} rhs;
}}
"""
            return f"""inline {totype(clean(self.a + iop + 'F3D'))} {operator} {{
  return lhs {op} static_cast<Field3D>(rhs);
}}
"""
        return f"""\
inline {totype('F3D' + iop + 'F3D')} {operator} {{
  return static_cast<Field3D>(lhs) {op} static_cast<Field3D>(rhs);
}}
"""


class Todo:
    def __init__(self, a, ob, b, ret):
        self.a = a
        self.op = op
        self.b = b
        self.ret = ret

    def print1(self):
        a = self.a
        op = self.op
        b = self.b
        ret = self.ret
        self.a = totype(clean(a))
        self.sa = tosympy(a)
        self.op = names[op]
        self.b = totype(clean(b))
        self.sb = tosympy(b)
        self.str = f"{a}{op}{b}"
        self.sr = tosympy(ret)
        self.ret = totype(clean(ret))
        return f"inline {self.ret} operator{self.op}(const {self.a}& lhs, const {self.b}& rhs);\n"

    def print(self):
        ids = [xire.findall(str(s[0])) for s in [self.sa, self.sb, self.sr]]
        ids = [[int(x) for x in y] for y in ids]
        ret = f"""
inline {self.ret} operator{self.op}(const {self.a}& lhs, const {self.b}& rhs) {{
  {self.ret} ret;
"""
        lenlhs = len(ids[0])
        for i in ids[2]:
            if i < lenlhs:
                if lenlhs == 1:
                    ret += f"  ret.x{i} = lhs;\n"
                else:
                    ret += f"  ret.x{i} = lhs.x{i};\n"
            else:
                if len(ids[1]) == 1:
                    ret += f"  ret.x{i} = rhs;\n"
                else:
                    ret += f"  ret.x{i} = rhs.x{i-lenlhs};\n"
        ret += "  return ret;\n"
        ret += "};\n"
        return ret

    def __hash__(self):
        return hash(repr(self))

    def __repr__(self):
        return str((self.a, self.op, self.b))

    def __lt__(self, rhs):
        return (self.a, self.op, self.b) < (rhs.a, rhs.op, rhs.b)


class ItemSet:
    def __init__(self):
        self.items = {}

    def add(self, item):
        item_hash = repr(item)
        self.items[item_hash] = item

    def values(self):
        return self.items.values()

    def __len__(self):
        return len(self.items)

    def __repr__(self):
        return repr(self.items.values())

    def __iter__(self):
        for i in self.items.values():
            yield i


todos = ItemSet()
todos2 = ItemSet()


def printp1(p):
    ret = f"""class {totype(p)};
"""
    return ret


def printp2(p):
    ret = f"""class {totype(p)} : public TemporaryOpF3D {{
  public:
    inline operator Field3D() const;
"""
    for i, t in enumerate(tosympy(p)[1]):
        ret += f"    {puredict[t]} x{i};\n"
    ret += "};\n"
    ret += f"""{totype(p)}::operator Field3D() const {{\n"""

    for i in range(1, mylen(p)):
        ret += f"  ASSERT1_FIELDS_COMPATIBLE(x0, x{i});\n"
    ret += "  Field3D result{emptyFrom(x0)};\n"
    # todo: set region
    ret += '  BOUT_FOR(i, result.getRegion("RGN_ALL")) {\n'
    ret += "    result[i] = " + re.sub("(x\\d+)", "\\1[i]", str(tosympy(p)[0])) + ";\n"
    ret += "#if CHECK > 2\n"
    ret += "    if (! finite(result[i])) {\n"
    ret += (
        '      throw BoutException("Non-finite value in expression: {:e} = '
        + re.sub("(x\\d+)", "{:e}", str(tosympy(p)[0]))
        + '", result[i], '
        + ", ".join([f"x{i}[i]" for i in range(mylen(p))])
        + ");\n"
    )
    ret += "    }\n"
    ret += "#endif\n"
    ret += "  }\n"
    ret += "  return result;\n"
    ret += "};\n"
    return ret


def printpas1(p, assign=False):
    return f"  inline Field3D& operator{assign}=(const {totype(p)}& rhs);\n"


def printpas2(p, assign=False):
    ret = ""
    ret += f"inline Field3D& Field3D::operator{assign}=(const {totype(p)}& rhs) {{\n"
    ret += "  if (data.unique()) {\n"
    ret += "    // Delete existing parallel slices. We don't copy parallel slices, so any\n"
    ret += "    // that currently exist will be incorrect.\n"
    ret += "    clearParallelSlices();\n\n"
    ret += "    checkData(*this);\n"

    for i in range(mylen(p)):
        ret += f"    ASSERT1_FIELDS_COMPATIBLE(rhs.x0, rhs.x{i});\n"
    # todo set region
    ret += '    BOUT_FOR(i, getRegion("RGN_ALL")) {\n'
    ret += (
        f"      (*this)[i] {assign}= "
        + re.sub("(x\\d+)", "rhs.\\1[i]", str(tosympy(p)[0]))
        + ";\n"
    )
    ret += "#if CHECK > 2\n"
    ret += "      if (! finite((*this)[i])) {\n"
    ret += (
        f'        throw BoutException("Non-finite value in expression: {{:e}} {assign}= '
        + re.sub("(x\\d+)", "{:e}", str(tosympy(p)[0]))
        + '", (*this)[i], '
        + ", ".join([f"rhs.x{i}[i]" for i in range(mylen(p))])
        + ");\n"
    )
    ret += "      }\n"
    ret += "#endif\n"
    ret += "    }\n"
    ret += "    checkData(*this);\n"
    ret += "  } else {\n"
    ret += f"    (*this) = (*this) {assign} rhs;\n"
    ret += "  }\n"
    ret += "  return *this;\n"
    ret += "}\n"
    return ret


for i in range(maxlen):
    posesc = [x if x in pure else f"l{x}r" for x in pos if mylen(x) < maxlen]

    for a, b in tqdm.contrib.itertools.product(
        posesc, posesc, desc=f"Finding ops          [{i+1}/{maxlen}]", unit="op"
    ):
        if mylen(a + b) <= maxlen:
            for op in names:
                ret = f"{a}{op}{b}"
                pos.add(clean(ret))
                todos.add(Todo(a, op, b, ret))
        else:
            for op in names:
                todos2.add(Todo2(a, op, b))

pos = sorted(pos)
todos = sorted(todos)
todos2 = sorted(todos2)

realopen = open


class open:
    def __init__(self, fn, op):
        self.fn = fn
        self.tmp = "." + "".join(random.choice(string.ascii_letters) for _ in range(10))
        self.op = op

    def __enter__(self):
        self.fd = realopen(self.tmp, self.op)
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        self.fd.__exit__(self, exc_type, exc_value, traceback)
        if exc_type == None:
            os.rename(self.tmp, self.fn)

    def write(self, *args):
        self.fd.write(*args)


with open(f"generated_fieldops_merged_declare_{maxlen}.hxx", "w") as f:

    f.write("class TemporaryOpF3D{};\n")
    for p in pos:
        if p in pure:
            continue
        f.write(printp1(p))

    for todo in tqdm.tqdm(todos, desc="Calclulating Todos   [1/4]", unit="op"):
        f.write(todo.print1())

with open(f"generated_fieldops_merged_implement_{maxlen}.hxx", "w") as f:

    for p in tqdm.tqdm(pos, desc="implement ops        [2/4]", unit="op"):
        if p in pure:
            continue
        f.write(printp2(p))

    for p in tqdm.tqdm(pos, desc="implement update ops [3/4]", unit="op"):
        if p in pure:
            continue
        for op in ops:
            f.write(printpas2(p, op))

    for todo in tqdm.tqdm(todos, desc="Writing Todos        [4/4]", unit="op"):
        f.write(todo.print())

    for op in ops:
        f.write(
            f"""
template <typename T1,
	std::enable_if_t<bout::utils::is_TemporaryOpF3D<T1>::value, bool> = true,
        typename T2,
	std::enable_if_t<not bout::utils::is_TemporaryOpF3D<T2>::value, bool> = true
        >
inline Field3D operator{op}(const T1& f1, const T2& f2) {{
  return static_cast<Field3D>(f1) {op} f2;
}}

template <typename T1,
	std::enable_if_t<bout::utils::is_TemporaryOpF3D<T1>::value, bool> = true,
        typename T2,
	std::enable_if_t<not bout::utils::is_TemporaryOpF3D<T2>::value, bool> = true
        >
inline Field3D operator{op}(const T2& f1, const T1& f2) {{
  return f1 {op} static_cast<Field3D>(f2);
}}

template <typename T1,
	std::enable_if_t<bout::utils::is_TemporaryOpF3D<T1>::value, bool> = true,
        typename T2,
	std::enable_if_t<bout::utils::is_TemporaryOpF3D<T2>::value, bool> = true
        >
inline auto operator{op}(const T1& f1, const T2& f2) {{
  // C++17
  // if constexpr (sizeof(T2) > sizeof(T1)) {{
  //   return f1 {op} static_cast<Field3D>(f2);
  // }}
  return static_cast<Field3D>(f1) {op} f2;
}}
"""
        )


with open(f"generated_fieldops_merged_field3d_{maxlen}.hxx", "w") as f:
    for p in pos:
        if p in pure:
            continue
        for op in ops:
            f.write(printpas1(p, op))
