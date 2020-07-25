#include<iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];
long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m,x1,x2,y1,y2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + arr[i][j];
		}

	for (int x = 0; x < m; x++) {
		cin >> x1 >> y1 >> x2 >> y2;
		ans = 0;
		for (int i = y1; i <= y2; i++) 
			ans = ans + dp[x2][i] - dp[x1-1][i];
		cout << ans << "\n";
	}
	return 0;
}