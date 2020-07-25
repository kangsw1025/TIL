#include<iostream>
#include<algorithm>
using namespace std;

int n, c, t;
int x, y;

int now[201][201];
int bi[201][201];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void copy() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) bi[i][j] = now[i][j];
}

void ploid() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (now[i][j] == 0) {
				int mi = 987654321;
				for (int k = 0; k < 4; k++) {
					int nx = i + n_x[k];
					int ny = j + n_y[k];
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
						if (bi[nx][ny] < mi && bi[nx][ny]!=0) mi = bi[nx][ny];
					}
				}
				if (mi != 987654321) now[i][j] = mi;
			}
		}
}

void show() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << now[i][j] << ' ';
		cout << "\n";
	}
}


void solve(int t) {

	for(int i = 1; i <= t; i++) {
		copy();
		ploid();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> now[i][j];
	cin >> t >> x >> y;
	solve(t);
	cout << now[x][y];
}