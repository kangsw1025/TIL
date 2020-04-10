#include<iostream>
using namespace std;

int arr[1000001];

int find(int n)
{
	if (n == arr[n]) return n;
	else return arr[n] = find(arr[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ln, n;
	int a, b, c;
	cin >> ln >> n;
	for (int i = 1; i <= ln; i++) arr[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			b = find(b);
			c = find(c);

			if (b > c) arr[c] = b;
			else if (b < c) arr[b] = c;
		}
		if (a == 1) {
			b = find(b);
			c = find(c);
			if (b == c) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}