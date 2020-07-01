#include<iostream>
#include<cmath>
using namespace std;

bool check[10];

int ch(int n) {
	if (n == 0) {
		if (check[0]) return 0;
		return 1;
	}

	int len = 0;

	while (n) {
		if (check[n % 10]) return 0;
		n = n / 10;
		len++;
	}
	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int num;
	cin>>num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		check[m] = true;
	}
	
	int ans = abs(m - 100);

	for (int i = 0; i <= 1000000; i++) {
		int len = ch(i);
		if (len > 0) {
			if (ans > abs(i - num) + len)
				ans = abs(i - num) + len;
		}
	}

	cout << ans;
	return 0;
}
