#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, ans, cnt, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans = 1;
		cin >> a >> b;
		if (a == 0 || b == 0) cout << 0 << "\n";
		else if (a == b) cout << 1 << "\n";
		else {
			cnt = 1;
			while (a != 0) {
				ans = ans * b / cnt;
				b--;
				a--;
				cnt++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}