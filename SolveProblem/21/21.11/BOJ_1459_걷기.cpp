#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long x, y, w, s;
	cin >> x >> y >> w >> s;

	long long dif = abs(x - y), sum = 0;

	sum = min(x, y) * (2 * w > s ? s : 2 * w);
	if (dif % 2) sum += w;
	dif /= 2;
	sum += dif * (w > s ? s : w) * 2;
	cout << sum;
	return 0;
}