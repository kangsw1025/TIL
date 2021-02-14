#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, T;
	long long num, prev, now, ans;

	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> vec;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (i == 0) {
				prev = num;
			}
			else {
				if (prev * num < 0) {
					vec.push_back(prev);
					prev = num;
				}
				else prev = max(prev, num);
			}
		}
		vec.push_back(prev);
		ans = 0;
		for (int i = 0; i < vec.size(); i++) ans += vec[i];
		cout << ans << "\n";
	}
	return 0;
}