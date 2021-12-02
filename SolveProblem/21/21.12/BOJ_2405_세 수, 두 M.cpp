#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	sort(arr + 1, arr + 1 + n);

	int ans = 0;

	for (int i = 2; i < n; i++) {
		ans = max(ans, abs(arr[1] + arr[i + 1] - 2 * arr[i]));
		ans = max(ans, abs(arr[n] + arr[i - 1] - 2 * arr[i]));
	}

	cout << ans;
	return 0;
}