#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
 
		int ab = 0, ba = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == 'a' && s[i + 1] == 'b') ab++;
			if (s[i] == 'b' && s[i + 1] == 'a') ba++;
		}
 
		if (ab == ba) cout << s << "\n";
		else {
			s[0] = s[s.length() - 1];
			cout << s << "\n";
		}
	}
 
	return 0;
}