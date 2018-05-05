#include <string>
#include <vector>
using namespace std;

bool IsPalindrom (string s) {
	unsigned int len = s.size() - 1;

	for (int i = len; i >= 0; i--)
		if (s[i] != s[(i - len) * -1])
			return false;

	return true;
}

vector<string> PalindromFilter (vector<string> words, int minLength) {
	vector<string> result;

	for (auto word : words)
		if (word.size() >= minLength && IsPalindrom(word))
			result.push_back(word);

	return result;
}
