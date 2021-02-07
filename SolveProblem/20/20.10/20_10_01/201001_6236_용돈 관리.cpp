#include<iostream>
using namespace std;

int n, k, ans;
int arr[100001];

bool solve(int num) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > num) return false;
		sum += arr[i];
		if (sum > num) {
			cnt++;
			sum = arr[i];
		}
	}
	return cnt <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int low = 1, high = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		high += arr[i];
	}
	while (low <= high) {
		int mid = (low + high) / 2;

		if (solve(mid)) {
			high = mid - 1;
			ans = mid;
		}
		else {
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}