#include<iostream>
#include<algorithm>
using namespace std;

long long n, k, arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);

	long long mx = 0;

	for (int i = 1; i < n; i++)
		mx = max(mx, arr[1] * i + arr[i + 1] * (n - i));

	long long md = k / mx;
	if (mx * md >= k) cout << md;
	else cout << md+1;
	return 0;
}