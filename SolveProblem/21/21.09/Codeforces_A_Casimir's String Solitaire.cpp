#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
 
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') a++;
			else if (s[i] == 'B') b++;
			else if (s[i] == 'C') c++;
		}
		if (a + c == b) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}