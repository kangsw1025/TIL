#include<iostream>
#include<queue>
using namespace std;

int arr[301][301];
int dp[301][301];

int n_x[2] = { 0,1 };
int n_y[2] = { 1,0 };

void solve(int x, int y) {
	
	for(int i=1;i<=x;i++)
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <=arr[i][j]; k++) {
				for (int f = 0; f < 2; f++) {
					int nx = i + n_x[f] * k;
					int ny = j + n_y[f] * k;
					if (nx >= 1 && nx <= x && ny >= 1 && ny <= y) {
						if (dp[nx][ny] == 0)
							dp[nx][ny] = dp[i][j] + 1;
						else if (dp[nx][ny] > dp[i][j] + 1) dp[nx][ny] = dp[i][j] + 1;
					}
				}
			}
		}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) cin >> arr[i][j];
	
	solve(x,y);
	cout << dp[x][y];
	return 0;
}