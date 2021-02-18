#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, ans = -1;
	vector<pair<int, int>> vec;
	cin >> T;
	for (int i = 0; i < T;i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < T; i++) {
		if (ans <= vec[i].second) ans = vec[i].second;
		else ans = vec[i].first;
	}
	cout << ans;
	return 0;
}