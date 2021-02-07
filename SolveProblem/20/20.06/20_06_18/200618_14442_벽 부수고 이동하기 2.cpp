#include<iostream>
#include<queue>
using namespace std;

char wall[1001][1001];
int arr[1001][1001][11];
int x, y, n;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int solve() {
	arr[1][1][0] = 1;
	queue<pair<int,pair<int, int>>> q;
	q.push(make_pair(0,make_pair(1, 1)));

	while (!q.empty()) {
		int w = q.front().second.first;
		int h = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		if (w == x && h == y) return arr[w][h][cnt];

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx > 0 && nx <= x && ny > 0 && ny <= y) {
				if (wall[nx][ny] == '1' && cnt<n) {
					if (!arr[nx][ny][cnt+1]) {
						arr[nx][ny][cnt + 1] = arr[w][h][cnt] + 1;
						q.push(make_pair(cnt + 1, make_pair(nx, ny)));
					}
				}
				else if (wall[nx][ny] == '0') {
					if (!arr[nx][ny][cnt]) {
						arr[nx][ny][cnt] = arr[w][h][cnt] + 1;
						q.push(make_pair(cnt, make_pair(nx, ny)));
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> n;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) cin >> wall[i][j];

	cout<<solve();
	return 0;
}