#include<iostream>
#include<algorithm>
using namespace std;

#define INF 2000000001
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int i = 0, j = 0;
	int ans = INF;
	while (i<=j && j<n) {
		if (arr[j] - arr[i] >= m) {
			ans = min(ans, arr[j] - arr[i]);
			if (i == j)	j++;
			else i++;
		}
		else j++;
	}
	cout << ans;
	return 0;
}