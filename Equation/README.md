# Equation

#### Summary

Write program that recieves 3 coefficients `A`, `B` & `C` from `std::cin` for the equation `Ax^2 + Bx + C = 0` and prints all square roots of the equation to the standard output. You've guaranteed that at least one coefficient is not equal to zero.

#### Examples
stdin	 |  stdout
-----  |  ------
2 5 2  |  -0.5 -2
2 4 2  |  -1
2 1 2  |
0 4 10 |  -2.5

To compute the square root you can use the `sqrt()` function from `cmath` library:

```
#include <cmath>
```
