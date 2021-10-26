#include<iostream>
#include<set>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> s;
	int T;
	int a, b, c, ans = 0;
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		bool is = false;
		if (s.find(a) != s.end()) is = true;
		if (s.find(b) != s.end()) is = true;
		if (s.find(c) != s.end()) is = true;
		if (!is) ans++;
		s.insert(a);
		s.insert(b);
		s.insert(c);
	}

	cout << ans;
	return 0;
}