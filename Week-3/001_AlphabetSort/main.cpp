#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

void _printVector(const std::vector<std::string>& v)
{
	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		if (i + 1 != size)
			std::cout << v[i] << " ";
		else
			std::cout << v[i] << std::endl;
	}
}

int main(void)
{
	int n;

	std::cin >> n;

	std::vector<std::string> v(n);

	for (std::string& itm : v)
		std::cin >> itm;

	std::sort(begin(v), end(v),
		[](const std::string& l, const std::string& r) {
			return (lexicographical_compare(begin(l), end(l),
				begin(r), end(r),
				[](char cl, char cr) {
					return (tolower(cl) < tolower(cr));
				}
			));
		}
	);

	_printVector(v);

	return (0);
}
