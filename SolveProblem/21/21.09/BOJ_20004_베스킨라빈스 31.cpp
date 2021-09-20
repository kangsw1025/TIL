#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		if (31 % (i + 1) == 1) cout << i << "\n";

	return 0;
}