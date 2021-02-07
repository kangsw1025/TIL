#include<iostream>
#include<queue>
using namespace std;

int arr[301][301];
bool v[301][301];
int len;

int n_x[8] = { -1, -2, -2, -1, 1, 2, 2 ,1};
int n_y[8] = { -2, -1, 1, 2, -2, -1, 1, 2};

void reset(int n)
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			v[i][j] = false;
		}
}

void go(int sx, int sy, int dx, int dy)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push(make_pair(0, make_pair(sx, sy)));
	v[sx][sy] = true;

	while (!q.empty())
	{
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cnt = q.top().first;
		q.pop();
		if (x == dx && y == dy) {
			cout << cnt<<"\n";
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];
			if (nx >= 0 && nx < len && ny >= 0 && ny < len && v[nx][ny] == false) {
				q.push(make_pair(cnt + 1, make_pair(nx, ny)));
				v[nx][ny] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,a,b,c,d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> len;
		cin >> a >> b >> c >> d;
		go(a, b, c, d);
		reset(len);
	}
	return 0;
}