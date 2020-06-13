#include<iostream>
using namespace std;

int x, y, t;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

char bomb[201][201];
char now[201][201];

void copy() {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			bomb[i][j] = now[i][j];
}

void setbomb() {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			now[i][j] = 'O';
}

void explosion() {
	for(int i=0;i<x;i++)
		for (int j = 0; j < y; j++) {
			if (bomb[i][j] == 'O') {
				now[i][j] = '.';
				for (int k = 0; k < 4; k++) {
					int nx = i + n_x[k];
					int ny = j + n_y[k];
					if (nx >= 0 && nx < x && ny >= 0 && ny < y) now[nx][ny] = '.';
				}
			}
		}
}

void solve() {
	if (t == 1) return;
	for (int i = 2; i <= t; i++) {
		if (i % 2 == 0) {
			copy();
			setbomb();
		}
		else {
			explosion();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> t;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> now[i][j];

	solve();

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) cout<< now[i][j];
		cout << "\n";
	}
	return 0;
}