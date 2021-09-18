#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);

		int l = 0, r = n - 1;

		int ans = 2e9, cnt = 0;

		while (l < r) {
			int sum = arr[l] + arr[r];

			int dif = abs(sum - k);

			if (dif <= ans) {
				if (dif == ans) {
					cnt++;
				}
				else {
					ans = dif;
					cnt = 1;
				}
			}
			if (sum < k) l++;
			else r--;
		}

		cout << cnt << "\n";
	}
	return 0;
}