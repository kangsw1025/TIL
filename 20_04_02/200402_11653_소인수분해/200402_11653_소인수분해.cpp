#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,num;
	cin >> n;
	num = n;
	for (int i = 2; i <= n; i++) {
		if (num == 1) break;
		else {
			if (num % i == 0) {
				cout << i << "\n";
				num = num / i;
				i--;
			}
		}
	}
	return 0;
}