#include<iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int left = 0, right = 2e9, ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = k;

		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) sum -= (mid - arr[i]);
			if (sum < 0) break;
		}
		
		if (sum >= 0) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}