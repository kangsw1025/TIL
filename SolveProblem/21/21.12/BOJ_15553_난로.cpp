#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v, diff;

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);

		if (i != 0)
			diff.push_back(val - v[i - 1]-1);
	}

	sort(diff.begin(), diff.end(),cmp);

	int time = v[n - 1] - v[0] + 1;

	for (int i = 0; i < k - 1; i++) {
		time -= diff[i];
	}

	cout << time;
	return 0;
}