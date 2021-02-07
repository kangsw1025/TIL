#include<iostream>
using namespace std;

bool sosu[1000001];

void check() {
	sosu[0] = true;
	sosu[1] = true;
	for (int i = 2; i <= 500000; i++)
		if (!sosu[i])
			for (int j = 2; i * j <= 1000000; j++)
				sosu[i * j] = true;	
}

bool solve(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (sosu[i] == false && sosu[n - i] == false) {
			cout << n << " = " << i << " + " << n - i << "\n";
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	check();
	while (1) {
		cin >> n;
		if (n == 0) break;
		if (!solve(n)) cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}