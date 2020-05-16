#include<iostream>
#include<algorithm>
using namespace std;

int arr[101][101];
bool v[101][101];
int x, y, c;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int solve(int w, int h)
{
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 1 && nx <= x && ny >= 1 && ny <= y && v[nx][ny] == false && arr[nx][ny] == 1) {
			v[nx][ny] = true;
			cnt += solve(nx, ny);
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> c;
	int a, b;
	for (int i = 0; i < c; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (v[i][j] == false && arr[i][j] == 1) {
				v[i][j] = true;
				ans = max(ans, solve(i, j));
			}
		}
	}
	cout << ans;
	return 0;
}