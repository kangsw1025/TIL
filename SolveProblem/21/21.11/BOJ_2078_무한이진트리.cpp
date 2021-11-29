#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l = 0, r = 0;
	int a, b;
	cin >> a >> b;

	while (1) {
		if (a == 1) {
			r += b - 1;
			break;
		}
		else if (b == 1) {
			l += a - 1;
			break;
		}

		if (a > b) {
			l++;
			a -= b;
		}
		else if(a<b) {
			r++;
			b -= a;
		}
	}
	cout << l << ' ' << r;
	return 0;
}