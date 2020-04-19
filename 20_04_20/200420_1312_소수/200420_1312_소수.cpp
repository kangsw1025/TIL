#include<iostream>
using namespace std;

int main()
{
	int n, m, c, ans;
	cin >> n >> m >> c;
	while (c--) {
		n %= m;
		n *= 10;
		ans = n / m;
	}
	cout << ans;
	return 0;
}