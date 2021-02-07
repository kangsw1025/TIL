#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int min1 = 1001, min2 = 1001;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		min1 = min(min1, a);
		min2 = min(min2, b);
	}

	if (min1 < min2 * 6) {
		if (min1 > min2 * (n % 6)) cout << (n / 6) * min1 + (n % 6) * min2;
		else cout << min1 * (n / 6 + 1);
	}
	else cout << n * min2;
	
	return 0;
}