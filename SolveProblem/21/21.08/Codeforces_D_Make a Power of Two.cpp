#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
 
vector<string> v;
 
int cmp(string f, string s) {
	int i, j = 0;
	for (i = 0; i < f.length(); i++) {
		if (f[i] == s[j]) {
			j++;
			if (j == s.length()) break;
		}
	}
	return f.length() + s.length() - j * 2;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	long long n = 1;
	v.push_back("1");
	for (int i = 1; i < 63; i++) {
		v.push_back(to_string(n * 2));
		n *= 2;
	}
 
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int ans = s.length()+1;
 
		for (int i = 0; i < v.size(); i++)
			ans = min(ans, cmp(s, v[i]));
		
		cout << ans << "\n";
	}
	return 0;
}