#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n;
char arr[2][51];
bool visit[2][51];

int n_x[3] = { 0,1,-1 };
int n_y[3] = { 1,0,0 };

int dfs(int s) {

	visit[s][0] = true;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push({ 1,{s,0 } });

	while (!q.empty()) {
		int dst = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		if (y == n - 1) return dst;

		for (int i = 0; i < 3; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];

			if (nx >= 0 && nx < 2 && ny >= 0 && ny < n && !visit[nx][ny] && arr[nx][ny] == '.') {
				visit[nx][ny] = true;
				q.push({ dst + 1,{nx,ny} });
			}
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int ans = 2e9 + 1;

	if (arr[0][0] == '.') ans = min(ans, dfs(0));
	memset(visit, false, sizeof(visit));
	if (arr[1][0] == '.') ans = min(ans, dfs(1));

	int w = 2 * n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++) if (arr[i][j] == '#') w--;

	w -= ans;
	cout << w;
	return 0;
}