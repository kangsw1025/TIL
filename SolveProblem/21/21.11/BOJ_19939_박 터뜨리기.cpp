#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, sum;
	cin >> n >> k;

	sum = (k) * (k + 1) / 2;
	if (n < sum) cout << -1;
	else {
		n -= sum;
		n %= k;
		if (n == 0) cout << k - 1;
		else cout << k;
	}
	return 0;
}