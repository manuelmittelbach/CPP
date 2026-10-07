*These projects have been created as part of the 42 curriculum by [mmittelb](https://github.com/manuelmittelbach).*

# C++ Modules

The 42 C++ module series — a step-by-step introduction to C++ (C++98) and
object-oriented programming, coming from a C background. Each module is a set
of small exercises built around one core concept.

## Modules

| Module | Topics |
|---|---|
| **CPP00** | Namespaces, classes, member functions, `iostream`, initialization lists, `static`, `const` |
| **CPP01** | Memory allocation (`new` / `delete`), references vs. pointers, pointers to member functions |
| **CPP02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form, fixed-point arithmetic |
| **CPP03** | Inheritance, constructor/destructor chaining, access specifiers |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces, deep copies, virtual destructors |
| **CPP05** | Exceptions (`try` / `catch` / `throw`), custom exception classes, nested classes |
| **CPP06** | C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`), scalar conversions, serialization, type identification |

CPP07 and beyond (templates, STL containers & algorithms)
are in progress and will be added as they are completed.

## Build

Each exercise is self-contained. Where a `Makefile` is present:

```bash
make
```

Otherwise:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp
```
