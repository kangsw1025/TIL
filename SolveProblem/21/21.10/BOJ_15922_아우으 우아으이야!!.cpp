#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v1, v2;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v1.push_back({ x,y });
	}

	sort(v1.begin(), v1.end());

	for (int i = 0; i < n; i++) {
		pair<int, int> p = v1[i];
		auto itr = lower_bound(v2.begin(), v2.end(), p, cmp);
		if (itr == v2.end()) v2.push_back(p);
		else itr->second = max(p.second, itr->second);
	}
	long long ans = 0;
	for (int i = 0; i < v2.size(); i++) {
		ans += v2[i].second - v2[i].first;
	}
	cout << ans;
	return 0;
}