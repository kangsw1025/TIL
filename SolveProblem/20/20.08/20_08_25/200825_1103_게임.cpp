#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[51][51];
int dp[51][51];
bool check[51][51];
int x, y, ans;

int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int solve(int w, int h) {
	if (w < 0 || h < 0 || w >= x || h >= y || arr[w][h] == 0) return 0;
	if (check[w][h]) {
		cout << -1;
		exit(0);
	}

	if (dp[w][h] != -1) return dp[w][h];

	check[w][h] = true;
	dp[w][h] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = w + (arr[w][h]*n_x[i]);
		int ny = h + (arr[w][h]*n_y[i]);
		dp[w][h] = max(dp[w][h], solve(nx, ny) + 1);
	}
	check[w][h] = false;
	return dp[w][h];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<x;i++)
		for (int j = 0; j < y; j++) {
			char w;
			cin >> w;
			if (w == 'H') arr[i][j] = 0;
			else arr[i][j] = w - '0';
		}
	ans = solve(0, 0);
	cout << ans;
	return 0;
}