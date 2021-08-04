#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

vector<int> vec[20001];
int dis[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];

			if (dis[next] == -1) {
				dis[next] = dis[now] + 1;
				q.push(next);
			}
		}
	}

	int num = 1, dst = 0, same = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] > dst) {
			num = i;
			dst = dis[i];
			same = 1;
		}
		else if (dis[i] == dst) {
			same++;
		}
	}
	cout << num << ' ' << dst << ' ' << same;
	return 0;
}