#include<iostream>
using namespace std;

int main()
{
	int n, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) ans *= i;
	cout << ans;
	return 0;
}