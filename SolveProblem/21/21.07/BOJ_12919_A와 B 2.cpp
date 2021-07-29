#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

string rule1(string st) {
	st.pop_back();
	return st;
}

string rule2(string st) {
	reverse(st.begin(), st.end());
	st.pop_back();
	return st;
}

int solve(string st, string ed) {

	if (st == ed) return true;
	if (st.front() == 'A' && st.back() == 'B' || st.length() <= ed.length()) return false;
	if (st.back() == 'A' && solve(rule1(st), ed)) return true;
	if (st.front() == 'B' && solve(rule2(st), ed)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string st, end;
	cin >> st >> end;

	cout << solve(end, st);
	return 0;
}