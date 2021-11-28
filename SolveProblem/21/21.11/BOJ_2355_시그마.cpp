#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long sum(long long n) {
	return n * (n + 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	cout << (b - a + 1) * (a + b) / 2;
	
	return 0;
}