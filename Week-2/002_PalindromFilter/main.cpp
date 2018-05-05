#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "palindrom_filter.cpp"

int main (void) {
  vector<string> words;

  // words = {"abacaba", "aba"};
  words = {"weew", "bro", "code"};

  vector<string> v = PalindromFilter(words, 4);
  for (auto w : v)
  	std::cout << w << std::endl;
  std::cout << "============" << std::endl;

  return 0;
}
