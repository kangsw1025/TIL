#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int Max = 2e6 + 1;
set<int> s[Max];
int ans;

void push(int u, int v) {
	if (u > v) swap(u, v);

	s[u].insert(v);

	if (s[u].size() == 1) ans--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q, u, v;
	cin >> n >> m;
	ans = n;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		push(u, v);
	}

	cin >> q;

	while (q--) {
		int op;
		cin >> op;

		if (op == 1) {
			cin >> u >> v;
			push(u, v);
		}

		else if (op == 2) {
			cin >> u >> v;
			if (u > v) swap(u, v);

			s[u].erase(v);
			if (s[u].size() == 0) ans++;
		}

		else if (op == 3) cout << ans<<"\n";
	}
	return 0;
}