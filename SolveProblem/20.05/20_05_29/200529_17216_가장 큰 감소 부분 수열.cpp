#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (dp[j] > m) m = dp[j];
			}
		}
		dp[i] = m + arr[i];
		ans = max(dp[i], ans);
	}
	cout << ans;
	return 0;
}