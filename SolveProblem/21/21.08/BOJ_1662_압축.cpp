#include<iostream>
#include<stack>
#include<string>
using namespace std;

string s;
int arr[51];

int solve(int st, int ed) {

	int rst = 0;

	for (int i = st; i < ed; i++) {
		if (s[i] == '(') {
			int k = s[i - 1] - '0';
			rst += k * solve(i + 1, arr[i]) - 1;
			i = arr[i];
		}
		else rst++;
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> st;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			arr[st.top()] = i;
			st.pop();
		}
	}

	cout << solve(0, s.length());

	return 0;
}