#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int x, y, sx, sy;
int arr[1001][1001], dp[1001][1001];
bool check[1001][1001];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void solve() {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	check[sx][sy] = true;
	while (!q.empty()) {
		int w = q.front().first;
		int h = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny]) {
				if (!check[nx][ny]) {
					dp[nx][ny] = dp[w][h] + 1;
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void show() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (arr[i][j]==1 && dp[i][j] == 0) cout << -1 << ' ';
			else cout << dp[i][j] << ' ';
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}

	solve();
	show();
	return 0;
}