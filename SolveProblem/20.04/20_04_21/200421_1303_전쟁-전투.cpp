#include<iostream>
using namespace std;

char w[101][101];
bool v[101][101];
int n, m, cnt;
int wh, bl;

int n_x[4] = { 0, 1, 0, -1 };
int n_y[4] = { 1, 0, -1, 0 };

int dfs(int i, int j)
{
	int c = 1;
	v[i][j] = true;
	

	for (int k = 0; k < 4; k++) {
		int nx = i + n_x[k];
		int ny = j + n_y[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny] && w[i][j] == w[nx][ny])
			c += dfs(nx, ny);
	}
	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> w[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v[i][j] == false) {
				cnt = dfs(i, j);
				if (w[i][j] == 'W') wh += cnt*cnt;
				else bl += cnt*cnt;
			}

	cout << wh << ' ' << bl;
	return 0;
}