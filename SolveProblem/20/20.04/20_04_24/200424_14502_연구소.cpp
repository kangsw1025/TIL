#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

int x, y, cnt;
int arr[9][9];
int r[9][9];
int n_x[4] = { 0,-1,0,1 };
int n_y[4] = { -1,0,1,0 };

void bfs()
{
	int temp[9][9];
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			temp[i][j] = r[i][j];
	queue<pair<int, int>> q;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (temp[i][j] == 2) q.push(make_pair(i, j));

	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = h + n_x[i];
			int ny = w + n_y[i];

			if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
				if (temp[nx][ny] == 0) {
					temp[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int c = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (temp[i][j] == 0) c++;
	cnt = max(c, cnt);
}

void makewall(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (r[i][j] == 0)
			{
				r[i][j] = 1;
				makewall(cnt + 1);
				r[i][j] = 0;
			}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (arr[i][j] == 0) {
				for (int k = 0; k < x; k++)
					for (int m = 0; m < y; m++)
						r[k][m] = arr[k][m];

				r[i][j] = 1;
				makewall(1);
				r[i][j] = 0;
			}

	cout << cnt;
	return 0;
}