#include<iostream>
#include<queue>
using namespace std;

int x, y;
char arr[51][51];
bool ch[51][51], fir[51][51];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void fire() {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) fir[i][j] = false;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (arr[i][j] == '*')
				if (fir[i][j] == false)
					for (int k = 0; k < 4; k++) {
						int nx = i + n_x[k];
						int ny = j + n_y[k];
						if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
							if (arr[nx][ny] == '.') {
								fir[nx][ny] = true;
								arr[nx][ny] = '*';
							}
						}
					}
}

void solve(int sx, int sy)
{
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(sx, sy)));
	ch[sx][sy] = true;
	int day = 0;
	while (!q.empty()) {
		int w = q.front().second.first;
		int h = q.front().second.second;
		int c = q.front().first;
		q.pop();
		if (day == c) {
			day++;
			fire();
		}

		for (int i = 0; i < 4; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && !ch[nx][ny]) {
				if (arr[nx][ny] == '.') {
					ch[nx][ny] = true;
					q.push(make_pair(c + 1, make_pair(nx, ny)));
				}
				if (arr[nx][ny] == 'D') {
					cout << c + 1;
					return;
				}
			}
		}
	}
	cout << "KAKTUS";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int sx, sy;
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	solve(sx, sy);
	return 0;
}