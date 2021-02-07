#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[101];
int dp[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,ans = 0;
	cin >> n;;
	for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n + 1);

	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i].second > arr[j].second) {
				if (dp[now] < dp[j]) now = j;
			}
		}
		dp[i] = dp[now] + 1;
		ans = max(dp[i], ans);
	}
	cout << n-ans;
	return 0;
}