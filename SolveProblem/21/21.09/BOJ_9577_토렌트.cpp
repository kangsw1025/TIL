#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n,m,b[101];
bool visit[101];

bool dfs(int a, vector<int> *vec) {
	if (visit[a]) return false;
	visit[a] = true;

	for (int i = 0; i < vec[a].size(); i++) {
		int next = vec[a][i];

		if (b[next] == -1 || dfs(b[next],vec)) {
			b[next] = a;
			return true;
		}
	}
	return false;
}

int solve(vector<int> *vec) {
	memset(b, -1, sizeof(b));

	int rst = 0;

	for (int i = 0; i < 100; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i,vec)) rst++;
		if (rst == n) return i + 1;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		vector<int> vec[101];
		for (int i = 0; i < m; i++) {
			int t1, t2, an;
			cin >> t1 >> t2 >> an;
			for (int j = 0; j < an; j++) {
				int op; cin >> op;
				for (int k = t1; k < t2; k++)
					vec[k].push_back(op);
			}
		}

		cout << solve(vec) << "\n";
	}
	return 0;
}