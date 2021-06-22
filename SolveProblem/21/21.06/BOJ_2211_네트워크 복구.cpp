#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 2e9
int n, m;
int dst[1001], parent[1001];
vector<pair<int,int>> vec[1001];
set<string> st;

void solve() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	fill(dst, dst + n + 1, INF);
	dst[1] = 0;
	parent[1] = 0;

	q.push({ 0,1 });

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();
	
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].first;
			int val = vec[now][i].second;
			if (dst[next] > dst[now] + val) {
				dst[next] = dst[now] + val;
				q.push({ dst[next],next });
				parent[next] = now;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		int now = i;
		while (parent[now] != 0) {
			string tmp = to_string(now) + " " + to_string(parent[now]);
			st.insert(tmp);
			now = parent[now];
		}
	}
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

	solve();
	cout << st.size() << "\n";
	for (auto itr = st.begin(); itr != st.end(); itr++)
		cout << *itr << "\n";
	return 0;
}