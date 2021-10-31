#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		s.insert(val);
	}

	for (auto itr : s) {

		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (s.find(itr+i)!=s.end()) cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << 5 - ans;

	return 0;
}