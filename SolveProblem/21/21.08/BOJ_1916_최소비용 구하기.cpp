#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 2e9 + 1;
vector<pair<int, int>> vec[1001];
int dst[1001];

void solve(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push({ 0,st });

	while (!q.empty()) {
		int cost = -q.top().first;
		int now = q.top().second;
		q.pop();

		if (dst[now] < cost) continue;

		for (int i = 0; i < vec[now].size(); i++) {
			int n = vec[now][i].first;
			int p = vec[now][i].second + cost;

			if (dst[n] > p) {
				dst[n] = p;
				q.push({ -p,n });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, st, dt;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		vec[u].push_back({ v,p });
	}

	for (int i = 1; i <= n; i++) dst[i] = INF;

	cin >> st >> dt;
	dst[st] = 0;

	solve(st);
	cout << dst[dt];

	return 0;
}