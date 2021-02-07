#include<iostream>
#include<queue>
using namespace std;

int n;
int n_i[4] = { 1,3,7,9 };
bool sosu(int num) {
	for (int i = 2; i <= num / 2; i++)
		if (num % i == 0)
			return false;
	return true;
}

void solve(int now, int cnt) {
	if (cnt == n) {
		cout << now << "\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		int num = now * 10 + n_i[i];
		if (sosu(num)) solve(num, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	solve(2, 1);
	solve(3, 1);
	solve(5, 1);
	solve(7, 1);
	return 0;
}