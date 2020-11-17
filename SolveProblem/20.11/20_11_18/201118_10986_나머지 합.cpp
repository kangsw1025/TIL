#include<iostream>
using namespace std;

long long arr[1000001];
long long Mod[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		arr[i] = (arr[i - 1] + num) % m;
		if (!arr[i]) ans++;
		Mod[arr[i]]++;
	}

	for (int i = 0; i < m; i++) ans += Mod[i] * (Mod[i] - 1) / 2;

	cout << ans;
	return 0;
}