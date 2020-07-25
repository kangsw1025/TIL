#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, now = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--) {
		now++;
		if (now % 3 == 0) {
			now = 0;
			continue;
		}
		ans += arr[i];
	}
	cout << ans;
	return 0;
}