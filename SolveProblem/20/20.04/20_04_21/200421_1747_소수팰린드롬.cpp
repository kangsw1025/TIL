#include <iostream>
using namespace std;

char num[9];
bool check;
bool pel;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n == 1) cout << 2;
	else {
		for (int i = n; i > 0; i++) {
			pel = true;
			check = false;
			int number = i;
			int numch = 0;
			while (number) {
				num[numch++] = char(number % 10);
				number = number / 10;
			}
			for (int j = 0; j < numch / 2; j++) {
				if (num[j] != num[numch - 1 - j]) {
					pel = false;
					break;
				}
			}
			if (pel == true) {
				for (int j = 2; j < i; j++) {
					if (i % j == 0) {
						check = true;
						break;
					}
				}
				if (check == false) {
					cout << i;
					break;
				}
			}
		}
	}
	return 0;
}