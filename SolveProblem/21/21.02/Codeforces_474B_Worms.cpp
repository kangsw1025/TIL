#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, num, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		vec.push_back(sum);
	}

	cin >> m;

	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;

		cout << lower_bound(vec.begin(), vec.end(), num) - vec.begin() + 1 << "\n";
	}
	return 0;
}