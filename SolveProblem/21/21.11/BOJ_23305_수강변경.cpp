#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int ac[1000001], bc[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		ac[val]++;
		s.insert(val);
	}

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		bc[val]++;
	}

	int ans = 0;

	for (auto itr : s) {
		ans += min(ac[itr], bc[itr]);
	}
	cout << n - ans;
	return 0;
}