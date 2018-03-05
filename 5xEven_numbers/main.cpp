#include <iostream>
using namespace std;

/**
 * main - prints all even number in range from a to b,
 * separated by spaces
 *
 * Return: always zero
 */
int main (void) {
  int a, b;

  cin >> a >> b;

  for (int i = a; i <= b; i++) {
    if (i % 2 == 0) {
      cout << i;

      if (i + 1 == b || i + 1 > b)
        cout << endl;
      else
        cout << " ";
    }
  }

  return (0);
}
