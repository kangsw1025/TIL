#include<iostream>
using namespace std;

int arr[250001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arr[i] += arr[i - 1] + num;
	}

	int ans = 0, cnt = 0;
	for (int i = n; i - x >= 0; i--) {
		int visiter = arr[i] - arr[i-x];

		if (visiter > ans) {
			ans = visiter;
			cnt = 1;
		}
		else if (visiter == ans) {
			cnt++;
		}
	}
	if (ans == 0) cout << "SAD";
	else cout << ans << "\n"<<cnt;
	return 0;
}