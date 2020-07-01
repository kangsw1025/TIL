#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, cnt = 0, min = 10001;
	cin >> a >> b;
	bool check;
	for (int i = a; i <= b; i++) {
		if (i == 1) continue;
		check = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check == true) {
			cnt += i;
			if (i < min) min = i;
		}
	}
	if (min == 10001) cout << -1;
	else cout << cnt << "\n" << min;
	return 0;
}