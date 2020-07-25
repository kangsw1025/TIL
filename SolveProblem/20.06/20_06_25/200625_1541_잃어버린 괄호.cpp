#include<iostream>
#include<string>
using namespace std;

bool mi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int ans = 0, sum = 0, now = 0;
	string w;
	cin >> w;
	for (int i = 0; i < w.length(); i++) {
		if (w[i] >= '0' && w[i] <= '9') {
			now = now * 10 + w[i] - '0';
		}
		else if (w[i] == '+' || w[i]=='-') {
			sum += now;
			now = 0;
			if (w[i] == '-') {
				if (mi == true) {
					ans -= sum;
					sum = 0;
				}
				else {
					mi = true;
					ans += sum;
					sum = 0;
				}
			}
		}
	}
	if (mi == true) {
		sum += now;
		ans -= sum;
	}
	else {
		sum += now;
		ans += sum;
	}
	cout << ans;
	return 0;
}