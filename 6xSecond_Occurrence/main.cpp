#include <iostream>
#include <string>
using namespace std;

/**
 * main - finds the second occurrence of character 'f' inside a string,
 * and prints the index of it. If 'f' was found only once, prints -1.
 * If 'f' wasn't found, prints -2.
 *
 * Return: always zero
 */
int main (void) {
  string s;
	int s_size, count = 0;

  cin >> s;
	s_size = s.size();

  for (int i = 0; i < s_size; i++) {
		if (s[i] == 'f' && count < 2)
		{
			count++;

			if (count == 2)
			{
				cout << i << endl;
				return (0);
			}
		}
  }

	if (count == 1)
		cout << -1 << endl;
	else
		cout << -2 << endl;

  return (0);
}
