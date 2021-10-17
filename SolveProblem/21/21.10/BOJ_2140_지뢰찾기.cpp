#include<iostream>
#include<vector>
using namespace std;

int n;
int n_x[8] = { -1,-1,-1,0,0,1,1,1 };
int n_y[8] = { -1,0,1,-1,1,-1,0,1 };
char arr[101][101];

bool solve(int x, int y) {
	bool rst = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + n_x[i];
		int ny = y + n_y[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (arr[nx][ny] == '0') {
				rst = false;
				break;
			}
		}
	}

	if (rst) {
		for (int i = 0; i < 8; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (arr[nx][ny] != '#') {
					arr[nx][ny]--;
				}
			}
		}

		return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == '#') ans += solve(i, j);

	cout << ans;
	return 0;
}