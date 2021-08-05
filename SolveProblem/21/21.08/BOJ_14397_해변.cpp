#include<iostream>
using namespace std;

char arr[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				if (j > 0)
					if (arr[i][j - 1] == '.') ans++;

				if (j < m - 1)
					if (arr[i][j + 1] == '.') ans++;

				if (i % 2 == 0) {
					if (i > 0) {
						if (j > 0) {
							if (arr[i - 1][j - 1] == '.') ans++;
						}
						
						if (arr[i - 1][j] == '.') ans++;
					}
					if (i < n - 1) {
						if (j > 0) {
							if (arr[i + 1][j - 1] == '.') ans++;
						}

						if (arr[i + 1][j] == '.') ans++;
						
					}
				}
				else {

					if (arr[i - 1][j] == '.') ans++;

					if (j < m - 1)
						if (arr[i - 1][j + 1] == '.') ans++;

					if (i < n - 1) {
						if (arr[i + 1][j] == '.') ans++;

						if (j < m - 1) {
							if (arr[i + 1][j + 1] == '.') ans++;
						}
					}
				}
			}
		}
	
	cout << ans;
	return 0;
}