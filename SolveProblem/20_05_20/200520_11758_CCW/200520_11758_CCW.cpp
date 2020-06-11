#include<iostream>
using namespace std;

int x[3];
int y[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
	int ans = x[0] * (y[1] - y[2]) - y[0] * (x[1] - x[2]) + (x[1] * y[2] - y[1] * x[2]);
	if (ans > 0) cout << 1;
	else if (ans == 0) cout << 0;
	else cout << -1;
	return 0;
}