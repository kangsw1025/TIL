#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <=n; i++) {
		int min = 0;

		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (min < dp[j]) min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i]) max = dp[i];
	}
	cout << max;
	return 0;
}