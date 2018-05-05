#include <iostream>
#include <sstream>
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

istream& operator >> (istream& s, Rational& n) {
	int a, b;
	char c;

	s >> a >> c >> b;

	if (s && c == '/')
		n = Rational(a, b);

	return (s);
}

ostream& operator << (ostream& s, const Rational& n) {
	return (s << n.Numerator() << '/' << n.Denominator());
}

int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}
