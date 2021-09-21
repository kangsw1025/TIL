#include<iostream>
#include<cmath>
using namespace std;

void dw() {
	cout << "Donghyuk wins.\n";
}

void bw() {
	cout << "Baekjoon wins.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	while (cin >> n) {
		long long num = 1;

		while (1) {
			num *= 9;
			if (num >= n) {
				bw();
				break;
			}

			num *= 2;
			if (num >= n) {
				dw();
				break;
			}
		}
	}
	return 0;
}