#include<iostream>
#include<algorithm>
using namespace std;

int now, dif, ans, minf;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		now += arr[i];
		if (i >= m) {
			dif += arr[i - m];
			minf = min(minf, dif);
			ans = max(ans, now - minf);
		}
	}
	cout << ans;
	return 0;
}