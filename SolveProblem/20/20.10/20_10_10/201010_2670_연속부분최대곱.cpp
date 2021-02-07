#include<iostream>
#include<algorithm>
using namespace std;

double arr[10001];
double dp[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	double ans = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = arr[i] * max(dp[i - 1], 1.0);
		ans = max(ans, dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << ans;
	return 0;
}