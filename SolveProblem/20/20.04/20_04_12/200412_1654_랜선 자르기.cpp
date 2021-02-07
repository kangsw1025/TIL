#include <iostream>
using namespace std;

long long arr[10001];
int n, l;

bool po(long long le) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += arr[i] / le;

	if (cnt >= l) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long max = 0;
	long long ans = 0, low = 1;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
	}

	while (low <= max) {
		long long mid = (low + max) / 2;
		if (po(mid)) {
			if (ans < mid) ans = mid;
			low = mid + 1;
		}
		else max = mid - 1;
	}
	cout << ans;
	return 0;
}