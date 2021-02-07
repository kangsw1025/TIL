#include<iostream>
#include<algorithm>
using namespace std;

int arr[3003001];
int rice[3001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < k; i++) arr[n + i] = arr[i];
	int ans = 0;
	int now = 1;
	rice[c]++;
	for (int i = 0; i < k; i++) {
		if (rice[arr[i]] == 0) now++;
		rice[arr[i]]++;
	}
	int i = 0, j = k - 1;
	while (j < n + k - 1) {
		ans = max(now, ans);
		rice[arr[i]]--;
		if (rice[arr[i]] == 0) now--;
		i++;
		j++;
		rice[arr[j]]++;
		if (rice[arr[j]] == 1) now++;
	}
	cout << ans;
	return 0;
}