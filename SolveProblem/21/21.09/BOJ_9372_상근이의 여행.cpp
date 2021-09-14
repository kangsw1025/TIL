#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
		}

		cout << n - 1 << "\n";
	}
	return 0;
}