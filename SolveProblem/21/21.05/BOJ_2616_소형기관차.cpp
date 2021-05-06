#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int arr[50001];
int dp[50001][4];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, people, take;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people;
		arr[i] = arr[i - 1] + people;
	}
	cin >> take;
	
	int ans = 0;

	for (int i = 1; i <= 3; i++) {
		for (int j = take * i; j <= n; j++) {
			if (i == 1)
				dp[j][i] = max(dp[j-1][i], arr[j]-arr[j-take]);
			else
				dp[j][i] = max(dp[j-1][i], dp[j-take][i-1] + arr[j]-arr[j-take]);
			ans = max(ans, dp[j][i]);
		}
	}
	cout << ans;

	return 0;
}