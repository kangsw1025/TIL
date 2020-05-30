#include<iostream>
#include<queue>
using namespace std;

int arr[64][64];
bool ch[64][64];
int n;
int n_x[2] = { 1,0 };
int n_y[2] = { 0,1 };

bool solve()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	ch[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n - 1 && y == n - 1) return true;
		for (int i = 0; i < 2; i++) {
			int nx = x + n_x[i]*arr[x][y];
			int ny = y + n_y[i]*arr[x][y];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !ch[nx][ny]) {
				ch[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	bool ans = solve();
	if (ans) cout << "HaruHaru";
	else cout << "Hing";
	return 0;
}