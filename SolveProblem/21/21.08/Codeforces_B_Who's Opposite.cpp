#include<iostream>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
 
		int dif = b - a;
		int peo = dif * 2;
 
		if (c > peo || a > peo || b > peo) cout << "-1\n";
		else {
			if (c <= dif) cout << c + dif << "\n";
			else cout << c - dif << "\n";
		}
	}
	return 0;
}