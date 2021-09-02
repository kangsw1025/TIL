#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m;
int aMatch[201], bMatch[201];
vector<int> vec[201];
bool visit[201];

bool dfs(int a) {
	if (visit[a]) return false;
	visit[a] = true;

	for (int i = 0; i < vec[a].size(); i++) {
		int b = vec[a][i];

		if (bMatch[b] == -1 || dfs(bMatch[b])) {
			bMatch[b] = a;
			aMatch[a] = b;
			return true;
		}
	}

	return false;
}

int solve() {
	memset(aMatch, -1, sizeof(aMatch));
	memset(bMatch, -1, sizeof(bMatch));

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (aMatch[i] == -1) {
			memset(visit, false, sizeof(visit));
			if (dfs(i)) cnt++;
		}
	}

	return n + m - cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> n >> m >> k;
	while (k--) {
		int u, v; cin >> u >> v;
		vec[u - 1].push_back(v - 1);
	}

	cout << solve();
	return 0;
}