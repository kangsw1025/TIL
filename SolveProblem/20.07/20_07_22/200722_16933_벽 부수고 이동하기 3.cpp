#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

char wall[1001][1001];
bool arr[1001][1001][11]; // 벽 뚫고 지나간 여부
int x, y, k;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

struct state {
	int w = 1;
	int h = 1;
	int bw = 0;
	bool sun = true;
};

int solve() {
	state w;
	queue<pair<int,state>> q;
	q.push(make_pair(1,w));
	arr[1][1][0] = true;

	while (!q.empty()) {
		int cnt = q.front().first;
		state now = q.front().second;
		q.pop();

		if (now.w == x && now.h == y) return cnt;


		for (int i = 0; i < 4; i++) {
			int nx = now.w + n_x[i];
			int ny = now.h + n_y[i];
			if (nx >= 1 && nx <= x && ny >= 1 && ny <= y) {
				if (wall[nx][ny] == '1' && now.bw < k) {
					if (!arr[nx][ny][now.bw + 1]) {
						if (now.sun) {
							state copy = now;
							copy.bw++;
							copy.sun = !copy.sun;
							copy.w = nx;
							copy.h = ny;
							q.push(make_pair(cnt + 1, copy));
							arr[nx][ny][now.bw + 1] = true;
						}
						else {
							state copy = now;
							copy.sun = !copy.sun;
							q.push(make_pair(cnt + 1, copy));
						}
					}
				}
				else if(wall[nx][ny]=='0' && !arr[nx][ny][now.bw]){
					state copy = now;
					copy.sun = !copy.sun;
					copy.w = nx;
					copy.h = ny;
					q.push(make_pair(cnt+1,copy));
					arr[nx][ny][copy.bw] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> k;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) cin >> wall[i][j];

	cout << solve();
	return 0;
}