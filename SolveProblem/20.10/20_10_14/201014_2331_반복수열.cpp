#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> ans;

int  solve(int now, int p) {
	auto itr = find(ans.begin(), ans.end(), now);
	if (itr != ans.end()) return itr-ans.begin();

	ans.push_back(now);
	int next = 0;
	while (now) {
		next += pow(now % 10, p);
		now /= 10;
	}
	return solve(next, p);
}

int main() {
	int a, p;
	cin >> a >> p;
	cout<<solve(a, p);
	return 0;
}