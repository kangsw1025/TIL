#include<iostream>
#include<algorithm>
using namespace std;

long long arr[51];

int cutting(int l, int n) {
	int rst = 0;
	if (l % n) rst++;

	return rst + l / n - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, c, w, mx = 0, ans = 0;
	cin >> n >> c >> w;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}

	for(int k = 1;k<=mx;k++) {
		long long price, rst = 0;
		for (int i = 0; i < n; i++) {
			price = (arr[i] / k) * w * k - cutting(arr[i], k) * c;
			if (price >= 0) rst += price;
		}
		ans = max(ans, rst);
	}
	cout << ans;
	return 0;
}