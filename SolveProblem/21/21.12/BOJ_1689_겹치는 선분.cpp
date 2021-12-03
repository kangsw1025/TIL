#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,1 });
		v.push_back({ b,0 });
	}

	sort(v.begin(), v.end());

	int cnt = 0, ans = 0;

	for (auto itr : v) {
		if (itr.second) cnt++;
		else cnt--;

		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}