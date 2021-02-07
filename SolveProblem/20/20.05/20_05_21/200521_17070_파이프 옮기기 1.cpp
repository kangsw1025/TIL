#include<iostream>
#include<queue>
using namespace std;

int n;
int arr[17][17];
int n_x[4] = { 0,0,1,1 };
int n_y[4] = { 0,1,0,1 };

int solve(int n)
{
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(1, make_pair(1, 2)));
	int cnt = 0;
	while (!q.empty()) {
		int sh = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (n == x && n == y) {
			cnt++;
			continue;
		}
		if (sh == 3) {
			for (int i = 1; i <= 3; i++) {
				int nx = x + n_x[i];
				int ny = y + n_y[i];
				if (nx <= n && ny <= n && arr[nx][ny] == 0) {
					if (i == 3) {
						if (arr[nx - 1][ny] == 0 && arr[nx][ny - 1] == 0)q.push(make_pair(i, make_pair(nx, ny)));
					}
					else q.push(make_pair(i, make_pair(nx, ny)));
				}
			}
		}
		else if (sh == 2) {
			for (int i = 1; i <= 3; i++) {
				if (i == 1) continue;
				int nx = x + n_x[i];
				int ny = y + n_y[i];
				if (nx <= n && ny <= n && arr[nx][ny] == 0) {
					if (i == 3) {
						if (arr[nx - 1][ny] == 0 && arr[nx][ny - 1] == 0)q.push(make_pair(i, make_pair(nx, ny)));
					}
					else q.push(make_pair(i, make_pair(nx, ny)));
				}
			}
		}
		else if (sh == 1) {
			for (int i = 1; i <= 3; i++) {
				if (i == 2) continue;
				int nx = x + n_x[i];
				int ny = y + n_y[i];
				if (nx <= n && ny <= n && arr[nx][ny] == 0) {
					if (i == 3) {
						if (arr[nx - 1][ny] == 0 && arr[nx][ny - 1] == 0) q.push(make_pair(i, make_pair(nx, ny)));
					}
					else q.push(make_pair(i, make_pair(nx, ny)));
				}
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> arr[i][j];

	cout << solve(n);
	return 0;
}