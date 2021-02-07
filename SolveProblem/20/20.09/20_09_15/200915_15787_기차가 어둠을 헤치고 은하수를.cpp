#include<iostream>
using namespace std;

long long train[100001];
bool check[(1 << 20)-1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int op, idx;
		cin >> op >> idx;
		if (op == 1) {
			int seat;
			cin >> seat;
			train[idx] |= 1LL << (seat-1);
		}
		else if (op == 2) {
			int seat;
			cin >> seat;
			train[idx] &= ((1LL << 20) - 1) - (1 << (seat-1));
		}
		else if (op == 3) {
			train[idx] = train[idx] * 2 & ((1 << 20) - 1);
		}
		else if (op == 4) {
			train[idx] /= 2;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[train[i]]) {
			ans++;
			check[train[i]] = true;
		}
	}
	cout << ans;
	return 0;
}