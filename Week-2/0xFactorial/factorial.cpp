int Factorial (int n) {
	if (n <= 1)
		return 1;

	n = n * Factorial(n - 1);

	return n;
}
