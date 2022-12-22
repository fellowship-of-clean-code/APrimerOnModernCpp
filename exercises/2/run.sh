# compile modules
g++ -std=c++14 -c print_string.cpp

# organize modules into libraries
ar rcs libtools.a print_string.o # + other_modules

# compile main
g++ -std=c++14 -c main.cpp

# link main to libraries
g++ -std=c++14 main.o -L. -ltools -o hello.out