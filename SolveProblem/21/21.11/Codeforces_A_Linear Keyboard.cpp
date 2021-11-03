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
 
map<char, int> mp;;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		mp.clear();
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < 26; i++) {
			mp[a[i]] = i;
		}
 
		int sum = 0;
 
		if (b.length() <= 1) {
			cout << "0\n";
			continue;
		}
 
		for (int i = 0; i < b.length() - 1; i++) {
			int diff = abs(mp[b[i]] - mp[b[i+1]]);
			sum += diff;
		}
		cout << sum << "\n";
	}
 
	return 0;
}