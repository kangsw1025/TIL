#include<iostream>
#include<algorithm>
using namespace std;

int arr[501][501];
bool v[501][501];
int x, y;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int solve(int w, int h)
{
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && v[nx][ny] == false && arr[nx][ny] == 1) {
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

	cin >> x >> y;
	int n;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];
	int cn = 0, ans = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (v[i][j] == false && arr[i][j] == 1) {
				v[i][j] = true;
				cn++;
				ans = max(ans, solve(i, j));
			}
		}
	}
	cout << cn << "\n" << ans;
	return 0;
}