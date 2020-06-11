#include<iostream>
#include<queue>
using namespace std;

int x, y, z;
int arr[101][101][101];
int n_x[6] = { 0,1,0,-1,0,0 };
int n_y[6] = { 1,0,-1,0,0,0 };
int n_z[6] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, pair<int,int>>> q;

void bfs()
{
	bool ch = true;

	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			for(int k=0;k<x;k++)
				if (arr[i][j][k] == 0) {
					ch = false;
					break;
				}
	if (ch == true) {
		cout << 0;
		return;
	}
	int day;

	while (!q.empty()) {
		int t = q.front().first.first;
		int h = q.front().first.second;
		int w = q.front().second.first;
		day = q.front().second.second;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = t + n_z[i];
			int ny = h + n_y[i];
			int nx = w + n_x[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && nz>=0 && nz<z)
				if (arr[nz][ny][nx] == 0) {
					arr[nz][ny][nx] = 1;
					q.push(make_pair(make_pair(nz, ny), make_pair(nx,day + 1)));
				}
		}
	}
	ch = true;
	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				if (arr[i][j][k] == 0) {
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

	cin >> x >> y>>z;
	
	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) q.push(make_pair(make_pair(i, j), make_pair(k,0)));
			}
		}

	bfs();
	return 0;
}