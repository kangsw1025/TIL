#include<iostream>
using namespace std;

char arr[101][101];
bool check[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, ans = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> arr[i][j];

	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++) {
			if (!check[i][j] && arr[i][j] == '#') {
				check[i][j] = true;
				ans++;

				if (j < c - 1) if (arr[i][j + 1] == '#') check[i][j + 1] = true;
				if (i < r - 1) if (arr[i + 1][j] == '#') check[i + 1][j] = true;
			}
		}
	cout << ans;
	return 0;
}