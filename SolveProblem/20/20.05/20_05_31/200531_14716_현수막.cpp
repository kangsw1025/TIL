#include<iostream>
#include<queue>
using namespace std;

int arr[251][251];
bool ch[251][251];
int x,y,cnt;
int n_x[8] = { 1,0,-1,0,1,1,-1,-1 };
int n_y[8] = { 0,1,0,-1,1,-1,1,-1 };

void solve(int a, int b)
{
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	ch[a][b] = true;

	while (!q.empty()) {
		int w = q.front().first;
		int h = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = w + n_x[i];
			int ny = h + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny] && !ch[nx][ny]) {
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
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) {
			if (!ch[i][j] && arr[i][j]) {
				solve(i, j);
				cnt++;
			}
		}
	cout << cnt;
	return 0;
}