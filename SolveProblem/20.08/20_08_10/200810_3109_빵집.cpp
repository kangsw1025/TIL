#include<iostream>
using namespace std;

int r, c, ans;
char arr[10001][501];
bool check[10001][501];

int n_x[3] = { -1,0,1 };
int n_y[3] = { 1,1,1 };

bool solve(int i, int j) {
	check[i][j] = true;

	if (j == c - 1) {
		ans++;
		return true;
	}

	for (int k = 0; k < 3; k++) {
		int nx = i + n_x[k];
		int ny = j + n_y[k];

		if (arr[nx][ny] == '.' && !check[nx][ny] && nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (solve(nx, ny)) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> arr[i][j];

	for (int i = 0; i < r; i++)
		if (arr[i][0] == '.') solve(i, 0);

	cout << ans;
	return 0;
}