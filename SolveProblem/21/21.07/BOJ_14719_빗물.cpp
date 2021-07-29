#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int arr[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w, ans = 0;

	cin >> h >> w;

	for (int i = 0; i < w; i++)
		cin >> arr[i];

	for (int i = 1; i < w - 1; i++) {
		int left = arr[i];
		int right = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);
		for (int j = i + 1; j < w; j++)
			right = max(right, arr[j]);
		int low = min(left, right);
		ans += max(0, low - arr[i]);
	}
	
	cout << ans;
	return 0;
}