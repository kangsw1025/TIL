#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 2e9 + 1;
vector<pair<int, int>> v[1001];
int dst[1001][1001];
int n, m;

void bfs(int st) {
	queue<pair<int, int>> q;
	dst[st][st] = 0;

	q.push({ 0,st });

	while (!q.empty()) {
		int sum = q.front().first;
		int now = q.front().second;
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int pay = v[now][i].second;

			if (dst[st][next] > sum + pay) {
				dst[st][next] = sum + pay;
				q.push({ sum + pay,next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int f, t, p;
		cin >> f >> t >> p;
		v[f].push_back({ t,p });
		v[t].push_back({ f,p });
	}
	memset(dst, INF, sizeof(dst));
	for (int i = 1; i <= n; i++)
		bfs(i);

	for (int i = 0; i < m; i++) {
		int f, t;
		cin >> f >> t;
		cout << dst[f][t] << "\n";
	}
	return 0;
}