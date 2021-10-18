#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), cmp);
	int time = v[0].second-v[0].first;

	for (int i = 1; i < n; i++) {
		int d = v[i].first, t = v[i].second;
		if (time >= t) time = t - d;
		else time = time - d;
	}
	cout << time;
	return 0;
}