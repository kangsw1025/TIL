#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int low = 0, high = 2e9;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		low = max(low, arr[i]);
	}

	while (low <= high) {
		int cnt = 1;
		int mid = (low + high) / 2;
		int sum = arr[0];
		for (int i = 1; i < n; i++) {
			if (sum + arr[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += arr[i];
		}

		if (cnt <= m) high = mid - 1;
		else low = mid + 1;
	}
	cout << low;
	return 0;
}