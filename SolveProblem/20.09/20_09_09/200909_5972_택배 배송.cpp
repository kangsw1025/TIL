#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define INF 2e9
int n, m;
int arr[50001];
vector<pair<int, int>> vec[50001];

void solve() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].first;
			int pay = vec[now][i].second;
			if (arr[next] > arr[now] + pay) {
				arr[next] = arr[now] + pay;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 2; i <= n; i++) arr[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, p;
		cin >> a >> b >> p;
		vec[a].push_back(make_pair(b, p));
		vec[b].push_back(make_pair(a, p));
	}

	solve();
	cout << arr[n];
	return 0;
}