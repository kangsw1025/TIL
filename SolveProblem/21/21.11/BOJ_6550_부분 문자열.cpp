#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	while (cin >> a >> b) {
		int l = 0;
		for (int i = 0; i < b.length(); i++) {
			if (a[l] == b[i]) l++;
			if (l == a.length()) break;
		}

		if (l == a.length()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}