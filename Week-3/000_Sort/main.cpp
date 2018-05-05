#include <iostream>
#include <algorithm>
#include <vector>

void _printVector(const std::vector<int>& v)
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

	std::vector<int> v(n);

	for (int& itm : v)
		std::cin >> itm;

	std::sort(begin(v), end(v), [](int x, int y) {
		x = x < 0 ? x * -1 : x;
		y = y < 0 ? y * -1 : y;
		return x < y;
	});
	_printVector(v);

	return (0);
}
