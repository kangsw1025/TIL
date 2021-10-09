#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
using namespace std;

int n, m;
int arr[1001][1001];
bool visit[1001][1001];

int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int solve() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	
	if (arr[0][0] == -1) return -1;

	q.push({ arr[0][0],{0,0} });
	visit[0][0] = true;

	while (!q.empty()) {
		int val = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1) return val;


		for (int i = 0; i < 4; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] != -1) {
				visit[nx][ny] = true;
				q.push({ val + arr[nx][ny],{nx,ny} });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	cout<<solve();

	return 0;
}