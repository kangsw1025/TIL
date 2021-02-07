#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];
int ans, now;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i <n; i++) {
		now = 0;
		for (int j = i; j < n; j++) {
			now += arr[j];
			if (now == m) ans++;
		}
	}
	cout << ans;
	return 0;
}