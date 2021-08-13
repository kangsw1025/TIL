#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool arr[1001][1001];

int a, b, c, d;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ a,b });
	arr[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int z = d - x - y;
		if (x == y && y == z) {
			cout << 1;
			return;
		}

		int nx[] = { x,x,y }, ny[] = { y,z,z };
		for (int i = 0; i < 3; i++) {
			int f = nx[i], s = ny[i];
			if (f < s) {
				s -= f;
				f += f;
			}
			else if (f > s) {
				f -= s;
				s += s;
			}
			else continue;

			int t = d - f - s;
			int X = min(min(f, s), t);
			int Y = max(max(f, s), t);
			if (!arr[X][Y]) {
				q.push({ X,Y });
				arr[X][Y] = true;
			}
		}
	}
	cout << 0;
}

void solve() {
	d = a + b + c;
	if (d % 3) cout << 0;
	else bfs();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	
	solve();
	return 0;
}