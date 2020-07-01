#include<iostream>
using namespace std;

int arr[51][51];
int v[51][51];
int x, y, cnt;
int n_x[8] = { 0, 1, 0, -1 , -1, -1, 1, 1 };
int n_y[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

void reset(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) v[i][j] = false;
	cnt = 0;
}

void go(int h, int w)
{
	v[h][w] = true;
	for (int i = 0; i < 8; i++) {
		int ny = h + n_y[i];
		int nx = w + n_x[i];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && v[ny][nx] == false && arr[ny][nx] == 1)
			go(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++) cin >> arr[i][j];
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				if (v[i][j] == false && arr[i][j] == 1) {
					go(i, j);
					cnt++;
				}
		cout << cnt << "\n";
		reset(y, x);
	}
}