#include<iostream>
#include<algorithm>
using namespace std;

int n, a, b, ans;
int one[2000], two[3000];

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> a >> b;
	for (int i = 0; i < a; i++)
		cin >> one[i];

	for (int i = 0; i < b; i++)
		cin >> two[i];


	sort(one, one + a);

	if (n & 1) ans += one[--a];
	n >>= 1;

	for (int i = 0; i < (a >> 1); i++)
		two[b++] = one[a - (i << 1) - 1] + one[a - (i << 1) - 2];

	sort(two, two + b);

	for (int i = 0; i < n; i++)
		ans += two[b - i - 1];
	cout << ans;
	return 0;
}