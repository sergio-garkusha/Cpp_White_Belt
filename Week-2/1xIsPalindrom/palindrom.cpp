#include <string>
#include <iostream>

bool IsPalindrom (std::string s) {
	unsigned int len = s.size() - 1;

	for (int i = len; i >= 0; i--)
		if (s[i] != s[(i - len) * -1])
			return false;

	return true;
}
