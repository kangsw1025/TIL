#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v1, v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h, ans = 2e9, range;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i % 2 == 0) v1.push_back(x);
		else v2.push_back(x);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 1; i <= h; i++) {
		int x = v1.size() - (lower_bound(v1.begin(), v1.end(), i) - v1.begin());
		int y = v2.size() - (lower_bound(v2.begin(), v2.end(), h-i+1) - v2.begin());

		if (x + y < ans) {
			ans = x + y;
			range = 1;
		}
		else if (ans == x + y) range++;
	}
	cout << ans << ' ' << range;
	return 0;
}