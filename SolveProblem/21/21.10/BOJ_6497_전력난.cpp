#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int p[200001];

int parent(int n) {
	if (p[n] == n) return n;
	return parent(p[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		memset(p, -1, sizeof(p));
		vector<pair<int, pair<int, int>>> vp;
		int ans = 0;

		for (int i = 0; i < n; i++) p[i] = i;

		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			vp.push_back({ p,{u,v} });
			ans += p;
		}

		sort(vp.begin(), vp.end());

		for (int i = 0; i < m; i++) {
			int dst = vp[i].first;
			int u = vp[i].second.first;
			int v = vp[i].second.second;

			int up = parent(u);
			int vp = parent(v);

			if (up == vp) continue;

			p[vp] = up;
			ans-= dst;
		}

		cout << ans << "\n";
	}
	return 0;
}