#include <iostream>
using namespace std;

int recursive_div_helper (int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (recursive_div_helper(b, a % b));
}

class Rational {
public:
	Rational () {
	        p = 0;
        	q = 1;
	}

	Rational (int numerator, int denominator) {
		int div = recursive_div_helper(numerator, denominator);

		p = numerator / div;
		q = denominator / div;

		if (q < 0) {
			p *= -1;
			q *= -1;
		}
	}

	int Numerator () const {
		return (p);
	}

	int Denominator () const {
		return (q);
	}

private:
	int p;
	int q;
};

bool operator == (const Rational& left, const Rational& right) {
	if (left.Numerator() == right.Numerator()
		&& left.Denominator() == right.Denominator())
		return (true);
	else
		return (false);
}

Rational operator + (const Rational& left, const Rational& right) {
	int l = (left.Numerator() * right.Denominator())
		+ // sign of the operation
		(right.Numerator() * left.Denominator());
	int r = left.Denominator() * right.Denominator();

	return (Rational(l, r));
}

Rational operator - (const Rational& left, const Rational& right) {
	int l = (left.Numerator() * right.Denominator())
		- // sign of the operation
		(right.Numerator() * left.Denominator());
	int r = left.Denominator() * right.Denominator();

	return (Rational(l, r));
}

Rational operator * (const Rational& left, const Rational& right) {
	int l = left.Numerator() * right.Numerator();
	int r = right.Denominator() * left.Denominator();

	return (Rational(l, r));
}

Rational operator / (const Rational& left, const Rational& right) {
	return (left * Rational(right.Denominator(), right.Numerator()));
}

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}
