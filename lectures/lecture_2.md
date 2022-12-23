# Lesson 2: Basic Syntax

## Comments
```cpp
// comment type 1

/* comment type 2 */

/* comment type 3 
BLOCK COMMENT 
*/ 
```

But keep in mind… comments are bad!

## C++ types
* Each object, reference, function, expression in C++ is associated with a *type*, which may be *fundamental*, *compound*, or *user-defined*

* C++ is a *strongly typed* language. 

```cpp
float a; 
bool b; 
MyType c; // incomplete
MyType c{}; // complete
std::vector v; // Also, user-defined type 
std::string s; // also, user-defind type 
```

## C++ identifiers
* An identifier is an arbitrarily long sequence of digits, underscores, lowercase and uppercase Latin letters, and most Unicode characters. 
* A valid identifier must begin with a *non-digit*
* Identifiers are case-sensitive 

```cpp
int s_my_var; // valid identifier
int S_my_var; // valid but different 
int 6_a; // NOT valid 
```

## Variable visibility
* Each variable identifier is only valid within a part of the program called its *scope*

```cpp
{ //<-this defines a new scope
   float var_fl; // var_f is valid within this scope  
} //<-this defines end of the scope 

std::cout << var_fl; // Error! var_fl outside its scope 

int var_fl; // valid, var_fl not declared 
```

## If statement
* Used to conditionally execute code

```cpp
if (STATEMENT) {
   // This is executed if STATEMENT == true 
} else if (OTHER_STATEMENT) {
   // This is executed if:
   // (STATEMENT == false) && (OTHER_STATEMENT == true) 
} else { 
   // This is executed if neither is true 
} 
```

* *STATEMENT* can be *any boolean expression*

## Switch statement
* Used to conditionally execute code 

```cpp
switch (STATEMENT) { 
   case CONST_1:
   // This runs if STATEMENT == CONST_1. 
   break; 
case CONST_2:
   // This runs if STATEMENT == CONST_2. 
   break; 
default:
   // This runs if no other options worked. 
} 
```

* *break* exits the *switch* block 
* *STATEMENT* usually returns *int* or *enum* value 

Example using `enum class`:
```cpp
#include <iostream> 

int main() {
	enum class RGB { RED, GREEN, BLUE }; 
	RGB color = RGB::GREEN; 
	
	switch (color) {
	   case RGB::RED: 
	      std::cout << “red\n”; 
	      break; 
	   case RGB::GREEN: 
	      std::cout << “green\n”; 
	      break; 
	   case RGB::BLUE: 
	      std::cout << “blue\n”; 
	      break; 
	} 
	return 0; 
} 
```

## While loop
```cpp
while (STATEMENT) { 
	// Loop while STATEMENT == true. 
} 
```

* Usually used when the exact number of iterations is unknown before-hand 
* Easy to form an endless loop by mistake 

## For loop
```cpp
for (int i = 0; i < COUNT; ++i) { 
   // This happens COUNT times. 
} 
```

* In C++ *for* loops are very fast. 
* Use *for* when number of iterations is fixed and *while* otherwise. 
* Iterating over a standard containers like *array* or *vector* has simpler syntax (C++11) :
```cpp
for (const auto& value : container) { 
   // This happens for each value in the container. 
} 
```
* Iterating over maps (C++17):
```cpp
std::map<char, int> my_dict{{‘a’, 27}, {‘b’, 3}}; 
for (const auto& [key, value] : my_dict) { 
   cout << key << “ has value “ << value << endl; 
} 
```

## Exit loops
* We have control over loop iterations 
* Use *break* to exit the loop
* Use *continue* to skip to next iteration 
* Very bad style, use only if absolutely necessary

## Built-in types
```cpp
bool this_is_fun = true; // Boolean: true or false
char carret_return = ‘\n’;  // Single character
int meaning_of_life = 42; // Integer number
short smaller_int = 42; // Short number
long bigger_int = 42; // Long number
float fraction = 0.01f; // Single precision float
double precise_num = 0.01; // Double precision float
auto some_int = 13;
auto some_float = 13.0f;
auto some_double = 13.0;
std::array<int, 3> arr = {1, 2, 3};// Array of integers 
```

* C++11: The *auto* keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer
* C++11: introducing uniform initialisation
* *Always initialize* variables if you can 

## Use of variables
* Give variables *meaningful names*
* Don’t be afraid to *use longer names*
* Don’t include type *in the name*
* All variables die at the end of *their* scope 

```cpp
int main() { // Start of main scope.
	float some_float = 13.13f; // Create variable. 
	{ // New inner scope. 
		auto another_float = some_float; // Copy variable. 
	} // another_float dies. 
	return 0;
} // some_float dies. 
```

* Always use *const*to declare a *constant*
* Use *constexpr* to declare that it is possible to evaluate the value of the function or variable at compile time (C++11)

```cpp
double blackbody(double nu, double T) {
	constexpr auto k = 2. * hPlanck / cLight / cLight;
	const auto x = h * nu / kBoltzmann / T;
	return k * nu * nu * nu / expm1(x);
```


## References to variables
* Use *&* to state that a variable is a reference 
* Whatever happens to a reference happens to the variable and vice versa 
* Yields performance gain as references *avoid copying data*
* To avoid unwanted changes use *const*:
```cpp
const float& ref = original_variable; 
const std::string& hello_ref = hello; 
```
