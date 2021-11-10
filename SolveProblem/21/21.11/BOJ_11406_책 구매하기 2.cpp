#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int src = 200, sink = 201, bias = 100;
int n, m, ans;
int capacity[202][202], flow[202][202];
vector<int> adj[202];

void solve() {
	while (1) {
		queue<int> q;
		q.push(src);

		int p[202];
		fill(p, p + 202, -1);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int next : adj[cur]) {
				if (capacity[cur][next] - flow[cur][next] > 0 && p[next] == -1) {
					q.push(next);
					p[next] = cur;
					if (next == sink) break;
				}
			}
		}

		if (p[sink] == -1) break;

		int minFlow = 2e9 + 1;
		for (int i = sink; i != src; i = p[i])
			minFlow = min(minFlow, capacity[p[i]][i] - flow[p[i]][i]);

		for (int i = sink; i != src; i = p[i]) {
			flow[p[i]][i] += minFlow;
			flow[i][p[i]] -= minFlow;
		}

		ans += minFlow;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> capacity[src][i];
		adj[src].push_back(i);
		adj[i].push_back(src);
	}

	for (int i = 0; i < m; i++) {
		cin >> capacity[bias + i][sink];
		adj[bias + i].push_back(sink);
		adj[sink].push_back(bias + i);
	}

	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++) {
			cin >> capacity[i][bias + j];
			adj[bias + j].push_back(i);
			adj[i].push_back(bias + j);
		}

	solve();

	cout << ans;
	return 0;
}