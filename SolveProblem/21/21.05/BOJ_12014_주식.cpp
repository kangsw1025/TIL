#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n, k, num;
		vector<int> vec;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (j == 0) vec.push_back(num);
			else {
				if (num > vec[vec.size() - 1]) vec.push_back(num);
				else {
					auto itr = lower_bound(vec.begin(), vec.end(), num);
					*itr = num;
				}
			}
		}
		cout << "Case #" << i << "\n";
		if (vec.size() >= k) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}