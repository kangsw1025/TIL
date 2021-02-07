#include<iostream>
#include<algorithm>
using namespace std;

int n, start, ans = 2e9;
int arr[11][11];
bool check[11];

void solve(int idx, int dst, int p) {
	if (ans < dst) return;
	if (p == n) {
		ans = min(ans, dst);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		solve(i, dst + arr[idx][i], p + 1);
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> start;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	check[start] = true;

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
	solve(start, 0, 1);
	cout << ans;
	return 0;
}