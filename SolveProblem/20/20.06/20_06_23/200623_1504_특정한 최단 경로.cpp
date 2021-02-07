#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 999999
int n, sec, thr;
vector<pair<int, int>> vec[801];
int arr[801][801];

void reset(int j) {
	for (int i = 1; i <= n; i++) arr[j][i] = INF;
}

void solve(int s) {
	arr[s][s] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	for (int i = 0; i < vec[s].size(); i++) {
		int p = vec[s][i].first;
		int d = vec[s][i].second;
		q.push(make_pair(p, make_pair(s, d)));
	}

	while (!q.empty()) {
		int p = q.top().first;
		int fi = q.top().second.first;
		int se = q.top().second.second;
		q.pop();

		if (arr[s][se] > arr[s][fi] + p) {
			arr[s][se] = arr[s][fi] + p;

			for (int i = 0; i < vec[se].size(); i++) {
				int pr = vec[se][i].first;
				int d = vec[se][i].second;
				q.push(make_pair(pr, make_pair(se, d)));
			}
		}
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int e, s, d, p;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		cin >> s >> d >> p;
		vec[s].push_back(make_pair(p, d));
		vec[d].push_back(make_pair(p, s));
	}
	cin >> sec >> thr;

	reset(1);
	reset(sec);
	reset(thr);
	solve(1);
	solve(sec);
	solve(thr);

	if (arr[1][sec] + arr[sec][thr] + arr[thr][n] > arr[1][thr] + arr[thr][sec] + arr[sec][n]) {
		if (arr[1][thr] == INF || arr[thr][sec] == INF || arr[sec][n] == INF) cout << -1;
		else cout << arr[1][thr] + arr[thr][sec] + arr[sec][n];
	}
	else {
		if (arr[1][sec] == INF || arr[sec][thr] == INF || arr[thr][n] == INF) cout << -1;
		else cout << arr[1][sec] + arr[sec][thr] + arr[thr][n];
	}
	return 0;
}