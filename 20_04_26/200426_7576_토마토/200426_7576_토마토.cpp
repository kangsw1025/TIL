#include<iostream>
#include<queue>
using namespace std;

int x, y;
int arr[1001][1001];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };
queue<pair<pair<int, int>, int>> q;

void bfs()
{
	bool ch = true;

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (arr[i][j] == 0) {
				ch = false;
				break;
			}
	if (ch == true) {
		cout << 0;
		return;
	}
	int day;

	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		day = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = h + n_y[i];
			int nx = w + n_x[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y)
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = 1;
					q.push(make_pair(make_pair(ny, nx), day + 1));
				}
		}
	}
	ch = true;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (arr[i][j] == 0) {
				ch = false;
				break;
			}
	if (ch == false) cout << -1;
	else cout << day;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	for(int i=0;i<y;i++)
		for (int j = 0; j < x; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push(make_pair(make_pair(i, j), 0));
		}
	
	bfs();
	return 0;
}