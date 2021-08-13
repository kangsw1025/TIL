#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, st, dt;
vector<pair<int,int>> v[100001];
bool check[100001];

void solve() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{0,st} });
	check[st] = true;

	while (!q.empty()) {
		int sum = q.front().first;
		int mx = q.front().second.first;
		int now = q.front().second.second;
		q.pop();

		if (now == dt) {
			cout << sum - mx;
			return;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int pay = v[now][i].second;

			if (!check[next]) {
				check[next] = true;
				q.push({ sum + pay,{max(mx,pay),next} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> st >> dt;
	for (int i = 1; i < n; i++) {
		int f, t, p;
		cin >> f >> t >> p;
		v[f].push_back({ t,p });
		v[t].push_back({ f,p });
	}

	solve();
	return 0;
}