# preprocess
g++ -E main.cpp > main.i

# compilation 
g++ -S main.i 

# assembly
g++ -c main.s 

# linking
g++ main.o -o hello.out 
