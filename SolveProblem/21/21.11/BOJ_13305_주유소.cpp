#include<iostream>
#include<algorithm>
using namespace std;

long long dst[100001], price[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) cin >> dst[i];
	for (int i = 0; i < n; i++) cin >> price[i];

	long long mx = 2e9 + 1, ans = 0;

	for (int i = 0; i < n - 1; i++) {
		mx = min(mx, price[i]);
		ans += mx * dst[i];
	}

	cout << ans;
	return 0;
}