#include<iostream>
#include<cstring>
using namespace std;

int arr[501][501];
int ch[501][501];
int n;

int solve(int x, int y) {

	int &day = ch[x][y];
	if (day != -1) return day;
	day = 1;
	int tmp;

	if (x - 1 >= 0 && arr[x][y] < arr[x - 1][y]) {
		tmp = 1 + solve(x - 1, y);
		if (tmp > day) day = tmp;
	}
	if (y - 1 >= 0 && arr[x][y] < arr[x][y-1]) {
		tmp = 1 + solve(x , y-1);
		if (tmp > day) day = tmp;
	}
	if (x + 1 < n && arr[x][y] < arr[x + 1][y]) {
		tmp = 1 + solve(x + 1, y);
		if (tmp > day) day = tmp;
	}
	if (y + 1 < n && arr[x][y] < arr[x][y + 1]) {
		tmp = 1 + solve(x, y + 1);
		if (tmp > day) day = tmp;
	}
	return day;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	int ans = 0;
	memset(ch, -1, sizeof(ch));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			int tmp = solve(i, j);
			if (tmp > ans) ans = tmp;
		}
	}
	cout << ans;
	return 0;
}