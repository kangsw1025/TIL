#include<iostream>
#include<queue>
#include<string>
using namespace std;

int z, x, y;
char arr[31][31][31];
bool check[31][31][31];

int n_z[6] = { 1,-1,0,0,0,0 };
int n_x[6] = { 0,0,1,0,-1,0 };
int n_y[6] = { 0,0,0,1,0,-1 };

void reset(int sz, int sx, int sy) {
	for (int i = 1; i <= sz; i++)
		for (int j = 1; j <= sx; j++)
			for (int k = 1; k <= sy; k++) check[i][j][k] = false;
}

void solve(int sz, int sx, int sy, int dz, int dx, int dy) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, sz), make_pair(sx, sy)));
	check[sz][sx][sy] = true;

	while (!q.empty()) {
		int cnt = q.front().first.first;
		int qz = q.front().first.second;
		int qx = q.front().second.first;
		int qy = q.front().second.second;
		
		q.pop();
		if (qz == dz && qx == dx && qy == dy) {
			cout << "Escaped in " << cnt << " minute(s).\n";
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nz = qz + n_z[i];
			int nx = qx + n_x[i];
			int ny = qy + n_y[i];

			if (nz >= 1 && nz <= z && nx >= 1 && nx <= x && ny >= 1 && ny <= y && arr[nz][nx][ny]=='.') {
				if (!check[nz][nx][ny]) {
					check[nz][nx][ny] = true;
					q.push(make_pair(make_pair(cnt+1, nz), make_pair(nx, ny)));
				}
			}
		}
	}
	cout << "Trapped!\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int sz, sx, sy, dz, dx, dy;
	string space;
	while (1) {
		cin >> z >> x >> y;
		if (z == 0 && x == 0 && y == 0) break;
		for (int i = z; i >= 1; i--) {
			for (int j = 1; j <= x; j++) {
				for (int k = 1; k <= y; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {
						sz = i;
						sx = j;
						sy = k;
						arr[i][j][k] = '.';
					}
					if (arr[i][j][k] == 'E') {
						dz = i;
						dx = j;
						dy = k;
						arr[i][j][k] = '.';
					}
				}
			}
		}
		solve(sz, sx, sy, dz, dx, dy);
		reset(z, x, y);
	}
	return 0;
}