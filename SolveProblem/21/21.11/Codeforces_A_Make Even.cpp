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
		int even = -1;
		for (int i = 0; i < s.length(); i++) {
			if ((s[i] - '0') % 2 == 0) {
				even = i;
				break;
			}
		}
 
		if (even == -1) cout << "-1\n";
		else if ((s[s.length() - 1] - '0') % 2 == 0) cout << "0\n";
		else if ((s[0] - '0') % 2 == 0) cout << "1\n";
		else cout << "2\n";
	}
 
	return 0;
}