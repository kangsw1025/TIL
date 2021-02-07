#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
bool check[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, ans = 0;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			for (int j = arr[i]; j < min(1000, arr[i] + l); j++)
				check[j] = true;
			ans++;
		}
	}
	cout << ans;
	return 0;
}