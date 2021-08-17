#include<iostream>
#include<string>
using namespace std;

int rst;
string s;

bool solve(int idx) {
	for (int i = 0; idx + i < s.length() - i - 1; i++)
		if (s[idx + i] != s[s.length() - i - 1])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	
	for(int i=0;i<s.length();i++)
		if (solve(i)) {
			rst = s.length() + i;
			break;
		}
	cout << rst;
	return 0;
}