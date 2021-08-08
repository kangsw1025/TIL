#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001], dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, Max, Min;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		Max = Min = arr[i];
		for (int j = i; j >= 0; j--) {
			Max = max(Max, arr[j]);
			Min = min(Min, arr[j]);
			dp[i + 1] = max(dp[i + 1], dp[j] + Max - Min);
		}
	}

	cout << dp[n];
	return 0;
}
