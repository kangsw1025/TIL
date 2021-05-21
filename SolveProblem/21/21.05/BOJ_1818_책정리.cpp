#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec;

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0) vec.push_back(num);
		else {
			if (num > vec[vec.size() - 1]) vec.push_back(num);
			else {
				auto itr = lower_bound(vec.begin(), vec.end(), num);
				*itr = num;
			}
		}
	}
	cout << n - vec.size();
	return 0;
}