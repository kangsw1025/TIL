#include<iostream>
using namespace std;

long long solve(long long n) {
	long long left = 0, right = 2e8;
	long long rst = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (mid *(mid+1) / 2 <= n) {
			rst = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}