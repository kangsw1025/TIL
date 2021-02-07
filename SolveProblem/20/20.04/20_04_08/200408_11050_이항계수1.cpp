#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b ,ans = 1;
	/*
	cin >> a >> b;
	cout << a << ' ' << b << ' ';
			if (a <= 0 || b <= 0 || a < b) cout << 0<< "\n";
			else if (a == b) cout << 1<<"\n";
			else {
				for (int i = 1; i <= b; i++) {
					ans = ans * a / i;
					a--;
				}
				cout << ans<<"\n";
			}
			*/
	for(int c=1;c<=10;c++)
		for (int d = 0; d <= c; d++) {
			ans = 1;
			cout << c << ' ' << d << ' ';
			int e = c;
			if (c <= 0 || d <= 0 || c < d) cout << 0<< "\n";
			else if (c == d) cout << 1<<"\n";
			else {
				for (int i = 1; i <= d; i++) {
					ans = ans * e / i;
					e--;
				}
				cout << ans<<"\n";
			}
		}

	return 0;
}
