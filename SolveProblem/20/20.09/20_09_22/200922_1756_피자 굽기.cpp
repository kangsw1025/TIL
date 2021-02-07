#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int d, n, d_size;
stack<pair<int,pair<int,int>>> oven;
queue<int> dough;

int solve() {

	while (!oven.empty()) {
		int depth = oven.top().first;
		int r = oven.top().second.first;
		int min_r = oven.top().second.second;
		oven.pop();

		if (min_r >= dough.front()) {
			dough.pop();
			if (dough.empty()) return depth;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> d >> n;
	for (int i = 1; i <= d; i++) {
		cin >> d_size;
		if (oven.empty()) oven.push({ i,{d_size,d_size} });
		else oven.push({ i,{d_size,min(d_size,oven.top().second.second)} });
	}
	for (int i = 0; i < n; i++) {
		cin >> d_size;
		dough.push(d_size);
	}
	cout << solve();
	return 0;
}