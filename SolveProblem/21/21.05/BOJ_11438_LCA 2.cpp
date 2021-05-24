#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 100000 + 1;
vector<int> node[MAX];
int N, M;
int parent[MAX][21], depth[MAX];

void makeGraph() {
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));

	queue<int> q;
	q.push(1);
	depth[1] = 0;

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int next : node[n]) {
			if (depth[next] == -1) {
				parent[next][0] = n;
				depth[next] = depth[n] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	makeGraph();

	for (int j = 0; j < 18; j++)
		for (int i = 1; i <= N; i++) {
			int k = parent[i][j];
			if (k != -1) parent[i][j + 1] = parent[k][j];
		}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];
		
		int j = 0;
		while (diff) {
			if (diff % 2) u = parent[u][j];
			j++;
			diff /= 2;
		}

		if (u != v) {
			for (int j = 17; j >= 0; j--) {
				if (parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}

		cout << u << "\n";
	}
	return 0;
}