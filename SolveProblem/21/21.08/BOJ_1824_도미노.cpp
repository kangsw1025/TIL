#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, l;
int match[10001];
bool arr[10001][10001], use[10001], visit[10001];
vector<int> vec[10001];

bool dfs(int a) {
	if (visit[a]) return false;

	visit[a] = true;

	for (int i = 0; i < vec[a].size(); i++) {
		int next = vec[a][i];

		if (!match[next] || dfs(match[next])) {
			match[a] = next;
			match[next] = a;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> l;

	memset(arr, true, sizeof(arr));

	while (l--) {
		int u, v;
		cin >> u >> v;
		arr[u][v] = false;
		arr[v][u] = false;
	}

	for (int i = 1; i <= m * n; i++) {
		if (i - m > 0)
			if (arr[i][i - m])
				vec[i].push_back(i - m);

		if (i % m != 1)
			if (arr[i][i - 1]) vec[i].push_back(i - 1);
		if (i % m != 0)
			if (arr[i][i + 1]) vec[i].push_back(i + 1);
		if (i + m <= n * m)
			if (arr[i][i + m]) vec[i].push_back(i + m);
	}

	for (int i = 1; i <= n * m; i++) {
		if (!match[i]) {
			memset(visit, false, sizeof(visit));
			dfs(i);
		}
	}

	for (int i = 1; i <= n * m; i++) {
		if (!use[i]) {
			cout << i << ' ' << match[i] << "\n";
			use[i] = true;
			use[match[i]] = true;
		}
	}
	return 0;
}