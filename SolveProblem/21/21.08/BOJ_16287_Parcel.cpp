#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int k, n;
int arr[5001], dp[800001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];

			if (k - sum <= 0) continue;
			else if (dp[k - sum] && dp[k - sum] < i) {
				cout << "YES";
				return 0;
			}
			dp[sum] = (dp[sum] ? min(dp[sum], j) : j);
		}
	}
	cout << "NO";
	return 0;
}