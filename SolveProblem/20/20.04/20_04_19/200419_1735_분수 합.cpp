#include <iostream>
using namespace std;

int main()
{
	int s[2], p[2], min, so, pa;
	for (int i = 0; i < 2; i++)
		cin >> s[i] >> p[i];
	so = s[0] * p[1] + s[1] * p[0];
	pa = p[0] * p[1];
	if (so > pa) min = pa;
	else min = so;
	for (int i = 2; i <= min; i++) {
		if (so % i == 0 && pa % i == 0) {
			so = so / i;
			pa = pa / i;
			min = min / i;
			i--;
		}
	}
	cout << so << ' ' << pa;
	return 0;
}