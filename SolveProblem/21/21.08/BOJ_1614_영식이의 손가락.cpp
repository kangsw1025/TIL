#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;
	
	if (n == 1) cout<< m * 8;
	else if (n == 2) cout << 1 + (m / 2) * 8 + (m % 2) * 6;
	else if (n == 3) cout << 2 + m * 4;
	else if (n == 4) cout << 3 + (m / 2) * 8 + (m % 2) * 2;
	else if (n == 5) cout << 4 + m * 8;
	return 0;
}