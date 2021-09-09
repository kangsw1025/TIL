#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
using namespace std;
 
const int INF = 2e9;
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n>>s;
		bool find = false;
		for (int i = 0; i < s.length()-1; i++) {
			int a = 0, b = 0;
			if (find) break;
			for (int j = i; j < s.length(); j++) {
				if (s[j] == 'a') a++;
				else b++;
				if (a != 0 && a == b) {
					cout << i + 1 << ' ' << j + 1 << "\n";
					find = true;
					break;
				}
			}
		}
		if (!find) cout << "-1 -1\n";
	}
	return 0;
}