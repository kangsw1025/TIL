#include<iostream>
using namespace std;

bool check[1000001];

void sosu() {
	for(int i=2;i<=1000;i++)
		if (!check[i]) {
			for (int j = 2; i * j <= 1000000; j++) check[i * j] = true;
		}
}

void solve(int n) {
	if (n < 8) {
		cout << -1;
		return;
	}

	if (n % 2) {
		cout << "2 3 ";
		n -= 5;
	}
	else {
		cout << "2 2 ";
		n -= 4;
	}
	for (int i = 2; i <= n; i++)
		if (!check[i] && !check[n - i]) {
			cout << i << ' ' << n - i;
			return;
		}
}

int main() {
	int n;
	cin >> n;
	sosu();
	solve(n);
	return 0;
}