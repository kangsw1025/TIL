#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 987654321

int n;
int arr[126][126];
int dp[126][126];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };


void reset() {
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			dp[i][j] = INF;
		}
}

int solve() {
	queue<pair<int, int>> q;
	dp[0][0] = arr[0][0];
	q.push(make_pair(0, 0));
	
	while (!q.empty()) {
		int w = q.front().first;
		int h = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (dp[nx][ny] > dp[w][h] + arr[nx][ny]) {
					dp[nx][ny] = dp[w][h] + arr[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return dp[n - 1][n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int k =1;;k++)  {
		cin >> n;
		reset();
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		int ans = solve();
		cout << "Problem " << k << ": " << ans << "\n";
	}
	return 0;
}