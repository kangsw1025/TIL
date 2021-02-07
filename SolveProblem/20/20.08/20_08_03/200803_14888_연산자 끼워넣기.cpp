#include<iostream>
#include<algorithm>
using namespace std;

#define INF 100000001
int arr[12];
int n, pl, mi, mu, di;
int max_ans = -1*INF, min_ans = INF;

void solve(int num, int cnt) {
	if (cnt == n) {
		max_ans = max(max_ans, num);
		min_ans = min(min_ans, num);
		return;
	}

	if (pl) {
		pl--;
		solve(num + arr[cnt], cnt + 1);
		pl++;
	}
	if (mi) {
		mi--;
		solve(num - arr[cnt], cnt + 1);
		mi++;
	}
	if (mu) {
		mu--;
		solve(num * arr[cnt], cnt + 1);
		mu++;
	}
	if (di) {
		di--;
		solve(num / arr[cnt], cnt + 1);
		di++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> pl >> mi >> mu >> di;

	solve(arr[0], 1);
	cout << max_ans << "\n" << min_ans;
	return 0;
}