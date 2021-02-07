#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[20001];
int v, e, st, INF=987564321;
vector<pair<int, int>> vec[20001];

vector<int> dp()
{
	vector<int> re(v+1, INF);
	re[st] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, st));

	while (!q.empty()) {
		int pay = -q.top().first;
		int dt = q.top().second;
		q.pop();

		if (pay > re[dt]) continue;

		for (int i = 0; i < vec[dt].size(); i++) {
			int bc = vec[dt][i].first;
			int bcp = pay + vec[dt][i].second;

			if (re[bc] > bcp) {
				re[bc] = bcp;
				q.push(make_pair(-bcp, bc));
			}
		}
	}
	return re;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e >> st;
	arr[st] = 0;
	int s, d, p;
	for (int i = 0; i < e; i++) {
		cin >> s >> d >> p;
		vec[s].push_back(make_pair(d, p));
	}
	arr[st] = 0;
	vector<int> ans = dp();
	for (int i = 1; i <= v; i++) {
		if (ans[i] == INF) cout << "INF\n";
		else cout << ans[i] << "\n";
	}
	return 0;
}