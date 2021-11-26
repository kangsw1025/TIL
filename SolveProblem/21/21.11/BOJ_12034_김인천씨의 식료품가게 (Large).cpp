#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		map<long long, int> mp;
		vector<long long> v;
		int n;
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			long long val;
			cin >> val;
			if (mp[val]) {
				mp[val]--;
				if (mp[val] == 0) mp.erase(val);
			}
			else {
				v.push_back(val);
				long long new_val = val / 3LL * 4LL;
				mp[new_val]++;
			}
		}

		cout << "Case #" << t << ":";
		for (int i = 0; i < n; i++) cout << ' ' <<v[i];
		cout << "\n";
	}
	return 0;
}