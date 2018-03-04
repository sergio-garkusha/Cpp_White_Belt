#include <iostream>
#include <string>

int main(void) {
	std::string f, s, t;

	std::cin >> f >> s >> t;

	if (f <= s && f <= t)
		std::cout << f << std::endl;
	else if (s <= f && s <= t)
		std::cout << s << std::endl;
	else
		std::cout << t << std::endl;

	return (0);
}
