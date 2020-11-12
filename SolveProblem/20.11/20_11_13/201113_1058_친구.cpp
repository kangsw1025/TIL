#include<iostream>
#include<queue>
using namespace std;

int x, y;
char arr[251][251];
bool check[251][251];
int fox, sheep;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void solve(int w, int h) {
	check[w][h] = true;
	queue<pair<int, int>> q;
	q.push({ w,h });

	int fo = 0, sh = 0;

	while (!q.empty()) {
		int nw = q.front().first;
		int nh = q.front().second;
		q.pop();

		if (arr[nw][nh] == 'v') fo++;
		else if (arr[nw][nh] == 'k') sh++;
		for (int i = 0; i < 4; i++) {
			int nx = nw + n_x[i];
			int ny = nh + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && !check[nx][ny] && arr[nx][ny] != '#') {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	if (fo >= sh) fox += fo;
	else sheep += sh;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (!check[i][j] && arr[i][j] != '#')
				solve(i, j);
	cout << sheep << ' ' << fox;
	return 0;
}