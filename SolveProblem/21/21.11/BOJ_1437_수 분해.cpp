#include<iostream>
using namespace std;

int solve(int cnt) {
	int rst = 1;
	int mul = 3;
	while (cnt) {
		if (cnt % 2) rst = (rst * mul) % 10007;
		mul = (mul * mul) % 10007;
		cnt /= 2;
	}

	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n <= 2) cout << n;
	else {
		int two = 0, three = 0;
		
		three = n / 3;
		if (n % 3 == 2) two = 1;
		else if (three && n % 3 == 1) {
			two = 2;
			three--;
		}

		int ans = solve(three);
		if (two) ans *= two*2;
		cout << ans % 10007;
	}
	return 0;
}
