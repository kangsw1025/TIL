#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int parent[10001][16];
int depth[10001];
vector<int> child[10001];

void LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	int j = 0;
	while (diff) {
		if (diff % 2) u = parent[u][j];
		j++;
		diff /= 2;
	}

	if (u != v) {
		for(int j = 14;j>=0;j--)
			if (parent[u][j] != parent[v][j]) {
				u = parent[u][j];
				v = parent[v][j];
			}
		u = parent[u][0];
	}
	cout << u << "\n";
}

void make_tree(int n) {
	int root = n;
	while (1) {
		if (parent[root][0] == -1) break;
		root = parent[root][0];
	}
	
	depth[root] = 0;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : child[now]) {
			if (depth[next] == -1) {
				depth[next] = depth[now] + 1;
				q.push(next);
			}
		}
	}

	for(int j = 0;j<15;j++)
		for (int i = 1; i <= n; i++) {
			int k = parent[i][j];
			if (k != -1) parent[i][j + 1] = parent[k][j];
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(depth, -1, sizeof(depth));
		memset(parent, -1, sizeof(parent));
		
		int n, u, v;
		cin >> n;

		for (int i = 1; i <= n; i++) child[i].clear();

		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			parent[v][0] = u;
			child[u].push_back(v);
		}

		make_tree(n);
		cin >> u >> v;
		LCA(u, v);
	}
	return 0;
}