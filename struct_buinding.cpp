#include <iostream>

struct StructBuinding {
  int a;
  double b;
  int ch;
};

// g++ -std=c++1z -Wall -pedantic struct_buinding.cpp
int main(int argc, char const *argv[]) {
  StructBuinding struct_buinding {10, 20.3, 'A'};

  std::cout << struct_buinding.a << " "
            << struct_buinding.b << " "
            << struct_buinding.ch
            << std::endl;

  auto[val_a, val_b, val_c] = struct_buinding;

  std::cout << val_a << " "
            << val_b << " "
            << val_c
            << std::endl;
  ++val_a;

  std::cout << val_a << " " << struct_buinding.a << std::endl;
  return 0;
}
