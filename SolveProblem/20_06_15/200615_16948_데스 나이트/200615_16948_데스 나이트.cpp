#include<iostream>
#include<queue>

using namespace std;

int sx, sy, dx, dy, n;
bool arr[201][201];
int n_x[6] = { -2,-2,0,0,2,2 };
int n_y[6] = { -1,+1,-2,+2,-1,+1 };

int solve() {
	arr[sx][sy] = true;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(sx, sy)));
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		if (x == dx && y == dy) return cnt;

		for (int i = 0; i < 6; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];
			if(nx>=0 && nx<n && ny>=0 && ny<n)
				if (arr[nx][ny] == false) {
					arr[nx][ny] = true;
					q.push(make_pair(cnt + 1, make_pair(nx, ny)));
				}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> sx >> sy >> dx >> dy;
	cout<<solve();
	return 0;
}