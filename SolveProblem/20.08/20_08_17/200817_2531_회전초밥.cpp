#include<iostream>
#include<algorithm>
using namespace std;

int n, d, k, c, now,ans;
int arr[3001];
int rice[30001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) cin >> rice[i];
	int i = 0;
	for (int j = 0; j < k; j++) {
		if (arr[rice[j]] == 0) now++;
		arr[rice[j]]++;
	}
	if (!arr[c]) ans = now + 1;
	else ans = now;

	while (i<n-1) {
		arr[rice[i]]--;
		if (!arr[rice[i]]) now--;
		arr[rice[(i+k)%n]]++;
		if (arr[rice[(i+k)%n]] == 1) now++;

		if (!arr[c]) ans = max(ans, now + 1);
		else ans = max(ans, now);
		i++;
	}
	cout << ans;
	return 0;
}