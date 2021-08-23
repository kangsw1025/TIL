#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100001];
int n, m, ans;

int parent(int i) {
	if (arr[i] == i) return i;
	return parent(arr[i]);
}

void join(int u, int v) {
	int up = parent(u);
	int vp = parent(v);

	if (up > vp) arr[up] = vp;
	else arr[vp] = up;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;


	for (int i = 1; i <= n; i++) arr[i] = i;

	for (int i = 0; i < m; i++) {
		int u, v, p;
		cin >> u >> v >> p;
		q.push({ p,{u,v} });
	}

	while (!q.empty()) {
		if (n == 2) break;

		int pay = q.top().first;
		int u = q.top().second.first;
		int v = q.top().second.second;
		q.pop();

		if (parent(u) != parent(v)) {
			join(u, v);
			ans += pay;
			n--;
		}
	}

	cout << ans;
	return 0;
}