#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

vector<pair<int, int>> pv[100001];
bool visit[100001];

void solve(int c) {
	memset(visit, false, sizeof(visit));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,c });

	int cnt = 0, ans = 0;

	while (!q.empty()) {
		int time = q.top().first;
		int now = q.top().second;
		q.pop();

		if (visit[now]) continue;
		ans = max(time, ans);
		cnt++;
		visit[now] = true;

		for (int i = 0; i < pv[now].size(); i++) {
			int next = pv[now][i].first;
			int delay = pv[now][i].second;

			if (!visit[next]) {
				q.push({ time+delay,next });
			}
		}
	}

	cout << cnt << ' ' << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, d, c;
		cin >> n >> d >> c;

		for (int i = 1; i <= n; i++) pv[i].clear();

		for (int i = 0; i < d; i++) {
			int u, v, t;
			cin >> u >> v >> t;
			pv[v].push_back({ u,t });
		}

		solve(c);
	}
	return 0;
}