#include<iostream>
#include<queue>
using namespace std;

int n, x, y;
int arr[200][200];
bool dp[200][200][30];
int n_x[12] = { 1,0,-1,0,1,1,2,2,-1,-1,-2,-2 };
int n_y[12] = { 0,1,0,-1,2,-2,1,-1,2,-2,1,-1 };

int solve()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	while (!q.empty()) {
		int u = q.front().first.second;
		int c = q.front().first.first;
		int w = q.front().second.first;
		int h = q.front().second.second;
		if (w == x - 1 && h == y - 1) {
			return c;
		}
		q.pop();

		if (u < n) {
			for (int i = 4; i < 12; i++) {
				int nx = w + n_x[i];
				int ny = h + n_y[i];
				if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny] == 0 && dp[nx][ny][u + 1] == false) {
					dp[nx][ny][u + 1] = true;
					q.push(make_pair(make_pair(c + 1, u + 1), make_pair(nx, ny)));
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny] == 0 && dp[nx][ny][u] == false) {
				dp[nx][ny][u] = true;
				q.push(make_pair(make_pair(c + 1, u), make_pair(nx, ny)));
			}
		}

	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> y >> x;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];
	cout << solve();
	return 0;
}
