#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, time, ans = 1, spend = 0;
	cin >> n >> time;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int start;
	for (start = 0; start < n; start++)
		if (arr[start] <= time) break;

	if (start != n) {
		int i = start, j = start;
		spend = arr[i];
		while (i < n && j < n) {
			if (spend <= time) {
				j++;
				if (j == n) break;
				spend += arr[j];
			}

			else if (spend > time) {
				spend -= arr[i];
				i++;
				if (i>j) {
					spend += arr[i];
					j++;
				}
			}
			if (spend <= time && spend > 0) ans = max(ans, j - i + 1);
		}

		cout << ans;
	}
	else cout << 0;

	return 0;
}