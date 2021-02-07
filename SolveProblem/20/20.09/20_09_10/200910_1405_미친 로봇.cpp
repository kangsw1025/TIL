#include<iostream>
#include<iomanip>
using namespace std;

int n_x[4] = { 1,-1,0,0 };
int n_y[4] = { 0,0,1,-1 };
int n;
double arr[4];
double ans;
bool check[30][30];

void solve(int x, int y, double ul) {
	if (n == 0) {
		ans += ul;
		return;
	}
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + n_x[i];
		int ny = y + n_y[i];
		if (!check[nx][ny]) {
			n--;
			solve(nx, ny, ul * arr[i]);
			n++;
			check[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
		arr[i] *= 0.01;
	}

	solve(15, 15, 1.0);
	cout << fixed;
	cout << setprecision(10) << ans;
	return 0;
}