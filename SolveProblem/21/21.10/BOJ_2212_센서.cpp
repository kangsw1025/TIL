#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0];

	for (int i = n - 1; i > 0; i--) arr[i] -= arr[i - 1];
	sort(arr + 1, arr + n);
	for (int i = n - 1; i > 0 && --k; i--) ans -= arr[i];
	cout << ans;
	return 0;
}