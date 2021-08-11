#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
int aMatch[201], bMatch[201];
bool visited[201], adj[201][201];

bool dfs(int a) {

	if (visited[a]) return false;

	visited[a] = true;

	for (int b = 2; b <= n; b += 2) {
		if (adj[a][b]) {
			if (!bMatch[b] || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch() {

	int rst = 0;

	for (int i = 1; i <= n; i += 2) {
		memset(visited, false, sizeof(visited));

		if (dfs(i)) rst+=2;
	}

	if (rst < n) rst++;
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v][u] = adj[u][v] = 1;
	}

	cout << bipartiteMatch();
	return 0;
}
