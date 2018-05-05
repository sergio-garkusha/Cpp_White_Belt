#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <exception>
#include <stdexcept>
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
		if (denominator == 0)
    			throw invalid_argument("zero denominator");

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
	if (right.Numerator() == 0)
		throw domain_error("division by zero");

	return (left * Rational(right.Denominator(), right.Numerator()));
}

bool operator < (const Rational& left, const Rational& right) {
    return (((left - right).Numerator()) < 0);
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
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	} catch (invalid_argument&) {

	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	} catch (domain_error&) {

	}

	cout << "OK" << endl;
	return 0;
}
