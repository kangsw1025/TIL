#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[21];
long long fac[21], idx;
bool use[21];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0] = 1;
	for (int i = 1; i <= 20; i++) fac[i] = i * fac[i - 1];

	int n, op;
	cin >> n >> op;
	
	if (op == 1) {
		cin >> idx;
		
		for (int i = 1; i <= n; i++) {
			int cnt = 1;

			for (int j = 1; j <= n; j++) {
				if (!use[j]) {
					if (cnt * fac[n - i] >= idx) {
						use[j] = true;
						cout << j << ' ';
						idx -= (cnt - 1) * fac[n - i];
						break;
					}
					cnt++;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) cin >> arr[i];

		idx = 1;
		for (int i = 1; i <= n; i++) {
			int cnt = 1;
			for (int j = 1; j <= n; j++) {
				if (!use[j]) {
					if (arr[i] == j) {
						use[j] = true;
						idx += (cnt - 1) * fac[n - i];
						break;
					}
					cnt++;
				}
			}
		}
		cout << idx;
	}

	return 0;
}