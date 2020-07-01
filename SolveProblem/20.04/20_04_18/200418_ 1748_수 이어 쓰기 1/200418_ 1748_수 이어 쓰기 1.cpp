#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, cnt = 0, sum = 0;
	cin >> n;
	int num = n;
	while (1) {
		num = num / 10;
		if (num) cnt++;
		else break;
	}
	for (int i = 0; i < cnt; i++) {
		sum += 9 * pow(10, i) * (i + 1);
	}
	sum += (n - pow(10, cnt) + 1) * (cnt + 1);
	cout << sum;
	return 0;
}