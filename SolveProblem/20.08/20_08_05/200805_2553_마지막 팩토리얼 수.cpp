#include<iostream>
using namespace std;

int solve(int n) {
	long long now = 1;
	for (int i = 2; i <= n; i++) {
		now = now * i % 100000000;
		while (now % 10 == 0) now /= 10;
	}
	return now % 10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cout<<solve(n);
	return 0;
}