#include<iostream>
#include<algorithm>
using namespace std;

int arr[15001];
int n, point, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> point;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int i = 0, j = n - 1;
	while (i < j) {
		if (arr[i] + arr[j] == point) {
			ans++;
			i++;
			j--;
		}
		else if (arr[i] + arr[j] > point)	j--;
		else i++;
	}
	cout << ans;
	return 0;
}