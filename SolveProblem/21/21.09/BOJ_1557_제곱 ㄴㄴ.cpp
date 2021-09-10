#include<iostream>
using namespace std;

const int mx = 1000000;
int arr[mx + 1];

void setting() {
	arr[1] = 1;
	for (int i = 1; i <= mx; i++)
		for (int j = i * 2; j <= mx; j += i)
			arr[j] -= arr[i];
}

long long check(long long val) {
	long long ans = 0;
	for (long long i = 1; i * i <= val; i++)
		ans += arr[i] * val / (i * i);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	setting();

	long long left = 0, right, k;
	cin >> k;

	right = k * 2;

	while (left < right - 1) {
		long long mid = (left + right) / 2;

		if (check(mid) < k) left = mid;
		else right = mid;
	}
	cout << right;
	return 0;
}