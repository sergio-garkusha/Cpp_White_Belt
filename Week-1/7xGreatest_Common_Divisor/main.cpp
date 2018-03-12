#include <iostream>
using namespace std;

/**
 * main - finds the greatest common divisor for A & B
 *
 * Return: always zero
 */
int main (void) {
	int a, b;

	cin >> a >> b;

	while (a != 0 && b != 0)
		if (a > b)
			a = a % b;
    else
      b = b % a;

	cout << a + b << endl;

  return (0);
}
