#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int MAX = 10001;

int n,rst,far;
bool check[MAX];
vector<pair<int, int>> vec[MAX];

void solve(int node, int cost) {
	if (check[node]) return;

	check[node] = true;

	if (rst < cost) {
		rst = cost;
		far = node;
	}

	for (int i = 0; i < vec[node].size(); i++)
		solve(vec[node][i].first, cost + vec[node][i].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int f, t, v;
		cin >> f >> t >> v;
		vec[f].push_back({ t, v});
		vec[t].push_back({ f, v});
	}

	memset(check, false, sizeof(check));
	solve(1, 0);
	memset(check, false, sizeof(check));
	rst = 0;
	solve(far, 0);
	cout << rst;
	return 0;
}