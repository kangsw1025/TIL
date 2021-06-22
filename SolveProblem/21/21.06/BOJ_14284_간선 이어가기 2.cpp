#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF = 2e9 + 1;
int n, m, st, ed, ans;
int dst[5001], parent[5001], dst_p[5001];
vector<pair<int, int>> vec[5001];

void solve(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> q;
	memset(dst, INF, sizeof(dst));
	q.push({ 0,start });
	dst[start] = 0;
	while (!q.empty()) {
		int now = q.top().second;
		q.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].first;
			int val = vec[now][i].second;

			if (dst[next] > dst[now] + val) {
				dst[next] = dst[now] + val;
				parent[next] = now;
				dst_p[next] = val;
				q.push({ dst[next],next });
			}
		}
	}
	int now = end;
	while (now != start) {
		ans += dst_p[now];
		now = parent[now];
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, r;
		cin >> u >> v >> r;

		vec[u].push_back({ v,r });
		vec[v].push_back({ u,r });
	}
	cin >> st >> ed;
	solve(st, ed);
	return 0;
}