#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, r = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		r = (r * (2 * i - 1)) % (int(1e9) + 9);
	cout << r;
	return 0;
}