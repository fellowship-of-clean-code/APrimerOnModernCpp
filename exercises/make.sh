export CMAKE_CXX_FLAGS="-std=c++14 -Wall -pedantic -ftree-vectorize -O1"
export CMAKE_CXX_COMPILER="g++"

# Exercise 1
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS src/ex1.cpp -o ex1.out

# Exercise 2
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS -c src/print_it.cpp 
ar rcs libtools.a print_it.o
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS -c src/ex2.cpp -o main.o
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS main.o -L. -ltools -o ex2.out 

# Exercise 3
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS src/ex3.cpp -o ex3.out

# Exercise 4
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS src/ex4.cpp -o ex4.out

# Exercise 5
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS src/ex5.cpp -o ex5.out

# Exercise 6
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS src/ex6.cpp -o ex6.out

# Exercise 7
$CMAKE_CXX_COMPILER $CMAKE_CXX_FLAGS src/ex7.cpp -o ex7.out
