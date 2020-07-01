#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long a, b, max, ans = 1;
	long long as[30], bs[30], gs[30];
	int ai = 0 , bi = 0, gi = 0;
	cin >> a >> b;
	if (a > b) max = a;
	else max = b;
	for (int i = 2; i <= max; i++) {
		if (a % i == 0 && b % i == 0) {
			gs[gi++] = i;
			a = a / i;
			b = b / i;
			i--;
		}
		else if (a % i == 0) {
			as[ai++] = i;
			a = a / i;
			i--;
		}
		else if (b % i == 0) {
			bs[bi++] = i;
			b = b / i;
			i--;
		}
	}
	if(ai!=0)
		for (int i = 0; i < ai; i++) ans *= as[i];
	if(bi!=0)
		for (int i = 0; i < bi; i++) ans *= bs[i];
	if(gi!=0)
		for (int i = 0; i < gi; i++) ans *= gs[i];
	cout << ans;
	return 0;
}