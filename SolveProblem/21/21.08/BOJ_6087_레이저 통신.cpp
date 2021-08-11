#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int w, h;
char arr[101][101];
int dp[101][101];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };
vector<pair<int, int>> v;

void solve() {
	queue<pair<int, int>> q;
	q.push({v[0].first, v[0].second});

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];

			while (nx >= 0 && nx < w && ny >= 0 && ny < h && arr[nx][ny] == '.') {
				if (!dp[nx][ny]) {
					dp[nx][ny] = dp[x][y] + 1;
					q.push({ nx,ny });
				}
				nx += n_x[i];
				ny += n_y[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	cin >> h >> w;
	for(int i=0;i<w;i++)
		for (int j = 0; j < h; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				v.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	solve();
	cout << dp[v[1].first][v[1].second] - 1;
	return 0;
}