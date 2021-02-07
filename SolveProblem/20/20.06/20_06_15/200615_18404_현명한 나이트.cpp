#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, sx, sy, dx, dy, cnt;
int arr[501][501];
int n_x[8] = { -2,-2,-1,-1,1,1,2,2 };
int n_y[8] = { -1,1,-2,2,-2,2,-1,1 };

void solve() {
	arr[sx][sy] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];
			
			if(nx>=1 && nx<=n && ny>=1 && ny<=n)
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = arr[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> vec;
	cin >> n >> cnt;
	cin >> sx >> sy;
	for (int i = 0; i < cnt; i++) {
		cin >> dx >> dy;
		vec.push_back(make_pair(dx, dy));
	}
	solve();
	for (int i = 0; i < vec.size(); i++)
		cout << arr[vec[i].first][vec[i].second] << ' ';
	return 0;
}