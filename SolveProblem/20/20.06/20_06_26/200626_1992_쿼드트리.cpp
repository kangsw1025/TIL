#include<iostream>
using namespace std;

char arr[65][65];

bool check(int x, int y, int n) {
	bool check = true;

	char w = arr[x][y];

	for(int i=x;i<x+n;i++)
		for(int j=y;j<y+n;j++)
			if (w != arr[i][j]) {
				check = false;
				break;
			}

	return check;
}

void solve(int x, int y, int n) {

	if (check(x,y,n)) cout << arr[x][y];
	else {
		cout << '(';
		solve(x, y, n / 2);
		solve(x, y + n / 2, n / 2);
		solve(x + n / 2, y, n / 2);
		solve(x + n / 2, y + n / 2, n / 2);
		cout << ')';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];


	solve(0,0,n);
	return 0;
}