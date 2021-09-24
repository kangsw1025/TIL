#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n % 2) cout << "koosaga\n";
		else cout << "cubelover\n";
	}
	return 0;
}