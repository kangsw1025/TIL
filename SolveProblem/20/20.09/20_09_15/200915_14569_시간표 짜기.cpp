#include<iostream>
#include<bitset>
using namespace std;

long long bit[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int b;
			cin >> b;
			bit[i] |= 1LL<<b;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num, cnt = 0;;
		cin >> num;
		long long com = 0;
		for (int j = 0; j < num; j++) {
			int b;
			cin >> b;
			com |= 1LL << b;
		}
		for (int j = 0; j < n; j++) if ((com & bit[j]) == bit[j]) cnt++;

		cout << cnt << "\n";
	}
	return 0;
}