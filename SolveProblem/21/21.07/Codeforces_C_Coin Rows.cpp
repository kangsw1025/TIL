#include<iostream>
using namespace std;

int arr[3][100001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int m;
		cin >> m;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= m; j++) {
				int n;
				cin >> n;
				arr[i][j] = arr[i][j - 1] + n;
			}
		int ans = 2e9;
		for (int i = 1; i <= m; i++) 
			ans = min(ans, max(arr[1][m] - arr[1][i], arr[2][i - 1]));
		cout << ans << "\n";
	}
	return 0;
}