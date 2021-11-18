#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[4001], sum[4001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		sort(arr + 1, arr + 1 + n);
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + arr[i];


		long long ans = 0;
		for (int i = 2; i <= n; i++) {
			int mn = 2e9;
			for (int j = i; j <= n; j++) {
				mn = min(mn, arr[j] * i - (sum[j] - sum[j - i]));
			}
			ans += mn;
		}

		cout << ans << "\n";
	}
	return 0;
}