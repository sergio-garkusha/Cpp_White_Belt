#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * main - prints binary representation of number N
 *
 * Return: always zero
 */
int main() {
    int n;
    vector<int> arr;

    cin >> n;

    while (n > 0) {
        arr.push_back(n % 2);
        n = n / 2;
    }

    reverse(begin(arr), end(arr));

    for (int i : arr)
        cout << i;

		cout << endl;

    return 0;
}
