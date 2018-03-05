#include <iostream>
using namespace std;

/**
 * main - calculates and prints the price with the discount
 *
 * Return: always zero
 */
int main (int argc, char *argv[]) {
	double n, a, b, x, y;

	cin >> n >> a >> b >> x >> y;

	if (n <= a)
		cout << n << endl;
	else if (n > b)
		cout << n - (n * y / 100) << endl;
	else if (n > a)
		cout << n - (n * x / 100) << endl;

	return (0);
}
