#include<iostream>
using namespace std;

char arr[101][101];
bool check[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				check[i][j] = true;
				ans++;
				if (arr[i][j] == '-') {
					for (int k = j + 1; k < m; k++) {
						if (arr[i][k] == '-') check[i][k] = true;
						else break;
					}

				}
				else {
					for (int k = i + 1; k < n; k++) {
						if (arr[k][j] == '|') check[k][j] = true;
						else break;
					}
				}
			}
		}
	cout << ans;
	return 0;
}