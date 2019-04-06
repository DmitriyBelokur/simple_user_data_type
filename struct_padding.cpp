#include <iostream>

struct Byte24 {
  char a;
  long int b;
  int c;
};

struct Byte16 {
  char a;
  int b;
  long int c;
};

int main(int argc, char const *argv[]) {
  std::cout << sizeof(Byte24) << " " << sizeof(Byte16) << std::endl;
  return 0;
}
