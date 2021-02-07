#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
#define INF 987654321
int arr[401][401];

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= n; k++) {
				if (k == i) continue;
				if (arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	solve();
	int ans = INF;
	for (int i = 1; i <= n; i++)
		ans = min(ans, arr[i][i]);
	if (ans < INF) cout << ans;
	else cout << -1;
	return 0;
}