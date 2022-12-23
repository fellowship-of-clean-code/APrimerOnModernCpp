# Lesson 1: Hello world!

## Basic compilation
The easiest way to compile is:
```sh
g++ hello.cpp [-o hello.out]
```

This will build a program `hello.out` which is ready to run:
```sh
./hello.out
```

## Compilation flags
There are a lot of flags that can be passed while compiling the code.

* To select the C++ version use:
```sh
-std=c++17
```

* To enable all warnings, treat them as errors:
```sh
-Wall, -Wextra, -Werror
```

* Optimization options:
```sh
-O0 (no optmization)
```
or
```sh
-O3 or -Ofast (for full optimizations)
```

## Compilation step-by-step
Let’s write our first C++ code in a file with name `main.cpp`:
```cpp
#include <iostream>

void print_it(std::string s) {
   std::cout << s << std::endl;
}

int main() {
   print_it("Hello world!");
}
```

To compile it we perform 4 distinct actions:
```sh
g++ -E main.cpp > main.i #preprocess
g++ -S main.i #compilation
g++ -c main.s #assembly
g++ main.o -o main.out #linking
```

The difference between *compiling* and *assembling* is subtle, but you can satisfy your curiosity [here](https://www.geeksforgeeks.org/difference-between-compiler-and-assembler/)

/Link to Exercise 1/

## Compilation of more than one file

Function declaration can be separated from the implementation details.

E.g., function *declaration* is:
```cpp
void FuncName(int param); 
```

while function *definition* is:
```cpp
void FuncName(int param) {
   // Implementation details.
   std::cout << "This function is called!";
} 
```

We now move the declaration in a *header* file, e.g., `print_it.h`, and the definition in a *source* file, e.g., `print_it.cpp`

Now the main file becomes
```cpp
#include "print_it.h"

int main() {
   print_it("Hello world!");
}
```

notice the different marks `”print_it.h“`!

How `main.cpp` does it know about the *definition* of this function?

We use *modules*!

```sh
# compile modules
g++ -std=c++14 -c print_string.cpp

# organize modules into libraries
ar rcs libtools.a print_string.o # + other_modules

# compile main
g++ -std=c++14 -c main.cpp

# link main to libraries
g++ -std=c++14 main.o -L. -ltools -o hello.out
```

Building by hand is hard! We need *build systems* as, e.g., [CMake](https://cmake.org/)

/Link to Exercise 2/
