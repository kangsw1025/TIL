#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, point;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cin >> point;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == point) ans++;
			else if (arr[i] + arr[j] > point) break;
		}
	}
	cout << ans;
	return 0;
}