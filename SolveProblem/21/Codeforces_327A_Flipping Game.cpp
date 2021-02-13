#include<iostream>
#include<algorithm>
using namespace std;

int arr[101], copy_arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, length = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			for (int k = 0; k < i; k++) copy_arr[k] = arr[k];
			for (int k = i; k <= j; k++) copy_arr[k] = 1 - arr[k];
			for (int k = j + 1; k < n; k++) copy_arr[k] = arr[k];

			length = 0;

			for (int k = 0; k < n; k++)
				if (copy_arr[k] == 1) length++;

			ans = max(ans, length);
		}
	}

	cout << ans;
	return 0;
}