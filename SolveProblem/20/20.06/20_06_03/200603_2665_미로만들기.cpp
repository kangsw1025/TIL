#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
char arr[51][51];
bool check[51][51][101];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };
int solve()
{
	check[0][0][0] = true;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push(make_pair(0, make_pair(0, 0)));

	while (!q.empty()) {
		int b = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (x == n - 1 && y == n - 1) return b;

		for (int i = 0; i < 4; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!check[nx][ny][b]) {
					check[nx][ny][b] = true;
					if (arr[nx][ny] == '1')
						q.push(make_pair(b, make_pair(nx, ny)));
					else q.push(make_pair(b + 1, make_pair(nx, ny)));
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	cout << solve();
	return 0;
}
