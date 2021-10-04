#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back({ val,i });
	}

	sort(v.begin(), v.end());

	int MAX = 0;

	for (int i = 0; i < n; i++) {
		MAX = max(MAX, v[i].second - i);
	}

	cout << MAX + 1;
	return 0;
}