#include<iostream>
using namespace std;

int n;
int arr[21];
bool check[2000000];

void solve(int idx, int now) {
	check[now] = true;
	if (idx > n) return;

	solve(idx + 1, now + arr[idx]);
	solve(idx + 1, now);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	solve(1, 0);

	for (int i = 1; i; i++)
		if (!check[i]) {
			cout << i;
			break;
		}

	return 0;
}