#include<iostream>
using namespace std;

bool br[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, r, ans = 0;
	cin >> n >> s >> r;

	for (int i = 0; i < s; i++) {
		int v;
		cin >> v;
		br[v] = true;
		ans++;
	}

	for (int i = 0; i < r; i++) {
		int v;
		cin >> v;
		if (br[v]) {
			br[v] = false;
			ans--;
			continue;
		}

		if (br[v - 1]) {
			br[v - 1] = false;
			ans--;
			continue;
		}

		if (br[v + 1]) {
			br[v + 1] = false;
			ans--;
			continue;
		}
	}
	cout << ans;
	return 0;
}