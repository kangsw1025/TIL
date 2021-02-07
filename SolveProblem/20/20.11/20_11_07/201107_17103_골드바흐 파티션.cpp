#include<iostream>
using namespace std;

bool check[1000001];

void sosu() {
	check[0] = true;
	check[1] = true;
	for (int i = 2; i <= 1000; i++) {
		if (!check[i])
			for (int j = 2; i * j <= 1000000; j++)
				check[i * j] = true;
	}
}

int solve(int n) {
	int cnt = 0;
	for (int i = 2; i <= n / 2; i++)
		if (!check[i] && !check[n - i]) cnt++;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sosu();
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}