#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int n, m, ans, now;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) now += arr[i];
	ans = now;
	for (int i = m; i < n; i++) {
		now = now + arr[i] - arr[i - m];
		ans = max(ans, now);
	}
	cout << ans;
	return 0;
}