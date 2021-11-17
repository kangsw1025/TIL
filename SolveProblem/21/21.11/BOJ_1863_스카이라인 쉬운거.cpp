#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

int arr[1000001], dp[1000001];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int idx;
		cin >> idx >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		if (dp[i] == -1) {
			ans++;
			dp[i] = i;
			for (int j = i + 1; arr[j] >= arr[i] && j < n; j++) {
				dp[j] = i;
			}
		}
		else {
			if (arr[dp[i]] == arr[i]) continue;
			
			ans++;
			if (arr[dp[i]] < arr[i]) {
				dp[i] = i;
				for (int j = i + 1; arr[j] >= arr[i] && j < n; j++) {
					dp[j] = i;
				}
			}
		}
	}
	cout << ans;
	return 0;
}