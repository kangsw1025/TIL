#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int sx, sy, x,y;
char arr[1001][1001];
bool check[1001][1001];
vector<pair<int, int>> vec;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };


int solve() {
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < vec.size(); i++)
		q.push(make_pair(-1, make_pair(vec[i].first, vec[i].second)));

	q.push(make_pair(0, make_pair(sx, sy)));
	check[sx][sy] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		int w = q.front().second.first;
		int h = q.front().second.second;
		q.pop();
		if (cnt != -1) {
			if (w == 0 || w == x - 1 || h == 0 || h == y - 1) return cnt + 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny]=='.') {
				if (cnt != -1) {
					if (!check[nx][ny]) {
						check[nx][ny] = true;
						q.push(make_pair(cnt + 1, make_pair(nx, ny)));
					}
				}
				else if (cnt == -1) {
					arr[nx][ny] = 'F';
					q.push(make_pair(-1, make_pair(nx, ny)));
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	for(int i=0;i<x;i++)
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				sx = i;
				sy = j;
			}
			if (arr[i][j] == 'F') vec.push_back(make_pair(i, j));
		}

	int ans = solve();
	if (ans == -1) cout << "IMPOSSIBLE";
	else cout << ans;
}