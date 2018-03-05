#include <iostream>
#include <cmath>
using namespace std;

/**
 * main - finds & prints all square roots
 * of the coefficients
 *
 * Return: void
 */
int main (void) {
    double a, b, c;

    cin >> a >> b >> c;

    if (a == 0) {
        if (b != 0)
            cout <<
							-1.0 * (c / b)
							<< endl;
    }
		else {
				// discriminant
        double di = (b * b) - (4 * a * c);

        if (di > 0)
            cout <<
							(-b + sqrt(di)) / (2 * a)
							<< " " <<
							(-b - sqrt(di)) / (2 * a)
							<< endl;
        else if (di == 0)
            cout <<
							-1.0 * b / (2 * a)
							<< endl;
    }

    return 0;
}
