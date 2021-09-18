#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		int val = min(arr[l], arr[r]) * (r - l - 1);

		ans = max(ans, val);

		if (arr[l] > arr[r]) r--;
		else l++;
	}
	cout << ans;
	return 0;
}