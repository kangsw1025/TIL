#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		while (1) {
			bool check = true;
			for (int i = 1; i < n; i++) {
				if (arr[i] > arr[i + 1]) {
					check = false;
					break;
				}
			}
			if (check) break;

			bool change = false;
			if (cnt % 2) {
				for (int i = 2; i <=n-1; i += 2) {
					if (arr[i] > arr[i + 1]) {
						swap(arr[i], arr[i + 1]);
					}
				}
			}

			else if (cnt % 2 == 0) {
				for (int i = 1; i <= n-2; i += 2) {
					if (arr[i] > arr[i + 1]) {
						swap(arr[i], arr[i + 1]);
					}
				}
			}
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}