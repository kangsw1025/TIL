#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF = 2e9 + 1;
vector<pair<int, int>> vec[1001];
long long dst[1001], parent[1001];

void show(int now, int cnt) {
	if (parent[now] == 0) cout << cnt << "\n";
	else show(parent[now], cnt + 1);
	cout << now << ' ';
}

void solve(int st, int ed) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

	for (int i = 0; i < vec[st].size(); i++)
		q.push({ vec[st][i].second, {st,vec[st][i].first} });
	dst[st] = 0;

	while (!q.empty()) {
		int pay = q.top().first;
		int s = q.top().second.first;
		int e = q.top().second.second;
		q.pop();


		if (dst[e] > dst[s] + pay) {

			dst[e] = dst[s] + pay;
			parent[e] = s;
			for (int i = 0; i < vec[e].size(); i++)
				q.push({ vec[e][i].second, {e,vec[e][i].first} });
		}
	}

	cout << dst[ed] << "\n";
	show(ed, 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		vec[u].push_back({ v,p });
	}

	int st, ed;
	cin >> st >> ed;

	memset(dst, INF, sizeof(dst));

	solve(st, ed);
	return 0;
}