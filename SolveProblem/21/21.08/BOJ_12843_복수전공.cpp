#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m;
int match[2001];
bool visit[2001];
vector<int> v[2001];

bool dfs(int a) {
	if (visit[a]) return false;
	visit[a] = true;

	for (int i = 0; i < v[a].size(); i++) {
		int b = v[a][i];

		if (!match[b] || dfs(match[b])) {
			match[a] = b;
			match[b] = a;
			return true;
		}
	}
	return false;
}

void solve() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));

		if (!match[i])
			if (dfs(i)) cnt++;
	}

	cout << n - cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int n;
		char c;
		cin >> n >> c;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	return 0;
}