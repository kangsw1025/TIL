#include<iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int solve(int ma, int mb, int a, int b) {
	int Max = ma*mb/gcd(ma, mb);
	while (1) {
		if ((a-1) % mb +1== b) return a;
		a += ma;
		if (a > Max) break;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int ma, mb, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ma >> mb >> a >> b;
		cout<<solve(ma, mb, a, b)<<"\n";
	}
	return 0;
}