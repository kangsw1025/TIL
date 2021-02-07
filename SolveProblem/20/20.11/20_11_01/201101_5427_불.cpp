#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char arr[1001][1001];
bool check[1001][1001];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(check, false, sizeof(check));
		int x, y;
		int sx, sy;
		bool find = false;
		queue<pair<int, pair<int, int>>> q;
		cin >> y >> x;
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') q.push({ -1,{i,j} });
				else if (arr[i][j] == '@') {
					arr[i][j] = '.';
					sx = i;
					sy = j;
				}
			}
		q.push({ 0,{sx,sy} });
		check[sx][sy] = true;
		while (!q.empty()) {
			int cnt = q.front().first;
			int w = q.front().second.first;
			int h = q.front().second.second;
			q.pop();

			if (w == 0 || w == x - 1 || h == 0 || h == y - 1) {
				if (cnt != -1) {
					cout << cnt + 1 << "\n";
					find = true;
					break;
				}
			}

			if (cnt == -1) {
				for (int i = 0; i < 4; i++) {
					int nx = w + n_x[i];
					int ny = h + n_y[i];
					if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
						if (arr[nx][ny] == '.') {
							arr[nx][ny] = '*';
							q.push({ -1,{nx,ny} });
						}
					}
				}
			}
			else {
				for (int i = 0; i < 4; i++) {
					int nx = w + n_x[i];
					int ny = h + n_y[i];
					if (nx >= 0 && nx < x && ny >= 0 && ny < y && !check[nx][ny]) {
						if (arr[nx][ny]=='.') {
							check[nx][ny] = true;
							q.push({ cnt + 1,{nx,ny} });
						}
					}
				}
			}
		}
		if(!find)	cout << "IMPOSSIBLE\n";
	}
	return 0;
}