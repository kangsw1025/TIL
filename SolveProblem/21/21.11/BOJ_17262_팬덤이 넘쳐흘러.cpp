#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ e,s });
	}

	sort(v.begin(), v.end());

	int s = v[0].first, e = v[0].second;
	for (int i = 1; i < n; i++) {
		e = max(e, v[i].second);
	}

	cout << max(0, e - s);
	return 0;
}