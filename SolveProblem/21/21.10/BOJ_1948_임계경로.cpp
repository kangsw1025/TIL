#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 1e4 + 1;

int n, m, st, dt, cnt;
int ind[MAX], dst[MAX];
bool visit[MAX];
vector<pair<int, int>> vc[10001], rvc[10001];

void dfs(int cur) {
	if (visit[cur]) return;
	visit[cur] = true;

	for (auto p : rvc[cur]) {
		int before = p.first;
		int time = p.second;

		if (dst[cur] == dst[before] + time) {
			dfs(before);
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		ind[v]++;
		vc[u].push_back({ v,p });
		rvc[v].push_back({ u,p });
	}

	cin >> st >> dt;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto p : vc[cur]) {
			int next = p.first;
			int time = p.second;

			if (dst[next] < dst[cur] + time) dst[next] = dst[cur] + time;

			if (--ind[next] == 0) q.push(next);
		}
	}

	dfs(dt);

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dst[i]);
	cout << ans << "\n" << cnt;
	return 0;
}