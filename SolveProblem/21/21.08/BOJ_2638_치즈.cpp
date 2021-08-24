#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m, ans;
int arr[101][101];
bool visit[101][101];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void bfs() {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]) {
				if (arr[nx][ny] >= 1) {
					arr[nx][ny] ++;
					continue;
				}
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}

bool melt() {
	bool check = false;

	for(int i=0;i<n;i++) 
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= 3) {
				arr[i][j] = 0;
				check = true;
			}
			else if (arr[i][j] == 2) arr[i][j] = 1;
		}

	return check;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	while (1) {
		bfs();
		if (melt()) ans++;
		else break;
	}

	cout << ans;
	return 0;
}