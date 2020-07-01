#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int x, y;
char is[51][51];
bool ch[51][51];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void reset() {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) ch[i][j] = false;
}

int go(int w, int h) {
	int ans = 0;
	ch[w][h] = true;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(w, h)));

	while (!q.empty()) {
		int day = q.front().first;
		int nw = q.front().second.first;
		int nh = q.front().second.second;
		q.pop();
		if (day > ans) ans = day;

		for (int i = 0; i < 4; i++) {
			int nx = nw + n_x[i];
			int ny = nh + n_y[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
				if(is[nx][ny]=='L')
					if (ch[nx][ny] == false) {
						ch[nx][ny] = true;
						q.push(make_pair(day + 1, make_pair(nx, ny)));
					}
			}
		}
	}
	return ans;
}

int solve() {
	int ans = 0;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (is[i][j] == 'L') {
				reset();
				ans = max(ans, go(i, j));
			}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> is[i][j];

	cout<< solve();
	return 0;
}