#include<iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		int mi = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				if (dp[j] > mi) mi = dp[j];
			}
		}
		dp[i] = mi + 1;
		if (dp[i] > m) m = dp[i];
	}
	cout << m;
	return 0;
}