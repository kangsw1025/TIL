#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n, num;
	cin >> T;
	while (T--) {
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (i == 0) v.push_back(num);
			else {
				if (num > v[v.size() - 1]) v.push_back(num);
				else {
					auto itr = lower_bound(v.begin(), v.end(), num);
					*itr = num;
				}
			}
		}
		cout << v.size() << "\n";
	}
	return 0;
}