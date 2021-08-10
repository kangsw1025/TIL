#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		auto itr = lower_bound(v.begin(), v.end(), num);
		if (itr == v.end()) v.push_back(num);
		else *itr = num;
	}
	cout << v.size();
	return 0;
}