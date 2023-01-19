#include <iostream>

void print_list(const std::initializer_list<int> &list) {
  for (auto itm : list) {
    std::cout << itm << " ";
  }
  std::cout << "\n";
}

int main() {
  print_list({1, 2, 3, 5, 8, 13});
  return EXIT_SUCCESS;
}