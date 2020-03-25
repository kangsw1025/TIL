#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int* h = new int[n];
	int* w = new int[n];
	int* num = new int[n];
	int* ans = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i] >> w[i] >> num[i];
		if (num[i] % h[i] == 0) ans[i] = h[i] * 100 + (num[i] - 1) / h[i] + 1;
		else ans[i] = num[i] % h[i] * 100 + (num[i] - 1) / h[i] + 1;
		cout << ans[i]<<"\n";
	}
	return 0;
}

