#include<iostream>
using namespace std;

int n, m;
bool cmp[501][501];

void floyd() {

	for(int k = 1;k<=n;k++) 
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++) {
				if (i == k || k == j) continue;
				else if (i == j) cmp[i][j] = true;
				else if (cmp[i][k] && cmp[k][j]) cmp[i][j] = true;
			}

}

void solve() {
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		bool com = true;
		for (int j = 1; j <= n; j++) {
			if (!(cmp[i][j] || cmp[j][i])) {
				com = false;
				break;
			}
		}
		if (com) ans++;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cmp[a][b] = true;
	}

	floyd();
	solve();
	return 0;
}