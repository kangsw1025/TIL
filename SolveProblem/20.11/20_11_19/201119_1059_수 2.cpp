#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool check[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,l;
	cin >> n;

	vector<int> vec(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		check[vec[i]] = true; 
	}

	cin >> l;
	if (check[l]) {
		cout << 0;
		return 0;
	}
	sort(vec.begin(), vec.end());
	int left = 0, right = 0;

	for (int i = 0; i < n; i++) {
		if (vec[i] <= l && vec[i + 1] > l) {
			left = vec[i];
			right = vec[i + 1];
			break;
		}
	}
	cout << (l - left) * (right - l) - 1;
	return 0;
}