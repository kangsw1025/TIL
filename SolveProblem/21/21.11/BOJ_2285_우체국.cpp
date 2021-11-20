#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

pair<long long, long long> arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long l = -1e9, r = 1e9;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	while (l <= r) {
		long long m = (l + r) / 2;
		long long x = 0, y = 0;
		for (int i = 1; i <= n; i++) {
			x += abs(arr[i].first - m) * arr[i].second;
			y += abs(arr[i].first - (m + 1)) * arr[i].second;
		}
		if (x <= y) r = m - 1;
		else l = m + 1;
	}
	cout << l;
	return 0;
}