#include<iostream>
using namespace std;

int arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n == 1) cout << 0;
	else {
		for (int i = n - 2; i >= 0; i--) {
			while (arr[i] >= arr[i + 1]) {
				arr[i]--;
				ans++;
			}
		}
		cout << ans;
	}
	return 0;
}