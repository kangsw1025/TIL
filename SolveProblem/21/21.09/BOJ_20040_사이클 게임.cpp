#include<iostream>
using namespace std;

int par[500001];

int pa(int n) {
	if (par[n] == n) return n;
	return pa(par[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans = 0;;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) par[i] = i;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		if (ans == 0) {

			int up = pa(u);
			int vp = pa(v);

			if (up == vp) ans = i;
			else par[vp] = up;
		}
	}

	cout << ans;
	return 0;
}