#include<iostream>
#include<algorithm>
using namespace std;

int solve(int n, int k) {
	long long ans = 1;
	for (int i = 1; i <= k; i++)
		ans = ans * (n - i + 1) / i;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	while (1) {
		cin >> n >> k;
		k = min(k, n - k);
		if (n == 0 && k == 0) break;
		cout << solve(n, k)<<"\n";
	}
	return 0;
}