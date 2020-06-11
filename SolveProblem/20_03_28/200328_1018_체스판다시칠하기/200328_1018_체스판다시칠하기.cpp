#include <iostream>
using namespace std;

char chess[51][51];

int count(int a, int b)
{
	int n = 0, m = 0;
	for (int i = a; i < a + 8; i++)
		for (int j = b; j < b + 8; j++) {
			if ((i - a + j - b) % 2 == 0) {
				if (chess[i][j] == 'B') n++;
				else m++;
			}
			else {
				if (chess[i][j] == 'W') n++;
				else m++;
			}
		}
	if (n > m) return m;
	else return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, re, min = 64;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) cin >> chess[i][j];
	for (int i = 0; i < a - 7; i++)
		for (int j = 0; j < b - 7; j++) {
			re = count(i, j);
			if (min > re) min = re;
		}
	cout << min;
	return 0;
}