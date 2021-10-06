#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v[100001];
bool visit[100001];
int ed, ans;

void dfs(int node, int dst) {
	visit[node] = true;

	if (dst > ans) {
		ans = dst;
		ed = node;
	}

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i].first;
		int val = v[node][i].second;

		if (!visit[next]) dfs(next, dst + val);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int f,s,dst;
		cin >> f;
		
		while (1) {
			cin >> s;
			if (s == -1) break;
			cin >> dst;
			v[f].push_back({ s,dst });
			v[s].push_back({ f,dst });
		}
	}

	dfs(1, 0);
	ans = 0;
	memset(visit, 0, sizeof(visit));
	dfs(ed, 0);

	cout << ans;

	return 0;
}

