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
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
 
		int idx = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[idx] > s[i]) idx = i;
		}
 
		cout << s[idx] << ' ';
		for (int i = 0; i < s.length(); i++) {
			if (i == idx) continue;
			cout << s[i];
		}
		cout << "\n";
	}
	
 
	return 0;
}