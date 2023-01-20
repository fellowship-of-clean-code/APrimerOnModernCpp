#include <iostream>

void how_to_use_ref() {
   std::cout << "how to use ref\n";

   int a = 1; // I define a new int variable a
   
   // int& int_ref; --- ERROR! refs require initialization  	
   int& iref = a; // now iref is a variable of type *ref to int*
   
   std::cout << " a = " << a << " , iref = " << iref << "\n";

   iref = 3; // I am able to modify the value of `a` by using the ref 

   // Notice that they both changed:
   std::cout << " a = " << a << " , iref = " << iref << "\n";

   int b = 10; // I define a new int variable b
   iref = b; // Now takes gets the value of b and by reference also a takes the same value

   std::cout << " a = " << a << " , b = " << b << " , iref = " << iref << "\n";

   iref = 5; // Notice this changes only a! iref remains an alias for a 

   std::cout << " a = " << a << " , b = " << b << " , iref = " << iref << "\n";
}

void how_to_use_ptr() {
   std::cout << "how to use ptr\n";

   int a = 1; // I define a new int variable a
   
   int * iptr; // You can define a ptr without initialization
   iptr = &a; // now iref is a variable of type *ptr to int*
   
   std::cout << " a = " << a << " , iref = " << iptr << " , *iptr = " << *iptr << "\n";

   *iptr = 3; // I am able to modify the value of `a` by using the ptr 

   // Notice that they both changed:
   std::cout << " a = " << a << " , iptr = " << iptr << " , *iptr = " << *iptr << "\n";

   int b = 10; // I define a new int variable b
   iptr = &b; // Now iptr points to b 

   // Notice that the value of iptr changed
   std::cout << " a = " << a << " , b = " << b << " , iptr = " << iptr << " , *iptr = " << *iptr << "\n";

   *iptr = 5; // Notice this changes only b! 

   std::cout << " a = " << a << " , b = " << b << " , iptr = " << iptr << " , *iptr = " << *iptr << "\n";
}

void the_problem_with_ptr() {
   std::cout << "the problem with ptr\n";

   int* iaptr;
   size_t N = 1; // but it could be much large
   iaptr = new int(N);
   iaptr[0] = 1;

   std::cout << " a = " << iaptr[0] << " , iaptr = " << iaptr << " , *iaptr = " << *iaptr << "\n";

   // What happens if I forget to delete iaptr?
   // Now iaptr gets out of scope, meaning that the variable having in memory the address dies 
   // but the memory allocate with new survives and you cannot access to that anymore
   // This cannot happen with ref as it is just an alias of the memory address 
}

int main() {
   std::cout << "Thanks Samuele for the question!\n";

   how_to_use_ref();
   how_to_use_ptr();
   the_problem_with_ptr();

   return EXIT_SUCCESS;
}
