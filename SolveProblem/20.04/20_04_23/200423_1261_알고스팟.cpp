#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

string w[101];
int x, y;
int n_x[4] = { 0, -1, 0, 1 };
int n_y[4] = { -1, 0, 1, 0 };
bool v[101][101];

int bfs()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push({ 0, {0, 0}});
	v[0][0] = true;

	while (!q.empty())
	{
		int _x = q.top().second.first;
		int _y = q.top().second.second;
		int p = q.top().first;

		q.pop();

		if (_x == x - 1 && _y == y - 1) return p;

		for (int i = 0; i < 4; i++) {
			int nx = _x + n_x[i];
			int ny = _y + n_y[i];

			if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
				if (v[nx][ny] == false) {
					if (w[nx][ny] == '1') {
						q.push(make_pair(p + 1, make_pair(nx, ny)));
						v[nx][ny] = true;
					}
					else {
						q.push(make_pair(p, make_pair(nx, ny)));
						v[nx][ny] = true;
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> y >> x;
	for (int i = 0; i < x; i++) cin >> w[i];

	cout << bfs();
	return 0;
}