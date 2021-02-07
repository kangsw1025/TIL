#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 53
#define INF 2e9

int n, c[MAX][MAX], f[MAX][MAX];
vector<int> adj[MAX];

int solve() {
	int rst = 0;
	int S = 0, T = 'Z' - 'A';

	while (1) {
		int prev[MAX];
		memset(prev, -1, sizeof(prev));

		queue<int> q;
		q.push(S);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];

				if (prev[next] != -1) continue;

				if (c[cur][next] - f[cur][next] > 0) {
					q.push(next);
					prev[next] = cur;

					if (next == T) break;
				}
			}
		}
		if (prev[T] == -1) break;

		int flow = INF;

		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

		rst += flow;
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char s, e;
		int val;
		cin >> s >> e >> val;

		int from, to;
		
		if ('A' <= s && s <= 'Z') from = s - 'A';
		else from = s - 'a' + 26;

		if ('A' <= e && e <= 'Z') to = e - 'A';
		else to = e - 'a' + 26;

		c[from][to] += val;
		c[to][from] += val;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	int ans = 0;

	ans = solve();

	cout << ans;
	return 0;
}