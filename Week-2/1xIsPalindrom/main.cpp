#include <iostream>

#include "palindrom.cpp"

int main (void) {

  std::cout << IsPalindrom("madam") << std::endl;
  std::cout << IsPalindrom("gentleman") << std::endl;
  std::cout << IsPalindrom("X") << std::endl;

  return 0;
}
