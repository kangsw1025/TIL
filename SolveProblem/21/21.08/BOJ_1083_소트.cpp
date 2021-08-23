#include<iostream>
#include<algorithm>
using namespace std;

int arr[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s == 0) break;

		int mx = arr[i], mxIdx = i;

		int cnt = min(n, i + 1 + s);
		for (int j = i + 1; j < cnt; j++) {
			if (mx < arr[j]) {
				mx = arr[j];
				mxIdx = j;
			}
		}

		s -= mxIdx - i;

		for (int j = mxIdx; j > i; j--)
			arr[j] = arr[j - 1];
		arr[i] = mx;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}