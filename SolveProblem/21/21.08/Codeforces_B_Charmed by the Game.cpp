#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;

		int game = a + b;
		vector<int> v;

		if (a < b) swap(a, b);

		if (game % 2 == 0) {
			int mx = min(game / 2, a) + b;
			for (int i = 0; i <= b; i++) {
				v.push_back(mx - 2 * i);
			}
		}
		else {
			int mx = min(game / 2, a) + b;
			for (int i = 0; i <= b; i++) {
				v.push_back(mx - 2 * i);
			}
			mx = min(game / 2 + 1, a) + b;
			for (int i = 0; i <= b; i++) {
				v.push_back(mx - 2 * i);
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		cout << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		cout << "\n";
	}
	return 0;
}