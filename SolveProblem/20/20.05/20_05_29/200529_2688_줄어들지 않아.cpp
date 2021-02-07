#include<iostream>
using namespace std;

long long arr[65][10];
long long ans[65];

void solve()
{
	for (int i = 0; i < 10; i++) arr[1][i] = 1;

	for (int i = 2; i <= 64; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k <= j; k++)
				arr[i][j] += arr[i - 1][k];
		
	
	for (int i = 1; i <= 64; i++)
		for (int j = 0; j < 10; j++) ans[i] += arr[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin >> n;

	solve();

	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << ans[m]<<"\n";
	}
	return 0;
}