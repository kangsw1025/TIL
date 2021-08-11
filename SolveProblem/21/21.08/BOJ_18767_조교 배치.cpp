#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

bool adj[10001][4], visited[10001];
vector<int> v[4];
queue<int> q[4];
int n, room[4], aMatch[10001], bMatch[4];

bool dfs(int a) {

	if (visited[a]) return false;

	visited[a] = true;

	for (int b = 1; b <= 3; b++) {

		if (adj[a][b]) {
			if (bMatch[b]<room[b]) {
				aMatch[a] = b;
				bMatch[b]++;
				q[b].push(a);
				return true;
			}
			else {
				while(!q[b].empty()) {
					int k = q[b].front();
					q[b].pop();

					if (dfs(k)) {
						aMatch[a] = b;
						q[b].push(a);
						return true;
					}
				}
			}
		}
	}
	return false;
}

int bipartiteMatch() {
	memset(aMatch, 0, sizeof(aMatch));
	memset(bMatch, 0, sizeof(bMatch));

	for (int i = 1; i <= 3; i++)
		while (!q[i].empty()) q[i].pop();

	int rst = 0;

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));

		if (dfs(i)) rst++;
	}

	return rst;
}

char change(int r) {
	if (r == 1) return 'A';
	else if (r == 2) return 'B';
	return 'C';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(adj, false, sizeof(adj));

		cin >> n;

		for (int i = 1; i <= 3; i++)
			cin >> room[i];

		for (int i = 1; i <= 3; i++) {
			int t;
			cin >> t;
			for (int j = 0; j < t; j++) {
				int p;
				cin >> p;
				adj[p][i] = 1;
			}
		}

		cout << bipartiteMatch() << "\n";

		for (int i = 1; i <= n; i++)
			if (aMatch[i] != 0) cout << i<<' '<< change(aMatch[i]) << "\n";
	}

	return 0;
}