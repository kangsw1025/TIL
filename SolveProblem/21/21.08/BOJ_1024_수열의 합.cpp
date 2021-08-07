#include <iostream>
using namespace std;

int count(int n) {
	return n * (n + 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int sum = count(m - 1);
	while (sum <= n) {
		if ((n-sum) % m == 0) {
			int st = (n-sum) / m;
			for (int i = 0; i < m; i++) cout << st + i << ' ';
			return 0;
		}
		else {
			sum += m;
			m++;
			if (m > 100) break;
		}
	}
	cout << -1;
	return 0;
}