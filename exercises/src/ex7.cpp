#include <functional>
#include <iostream>

int add(int x, int y) { return x + y; }

int multiply(int x, int y) { return x * y; }

int invoke(int x, int y, std::function<int(int, int)> f) { return f(x, y); }

int main() {
  std::cout << "Addition of 20 and 10 is ";
  std::cout << invoke(20, 10, &add) << '\n';

  std::cout << "Multiplication of 20 and 10 is ";
  std::cout << invoke(20, 10, &multiply) << '\n';

  std::cout << "Addition of 20 and 10 is ";
  std::cout << invoke(20, 10, [](int x, int y) { return x + y; }) << '\n';

  std::cout << "Multiplication of 20 and 10 is ";
  std::cout << invoke(20, 10, [](int x, int y) { return x * y; }) << '\n';

  return EXIT_SUCCESS;
}