# C++: The White Belt
by Moscow Institute of Physics and Technology & Yandex

### Goals
- [ ] Get general understanding of modern `C++ -std=c++1y`
- [ ] Get understanding of pros and cons in comparison with C language
- [ ] Build fundation for being able to create `C++` modules for Node.js

### Summary
The summary will be added by me when I will finish the course.

### Tools
* OS: MacOS High Sierra, v10.13.3+
* Editor: VIM v8.0+ with plugins
* Git:
	* git v2.14.3+ (Apple Git-98)
	* hub for GitHub v2.2.9+
* Compiler:
	* g++ Apple LLVM version 9.0.0 (clang-900.0.39.2)
* Memory Tools:
	* ~gdb v8.1~ lldb (macOS default)
	* ~Valgrind~ leaks (macOS default)

### Week #1
1. Intro to C++
	* Types overview
		* `int`
		* `double`
		* `bool`
		* `char`
		* `string`
		* `vector<int> var_name`
		* `map<int, string> var_name`
		* `map<string, int> var_name`
	* Operation with builtin primitives
	* Operations with builtin containers (string & vector)
		* algorithm standard library
		* `count(begin(var_name), end(var_name), length(var_name));`
		* `sort(begin(var_name), end(var_name));`
	* Input/Output (`cin`, `cout`);
		* `cin >> x >> y;`
		* `cout << x + y << endl;`
	* Loops, conditions, comments
		* `for (auto x : var_name) {cout << x;}`
	* Usge of semicolon
	* Eclipse (Don't work well on macOS High Sierra)
	* Programming Assignment: `A+B` (see 0xA+B/README.md)
	* Operations: assignment
		* concept of full deep copying
	* Operations: division, incrementation
		* Division is type dependent
		* `+=`, `-=`, `*=` & `/=`
		* `++i`, `i++`, `--i`, `i--` and difference between pre & post increments
	* Logical operations
		* `==` operator
		* strings are compared lexicographically
		* maps & vectors could be compared with `==` operator
		* Logical NO (negation)	operator `!`
		* Logical AND (conjunction) operator `&&`
		* Logical OR (disjunction) operator `||`
	* Programming Assignment: `Min_String` (see 1xMin_String/README.md)
	* Programming Assignment: `Equation` (see 2xEquation/README.md)
	* Principles of testing
		* Create a test plan
		* Cover the edge cases
		* Cover the normal cases
	* Conditional operators and loops
		* `if`
		* `while`, `do {} while`
		* `for`, `for (auto : i)`
		* `map<string, int> dict = { {"alpha", 1}, ... };`
		* `for (auto : i) {i.first; i.second}`
		* break;
	* Programming Assignment: Division (see 3xDivision/README.md)
