#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
 
		int zero = 0;
 
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				zero++;
				while (s[i] == '0' && i < s.length()) {
					i++;
				}
			}
		}
		if (zero == 0) cout << "0\n";
		else if (zero == 1) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}