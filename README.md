# 42 C++ Modules (CPP00–CPP09)

Ten progressive C++98 modules from the 42 curriculum, covering object-oriented design, resource ownership, runtime polymorphism, generic programming, and practical use of the STL. Each exercise is a small, independent program with its own Makefile.

## Modules

- **CPP00 — C++ foundations:** namespaces, classes, member functions, streams, initialization lists, and `const`/`static` members.
- **CPP01 — Memory and references:** stack and heap allocation, pointers, references, object lifetime, file streams, and member-function pointers.
- **CPP02 — Ad-hoc polymorphism:** Orthodox Canonical Form, operator overloading, and a fixed-point number type.
- **CPP03 — Inheritance:** base and derived classes, construction order, overridden behavior, and reusable interfaces.
- **CPP04 — Runtime polymorphism:** virtual dispatch, abstract classes, interfaces, and deep copying of owned resources.
- **CPP05 — Exceptions:** validated state, custom exception types, abstract forms, concrete actions, and a small factory.
- **CPP06 — Casts:** scalar conversion plus `static_cast`, `reinterpret_cast`, and `dynamic_cast` use cases.
- **CPP07 — Templates:** generic functions, array iteration, and a bounds-checked `Array<T>` with deep-copy semantics.
- **CPP08 — Containers and iterators:** generic lookup, range insertion, span calculation, and an iterable stack adapter.
- **CPP09 — STL algorithms:** data lookup, stack-based expression evaluation, and merge-insertion sorting across container types.

## Build

Exercises build separately with `c++ -Wall -Wextra -Werror -std=c++98`:

```sh
cd CPP03/ex02        # choose any exercise directory
make                 # build its executable
./ex00               # executable name varies by exercise
make clean           # remove object files
make fclean          # remove objects and executable
make re              # rebuild from scratch
```

Run each executable from its exercise directory. Programs may expect command-line arguments or interactive input. `CPP09/ex00` also requires a historical exchange-rate file named `data.csv` in that directory; it is not included in the repository.

## Notable projects

- **PhoneBook:** fixed-capacity interactive contact manager with formatted table output.
- **Fixed:** canonical fixed-point class with conversions, comparisons, arithmetic, and increment/decrement operators.
- **Animal hierarchy:** demonstrates virtual dispatch, abstract types, and safe deep copying of dynamically allocated brains.
- **Bureaucrat and forms:** exception-driven domain model with immutable constraints, executable form types, and an intern factory.
- **Bitcoin Exchange:** validates dated input and resolves each value against the nearest earlier exchange rate.
- **RPN:** evaluates Reverse Polish Notation expressions with a stack.
- **PmergeMe:** implements and times merge-insertion sorting with both `std::vector` and `std::deque`.
