#include <iostream>
using namespace std;

int one[41];
int zero[41];


void show(int n)
{
	if (n < 2) return;
	for (int i = 2; i <= n; i++) {
		one[i] = one[i - 2] + one[i - 1];
		zero[i] = zero[i - 2] + zero[i - 1];
	}
}

int main()
{
	int n, max = 0;;
	cin >> n;
	int* num = new int[n];
	one[1] = 1;
	zero[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (max < num[i]) max = num[i];
	}
	show(max);
	for (int i = 0; i < n; i++) cout << zero[num[i]] << ' ' << one[num[i]] << "\n";
	return 0;
}