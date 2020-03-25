#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, cnt = 0, c = 0;
	cin >> n;
	for (int i = 666; i > 0; i++) {
		a = i;
		c = 0;
		while (a) {
			if (a % 10 == 6) c++;
			else c = 0;
			a = a / 10;
			if (c == 3) {
				cnt++;
				break;
			}
		}
		if (cnt == n) {
			cout << i;
			break;
		}
	}

	return 0;
}