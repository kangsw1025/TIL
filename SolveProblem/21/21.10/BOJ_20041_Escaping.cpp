#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
using namespace std;

int n;
pair<int, int> me, police[500001];

bool solve(int op) {

	if (op == 0) {
		for (int i = 0; i < n; i++) {
			if (police[i].second <= me.second) continue;
			if (police[i].second - me.second >= abs(police[i].first - me.first)) return false;
		}
	}

	else if (op == 1) {
		for (int i = 0; i < n; i++) {
			if (police[i].second >= me.second) continue;
			if (me.second - police[i].second >= abs(police[i].first - me.first)) return false;
		}
	}
	else if (op == 2) {
		for (int i = 0; i < n; i++) {
			if (police[i].first >= me.first) continue;
			if (me.first - police[i].first >= abs(police[i].second - me.second)) return false;
		}
	}

	else {
		for (int i = 0; i < n; i++) {
			if (police[i].first <= me.first) continue;
			if (police[i].first - me.first >= abs(police[i].second - me.second)) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int x, y;


	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		police[i] = { x,y };
	}

	cin >> x >> y;
	me = { x,y };

	for (int i = 0; i < 4; i++) {
		if (solve(i)) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}