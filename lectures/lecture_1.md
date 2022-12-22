### Lesson 1: Hello world!

# Basic compilation

The easiest way to compile is:
```
g++ hello.cpp [-o hello.out]
```

This will build a program `hello.out` which is ready to run:
```
./hello.out
```

# Compilation flags

There is a lot of flags that can be passed while compiling the code

To select the C++ version use:
```
-std=c++17
```

To enable all warnings, treat them as errors:
```
-Wall, -Wextra, -Werror
```

Optimization options:
```
-O0 (no optmization)
```
or
```
-O3 or -Ofast (for full optimizations)
```

# Compilation step-by-step

The compiler performs 4 distinct actions:

