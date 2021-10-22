#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	int cnt = 0;
	for (long long i = 2; i * i <= n && cnt < 2; i++) {
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
	}

	if (n > 1) cnt++;

	cout << (cnt == 2 ? "cubelover" : "koosaga");
	return 0;
}