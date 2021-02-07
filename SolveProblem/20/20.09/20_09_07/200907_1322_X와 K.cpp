#include<iostream>
using namespace std;

bool bits[65];
int n, k;
long long ans, p = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; n > 0; n /= 2) bits[i++] = n % 2;
	for(int i=0;i<65 && k;i++,p*=2)
		if (!bits[i]) {
			if (k % 2) ans += p;
			k /= 2;
		}
	cout << ans;
	return 0;
}