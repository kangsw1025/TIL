#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

bool can(int val, int k) {
	int cnt = k + 1;
	auto itr = v.begin();
	while (cnt) {
		itr = lower_bound(v.begin(), v.end(), *itr+val);
		cnt--;
		if (itr == v.end()) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, l;
	cin >> n >> m >> l;

	v.push_back(0);
	for (int i = 0; i < m; i++) {
		int op;
		cin >> op;
		v.push_back(op);
	}
	v.push_back(l);

	while (n--) {
		int k;
		cin >> k;

		int left = 0, right = l, ans = 0;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (can(mid, k)) {
				left = mid + 1;
				ans = max(ans, mid);
			}
			else right = mid - 1;
		}

		cout << ans<< "\n";
	}
	return 0;
}