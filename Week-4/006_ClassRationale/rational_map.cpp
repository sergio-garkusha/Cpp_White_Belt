#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
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
	{
		const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
			for (auto x : rs)
				v.push_back(x);

			if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
				cout << "Rationals comparison works incorrectly" << endl;
				return 2;
			}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
