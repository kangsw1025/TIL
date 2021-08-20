#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, dst;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> dst;

	v.push_back(0);
	v.push_back(dst);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int left = 1, right = dst-1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 1; i < v.size(); i++) {
			int dist = v[i] - v[i - 1];
			cnt += dist / mid;
			if (dist % mid == 0) cnt--;
		}

		if (cnt > m) left = mid + 1;
		else right = mid - 1;
	}

	cout << left;
	return 0;
}