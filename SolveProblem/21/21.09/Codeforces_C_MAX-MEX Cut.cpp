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
		int n, ans = 0;
		string s1, s2;
 
		cin >> n;
 
		cin >> s1>>s2;
 
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) ans += 2;
			else {
				if (i == n - 1) {
					if (s1[i] == '0') ans++;
				}
				else {
					if (s1[i] == '0') {
						if (s1[i + 1] == '1' && s2[i + 1] == '1') {
							ans += 2;
							i++;
						}
						else ans++;
					}
					else {
						while (i + 1 < n) {
							if (s1[i + 1] == '0' || s2[i + 1] == '0') {
								ans += 2;
								i++;
								break;
							}
							i++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}