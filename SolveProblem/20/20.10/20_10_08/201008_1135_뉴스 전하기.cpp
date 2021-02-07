#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> vec[51];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int solve(int now) {
	int rst = 0;

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i].second;
		vec[now][i].first = 1 + solve(next);
	}

	sort(vec[now].begin(), vec[now].end(), cmp);

	for (int i = 0; i < vec[now].size(); i++) {
		vec[now][i].first += i;
		rst = max(rst, vec[now][i].first);
	}

	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		if (val == -1) continue;

		vec[val].push_back({ 0,i });
	}
	cout << solve(0);
	return 0;
}