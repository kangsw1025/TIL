#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (v.empty()) v.push_back(val);
		else {
			while (v.back() < val) {
				int del = v.back();
				v.pop_back();

				if (v.empty() || v.back() > val) {
					ans += val - del;
					break;
				}
				else ans += v.back() - del;
			}
			v.push_back(val);
		}
	}

	if (v.size() > 1) ans += v.front() - v.back();
	cout << ans;
	return 0;
}

