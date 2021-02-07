#include<iostream>
#include<algorithm>
using namespace std;

int n, l, r, x;
int arr[15];

long long solve(int idx, int now, int low, int high, int cnt) {
	if (now > r) return 0;
	if (idx == n) {
		if (now >= l && high - low >= x && cnt>=2) return 1;
		return 0;
	}
	long long ans = 0;
	ans += solve(idx + 1, now, low, high, cnt);
	ans += solve(idx + 1, now + arr[idx], min(low, arr[idx]), max(high, arr[idx]), cnt + 1);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) cin >> arr[i];
	long long ans = 0;
	for(int i=0;i<n;i++)
		ans += solve(i+1, arr[i], arr[i], arr[i], 1);
	cout << ans;
	return 0;
}