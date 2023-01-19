#include <iostream>

auto counterBefore() {
  static size_t c = 0;
  return (++c);
}

auto counterAfter() {
  static size_t c = 0;
  return (c++);
}

int main() {
  for (size_t i = 0; i < 10; ++i) {
    std::cout << counterBefore() << " " << counterAfter() << "\n";
  }
  return EXIT_SUCCESS;
}