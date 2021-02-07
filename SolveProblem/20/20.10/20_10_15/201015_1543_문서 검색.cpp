#include<iostream>
#include<string>
using namespace std;

int main() {
	int ans = 0;
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < a.length(); i++) {
		bool check = true;
		for (int j = 0; j < b.length(); j++) {
			if (a[i + j] != b[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			i += b.length() - 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}