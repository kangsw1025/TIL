#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,dst;
int arr[101];
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> dst;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= dst; j++)
			if (j - arr[i] >= 0) dp[j] += dp[j - arr[i]];
	}
	cout << dp[dst];
	return 0;
}