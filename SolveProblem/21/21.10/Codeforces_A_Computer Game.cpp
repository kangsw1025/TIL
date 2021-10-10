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
 
int n;
char arr[3][101];
bool visit[3][101];
 
int n_x[5] = { 0,1,1,-1,-1 };
int n_y[5] = { 1,0,1,1,0 };
 
bool solve() {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == 2 && y == n) return true;
 
		for (int i = 0; i < 5; i++) {
			int nx = x + n_x[i];
			int ny = y + n_y[i];
 
			if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= n && !visit[nx][ny] && arr[nx][ny] == '0') {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
 
	return false;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
 
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++) cin >> arr[i][j];
		
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}