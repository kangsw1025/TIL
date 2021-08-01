#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<pair<int, int>> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, et;
		cin >> st >> et;
		vec.push_back({ st,et });
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int st = vec[i].first;
		int et = vec[i].second;
		
		if (st > ans) ans = st + et;
		else ans += et;
	}

	cout << ans;
	return 0;
}