#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int i = 0, j = n - 1, now = 2000000001;
	pair<int, int> ans;
	while (i < j) {
		int a = arr[i];
		int b = arr[j];
		if (abs(a + b) < now) {
			now = abs(a + b);
			ans.first = arr[i];
			ans.second = arr[j];
		}

		if (a + b < 0) i++;
		else j--;
	}
	cout << ans.first << ' ' << ans.second;
	return 0;
}