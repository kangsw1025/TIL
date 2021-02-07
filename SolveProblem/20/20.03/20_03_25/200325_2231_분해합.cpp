#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, sum;
	bool check = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		sum = i;
		num = i;
		while (1) {
			sum += num % 10;
			num = num / 10;
			if (num == 0) break;
		}
		if (sum == n) {
			check = true;
			cout << i;
			break;
		}
	}
	if (check == false) cout << 0;
	return 0;
 }