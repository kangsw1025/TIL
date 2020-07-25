#include<iostream>
#include<queue>
using namespace std;

char arr[101][101];
bool ch[101][101];
int sum[101][101];
int ax[4] = { 0, 1, 0, -1 };
int ay[4] = { 1 ,0, -1, 0 };
int a, b;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	ch[x][y] = true;
	sum[x][y] = 1;

	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = h + ax[i];
			int ny = w + ay[i];

			if (nx >= 1 && nx <= a && ny >= 1 && ny <= b && arr[nx][ny] == '1' && ch[nx][ny] == false) {
				sum[nx][ny] = sum[h][w] + 1;
				ch[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}

	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			cin >> arr[i][j];

	bfs(1, 1);
	cout << sum[a][b];
	return 0;
}