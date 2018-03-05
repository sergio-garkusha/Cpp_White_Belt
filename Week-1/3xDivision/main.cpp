#include <iostream>
using namespace std;

/**
 * main - prints the result of the division of
 * A to B, or "Impossible" if B = 0
 *
 * Return: always 0
 */
int main (void) {
  int a, b;

  cin >> a >> b;

  if (b == 0)
    cout << "Impossible" << endl;
  else
    cout << a / b << endl;

  return (0);
}
