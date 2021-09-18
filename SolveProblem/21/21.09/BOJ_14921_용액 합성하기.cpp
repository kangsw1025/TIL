#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n, ans = 2e9;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int l = 0, r = n-1;

	while (l < r) {
		int sum = arr[l] + arr[r];
		if (abs(sum) < abs(ans)) {
			ans = sum;
		}

		if (sum < 0) l++;
		else r--;
	}

	cout << ans;
	return 0;
}