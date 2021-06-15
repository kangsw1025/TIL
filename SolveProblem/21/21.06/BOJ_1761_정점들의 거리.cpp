#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 40000
vector<pair<int, int>> vec[MAX + 1];
int parent[MAX + 1][20], dist[MAX + 1], depth[MAX+1];
bool visit[MAX + 1];

void dfs(int v, int dth, int dst) {
	visit[v] = true;
	depth[v] = dth;
	dist[v] = dst;
	for (pair<int, int> p : vec[v]) {
		int next = p.first;
		int val = p.second;
		if (!visit[next]) {
			dfs(next, dth + 1, dst + val);
			parent[next][0] = v;
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	int j = 0;
	while (diff) {
		if (diff % 2) u = parent[u][j];
		j++;
		diff /= 2;
	}

	if (u != v) {
		for (int i = 19; i >= 0; i--) {
			if (parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, start;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		vec[u].push_back({ v,l });
		vec[v].push_back({ u,l });
	}

	dfs(1,0,0);

	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= N; i++) 
			parent[i][j] = parent [parent[i][j - 1]] [j - 1];
		

	cin >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cout << dist[u] + dist[v] - 2*dist[lca(u, v)]<<"\n";
	}

	return 0;

}