#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, cnt;
int arr[101];
bool check[101], cycle[101];

bool solve(int start, int now) {
	if (check[now]) return false;
	check[now] = true;
	if (start == now || solve(start, arr[now])) {
		cnt++;
		cycle[now] = true;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) check[j] = cycle[j];
		solve(i, arr[i]);
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++) if (cycle[i]) cout << i << "\n";
	return 0;
}