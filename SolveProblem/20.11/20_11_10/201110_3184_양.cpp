#include<iostream>
#include<queue>
using namespace std;

int sheep, fox;
char arr[251][251];
bool check[251][251];

int x, y;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void solve(int w, int h) {
	check[w][h] = true;

	int sh = 0, fo = 0;

	queue<pair<int, int>> q;
	q.push({ w,h });

	while (!q.empty()) {
		int nw = q.front().first;
		int nh = q.front().second;
		if (arr[nw][nh] == 'o') sh++;
		if (arr[nw][nh] == 'v') fo++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nw + n_x[i];
			int ny = nh + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && !check[nx][ny] && arr[nx][ny] != '#') {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	if (sh > fo) sheep += sh;
	else fox += fo;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];


	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (!check[i][j] && arr[i][j] != '#') solve(i, j);
	cout << sheep << ' ' << fox;
	return 0;
}