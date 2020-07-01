#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

bool check[102];

void reset(int m) {
	for (int i = 0; i < m; i++)
		check[i] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y;
	int sx, sy, dx, dy;
	bool ar;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> vec;
		queue<pair<int, int>> q;
		ar = false;
		cin >> m;
		reset(m+1);
		cin >> sx >> sy;
		q.push(make_pair(sx, sy));
		for (int j = 0; j < m; j++) {
			cin >> x >> y;
			vec.push_back(make_pair(x, y));
		}
		cin >> dx >> dy;
		vec.push_back(make_pair(dx, dy));

		while (!q.empty()) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			if (nx == dx && ny == dy) {
				ar = true;
				break;
			}
			for (int k = 0; k < vec.size(); k++) {
				int n_x = vec[k].first;
				int n_y = vec[k].second;

				if (abs(n_x - nx) + abs(n_y - ny) <= 1000) {
					if (check[k] == false) {
						check[k] = true;
						q.push(make_pair(n_x, n_y));
					}
				}
			}
		}
		if (ar == true) cout << "happy\n";
		else cout << "sad\n";

	}
	return 0;
}