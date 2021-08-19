#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
 
		int x, y = 0, sum;
		for (int i = 1; pow((i - 1), 2) + 1 <= n; i++) {
			sum = pow((i - 1), 2) + 1;
			y++;
		}
 
		int dif = n - sum;
		if (dif >= y) {
			x = y;
			y -= (dif - y + 1);
		}
		else {
			x = 1 + dif;
		}
 
		cout << x << ' ' << y << "\n";
	}
	return 0;
}