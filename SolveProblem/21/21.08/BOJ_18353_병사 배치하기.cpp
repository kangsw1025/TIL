#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[2001];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n - 1; i >= 0; i--) {
		int num = arr[i];

		auto itr = lower_bound(v.begin(), v.end(), num);
		if (itr == v.end()) v.push_back(num);
		else *itr = num;
	}

	cout << n - v.size();
	return 0;
}